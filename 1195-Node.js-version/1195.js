const fs = require('fs');

try {

    class No {
        constructor(chave){
        this.chave=chave;
        this.esq=null;
        this.dir=null;
        }
    }

    class Arvore  {

        constructor() { 
            this.raiz = null; 
        } 

        inserir(chave){

            let newNo = new No(chave);
            
            if(this.raiz===null){
                this.raiz = newNo;
            }else{
                this.insertNode(this.raiz, newNo); 
            }
            
        }

        insertNode(node, newNode) 
        { 
            // if the data is less than the node 
            // data move left of the tree  
            if(newNode.chave < node.chave) 
            { 
                // if left is null insert node here 
                if(node.esq === null) 
                    node.esq = newNode; 
                else
        
                    // if left is not null recur until  
                    // null is found 
                    this.insertNode(node.esq, newNode);  
            } 
        
            // if the data is more than the node 
            // data move right of the tree  
            else
            { 
                // if right is null insert node here 
                if(node.dir === null) 
                    node.dir = newNode; 
                else
        
                    // if right is not null recur until  
                    // null is found 
                    this.insertNode(node.dir,newNode); 
            } 
        }

        mostrarInfix(node){
            
            if(node !== null){
                this.mostrarInfix(node.esq);
                // console.log(node.chave);
                arInOrder += " " + node.chave;
                this.mostrarInfix(node.dir);
            }
        }

        preorder(node) 
        { 
            if(node !== null) 
            { 
                // console.log(node.chave); 
                arPreOrder += " " + node.chave;
                this.preorder(node.esq); 
                this.preorder(node.dir); 
            } 
        } 

        postorder(node) 
        { 
            if(node !== null) 
            { 
                this.postorder(node.esq); 
                this.postorder(node.dir); 
                // console.log(node.chave); 
                arPosOrder += " " + node.chave;
            } 
        } 

    }

    const data = 
    // fs.readFileSync('input.txt', 'UTF-8');
    fs.readFileSync('/dev/stdin', 'UTF-8'); // NO URI / LINUX funciona assim

    const lines = data.split(/\r?\n/);

    let arInOrder,arPreOrder,arPosOrder,cont;
    cont=1;
    let i = 0;

    let testes = parseInt(lines.shift());

    while(testes > 0){

        exp = parseInt(lines.shift());
        exp2 = lines.shift().split(" ");

        arInOrder = '';
        arPreOrder = '';
        arPosOrder = '';

        arvore = new Arvore();

        while(exp > 0){
            arvore.inserir(parseInt(exp2[i]));
            i++;
            exp--;
        }

        arvore.preorder(arvore.raiz);
        arvore.mostrarInfix(arvore.raiz);
        arvore.postorder(arvore.raiz);

        console.log("Case " + cont + ":");
        console.log("Pre.:" + arPreOrder);
        console.log("In..:" + arInOrder);
        console.log("Post:" + arPosOrder);
        console.log("");
        testes--;
        cont++;
        i=0;
    }
        
} catch (err) {
    console.error(err);
}
