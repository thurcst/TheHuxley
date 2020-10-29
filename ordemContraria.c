#include <stdio.h>

int main(){
    int numeros[10];
    int pares[10];
    int i;
    int j = 0;

    for(i = 0; i<10; i++){
        scanf("%d", &numeros[i]);
    }
    for(i = 0; i<10; i++){
        if(numeros[i]%2 == 0){
            pares[j] = numeros[i];
            printf("%d", pares[j]);
            j++;
        }
    }
    printf("\n");
    printf("%d", j);
    printf("\n");
    j = j -1;
    while (j>=0)
    {
        printf("%d", pares[j]);
        j--;
    }
    
    return 0;
}