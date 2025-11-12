#include <iostream>
using namespace std;

int main(void)
{
    int i;
    int array[5] = {1,2,3,4,5};
    for(i=5;i>0;i--)
    {
        array[i]=array[i-1];
    }
    for(i=0;i<5;i++)
        cout<<array[i];
    system("PAUSE");
}