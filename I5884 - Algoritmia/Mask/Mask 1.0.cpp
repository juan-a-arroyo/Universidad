#include <iostream>
using namespace std;

int main(void)
{
    int matrix[10][10]={
        {255,255,254,255,255,255,255,254,255,255},
        {255,244,254,255,255,255,255,254,244,255},
        {236,223,254,255,255,255,255,254,225,234},
        {184,200,232,247,252,252,247,233,202,182},
        {131,163,190,206,214,214,207,191,164,128},
        {103,116,142,157,165,165,158,143,117,99},
        {134,78,91,104,111,111,105,92,78,129},
        {214,76,75,75,76,76,75,75,76,210},
        {255,177,76,75,75,75,75,76,172,255},
        {255,255,214,133,95,95,132,211,255,255}
    };
    int matrix2[10][10]={};
    int mask[3][3]={
        {-1,0,1},
        {-1,1,1},
        {-1,0,1}
    };
    cout<<"MATRIZ"<<endl;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(matrix[i][j]<100)
                cout<<" ";
            cout<<matrix[i][j]<<",";
        }  
        cout<<endl;
    }
    cout<<endl<<endl<<"MASCARA"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout<<mask[i][j]<<",";
        cout<<endl;
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        { 
            if(i-1>=0&&j-1>=0)
            {
                matrix2[i][j]+=mask[0][0]*matrix[i-1][j-1];
            }
            if(i-1>=0)
            {
                matrix2[i][j]+=mask[0][1]*matrix[i-1][j];
            }
            if(i-1>=0&&j+1<10)
            {
                matrix2[i][j]+=mask[0][2]*matrix[i-1][j+1];
            }
            if(j-1>=0)
            {
                matrix2[i][j]+=mask[1][0]*matrix[i][j-1];
            }

            matrix2[i][j]+=mask[1][1]*matrix[i][j];

            if(j+1<10)
            {
                matrix2[i][j]+=mask[1][2]*matrix[i][j+1];
            }
            if(i+1<10&&j-1>=0)
            {
                matrix2[i][j]+=mask[2][0]*matrix[i+1][j-1];
            }
            if(i+1<=10)
            {
                matrix2[i][j]+=mask[2][1]*matrix[i+1][j];
            }
            if(i+1<10&&j+1<10) 
            {
                matrix2[i][j]+=mask[2][2]*matrix[i+1][j+1];
            }
        } 
    }
    cout<<endl<<endl<<"MATRIZ PROCESADA"<<endl;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            cout<<matrix2[i][j]<<",";
        cout<<endl;
    }
    system("PAUSE");
}