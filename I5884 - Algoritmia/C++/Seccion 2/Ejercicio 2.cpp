#include <iostream>
using namespace std;

int main (void){
    float a, b, c, d, resultado;
    cout<<"Ingrese el valor de a: "; cin>>a;
    cout<<"Ingrese el valor de b: "; cin>>b;
    cout<<"Ingrese el valor de c: "; cin>>c;
    cout<<"Ingrese el valor de d: "; cin>>d;
    resultado = (a + b) / (c + d);
    cout<<endl<<"El resultado es: "<<resultado<<endl;
    system("PAUSE");
}