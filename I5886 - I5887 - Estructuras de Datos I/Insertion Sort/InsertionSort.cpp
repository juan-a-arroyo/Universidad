#include <iostream>
using namespace std;

int main(void)
{
    int i, j, k, ctd, num, act, ins;
    cout<<"ORDENAMIENTO POR INSERCION"<<endl<<endl<<"Ingrese la cantidad de elementos del arreglo: ";
    cin>>ctd;
    int array[ctd];
    cout<<"Ingrese los elementos del arreglo:"<<endl;
    for(i=0;i<ctd;i++)
        cin>>array[i];
    for(i=0;i<ctd;i++)
    {
        num=array[i];
        j=i-1;
        while(j>=0 && array[j]>num)
        {
            array[j+1]=array[j];
            j=j-1;
        }
        array[j+1]=num;
        for(k=0;k<ctd;k++)
            cout<<array[k]<<", ";
            cout<<endl;
    }
    cout<<endl<<endl;
    system("PAUSE");
    return 0;
}