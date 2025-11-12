#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(void)
{
    ofstream file;
    char text[15];
    int nbytes;
    file.open("Xd.dat", ios::trunc | ios::binary);
    if(file.is_open())
    {
        file.write("Jeongyeon Yoo", nbytes=sizeof("Jeongyeon Yoo"));
        file.write("Jeongyeon Yoo", nbytes=sizeof("Jeongyeon Yoo"));
        cout<<"Written "<<nbytes<<" bytes"<<endl;
        file.close();
    }
    else
    {
        cout<<"An error ocurred while writing the file";
    }
    ifstream file2;
    file2.open("XD.dat", ios::binary);
    if(file2.is_open())
    {
        file2.read(text, sizeof(text));
        file2.close();
    }
    else
    {
        cout<<"An error ocurred while reading the file";
    }
    cout<<text;
    system("PAUSE");
}