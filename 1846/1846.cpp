#include <bits/stdc++.h>

using namespace std;

unordered_map<int,string>mapa;
unordered_map<int,string>::iterator it;

void preencheMapa(){
    mapa[0] = "zero";
    mapa[1] = "um";
    mapa[2] = "dois";
    mapa[3] = "tres";
    mapa[4] = "quatro";
    mapa[5] = "cinco";
    mapa[6] = "seis";
    mapa[7] = "sete";
    mapa[8] = "oito";
    mapa[9] = "nove";
    mapa[10] = "dez";
    mapa[11] = "onze";
    mapa[12] = "doze";
    mapa[13] = "treze";
    mapa[14] = "quatorze";
    mapa[15] = "quinze";
    mapa[16] = "dezesseis";
    mapa[17] = "dezessete";
    mapa[18] = "dezoito";
    mapa[19] = "dezenove";
    mapa[20] = "vinte";
    mapa[30] = "trinta";
    mapa[40] = "quarenta";
    mapa[50] = "cinquenta";
    mapa[60] = "sessenta";
    mapa[70] = "setenta";
    mapa[80] = "oitenta";
    mapa[90] = "noventa";
    mapa[100] = "cem";
    mapa[200] = "duzentos";
    mapa[300] = "trezentos";
    mapa[400] = "quatrocentos";
    mapa[500] = "quinhentos";
    mapa[600] = "seiscentos";
    mapa[700] = "setecentos";
    mapa[800] = "oitocentos";
    mapa[900] = "novecentos";
}

void numeroUmDigito(int numero){
    it = mapa.find(numero);
    printf("%s",it->second.begin());
}

void numeroDoisDigitos(int numero){
    if(mapa.count(numero) > 0){
        it = mapa.find(numero);
        printf("%s",it->second.begin());
    }else{
        int numeroInt = numero;
        int numeroResto = numeroInt % 10;
        int resp = numeroInt - numeroResto;

        it = mapa.find(resp);
        printf("%s",it->second.begin());

        if(numeroResto != 0){
            printf(" e ");
            numeroUmDigito(numeroResto);
        }
    }
}

void numeroTresDigitos(int numero){
    if(mapa.count(numero) > 0){
        it = mapa.find(numero);
        printf("%s",it->second.begin());
    }else{
        int numeroInt = numero;
        int numeroResto = numeroInt % 100;
        int resp = numeroInt - numeroResto;

        it = mapa.find(resp);

        if(numeroInt > 100 && numeroInt < 200)
            printf("cento");
        else if(resp != 0)
            printf("%s",it->second.begin());

        if(numeroResto != 0){
            printf(" e ");
            numeroDoisDigitos(numeroResto);
        }
    }
}

void numeroQuatroDigitos(int numero){
    if(mapa.count(numero) > 0){
        it = mapa.find(numero);
        printf("%s",it->second.begin());
    }else{
        int numeroInt = numero;
        int numeroResto = numeroInt % 1000;
        int respNum = numeroInt - numeroResto;

        it = mapa.find(respNum / 1000);

        if(respNum / 1000 == 1){
            printf("mil");
        }else{
            printf("%s",it->second.begin());
            printf(" mil");
        }
        if(to_string(numeroResto).size() == 3 && numeroResto != 0){
            string numer = to_string(numero);
            if(numer[2]=='0' && numer[3]=='0')
                printf(" e ");
            else
                printf(" ");
            numeroTresDigitos(numeroResto);
        }
        if(to_string(numeroResto).size() == 2 && numeroResto != 0){
            printf(" e ");
            numeroDoisDigitos(numeroResto);
        }
        if(to_string(numeroResto).size() == 1 && numeroResto != 0){
            printf(" e ");
            numeroUmDigito(numeroResto);
        }
    }
}

void funcaoAuxiliar(int numero, int numeroResto){
    if(to_string(numeroResto % 1000).size() == 3 && (numeroResto % 1000) != 0){
        string numeroString = to_string(numero);
        if((numeroString[3]=='0' && numeroString[4]=='0') || (numeroString[2]=='0' && numeroString[3]=='0'))
            printf(" e ");
        else
            printf(" ");
        numeroTresDigitos(numeroResto % 1000);
    }
    if(to_string(numeroResto % 1000).size() == 2 && (numeroResto % 1000) != 0){
        printf(" e ");
        numeroDoisDigitos(numeroResto % 1000);
    }
    if(to_string(numeroResto % 1000).size() == 1 && (numeroResto % 1000) != 0){
        printf(" e ");
        numeroUmDigito(numeroResto % 1000);
    }
}

void numeroCincoDigitos(int numero){
    string resp;
    int numeroInt = numero;
    int numeroResto = numeroInt % 10000;
    int respos = numeroInt - numeroResto;

    if(mapa.count(numeroInt / 1000) > 0){
            it = mapa.find(numeroInt / 1000);
            resp = it->second;
    }else{

        it = mapa.find(respos / 1000);
        resp = it->second;
        if(numeroResto != 0){
            it = mapa.find(numeroResto / 1000);
            resp += " e ";
            resp += it->second;
        }
    }
    resp += " mil";
    printf("%s",resp.begin());
    funcaoAuxiliar(numero,numeroResto);
}

void numeroSeisDigitos(int numero){
    int numeroResto = numero % 100000;
    string numeroString = to_string(numero), tresPrimeirosDigitosmilhar;
    stringstream ss,ss2;

    ss << numeroString[0]<<numeroString[1]<<numeroString[2];
    ss >> tresPrimeirosDigitosmilhar;

    numeroTresDigitos(stoi(tresPrimeirosDigitosmilhar));
    printf(" mil");

    if(numeroString[3] != '0' && numeroString[4]=='0' && numeroString[5]=='0')
        printf(" e");
    funcaoAuxiliar(numero,numeroResto);
}

main()
{
    preencheMapa();
    int numero;
    while(scanf("%d",&numero) != EOF){
        if(numero < 10)numeroUmDigito(numero);
        if(numero > 9 && numero < 100)numeroDoisDigitos(numero);
        if(numero > 99 && numero < 1000)numeroTresDigitos(numero);
        if(numero > 999 && numero < 10000)numeroQuatroDigitos(numero);
        if(numero > 9999 && numero < 100000)numeroCincoDigitos(numero);
        if(numero > 99999 && numero < 1000000)numeroSeisDigitos(numero);
        printf("\n");
    }
}
