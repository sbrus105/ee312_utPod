//song.cpp
//Sam Brus and Collin Torok

#include <cstdlib>
#include <iostream>
#include "song.h"

using namespace std;

//**********************************
//Default Constructor
//**********************************
Song::Song(){
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
    if(specialSize<=0){
        size = 42; //TODO: Is this the correct way to approach this  user  error?
    }
    else{
        size = specialSize;
    }
}
//--------------------------------------------
//**********************************
//Set Song object's title
//**********************************
void Song::setTitle(string t){  //TODO: Wtf
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
string Song::getArtist() const{
    return artist;
}

string Song::getTitle() const{
    return title;
}

int Song::getSize() const{
    return size;
}