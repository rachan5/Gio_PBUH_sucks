#include "CPUTimer.h"
#include <fstream>
#include "CursorList2.h"
#include "LinkedList.h"
#include "StackAr.h"
#include "StackLi.h"
#include "QueueAr.h"
#include "SkipList.h"


using namespace std;

const int MAX_SIZE = 250000;
vector<CursorNode<int> > cursorSpace;


int getChoice()
{
  int choice;
  do{
    cout << "\n      ADT Menu\n0. Quit\n1. LinkedList\n";
    cout << "2. CursorList\n3. StackAr\n";
    cout << "4. StackLi\n5. QueueAr\n6. SkipList\n";
    cout << "Your choice >> ";
    cin >> choice;
    if(choice < 0 || choice > 6)
      cout << "Your choice is not between 1 and 6.\nPlease try again.\n";
  } while (choice < 0 || choice > 6);
  return choice;
} // getChoice()


void RunList(char *filename)
{
  List <int> list;
  ListItr <int> listItr = list.zeroth();
  ifstream inf(filename);
  char command, s[512];
  int i;

  inf.getline(s,512);

  while(inf >> command)
  {
    inf >> i;
    if (command == 'i')
    	list.insert(i,listItr);
		else
			list.remove(i);
  } //while
} // RunList()


void RunCursorList(char *filename)
{
  CursorList <int> list(cursorSpace);
  CursorListItr <int> listItr = list.zeroth();
  ifstream inf(filename);
  char command, s[512];
  int i;

  inf.getline(s,512);

  while(inf >> command)
  {
    inf >> i;
    if (command == 'i')
    	list.insert(i,listItr);
		else
			list.remove(i);
  } //while

} // RunCursorList()



void RunStackAr(char *filename)
{
  StackAr <int> stack(MAX_SIZE);
  ifstream inf(filename);
  char command, s[512];
  int i;

  inf.getline(s,512);

  while(inf >> command)
  {
    inf >> i;
    if (command == 'i')
    	stack.push(i);
		else
			stack.pop();
  } //while

} // RunStackAr()



void RunStackLi(char *filename)
{
  StackLi <int> stack;
  ifstream inf(filename);
  char command, s[512];
  int i;

  inf.getline(s,512);

  while(inf >> command)
  {
    inf >> i;
    if (command == 'i')
    	stack.push(i);
		else
			stack.pop();
  } //while
}  // RunStackLi()


void RunQueueAr(char *filename)
{
  Queue <int> queue(MAX_SIZE);
  ifstream inf(filename);
  char command, s[512];
  int i;

  inf.getline(s,512);

 while(inf >> command)
  {
    inf >> i;
    if (command == 'i')
    	queue.enqueue(i);
		else
			queue.dequeue();
  } //while
} // RunQueueAr()

void RunSkipList(char *filename)
{
  SkipList <int> list(0, MAX_SIZE);
  ifstream inf(filename);
  char command, s[512];
  int i;

  inf.getline(s,512);

  while(inf >> command)
  {
    inf >> i;
    if (command == 'i')
        list.insert(i);
                else
                        list.deleteNode(i);
  } //while
} // RunList()

//template <class T> vector<CursorList<int>::CursorNode> CursorList<int>::cursorSpace;
//template <class T> 
//vector<CursorNode> CursorList<int>::cursorSpace;

int main(){
  char filename[80];
  int choice;
  CPUTimer ct;

  cout << "Filename >> ";
  cin >> filename;
  do
  {
    choice = getChoice();
    ct.reset();

    switch (choice)
    {
      case 1: RunList(filename); break;
      case 2: RunCursorList(filename); break;
      case 3: RunStackAr(filename); break;
      case 4: RunStackLi(filename); break;
      case 5: RunQueueAr(filename); break;
      case 6: RunSkipList(filename);break;
    }

    cout << "CPU time: " << ct.cur_CPUTime() << endl;
  } while(choice > 0);

  return 0;
}

