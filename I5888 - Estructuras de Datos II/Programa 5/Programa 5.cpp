#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#define BLOCK 16
using namespace std;

void encrypt();
void XOR(string &, string &, string &);
void split(string &, int, string &, bool (&)[BLOCK][8]);
void binary(string &, bool (&)[BLOCK][8]);
void write(string &, string &, bool &);
string read(string &);

int main (void)
{
    string text, key, encryptedText, filename = "INVU.dat";
    bool newFile = true;
    cout<<"Introduce un texto: ";
    fflush(stdin);
    getline(cin, text);
    cout<<"Introduce la clave de cifrado: ";
    fflush(stdin);
    getline(cin, key);
    XOR(text, key, encryptedText);
    write(filename, encryptedText, newFile);
    cout<<endl<<read(filename)<<endl;
    system("PAUSE");
}

void XOR(string &text, string &key, string &encryptedText)
{
    bool binaryText [BLOCK][8], binaryKey[BLOCK][8], binaryXOR[BLOCK][8];
    int position, textSize, keySize, asciiValue;
    textSize = ((text.length() - text.length()%BLOCK) + BLOCK) / BLOCK;
    keySize = ((key.length() - key.length()%BLOCK) + BLOCK) / BLOCK;
    string buffer;
    cout<<endl<<"Text: "<<textSize<<" bytes"<<endl<<"Key: "<<keySize<<" bytes"<<endl;
    for(int i=0; i<textSize; i++)
    {
        for(int j=0; j<keySize; j++)
        {
            split(buffer, i, text, binaryText);
            split(buffer, j, key, binaryKey);
            for(int k=0; k<BLOCK; k++)
                for(int l=0; l<8; l++)
                {
                    if(binaryText[k][l] != binaryKey[k][l])
                        binaryXOR[k][l] = 1;
                    else
                        binaryXOR[k][l] = 0;
                }
        }
        cout<<endl;
        for(int k=0; k<BLOCK; k++)
        {
            asciiValue=0;
            position = 7;
            for(int l=0; l<8; l++)
            {
                asciiValue += binaryXOR[k][position] * pow (2, l);
                position --;
            }
            while(asciiValue <= 32|| asciiValue >= 127)
            {
                asciiValue += 64 + pow(k, 2);
                asciiValue %= 127;
            }
            encryptedText += char(asciiValue);
        }
    }
}

void split(string &buffer, int start, string &text_key, bool (&binaryText_key)[16][8])
{
    start *= BLOCK;
    int end = start + BLOCK;
    if(end > text_key.length())
        end = text_key.length();
    for(int i=start+1; i<end+1; i++)
    {
        buffer += text_key[i-1];
        if(i%16 == 0 || i == text_key.length())
        {
            binary(buffer, binaryText_key);
            cout<<endl<<"------------------------------------------------------------------"<<endl;
            buffer = "";
        } 
    }
}

void binary(string &buffer, bool (&binaryText_key)[16][8])
{
    bool bit;
    int asciiValue;
    char text_key[17];
    for(int i=0; i<16; i++)
        text_key[i] = '\0';
    for(int i=0; i<buffer.length(); i++)
    {
        asciiValue = int(buffer[i]);
        text_key[i] = buffer[i];
        for(int j=7; j>=0; j--)
        {
            bit=(asciiValue)%2;
            binaryText_key[i][j] = bit;
            asciiValue = (asciiValue - int(bit))/2;
        }
    }
    for(int i=buffer.length(); i<16; i++)
        for(int j=0; j<8; j++)
            binaryText_key[i][j] = i%2;
    for(int i=0; i<16; i++)
    {
        if(text_key[i] != '\0')
            cout<<endl<<text_key[i]<<endl;
        else
            cout<<endl<<"[NULL]"<<endl;
        for(int j=0; j<8; j++)
        {
            cout<<binaryText_key[i][j];
        }
    }
}

void write(string &filename, string &encryptedText, bool &newFile)
{
    ofstream file;
    char block[encryptedText.length()+2];
    strcpy(block, encryptedText.c_str());
    if(newFile)
        file.open(filename, ios::out | ios::binary);
    else
        file.open(filename, ios::app | ios::binary);
    if(file.is_open())
    {
        file.write(block, sizeof(block)-2);
        newFile = false;
        file.close();
    }
    else
    {
        cout<<endl<<"Error al crear el archivo"<<endl;
    }
}

string read(string &filename)
{
    ifstream file;
    string text;
    file.open(filename, ios::in | ios::binary);
    if(file.is_open())
    {
        while(!file.eof())
            getline(file, text);
        return text;
    }
}