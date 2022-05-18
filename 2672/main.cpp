#include <bits/stdc++.h>

using namespace std;

map<int,string>mapaMascara;

void preencheMapa(){
    mapaMascara.insert(make_pair(0,"0.0.0.0."));
    mapaMascara.insert(make_pair(1,"128.0.0.0."));
    mapaMascara.insert(make_pair(2,"192.0.0.0."));
    mapaMascara.insert(make_pair(3,"224.0.0.0."));
    mapaMascara.insert(make_pair(4,"240.0.0.0."));
    mapaMascara.insert(make_pair(5,"248.0.0.0."));
    mapaMascara.insert(make_pair(6,"252.0.0.0."));
    mapaMascara.insert(make_pair(7,"254.0.0.0."));
    mapaMascara.insert(make_pair(8,"255.0.0.0."));
    mapaMascara.insert(make_pair(9,"255.128.0.0."));
    mapaMascara.insert(make_pair(10,"255.192.0.0."));
    mapaMascara.insert(make_pair(11,"255.224.0.0."));
    mapaMascara.insert(make_pair(12,"255.240.0.0."));
    mapaMascara.insert(make_pair(13,"255.248.0.0."));
    mapaMascara.insert(make_pair(14,"255.252.0.0."));
    mapaMascara.insert(make_pair(15,"255.254.0.0."));
    mapaMascara.insert(make_pair(16,"255.255.0.0."));
    mapaMascara.insert(make_pair(17,"255.255.128.0."));
    mapaMascara.insert(make_pair(18,"255.255.192.0."));
    mapaMascara.insert(make_pair(19,"255.255.224.0."));
    mapaMascara.insert(make_pair(20,"255.255.240.0."));
    mapaMascara.insert(make_pair(21,"255.255.248.0."));
    mapaMascara.insert(make_pair(22,"255.255.252.0."));
    mapaMascara.insert(make_pair(23,"255.255.254.0."));
    mapaMascara.insert(make_pair(24,"255.255.255.0."));
    mapaMascara.insert(make_pair(25,"255.255.255.128."));
    mapaMascara.insert(make_pair(26,"255.255.255.192."));
    mapaMascara.insert(make_pair(27,"255.255.255.224."));
    mapaMascara.insert(make_pair(28,"255.255.255.240."));
    mapaMascara.insert(make_pair(29,"255.255.255.248."));
    mapaMascara.insert(make_pair(30,"255.255.255.252."));
}
int main()
{
    string entrada;
    preencheMapa();

    while(getline(cin,entrada)!=NULL){

        string ip,mascaraRede,t;
        string binarioIp,binarioMascaraRede;
        bool flagEspaco = false;
        int pos=0;

        for(int i=0;i<entrada.size();i++){

            if(entrada[i]==' '){
                pos = i;
                flagEspaco = true;
                break;
            }
            if(entrada[i]=='/'){
                pos = i;
                break;
            }
        }

        if(flagEspaco){ // entrada com a mascara informada por exemplo 255.255.255.5
            for(int i=0;i<entrada.size();i++){

                if(i<=pos-1){
                    ip+=entrada[i];
                }else if(i > pos){

                    mascaraRede+=entrada[i];
                }
            }
            mascaraRede +='.';

        }else{ // entrada tipo /23

            string pegaValorMapa;

            for(int i=0;i<entrada.size();i++){

                if(i<pos){
                    ip +=entrada[i];
                }else if(i > pos){

                    pegaValorMapa +=entrada[i];
                }
            }
            int chaveMapa = atoi(pegaValorMapa.c_str());
            mascaraRede = mapaMascara.find(chaveMapa)->second;
        }

        /*printf("IP = %s\n",ip.c_str());
        printf("Mascara = %s\n",mascaraRede.c_str());*/

        ip+='.';
        int cont=0;

        for(int i=0;i<ip.size();i++){

            if(ip[i]!='.'){
                t += ip[i];
            }else{

                int aux;
                aux = atoi(t.c_str());

                for(int j=7;j>=0;j--){

                    if(cont+(1LL<<j) <= aux){
                        //printf("1");
                        binarioIp+='1';
                        cont+= 1LL<<j;
                    }else{
                        //printf("0");
                        binarioIp+='0';
                    }
                }
                t.clear();
                cont = 0;
            }
        }

        int qtdZerosNaMascara=0;
        int qtdUnsMascara=0;
        int cont2=0;
        string t2;

        for(int i=0;i<mascaraRede.size();i++){

            if(mascaraRede[i]!='.'){
                t2 += mascaraRede[i];
            }else{

                int aux;
                aux = atoi(t2.c_str());

                for(int j=7;j>=0;j--){

                    if(cont2+(1LL<<j) <= aux){
                        //printf("1");
                        qtdUnsMascara++;
                        binarioMascaraRede+='1';
                        cont2+=1LL<<j;
                    }else{
                        //printf("0");
                        qtdZerosNaMascara++;
                        binarioMascaraRede+='0';
                    }
                }
                t2.clear();
                cont2 = 0;
            }
        }

        int zeraIp = 31 - qtdUnsMascara;
        int i=binarioIp.size()-1;
        while(zeraIp >= 0){
            binarioIp[i] = '0';
            i--;
            zeraIp--;
        }

        string binarioIp2 = binarioIp;

        zeraIp = 31 - qtdUnsMascara;
        i=binarioMascaraRede.size()-1;
        while(zeraIp >= 0){
            binarioIp2[i] = '1';
            i--;
            zeraIp--;
        }

        int primOctetoBinarioIp=0;
        int segOctetoBinarioIp=0;
        int terOctetoBinarioIp=0;
        int quartoOctetoBinarioIp=0;

        printf("Endereco de rede: ");
        int j = 7;
        for(int i=0;i<=7;i++){

            if(binarioIp[i]=='1'){

                primOctetoBinarioIp += 1LL<<j;
            }
            j--;
        }
        printf("%d.",primOctetoBinarioIp);

        j=7;
        for(int i=8;i<=15;i++){

            if(binarioIp[i]=='1'){

                segOctetoBinarioIp += 1LL<<j;
            }
            j--;
        }
        printf("%d.",segOctetoBinarioIp);

        j=7;
        for(int i=16;i<=23;i++){

            if(binarioIp[i]=='1'){

                terOctetoBinarioIp += 1LL<<j;
            }
            j--;
        }
        printf("%d.",terOctetoBinarioIp);

        j=7;
        for(int i=24;i<=31;i++){

            if(binarioIp[i]=='1'){

                quartoOctetoBinarioIp += 1LL<<j;
            }
            j--;
        }
        printf("%d\n",quartoOctetoBinarioIp);

        int primOctetoBinarioIp2=0;
        int segOctetoBinarioIp2=0;
        int terOctetoBinarioIp2=0;
        int quartoOctetoBinarioIp2=0;

        printf("Endereco de broadcast: ");
        j = 7;
        for(int i=0;i<=7;i++){
            if(binarioIp2[i]=='1'){
                primOctetoBinarioIp2 +=  1LL<<j;
            }
            j--;
        }
        printf("%d.",primOctetoBinarioIp2);

        j=7;
        for(int i=8;i<=15;i++){
            if(binarioIp2[i]=='1'){
                segOctetoBinarioIp2 +=  1LL<<j;
            }
            j--;
        }
        printf("%d.",segOctetoBinarioIp2);

        j=7;
        for(int i=16;i<=23;i++){
            if(binarioIp2[i]=='1'){
                terOctetoBinarioIp2 +=  1LL<<j;
            }
            j--;
        }
        printf("%d.",terOctetoBinarioIp2);

        j=7;
        for(int i=24;i<=31;i++){

            if(binarioIp2[i]=='1'){
                quartoOctetoBinarioIp2 +=  1LL<<j;
            }
            j--;
        }

        printf("%d\n",quartoOctetoBinarioIp2);

        /*printf("binario ip = %s\n",binarioIp.c_str());
        printf("binario mascara = %s\n",binarioIp2.c_str());*/

        long long qtdEnderecosDisponiveis = (1LL<<qtdZerosNaMascara)-2;
        printf("Numero de maquinas: %llu\n",qtdEnderecosDisponiveis);
        printf("\n");
    }
    return 0;
}
