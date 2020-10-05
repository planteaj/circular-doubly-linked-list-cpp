#include "ItemType.h"

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
struct NodeType;

class CircularLinkedList
{
 public:
  CircularLinkedList();
  ~CircularLinkedList();

  void insertItem(ItemType &item);
  void deleteItem(ItemType &item);
  void findItem(ItemType &item, NodeType* &location, NodeType* &predloc, bool & found);
  int lengthIs() const;
  void print();

 private:
  int length;
  NodeType *head;
};

struct NodeType
{
  ItemType data;
  NodeType *next;
};
  
#endif
