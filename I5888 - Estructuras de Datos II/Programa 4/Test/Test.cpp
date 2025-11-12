#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
    string ptv;
    getline(cin, ptv);
    char ptvs[ptv.length()+1];
    strcat(strcpy(ptvs, ptv.c_str()),",");
    cout<<ptvs;
    system("PAUSE");
}