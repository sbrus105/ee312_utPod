//song.cpp
//Sam Brus and Collin Torok

#include <cstdlib>
#include <iostream>
#include "song.h"
#include <string>
using namespace std;

//**********************************
//Default Constructor
//**********************************

Song::Song(){ //confirmed don't need
    artist = "Sam Torok";
    title = "Horns";
    size = 42;
}


//**********************************
//Specialized Constructor
//**********************************
Song::Song(string specialArtist,string specialTitle,int specialSize){
    artist = specialArtist;
    title = specialTitle;
    size = specialSize;
}
//--------------------------------------------
//**********************************
//Set Song object's title
//**********************************
void Song::setTitle(string t){
    title = t;
}

//**********************************
//Set Song object's artist
//**********************************
void Song::setArtist(string a){
    artist = a;
}

//**********************************
//Set Song object's size
//**********************************
void Song::setSize(int s){
    size = s;
}
//--------------------------------------------
bool Song::operator >(Song const &rhs) {
    if (artist > rhs.artist)
        return true;
    else if (artist < rhs.artist)
        return false;
    else if (title > rhs.title)
        return true;
    else if (title < rhs.title)
        return false;
    else if (size > rhs.size)
        return true;
    else
        return false;
}


bool Song::operator ==(Song const &rhs) {
   return (artist == rhs.artist && title == rhs.title && size == rhs.size);
}

bool Song::operator !=(Song const &rhs) {
    return (artist != rhs.artist || title != rhs.title || size != rhs.size);
}

