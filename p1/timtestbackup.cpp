#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "CPUTimer.h"
#include "LinkedList.h"
#include "CursorList.h"
#include "StackAr.h"
#include "StackLi.h"
#include "QueueAr.h"
#include "SkipList.h"
#include "vector.h"
#include "dsexceptions.h"
#include "string.h"

vector<CursorNode <int> > cursorSpace(250000);
using namespace std;



  int getChoice()
  {
    int g;
    do
    {
    cout << "\tADT Menu \n 0. Quit \n 1. LinkedList \n 2. CursorList \n" 
         << " 3. StackAr \n 4. StackLi \n 5. QueueAr \n 6. SkipList \n" 
         << endl;
    cout << "Your Choice >> ";
    cin >> g;
    if (g > 6 || g < 0)
     {
      cout << "Your choice is not between 1 and 6. \nPlease try again. \n\n" ;
     }
    }while(g < 0 || g > 6);
    return g;
  }

void RunList(const char* filename) 
{
  List <int> List;
  ListItr <int> itr = List.zeroth();
  ifstream myfile;
  myfile.open(filename);
  char line1 [1000];
  char command;
  int value;
   
  myfile.getline(line1,1000);
   
  while(myfile >> command >> value)
  {
    //cout << command << value << endl;
    if (command == 'i')
    {
      List.insert(value,itr);
      //++itr;
    }
    else //command == 'd'
    {
      List.remove(value);
    }
  }


}

void RunCursorList(const char* filename) 
{
  CursorList <int> RunCursorList(cursorSpace);
  CursorListItr <int> itr = RunCursorList.zeroth();
  ifstream myfile;
  myfile.open(filename);
  char line1 [1000];
  char command;
  int value;
   
  myfile.getline(line1,1000);
   
  while(myfile >> command >> value)
  {
    //cout << command << value << endl;
    if (command == 'i')
    {
      RunCursorList.insert(value,itr);
      //itr = RunCursorList.first();
    }
    else //command == 'd'
    {
     RunCursorList.remove(value);
    }
  }


}

void RunStackAr(const char* filename)
{
  StackAr <int> RunStackAr(250000);
  ifstream myfile;
  myfile.open(filename);
  char line1 [1000];
  char command;
  int value;
   
  myfile.getline(line1,1000);
   
  while(myfile >> command >> value)
  {
    //cout << command << value << endl;
    if (command == 'i')
    {
      RunStackAr.push(value);
      //++itr;
    }
    else //command == 'd'
    {
     RunStackAr.pop();
    }
  }




}

void RunStackLi(const char* filename)
{
  StackLi <int> RunStackLi;
  ifstream myfile;
  myfile.open(filename);
  char line1 [1000];
  char command;
  int value;
   
  myfile.getline(line1,1000);
   
  while(myfile >> command >> value)
  {
    //cout << command << value << endl;
    if (command == 'i')
    {
      RunStackLi.push(value);
      //++itr;
    }
    else //command == 'd'
    {
     RunStackLi.pop();
    }
  }

}


void RunQueueAr(const char* filename)
{
  Queue <int> RunQueueAr(250000);
  ifstream myfile;
  myfile.open(filename);
  char line1 [1000];
  char command;
  int value;
   
  myfile.getline(line1,1000);
   
  while(myfile >> command >> value)
  {
    //cout << command << value << endl;
    if (command == 'i')
    {
      RunQueueAr.enqueue(value);
      //++itr;
    }
    else //command == 'd'
    {
     RunQueueAr.dequeue();
    }
  }

}


void RunSkipList(const char* filename)
{
  SkipList <int> RunSkipList(250000,250000);
  ifstream myfile;
  myfile.open(filename);
  char line1 [1000];
  char command;
  int value;
   
  myfile.getline(line1,1000);
   
  while(myfile >> command >> value)
  {
    //cout << command << value << endl;
    if (command == 'i')
    {
      RunSkipList.insert(value);
      //++itr;
    }
    else //command == 'd'
    {
     RunSkipList.deleteNode(value);
    }
  }

}

int main()
{
  int choice;
  char filename[100];
  
  int i = 0, k = 0, m = 0;
  
   cout << "Filename >> ";
  cin.getline(filename,100);


  
  CPUTimer ct; 
    
  do
  {
    choice = getChoice();
    ct.reset();
    
    switch(choice)
    {
      case 1: // RunList(filename);
      {
        RunList(filename);
        break;
      }       
      case 2: //RunCursorList(filename); 
      {
	    RunCursorList(filename);
        break;
      }
      case 3: //RunStackAr(filename); 
      { 
        
        RunStackAr(filename);
        
        break;
      }
      case 4: //RunStackLi(filename); 
      {
        RunStackLi(filename);
        break;
      }
      case 5: //RunQueueAr(filename); 
      {
        RunQueueAr(filename);
        break;
      }
      case 6: //RunSkipList(filename); 
      {
        
        RunSkipList(filename);
        
        break;
      }
    }

    cout << "CPU time: " << ct.cur_CPUTime() << endl;
  
  }while(choice > 0);
  
  return (0);
}
