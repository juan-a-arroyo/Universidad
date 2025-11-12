#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(void)
{
    string line;
    ifstream file;
    file.open("file01.txt",ios::in);
    if(file.fail())
    {
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    while(getline(file,line))
    {
        stringstream stream(line);
        string val;
        while(getline(stream, val, '|'))
        {
            cout<<val<<endl;
        }
    }
    file.close();
    system("PAUSE");
}