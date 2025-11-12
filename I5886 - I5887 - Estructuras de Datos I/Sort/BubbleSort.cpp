#include <iostream>
using namespace std;

int main(void)
{
    int i, j, k, ctd, min, may;
    cout<<"ORDENAMIENTO BURBUJA"<<endl<<endl<<"Ingrese la cantidad de elementos del arreglo: ";
    cin>>ctd;
    int array[ctd];
    cout<<"Ingrese los elementos del arreglo:"<<endl;
    for(i=0;i<ctd;i++)
        cin>>array[i];
    for(i=0;i<ctd;i++)
        for(j=0;j<ctd-1;j++)
        {
            if(array[j]>array[j+1])
            {
                may=array[j];
                min=array[j+1];
                array[j]=min;
                array[j+1]=may;
            }
            for(k=0;k<ctd;k++)
                cout<<array[k]<<", ";
            cout<<endl;
        }
    cout<<endl<<endl;
    system("PAUSE");
    return 0;
}