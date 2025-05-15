#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 48
#define MAX_STR_LEN 30

typedef struct {
    int key;
    char value[MAX_STR_LEN];
} MapEntry;

MapEntry mapa[MAX_ENTRIES];
int mapa_size = 0;

void preencheMapa() {
    int keys[] = {
        1,2,3,4,5,6,7,8,9,
        10,11,12,13,14,15,16,17,18,19,
        20,30,40,50,60,70,80,90,
        100,200,300,400,500,600,700,800,900
    };

    char* values[] = {
        "um","dois","tres","quatro","cinco","seis","sete","oito","nove",
        "dez","onze","doze","treze","quatorze","quinze","dezesseis","dezessete","dezoito","dezenove",
        "vinte","trinta","quarenta","cinquenta","sessenta","setenta","oitenta","noventa",
        "cem","duzentos","trezentos","quatrocentos","quinhentos","seiscentos","setecentos","oitocentos","novecentos"
    };

    mapa_size = sizeof(keys)/sizeof(int);

    for(int i=0; i<mapa_size; i++) {
        mapa[i].key = keys[i];
        strcpy(mapa[i].value, values[i]);
    }
}

char* mapa_find(int numero) {
    for(int i = 0; i < mapa_size; i++) {
        if(mapa[i].key == numero)
            return mapa[i].value;
    }
    return NULL;
}

void numeroUmDigito(int numero) {
    char* res = mapa_find(numero);
    if(res) printf("%s", res);
}

void numeroDoisDigitos(int numero) {
    char* res = mapa_find(numero);
    if(res) {
        printf("%s", res);
    } else {
        int numeroResto = numero % 10;
        int resp = numero - numeroResto;

        res = mapa_find(resp);
        if(res) printf("%s", res);

        if(numeroResto != 0) {
            printf(" e ");
            numeroUmDigito(numeroResto);
        }
    }
}

void numeroTresDigitos(int numero) {
    char* res = mapa_find(numero);
    if(res) {
        printf("%s", res);
    } else {
        int numeroResto = numero % 100;
        int resp = numero - numeroResto;

        res = mapa_find(resp);

        if(numero > 100 && numero < 200)
            printf("cento");
        else if(resp != 0 && res != NULL)
            printf("%s", res);

        if(numeroResto != 0) {
            printf(" e ");
            numeroDoisDigitos(numeroResto);
        }
    }
}

void escreveMilhares(int milhar) {
    if(milhar == 1) {
        printf("mil");
        return;
    }
    else if(milhar < 10) {
        numeroUmDigito(milhar);
        printf(" mil");
    }
    else if(milhar < 100) {
        numeroDoisDigitos(milhar);
        printf(" mil");
    }
    else {
        numeroTresDigitos(milhar);
        printf(" mil");
    }
}

void numeroAteSeisDigitos(int numero) {
    if(numero == 0) {
        printf("zero");
        return;
    }

    if(numero < 10) {
        numeroUmDigito(numero);
    } else if(numero < 100) {
        numeroDoisDigitos(numero);
    } else if(numero < 1000) {
        numeroTresDigitos(numero);
    } else {
        int milhar = numero / 1000;
        int resto = numero % 1000;

        escreveMilhares(milhar);

        if(resto != 0) {
            // Decide onde colocar "e" ou espaço entre milhar e resto

            // Conta quantos dígitos tem o resto
            int temp = resto;
            int count = 0;
            while(temp > 0) {
                temp /= 10;
                count++;
            }

            if(count == 3) {
                // Se resto tem 3 dígitos, e o número não é múltiplo de 1000
                // Se centenas do resto forem "00" então " e ", senão espaço
                int centenas_rest = resto / 100;
                int dezenas_rest = (resto % 100) / 10;
                int unidades_rest = resto % 10;

                if(dezenas_rest == 0 && unidades_rest == 0) {
                    printf(" e ");
                } else {
                    printf(" ");
                }

                numeroTresDigitos(resto);
            }
            else {
                printf(" e ");
                if(count == 2) {
                    numeroDoisDigitos(resto);
                } else {
                    numeroUmDigito(resto);
                }
            }
        }
    }
}

int main() {
    preencheMapa();

    int n;
    while(scanf("%d", &n) != EOF) {
        numeroAteSeisDigitos(n);
        printf("\n");
    }

    return 0;
}
