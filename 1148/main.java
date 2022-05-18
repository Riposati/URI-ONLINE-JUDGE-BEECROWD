import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

class Comparador implements Comparator<Vertice> {

	@Override
	public int compare(Vertice o1, Vertice o2) {

		if (o1.getDistancia() < o2.getDistancia()) {
			return -1;
		}
		if (o1.getDistancia() > o2.getDistancia()) {
			return 1;
		}
		return 0;
	}
}

class Vertice {

	private int rotulo;
	private double distancia;
	private List<Aresta> listaArestas;
	private Vertice precedente;

	public Vertice(int rotulo) {
		this.rotulo = rotulo;
		this.distancia = Double.POSITIVE_INFINITY;
		this.listaArestas = new ArrayList<Aresta>(1000);
		this.precedente = null;
	}

	public void setPrecedente(Vertice v) {
		this.precedente = v;
	}

	public Vertice getPrecedente() {
		return this.precedente;
	}

	public double getDistancia() {
		return distancia;
	}

	public void setDistancia(double distancia) {
		this.distancia = distancia;
	}

	public int getRotulo() {
		return rotulo;
	}

	public List<Aresta> getListaArestas() {
		return listaArestas;
	}
}

class Aresta {

	private Vertice verticeAdj;
	private double pesoAresta;

	public double getPesoAresta() {
		return pesoAresta;
	}

	public void setPesoAresta(double pesoAresta) {
		this.pesoAresta = pesoAresta;
	}

	public Vertice getRotuloVerticeVai() {
		return verticeAdj;
	}

	public void setRotuloVerticeVai(Vertice rotuloVerticeVai) {
		this.verticeAdj = rotuloVerticeVai;
	}
}

class Grafo {

	private List<Vertice> vertices;
	private PriorityQueue<Vertice> filaDeVertices;

	public Grafo() {
		this.vertices = new ArrayList<Vertice>(1000);
		this.filaDeVertices = new PriorityQueue<>(1000, new Comparador());
	}

	public List<Vertice> getVertices() {
		return vertices;
	}

	public void addVertice(Vertice v) {
		this.vertices.add(v);
	}

	public void mostraGrafo(int vInicial, int vFinal) {

		for (Vertice v : this.vertices) {

			if (v.getRotulo() == vFinal) {
				if (v.getDistancia() == Double.POSITIVE_INFINITY) {

					System.out.println("Nao e possivel entregar a carta");
				} else
					System.out.println((int) v.getDistancia());
			}
		}
	}

	public void addAresta(Vertice verticeParteAresta, Vertice verticeRecebeAresta, double pesoAresta) {

		Aresta a = new Aresta();
		a.setRotuloVerticeVai(verticeRecebeAresta);
		a.setPesoAresta(pesoAresta);
		this.vertices.get(verticeParteAresta.getRotulo() - 1).getListaArestas().add(a);

		for (int i = 0; i < this.vertices.get(verticeParteAresta.getRotulo() - 1).getListaArestas().size(); i++) { // O(500)

			if (this.vertices.get(verticeParteAresta.getRotulo() - 1).getListaArestas().get(i).getRotuloVerticeVai()
					.getRotulo() == verticeRecebeAresta.getRotulo()) {

				for (int j = 0; j < verticeRecebeAresta.getListaArestas().size(); j++) { // O(250 000)

					if (verticeRecebeAresta.getListaArestas().get(j).getRotuloVerticeVai().getRotulo() == this.vertices
							.get(verticeParteAresta.getRotulo() - 1).getRotulo()) {

						verticeRecebeAresta.getListaArestas().get(j).setPesoAresta(0);
						verticeParteAresta.getListaArestas().get(i).setPesoAresta(0);
						break;
					}
				}
			}
		}
	}
	
	private boolean acheiVertice(int rotulo) {

		for (int i = 0; i < this.getVertices().size(); i++) {

			if (this.getVertices().get(i).getRotulo() == rotulo) {
				this.getVertices().get(i).setDistancia(0); // O começo da busca
				filaDeVertices.add(this.getVertices().get(i));
				return true;
			}
		}

		return false;
	}

	private void BFS(Vertice v) {

		double sum = 0;

		for (int i = 0; i < v.getListaArestas().size(); i++) {

			Aresta a = v.getListaArestas().get(i);
			sum = v.getDistancia() + a.getPesoAresta();

			if (sum < a.getRotuloVerticeVai().getDistancia()) {

				a.getRotuloVerticeVai().setDistancia(sum);
				a.getRotuloVerticeVai().setPrecedente(v);
				this.filaDeVertices.add(a.getRotuloVerticeVai());
			}
		}
	}

	public void dijkstra(int rotuloVerticeInicial) {

		if (acheiVertice(rotuloVerticeInicial)) {

			while (filaNaoVazia()) {

				BFS(filaDeVertices.poll());
			}
		}
	}

	private boolean filaNaoVazia() {
		return !this.filaDeVertices.isEmpty();
	}
}

class Reader
{
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Reader()
    {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException
    {
        din = new DataInputStream(new FileInputStream(file_name));
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public String readLine() throws IOException
    {
        byte[] buf = new byte[64]; // line length
        int cnt = 0, c;
        while ((c = read()) != -1)
        {
            if (c == '\n')
                break;
            buf[cnt++] = (byte) c;
        }
        return new String(buf, 0, cnt);
    }

    public int nextInt() throws IOException
    {
        int ret = 0;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do
        {
            ret = ret * 10 + c - '0';
        }  while ((c = read()) >= '0' && c <= '9');

        if (neg)
            return -ret;
        return ret;
    }

    public long nextLong() throws IOException
    {
        long ret = 0;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do {
            ret = ret * 10 + c - '0';
        }
        while ((c = read()) >= '0' && c <= '9');
        if (neg)
            return -ret;
        return ret;
    }

    public double nextDouble() throws IOException
    {
        double ret = 0, div = 1;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();

        do {
            ret = ret * 10 + c - '0';
        }
        while ((c = read()) >= '0' && c <= '9');

        if (c == '.')
        {
            while ((c = read()) >= '0' && c <= '9')
            {
                ret += (c - '0') / (div *= 10);
            }
        }

        if (neg)
            return -ret;
        return ret;
    }

    private void fillBuffer() throws IOException
    {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1)
            buffer[0] = -1;
    }

    private byte read() throws IOException
    {
        if (bufferPointer == bytesRead)
            fillBuffer();
        return buffer[bufferPointer++];
    }

    public void close() throws IOException
    {
        if (din == null)
            return;
        din.close();
    }
}

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {

		Reader s = new Reader();

		Grafo g = new Grafo();
		int qtdVertices, qtdArestas, auxArestaVai, auxArestaRecebe, auxPesoAresta;
		List<Vertice> lista = new ArrayList<Vertice>(1000);

		qtdVertices = s.nextInt();
		qtdArestas = s.nextInt();

		while (qtdVertices != 0 || qtdArestas != 0) {

			for (int i = 0; i < qtdVertices; i++) { // O(500)
				Vertice v = new Vertice(i + 1);
				lista.add(v);
				g.addVertice(v);
			}

			Vertice verticeAux1 = null, verticeAux2 = null;

			for (int i = 0; i < qtdArestas; i++) { // O(250 000)

				auxArestaVai = s.nextInt();
				auxArestaRecebe = s.nextInt();
				auxPesoAresta = s.nextInt();

				for (int j = 0; j < lista.size(); j++) {

					if (auxArestaVai == lista.get(j).getRotulo()) {
						verticeAux1 = lista.get(j);
					}
					if (auxArestaRecebe == lista.get(j).getRotulo()) {
						verticeAux2 = lista.get(j);
					}
				}
				g.addAresta(verticeAux1, verticeAux2, auxPesoAresta);
			}

			int qtdPesquisas = s.nextInt();
			int a, b;

			for (int i = 0; i < qtdPesquisas; i++) { // O(100)

				a = s.nextInt();
				b = s.nextInt();

				g.dijkstra(a);
				g.mostraGrafo(a, b);

				for (int j = 0; j < g.getVertices().size(); j++) {
					g.getVertices().get(j).setDistancia(Double.POSITIVE_INFINITY);
				}
			}

			qtdVertices = s.nextInt();
			qtdArestas = s.nextInt();
			lista.clear();
			g = new Grafo();
			System.out.print("\n");
		}
	}
}