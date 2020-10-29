#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int q; // o numero que ele me da � igual a quantidade de linhas
    int p = 1; //quantidade numeros para ser printado, inicialmente 1
    scanf("%d", &q);
    int aux = 1; // auxiliar para saber se vou printar o espa�o
    for(int i = 0; i<q; i++){ //primeiro loop para percorrer todas as colunas
        for(int j = 1; j<=p; j++){ //for para printar a quantidade de numeros necessarios
            if(j == p){ // se o numero que for printar, � o ultimo da linha, nn prnto espa�o
            aux = 0;
            }
           printf("%d", j); //printo o valor
           if(aux == 1){ //se n�o for o ultimo elemento da linha que vou printar, printo espa�o
            printf(" ");
           }
        }
    if(p != q){ //se quantidade de linhas for diferente de colunas
        p++; // aumento o valor de numeros para printar da proxima vez
    }
    printf("\n");// pulo linha
    aux = 1; // garanto que na proxima intera��o, vou printar os espa�os
    }
	return 0;
}