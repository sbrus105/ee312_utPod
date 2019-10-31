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
       while ((temp -> next != NULL) && (temp -> s != s)) {
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
void shuffle(){
    //praise RNG gods
}


/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)
   input parms - head pointer
   output parms -
*/
void UtPod::showSongList() {

    SongNode *temp = songs;
    while (temp->next != NULL) {
        cout << "Title: " << temp->s.getTitle() << "\n";
        cout << "Artist: " << temp->s.getArtist() << "\n";
        cout << "Size: " << temp->s.getSize() << "MB\n";
        temp = temp->next;

        while (songs->next != NULL) {
            cout << "Title: " << (songs->s.getTitle)() << "\n";
            cout << "Artist: " << (songs->s.getArtist()) << "\n";
            cout << "Size: " << (songs->s.getSize()) << "MB\n";

        }
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
        while (temp->next != NULL) {
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
    while ((temp->next) != NULL) {
        remaining = remaining + (temp->s).getSize();
        temp = temp->next;
    }
    return total - remaining;
}


/* FUNCTION - int countSongs
   returns the number of songs in the song list
   input params -
   output params - number of songs
*/
int UtPod::numSongs() {
    SongNode *temp = songs;
    int numSongs = 0;
    while (temp->next != NULL) {
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
