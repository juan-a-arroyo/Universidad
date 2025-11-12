#include <iostream>
using namespace std;
int main ()
{
    string nombre;
    int edad;
    cout<<"Cual es tu nombre?: ";
    getline(cin, nombre);
    fflush(stdin);
    cout<<"Cual es tu edad?: ";
    cin>>edad;
    cout<<"Hola soy "<<nombre<<" y tengo "<<edad<<" A"<<char(164)<<"os"<<endl;
    system("PAUSE");
    return 0;
}