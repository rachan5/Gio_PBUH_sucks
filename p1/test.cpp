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



using namespace std;

int main()
{
  int choice;
  char filename[100];
  char* ptr;
  char line1 [1000];
  char line2 [1000000];
  char num[20];
  int i = 0, k = 0, m = 0;
  int insertarray[250000];
  int deletearray[250000];
  char command;
  int value;

  cout << "Filename >> ";
  cin.getline(filename,100);
  ifstream myfile (filename);
 
  myfile.getline(line1,1000);
   
  while(myfile >> command >> value)
  {
    cout << command << value << endl;
  }
  
  /*
  myfile.getline(line1,1000);
  while(myfile.good())
  {
    char c= myfile.get();
	  if(c!=' ') //the char is an i,d or number
	  {
	    num[i]=c;
	    i++;
	  }
	  else
	  {
	    if(num[0]=='i')
	    {
	      insertarray[k]=atoi(num+1);
	      cout << "This is to be added: " << insertarray[k] << endl;
	      k++;
	      i = 0;
	    }
	    else
	    {
	      deletearray[m]=atoi(num+1);
		    cout << "This is to be deleted: " << deletearray[m] << endl;;
	      m++;
		    i = 0;
	    }
	  }  
  }	  
  */
}
