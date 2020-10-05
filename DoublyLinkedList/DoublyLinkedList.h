#include "ItemType.h"

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

struct NodeType;

class DoublyLinkedList
{
 public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  int lengthIs() const;
  void findItem(ItemType item, NodeType* &location, bool &found);
  void insertItem(ItemType &item);
  void deleteItem(ItemType &item);
  void print();
  void printReverse();
 private:
  NodeType* head;
  NodeType* tail;

};

struct NodeType
{
  ItemType data;
  NodeType *next;
  NodeType *back;
};

#endif
