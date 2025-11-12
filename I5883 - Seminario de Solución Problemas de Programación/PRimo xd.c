#include <stdio.h>
#include <stdlib.h>
int main(){
    int N,M,i=0,cout=0;
    printf("Ingrese un numero: ");
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        if((N%i)==0)
            cout++;
    }
    if(cout==2)
        printf("Es primo");
    else
        printf("No es primo");
    return 0;
}
