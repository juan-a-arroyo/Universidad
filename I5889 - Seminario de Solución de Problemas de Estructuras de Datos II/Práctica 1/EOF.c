#include <stdio.h>

int main(void)
{
  int nc = 0; // Para enteros mejor int
  while( getchar() != EOF )
    nc++;

  printf("%d\n", nc);
  system("PAUSE");
}