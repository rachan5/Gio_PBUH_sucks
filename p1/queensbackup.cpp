#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
  stack <int* > possibilities;
  stack <int*> solutions;
  int* row;
  int* test;
  
  
  for(int i = 1; i <= 8; i++) // first 8 arrays of stack
    {
      row = new int[8]; 
      row[0] = i;
      for (int w = 1; w < 8; w++)
	    {
        row[w] = 0;
      }
      possibilities.push(row);
      cout << "The size of stack is " << possibilities.size() << endl;
    }

  // make copy of top array for examination
  // if there exists a zero (starting from left), fill it
  // Using Sean's hint, you can determine what could fill it
  // Push all those valid fillings to the stack
  // REPEAT.
  // If zero can't be filled, POP
  // If there are no zeros, PUSH to SOLUTIONS STACK
  
  int* temp; // = new int[8];
  //int *temp;
  //temp = possibilities.top(); //shallow or deep copy?
  int d;
  int cols[8];
  
  while(!possibilities.empty())
  {
    temp = possibilities.top();
    possibilities.pop();
    cout << "Top = " << temp[0] << temp[1] << temp[2] << temp[3] << temp[4] << temp[5] << temp[6] << temp[7] << " Popped " << endl;
    
    int j;

    for (j = 1; j < 8; j++) 
	  {
      if (temp[j] == 0) // need to fill row j 
	    {
        break;
      }
    }//j loop

    for (int t = 1; t <= 8; t++)
    {
      cols[t]= t;
    }
	      
        //FILL IT, PUSH ALL fillings to stack
	      // know i,j and P[i], need to solve FOR ALL P[j]
	      // each P[j] gets pushed to to staqck
	      //if it can't be filled, POP, j = j-1?
	      for (d = 1; d <= 8; d++) //cycle thru what column (1-8) row j should go
		    {
		      for (int i = 0; i <= j; i++) // begin feasibility test
		      {
		        int r = temp[i] - d; // P[i] - P[j]
		        //cout << r << " = " << temp[i] << " - " << d << endl;
		        if(r == i-j ||  r == j-i || r == 0)
			      {
			        for (int e = 1; e <= 8; e++)
			        {
			          if(cols[e] == d)
				        {
				          cols[e] = 0;
				        }
			        }
			      }
		      } // i loop
		    } //d loop

  cout << "This is possbilities:" << cols[1] << cols[2]<< cols[3] << cols[4] << cols[5] << cols[6] << cols[7] << cols[8] << endl;
	  
	  if(!(cols[1] == 0 && cols[2] == 0 && cols[3] == 0 && cols[4] ==0 && cols[5] == 0 && cols[6] == 0 && cols[7] == 0)) 
    { 
    int* thing;// = new int[8];
	  thing = temp;
	  for (int i = 1; i <=8; i++)
    {
      //for (int a = 1; a < 8; a++)
      //{
	      //cout << cols[a] << " ";
      //}
      if (cols[i] != 0)
		  {
		    thing[j] = cols[i];
        possibilities.push(thing);
		    cout << "Vector being pushed... " ;
		    cout << thing[0] << thing[1] << thing[2]<< thing[3] << thing[4] << thing[5] << thing[6] << thing[7] << endl;
        //temp = possibilities.top();
      }
    }
  }
    
	  if(cols[1] == 0 && cols[2] == 0 && cols[3] == 0 && cols[4] ==0 && cols[5] == 0 && cols[6] == 0 && cols[7] == 0)
	  {
      //cout << " its all zeros yo" ;
	    //j=j-1;
      possibilities.pop();
	    //temp = possibilities.top(); 
	  }

	  if (j == 8)
	  {
	    cout << "solution found" << endl;
	    solutions.push(temp);
	  }

	  //}// j loop
  }//while

  //int* answer = solutions.top();
  //cout << test[0] << test[1] << test[2]<< test[3] << test[4] << test[5] << test[6] << test[7] << endl;

  return 0;
}
