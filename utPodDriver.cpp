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
#include "Song.h"
#include "UtPod.h"
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    cout << "Shuffling one song: "<< endl;
    t.shuffle();
    t.showSongList();

    cout << "Sort one song: "<< endl;
    t.sortSongList();

    cout << "Song List: "<< endl;
    t.showSongList();
          
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    cout << "Shuffle two songs: " << endl;
    t.shuffle();
    cout << "Song List: "<< endl;
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

    cout << "Song List: "<< endl;
    t.showSongList();

    cout << "Adding multiple of same song: "<< endl;
    Song s6("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
    Song s7("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
    t.showSongList();


    cout << "Shuffling...\n" << endl;
    t.shuffle();
    t.showSongList();

    cout << "Shuffling again ...\n" << endl;
    t.shuffle();
    t.showSongList();

    cout << "Sorting...\n" << endl;
    t.sortSongList();
    t.showSongList();

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
    cout << "Delete again: "<< endl;
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    cout << "Deleting song with multiple instances: " << endl;
    t.removeSong(s6);

    cout << "new song list: " << endl;
    t.showSongList();
  
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    cout << "Song List: "<< endl;
    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    cout << "Song List: "<< endl;
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    t.sortSongList();

    cout << "Song List: "<< endl;
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
}
