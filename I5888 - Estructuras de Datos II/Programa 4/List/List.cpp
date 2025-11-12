#include <iostream>
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
        void insertHead(string, string, string, int);
        void insertTail(string, string, string, int);
        friend ostream& operator <<(ostream &out, const List & list)
        {
            int track=1;
            if(list.head==nullptr)
                out<<"[Lista Vacía]"<<endl;
            Song *song;
            song=list.head;
            while(song!=nullptr)
            {
                out<<track<<". "<<endl<<
                "Título: "<<song->getTitle()<<endl<<
                "Artista: "<<song->getArtist()<<endl<<
                "Álbum: "<<song->getAlbum()<<endl<<
                "Año: "<<song->getYear()<<endl<<endl;
                song=song->next;
                track++;
            }
            return out;
        }
};

int main(void)
{
    List list;
    cout<<list<<endl;
    list.insertTail("Timeless", "Taeyeon", "INVU", 2022);
    cout<<list<<endl;
    list.insertTail("Be as ONE", "TWICE", "BDZ", 2018);
    cout<<list<<endl;
    system("PAUSE");
}

void List::insertHead(string title_, string artist_, string album_, int year_)
{
    Song *song = new Song(title_, artist_, album_, year_);
    song->next=head;
    head=song;
    if(tail==nullptr)
        tail=head;
}

void List::insertTail(string title_, string artist_, string album_, int year_)
{
    if(tail==nullptr)
    {
        insertHead(title_, artist_, album_, year_);
        return;
    }
    Song *song = new Song(title_, artist_, album_, year_);
    tail->next=song; 
    tail=song;
}