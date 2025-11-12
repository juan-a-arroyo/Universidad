#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c, i, blank, other;
    int digit[10];
    blank=other=0;
    for(i=0;i<10;i++)
        digit[i]=0;
    printf("Entrada: ");
    while((c=getchar())!=EOF)
    {
        if(c>='0'&&c<='9')
            digit[c-'0']++;
        else if(c==' '||c=='\n'||c=='\t')
            blank++;
        else
            other++;
    }
    printf("\nOcurrencias por numero: \n");
    for(i=0;i<10;i++)
        printf("%d: %d \n",i, digit[i]);
    printf("Espacios blancos: %d \nOtros: %d\n",blank, other);
    system("PAUSE");
}