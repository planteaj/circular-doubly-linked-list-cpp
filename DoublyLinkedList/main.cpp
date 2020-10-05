#include <iostream>
#include "DoublyLinkedList.h"
#include "ItemType.h"

using namespace std;


int main(int argc, char ** argv) {
  if(argc != 2)
    {
      cout << "Wrong command-line input" << endl;
      return -1;
    }
  fstream fs;
  fs.open(argv[1]);
  DoublyLinkedList list;
  int streamInt;
  while(fs >> streamInt)
    {
      ItemType temp;
      temp.initialize(streamInt);
      list.insertItem(temp);
    }
  
  fs.close();

  cout << argv[0] << " " << argv[1] << " Commands:" << endl;
  cout << "insert (i), delete (d), length (l), print (p), printReverse (r), quit (q)" << endl;
 
  while(true) {
    cout << "Enter a command: ";
    char inp;
    cin >> inp;

    if(inp == 'i')
      {
	cout << "Number to insert: ";
	int itemp;
	cin >> itemp;
	ItemType temp;
	temp.initialize(itemp);
	list.insertItem(temp);
	list.print();
      }
    else if(inp == 'd')
      {
	cout << "Number to delete: ";
	int itemp;
	cin >> itemp;
	ItemType temp;
	temp.initialize(itemp);
	if(list.lengthIs() == 0)
	  cout <<"You cannot delete from an empty list." << endl;
	else
	  list.deleteItem(temp);
	list.print();
      }
    else if(inp == 'p')
      {
	list.print();
      }
    else if(inp == 'r')
      {
	list.printReverse();
      }
    else if(inp == 'l')
      {
	cout << "The length is: " <<  list.lengthIs() << endl;
      }
    else if(inp == 'q')
      {
	cout << "Quitting Program..." << endl;;
	return 0;
      }
    else
      cout << "Invalid command, try again!" << endl;
  }  
  return 0;
	  
}
