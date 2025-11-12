#include <iostream>
using namespace std;

int main (void)
{
    float precio;
    cout<<"Escribe el precio del artículo: "; cin>>precio;
    cout<<"El precio con IVA es de $"<<precio*1.16<<endl;
    system("PAUSE");
}