#include <stdio.h>
#include <stdlib.h>
int main() {
    int f,i,a=9,b=1,c=0,x;
    for(f=1;f<=10;f++)
    {
        for(i=1;i<=a;i++)
        {
            printf(" ");
        }
        a--;
        x=f;
        for(i=1;i<=b;i++){
            if(x>9)
                x=0;
            printf("%d",x);
            x++;
        }
        b++;
        x--;
        for(i=1;i<=c;i++){
            x--;
            if(x<0)
                x=9;
            if(x>9)
                x=0;
            printf("%d",x);
        }
        c++;
        printf("\n");
    }
    system("PAUSE");
    return 0;
}
