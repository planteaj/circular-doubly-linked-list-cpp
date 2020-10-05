#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList()
{
  ItemType temp1, temp2;
  temp1.initialize(-1);
  temp2.initialize(1000000);

  NodeType *newNode1, *newNode2;
  newNode1 = new NodeType;
  newNode2 = new NodeType;
  newNode1->data = temp1;
  newNode2->data = temp2;
  
  head = newNode1;
  tail = newNode2;

  head->next = tail;
  tail->back = head;

  head ->back = NULL;
  tail->next = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
  NodeType *temp;
  while(head!=NULL)
    {
      temp = head;
      head = head->next;
      delete temp;
    }
}

int DoublyLinkedList::lengthIs() const
{
  NodeType *tmp;
  tmp = head;
  int i = 0;

  while(tmp!=NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return i-2;
}

void DoublyLinkedList::findItem(ItemType item, NodeType* &location, bool &found)
{
  bool search = true;
  location = head;

  while(search && !found)
    {
      if(item.compareTo(location->data) == LESS)
	search = false;
      else if(item.compareTo(location->data) == EQUAL)
	found = true;
      else
	{
	  location = location ->next;
	  search = (location != NULL);
	} //else
    } //while
} //findItem

void DoublyLinkedList::insertItem(ItemType &item)
{
  NodeType *location;
  bool found;
  NodeType* newNode;
  findItem(item, location, found);
  if(found)
    {
      std::cout <<"Item already exits" << std::endl;
      return;
    }
  else
    {
      newNode = new NodeType;
      newNode->data = item;

      newNode->back = location->back;
      newNode->next = location;
      location->back->next = newNode;
      location->back = newNode;
    }
}

void DoublyLinkedList::deleteItem(ItemType &item)
{
  NodeType *location;
  bool found;
  findItem(item, location, found);
  if(!found)
    {
      std::cout << "Item not in list!" << std::endl;
      return;
    }
  else
    {
      location->next->back = location->back;
      location->back->next = location->next;
      delete location;
    }
}

void DoublyLinkedList::print()
{
  NodeType* tmp;
  tmp = head->next;
  while(tmp!=tail)
    {
      std::cout <<tmp->data.getValue() << " ";
      tmp = tmp->next;
    }
  std::cout <<"\n";
}

void DoublyLinkedList::printReverse()
{
  NodeType* tmp;
  tmp = tail->back;
  while(tmp!=head)
    {
      std::cout <<tmp->data.getValue() << " ";
      tmp = tmp->back;
    }
  std::cout <<"\n";
}
