//song.h
//Sam Brus and Collin Torok

using namespace std;
#ifndef SONG_H
#define SONG_H
#include <cstdlib>
#include <iostream>

class Song
{
    private:
        string title;
        string artist;
        int size;
    public:
        Song();
        Song(string title, string artist, int size);
        string getTitle() const
            {return title;}
        string getArtist() const
            {return artist;}
        int getSize() const
            {return size;}
        void setTitle(string t);
        void setArtist(string a);
        void setSize(int s);
        bool operator >(Song const &rhs);
        bool operator ==(Song const &rhs);
        bool operator !=(Song const &rhs);

//        string getTitle() const; ----Duplicate functions removed
//        string getArtist() const;
//        int getSize() const;
};

#endif
