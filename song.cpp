//song.cpp
//Sam Brus and Collin Torok

#include <cstdlib>
#include <iostream>
#include "song.h"


//**********************************
//Set Song object's title
//**********************************
void Song::setTitle(std::string s){
    title = s;
}

//**********************************
//Set Song object's artist
//**********************************
void Song::setArtist(std::string s){
    artist = s;
}

//**********************************
//Set Song object's size
//**********************************
void Song::setSize(int i){
    size = i;
}