//utPod.cpp
//Sam Brus and Collin Torok

#include <cstdlib>
#include <iostream>
#include "song.h"
#include "utPod.h"
#include <string>

using namespace std;

//Default constructor
//set the memory size to MAX_MEMORY
UtPod::UtPod(){
    unsigned int currentTime = (unsigned)time(0);
    memSize = MAX_MEMORY;
    songs = NULL;
}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size){
    if((size<=0)||(size>MAX_MEMORY)){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = size;
    }
    songs = NULL;
    unsigned int currentTime = (unsigned)time(0);
}


/* FUNCTION - int addSong
 * attempts to add a new song to the UtPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song
 precondition: s is a valid Song
 input parms -
 output parms -
*/
int UtPod::addSong(Song const &s){
   int remain = getRemainingMemory();
   if (remain <= s.getSize()) {
      return NO_MEMORY;
   }
   else {
      SongNode *temp = new SongNode;
      temp->s = s;
      temp->next = songs;
      songs = temp;
      return SUCCESS;
   }
}


/* FUNCTION - int removeSong
 * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
     o returns 0 if successful
     o returns -1 if nothing is removed
   input parms -
   output parms -
*/
int UtPod::removeSong(Song const &s) {
    SongNode *temp = songs;

    SongNode *prev = NULL;
    if (songs == NULL)
       return -1;
    else {
       while ((temp != NULL) && (temp -> s != s)) {
          prev = temp;
          temp = temp -> next;
       }
       if (prev == NULL) { //first element
          songs = temp -> next;
          delete temp;
          return 0;
       }
       else if (temp != NULL) {
          prev -> next = temp -> next;
          delete temp;
          return 0;
       }
       return -1;
    }
}


/* FUNCTION - void shuffle
 *  shuffles the songs into random order
    o will do nothing if there are less than two songs in the current list
   input parms -
   output parms -
*/
void UtPod::shuffle(){
   int numShuffle;
   int swap1;
   int swap2;
   srand(currentTime);
   numShuffle = 2 * numSongs();
   for (int i =0; i < numShuffle; i++) {
      swap1 = (rand() % numSongs());
      swap2 = (rand() % numSongs());
      SongNode *p1 = songs;
      SongNode *p2 = songs;
      for (int i = 0; i < swap1; i++)
         p1 = p1 -> next;
      for (int i = 0; i < swap2; i++)
         p2 = p2 -> next;
      swap (p1, p2);
   }
}

/* FUNCTION - void swap
   swaps the song contents of 2 inputs
   input params - pointer to song 1, pointer to song 2
   output params - 
*/

void UtPod::swap (SongNode *p1, SongNode *p2) {
   SongNode *temp = p2;
//   temp.s = p2 -> s;
   p2 -> s = p1 -> s;
   p1 -> s = temp -> s;
}
/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)
   input parms - head pointer
   output parms -
*/
void UtPod::showSongList() {

    SongNode *temp = songs;
    while (temp != NULL) {
        cout << "Title: " << temp->s.getTitle() << "\n";
        cout << "Artist: " << temp->s.getArtist() << "\n";
        cout << "Size: " << temp->s.getSize() << "MB\n";
        temp = temp->next;
/*
        while (songs->next != NULL) {
            cout << "Title: " << (songs->s.getTitle)() << "\n";
            cout << "Artist: " << (songs->s.getArtist()) << "\n";
            cout << "Size: " << (songs->s.getSize()) << "MB\n";

        }
*/
    }
}

/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
    o will do nothing if there are less than two songs in the current list
   input parms -
   output parms -
*/
    void UtPod::sortSongList() {
        bool notSorted = false;
        while (notSorted) {

            //bubble sort
            //create two counters, compare one "largest" song with a second iterator. continue comparing
            //until all comprisons turn up true

        }//end of while
    }//end of sortSongList


/* FUNCTION - void clearMemory
 * clears all the songs from memory
   input parms - Head pointer
   output parms -
*/

void UtPod::clearMemory(){ //TODO: change this? -- yes, delete songs from memory
        SongNode *temp = songs;
        while (temp != NULL) {
            delete temp;
            temp = temp->next;
        }
        songs = NULL;
}


/* FUNCTION - int getTotalMemory
 *  returns the total amount of memory in the UtPod
    o will do nothing if there are less than two songs in the current list
   input parms -
   output parms -
*/
int UtPod::getTotalMemory(){
    return memSize;
}

/* FUNCTION - int getRemainingMemory
   returns the amount of memory available for adding new songs
   input parms -
   output parms -
*/

int UtPod::getRemainingMemory() {
    int remaining = 0;
    int total = getTotalMemory();
    SongNode *temp = songs;
    while ((temp) != NULL) {
        remaining = remaining + (temp->s).getSize();
        temp = temp->next;
    }
    return total - remaining;
   return getTotalMemory();
}


/* FUNCTION - int countSongs
   returns the number of songs in the song list
   input params -
   output params - number of songs
*/
int UtPod::numSongs() {
    SongNode *temp = songs;
    int numSongs = 0;
    while (temp != NULL) {
        numSongs++;
        temp = temp->next;
    }
    return numSongs;
}

/* FUNCTION - destructor
   calls clear memory, destructs the UtPod
   input params -
   output params -
*/
UtPod::~UtPod() {
    clearMemory();
}
