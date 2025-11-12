#include <iostream>
using namespace std;

int main(void)
{
    int i, j, k, ctd, min, act;
    cout<<"ORDENAMIENTO POR SELECCION"<<endl<<endl<<"Ingrese la cantidad de elementos del arreglo: ";
    cin>>ctd;
    int array[ctd];
    cout<<"Ingrese los elementos del arreglo:"<<endl;
    for(i=0;i<ctd;i++)
        cin>>array[i];
    for(k=0;k<ctd;k++)
        cout<<array[k]<<", ";
    cout<<endl;
    for(i=0;i<ctd;i++)
    {
        min=2147483647;
        for(j=i;j<ctd;j++)
        {
            if(array[j]<min)
            {
                min=array[j];
                act=j;
            }
        }
        array[act]=array[i];
        array[i]=min;
        for(k=0;k<ctd;k++)
            cout<<array[k]<<", ";
        cout<<endl;
    }
    cout<<endl<<endl;
    system("PAUSE");
    return 0;
}