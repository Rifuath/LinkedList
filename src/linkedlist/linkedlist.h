#pragma once
#include <iostream>

struct Node 
{
  int data;
  Node *next;
};

class LinkedList {
private:
  int m_Count;
  Node *m_Node;
  Node *lastAddress;

public:
  LinkedList(int value);
  ~LinkedList();

  void append(int value);
  void prepend(int value);
  void deleteWithValue(int value);
  void printList() const;
  Node* find(int value) const;
  void reverse();
  int getSize() const;

};


