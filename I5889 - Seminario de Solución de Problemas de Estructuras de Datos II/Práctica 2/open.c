#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int File = open("Act2.txt",0_CREAT|0_WRONLY,0644);
if(File==-1)
{
    perror("Error al Abrir");
    exit(1);
}