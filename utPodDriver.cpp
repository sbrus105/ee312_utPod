/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.
You will want to do more complete testing.
*/

//Sam Brus and Collin Torok

#include <cstdlib>
#include <iostream>
#include "song.h"
#include "utPod.h"
#include "stack.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    
    t.showSongList();
          
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
       
    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
       
    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
  
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
}
//##########################################################################################################
//############################################END OF MAIN###################################################
//##########################################################################################################

//Default constructor
//set the memory size to MAX_MEMORY
UtPod::UtPod(){
    memSize = MAX_MEMORY;
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
}


/* FUNCTION - int addSong
 * attempts to add a new song to the UtPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song
 precondition: s is a valid Song
 input parms -
 output parms -
*/
int addSong(Song const &s){
   if ((int remain = getRemainingMemory) <= s.size) {
      return -1;
   }
   else {
      push (s);
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
int removeSong(Song const &s) {
    SongNode *temp = songs;
    while ((temp -> next) != NULL) {
       if ((temp -> s) == s) //TODO: a little confused on how this works
          pop (&temp);
       else
          temp = temp -> next;
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
void showSongList(SongNode *songs){
    while(songs->next != NULL){
        cout << "Title: " << (songs -> song.title) << "\n";
        cout << "Artist: " << (songs -> song.artist) << "\n";
        cout << "Size: " << (songs -> song.size) << "MB\n";
    }
}


/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
    o will do nothing if there are less than two songs in the current list
   input parms -
   output parms -
*/
void sortSongList(){
    bool notSorted = false;
    while(notSorted){
        //bubble sort
        //create two counters, compare one "largest" song with a second iterator. continue comparing
        //until all comprisons turn up true
    }
}


/* FUNCTION - void clearMemory
 * clears all the songs from memory
   input parms - Head pointer
   output parms -
*/
void clearMemory( SongNode &songs){ //TODO: change this?
    songs = NULL;
}


/* FUNCTION - int getTotalMemory
 *  returns the total amount of memory in the UtPod
    o will do nothing if there are less than two songs in the current list
   input parms -
   output parms -
*/
UtPod::getTotalMemory() {
    return memSize;
}



/* FUNCTION - int getRemainingMemory
   returns the amount of memory available for adding new songs
   input parms -
   output parms -
*/
int getRemainingMemory() {
   int remaining = 0;
   int total = getTotalMemory();
   SongNode *temp = songs;
   while ((temp -> next) != NULL) {
      remaining = remaining + (temp -> s).size
      temp = temp -> next;
   }
   return total - remaining;
}
