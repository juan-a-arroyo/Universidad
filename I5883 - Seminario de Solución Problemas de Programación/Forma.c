#include <stdio.h>
#include <stdlib.h>
int main (){
    int c,i,j;
    for(c=1;c<=5;c++)
    {
        for(i=1;i<=c;i++)
            printf("*");
        for(j=1;j<=(5+5-c);j++)
            printf(" ");
        for(i=1;i<=(6-c);i++)
            printf("*");
        for(j=1;j<=15;j++)
            printf(" ");
        for(i=1;i<=c;i++)
            printf("*");
        for(j=1;j<=(4+c);j++)
            printf(" ");
        for(i=1;i<=(6-c);i++)
            printf("*");
        printf("\n");
    }
    return 0;
}
