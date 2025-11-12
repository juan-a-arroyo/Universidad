#include <iostream>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <sstream>
#define INT 32767
using namespace std;

class Song
{
    private:
        string title;
        string artist;
        string album;
        int year;
    public:
        Song *next;
        Song()
        {
            title="";
            artist="";
            album="";
            year=0;
            next=nullptr;
        }
        Song(string title_, string artist_, string album_, int year_)
        {
            title=title_;
            artist=artist_;
            album=album_;
            year=year_;
            next=nullptr;
        }
        string getTitle(){return title;}
        void setTitle(string title_){title=title_;}
        string getArtist(){return artist;}
        void setArtist(string artist_){artist=artist_;}
        string getAlbum(){return album;}
        void setAlbum(string album_){album=album_;}
        int getYear(){return year;}
        void setYear(int year_){year=year_;}
};

class List
{
    private:
        Song *head, *tail;
    public:
        List(){head=tail=nullptr;}
        Song *insertFirst(string, string, string, int);
        Song *insert(string, string, string, int);
        int search(bool, string, int);
        void deleteSong(int, string);
        friend ostream& operator <<(ostream &out, const List &list)
        {
            if(list.head==nullptr)
                out<<"[Lista Vacía]"<<endl;
            Song *song;
            song=list.head;
            while(song!=nullptr)
            {
                out<<"Título: "<<song->getTitle()<<endl<<
                "Artista: "<<song->getArtist()<<endl<<
                "Álbum: "<<song->getAlbum()<<endl<<
                "Año: "<<song->getYear()<<endl<<endl;
                song=song->next;
            }
            return out;
        }
};

int hashing(string, int);
bool write(bool, string, Song &);
void read(string, int, List []);

int main(void)
{
    int option, year, tableSize, key;
    string title, artist, album, filename;
    bool newFile;
    cout<<"Ingrese el nombre del archivo: ";
    fflush(stdin);
    getline(cin, filename);
    filename+=".dat";
    ifstream file(filename, ios::binary);
    if(file.fail())
    {
        cout<<"El archivo "<<filename<<" no existe, se creará al momento de escribir en él"<<endl<<endl;
        system("PAUSE");
        newFile==true;
    }
    else
    {
        cout<<"El archivo "<<filename<<" ya existe"<<endl
        <<"1. Borrar datos del archivo"<<endl
        <<"2. Cargar datos del archivo"<<endl<<endl<<"Seleccion: ";
        cin>>option;
        switch(option)
        {
            case 1:
                newFile=true;
            break;
            case 2:
                newFile=false;
            break;
        }
        file.close();
    }
    system("CLS");
    cout<<"Ingrese el tamaño de la tabla hash: ";
    cin>>tableSize;
    List Songs[tableSize];
    if(newFile==false)
        read(filename, tableSize, Songs);
    system("CLS");
    do{
        cout<<"MENU"<<endl<<endl
        <<"1. Agregar Canción"<<endl
        <<"2. Buscar Canción"<<endl
        <<"3. Borrar Canción"<<endl
        <<"4. Salir"<<endl<<endl
        <<"Selección: ";
        cin>>option;
        switch (option)
        {
            case 1:
                system("CLS");
                cout<<"AGREGAR CANCIÓN"<<endl<<endl<<"Título: ";
                fflush(stdin);
                getline(cin, title);
                cout<<"Artista: ";
                fflush(stdin);
                getline(cin, artist);
                cout<<"Álbum: ";
                fflush(stdin);
                getline(cin, album);
                cout<<"Año: ";
                cin>>year;
                key=hashing(title, tableSize);
                newFile=write(newFile, filename, *Songs[key].insert(title, artist, album, year));
                system("PAUSE");
                system("CLS");
            break;
            case 2:
                system("CLS");
                cout<<"BUSCAR CANCION"<<endl<<endl<<"Título: ";
                fflush(stdin);
                getline(cin, title);
                key=hashing(title, tableSize);
                Songs[key].search(true, title, key);
                system("PAUSE");
                system("CLS");
            break;
            case 3:
                system("CLS");
                cout<<"BORRAR CANCION"<<endl<<endl<<"Título: ";
                fflush(stdin);
                getline(cin, title);
                key=hashing(title, tableSize);
                Songs[key].deleteSong(Songs[key].search(false, title, key), filename);
                system("PAUSE");
                system("CLS");
            break;
        }
    }while(option!=4);
    system("PAUSE");
}

Song *List::insertFirst(string title_, string artist_, string album_, int year_)
{
    Song *song = new Song(title_, artist_, album_, year_);
    song->next=head;
    head=song;
    if(tail==nullptr)
        tail=head;
    return song;
}

Song *List::insert(string title_, string artist_, string album_, int year_)
{
    if(tail==nullptr)
    {
        return insertFirst(title_, artist_, album_, year_);
    }
    Song *song = new Song(title_, artist_, album_, year_);
    tail->next=song; 
    tail=song;
    return song;
}

int List::search(bool showSong, string title_, int key)
{
    if(head==nullptr)
        cout<<endl<<endl<<"No encontrado"<<endl;
    else
    {
        int index=0;
        Song *song = head;
        while((song!=nullptr)&&(song->getTitle()!=title_))
        {
            index++;
            song=song->next;
        }
        if(song==nullptr)
            cout<<endl<<endl<<"No encontrado"<<endl;
        else
        {
            if(showSong==true)
            {
                cout<<endl<<"Encontrado!"<<endl
                <<"Llave hash "<<key<<" en la posición "<<index<<endl
                <<"Título: "<<song->getTitle()<<endl
                <<"Artista: "<<song->getArtist()<<endl
                <<"Álbum: "<<song->getAlbum()<<endl
                <<"Año: "<<song->getYear()<<endl<<endl;
            }
            return index;
        }
    }
}

void List::deleteSong(int index, string filename)
{
    int i;
    string title;
    bool del = false;
    if(head==nullptr)
    {
        cout<<endl<<"Nada que borrar"<<endl;
        return;
    }
    if(index==0)
    {
        Song *song = head;
        head = head->next;
        title = song->getTitle();
        delete song;
        del = true;
        cout<<endl<<"Elemento Borrado"<<endl;
    }
    else
    {
        Song *song = head;
        for(i=0; i<index-1; i++)
            if(song!=nullptr)
                song=song->next;
        if(song!=nullptr)
        {
            Song *delete_ = song->next, *after = delete_->next;
            song->next = after;
            title = delete_->getTitle();
            delete delete_;
            del = true;
            cout<<endl<<"Elemento Borrado"<<endl;
        }
        else
            cout<<endl<<"El elemento a borrar no existe"<<endl;
    }
    if(del == true)
    {
        string fullFile;
        ifstream in;
        in.open(filename, ios::in | ios::binary);
        ofstream out;
        out.open("temp.dat", ios::out | ios::binary);
        if(out.is_open()&&in.is_open())
        {
            while(getline(in, fullFile))
            {
                stringstream stream(fullFile);
                string register_;
                index = 0;
                while(getline(stream, register_, '\0'))
                {
                    stringstream stream(register_);
                    string songData;
                    index=0;
                    while((getline(stream, songData, '|'))&&songData!=title)
                    {
                        if(index==3)
                        {
                            char data[(songData.length())+1];
                            strcpy(data, songData.c_str());
                            out.write(data, sizeof(data));
                        }
                        else
                        {
                            char data[(songData.length())+2];
                            strcat(strcpy(data, songData.c_str()), "|");
                            out.write(data, sizeof(data)-1);
                        }
                        index++;
                    }
                }
            }
        }
        in.close();
        out.close();
        remove(filename.c_str());
        rename("temp.dat", filename.c_str());
    }
}

int hashing (string title, int tableSize)
{
    int key=0, i;
    for(i=0; i<title.length(); i++)
        key=(key+title[i]*tableSize)%INT;
    key%=tableSize;
    return key;
}

bool write (bool newFile, string filename, Song &song)
{
    ofstream file;
    int i;
    char title[(song.getTitle().length())+2],
    artist[(song.getArtist().length())+2],
    album[(song.getAlbum().length())+2],
    year[(to_string(song.getYear()).length()+1)];
    strcat(strcpy(title, song.getTitle().c_str()),"|");
    strcat(strcpy(artist, song.getArtist().c_str()),"|");
    strcat(strcpy(album, song.getAlbum().c_str()),"|");
    strcpy(year, (to_string(song.getYear())).c_str());
    if(newFile == true)
        file.open(filename, ios::out | ios::binary);
    else
        file.open(filename, ios::app | ios::binary);
    if(file.is_open())
    {
        file.write(title, sizeof(title)-1);
        file.write(artist, sizeof(artist)-1);
        file.write(album, sizeof(album)-1);
        file.write(year, sizeof(year));
        file.close();
        return false;
    }
    else
        cout<<endl<<"No se ha podido crear el archivo"<<endl<<endl;
}

void read (string filename, int tableSize, List songs[])
{
    ifstream file;
    string fullFile;
    string title, album, artist;
    int year, index, key;
    file.open(filename, ios::in | ios::binary);
    if(file.is_open())
    {
        while(getline(file, fullFile))
        {
            stringstream stream(fullFile);
            string register_;
            index = 0;
            while(getline(stream, register_, '\0'))
            {
                stringstream stream(register_);
                string songData;
                index=0;
                while(getline(stream, songData, '|'))
                {
                    switch (index)
                    {
                        case 0:
                            title = songData;
                        break;
                        case 1:
                            artist = songData;
                        break;
                        case 2:
                            album = songData;
                        break;
                        case 3:
                            year = stoi(songData, nullptr, 10);
                        break;
                    }
                    index++;
                }
                key=hashing(title, tableSize);
                songs[key].insert(title, artist, album, year);
            }
        }
        file.close();
        cout<<endl<<"Archivo leído correctamente"<<endl;
        system("PAUSE");
    }
}