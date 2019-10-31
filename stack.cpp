#include <cstdlib>
#include <iostream>
#include "song.h"
#include "utPod.h"
#include "stack.h"
//stack_ll.c file, holds functions for the floodfill program


//inputs a pointer to the stack called s
//outputs: none
//starts the stack by placing a NULL at the head
void makeStack (SongNode *s) {
   s -> next = NULL;
}

//inputs: the stack called s
//ouputs: true or false
//checks to see if the stack is full, stack is never full in this case
bool isFull (SongNode s) {
   return false;   //stack will never be full in this implementation
}

//inputs: the stack called s
//outputs: true or false
//checks if the stack is empty when trying to pop a stack value
bool isEmpty (SongNode s) {
   return (s.next == NULL);   //return true if stack is empty
}

//inputs: a pointer to the stack called s, an entry to push onto the stack called p
//ouputs: none
//pushes e onto the stack
void push (song e, SongNode *s) {
   SongNode *p = new SongNode;
//   (*p).next = s -> top;
   (*p).song = e;
   p -> next = s;
   s -> next = p;
   
}

//inputs: pointer to the stack called s
//otputs: the top entry of the stack
//pops the top element of the stack and returns it
StackEntry pop (SongNode *s) {
   SongNode *temp = s;
   SongEntry topElement = (*temp).Song; 
//   free(s -> top);
//   free((*temp).pixel);
//   free((*temp).next);
   s = temp -> next;
   delete(temp);
   return topElement;
}
