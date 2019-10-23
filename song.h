//song.h
//Sam Brus and Collin Torok

using namespace std;
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
        void setTitle(string);
        void setArtist(string);
        void setSize(int);

        string getTitle() const;
        string getArtist() const;
        int getSize() const;
};

