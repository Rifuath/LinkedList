#include "linkedlist.h"


//constructor
LinkedList::LinkedList(int value)
{
  m_Node = new Node;

  m_Count = 1;
  m_Node->data = value;
  m_Node->next = NULL;
  lastAddress = m_Node;
}

//destructor
LinkedList::~LinkedList()
{
  Node *temp =  m_Node;


  while(m_Node != NULL)
  {
    temp = m_Node->next;

    delete m_Node;
    std::cout << "freeing the memory" << std::endl;

    m_Node = temp;
  }

}

//------------------Append Method
void LinkedList::append(int value)
{
  Node *node = new Node;

  node->data = value;
  node->next = NULL;
  lastAddress->next = node;
  lastAddress = node;

  m_Count++;
}

//------------------Prepend Method
void LinkedList::prepend(int value)
{
  Node *node = m_Node;
  m_Node = new Node;

  m_Node->data = value;
  m_Node->next = node;

  m_Count++;
}

//------------------Print Method
void LinkedList::printList() const
{
  Node *temp = m_Node;

  while(temp != NULL)
  {
    std::cout << "[ Address = " << temp << " value = " << temp->data << " next = " << temp->next << " ]\n";
    temp = temp->next;
  }

}

//------------------deleteWithValue Method
void LinkedList::deleteWithValue(int value)
{
  if (m_Node == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node *temp = m_Node;
    Node *prev = nullptr;

    // Deleting the head node
    if (temp != nullptr && temp->data == value) {
        m_Node = temp->next; // Changed head
        delete temp;         // Free old head
        m_Count--;
        return;
    }

    // Search for the value to be deleted
    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not present in the list
    if (temp == nullptr) {
        std::cout << "Value provided not found in the list." << std::endl;
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    delete temp;
    m_Count--;

}

//-------------Find Method
Node* LinkedList::find(int value) const
{
  Node *temp = m_Node;

  while(temp != NULL)
  {
    if(temp->data == value) {
      return temp;
    }
    temp = temp->next;
  }

  return nullptr;

}

//-----------------Reverse Method 
void LinkedList::reverse()
{
  //edge case if the list is empty
  if(m_Node == NULL) {
    std::cout << "Empty list" << std::endl;
    return;
  }

  Node *current = m_Node;
  Node *next = nullptr, *prev = nullptr;
  lastAddress = m_Node;

  while(current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  m_Node = prev;
}

//-----------------getSize Method

int LinkedList::getSize() const 
{
  return m_Count;
}

