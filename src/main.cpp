/**
*------------------------
* RIFEY PROJECTS
* STARTED ON 2024-01-17  18:59
* FINISHED ON 2024-01-18 06:52
*------------------------
**/

#include <iostream>
#include "linkedlist/linkedlist.h"

int main()
{
  LinkedList nodes(12);
  nodes.append(17);
  nodes.append(10);
  nodes.prepend(11);
  nodes.append(100);
  std::cout << "-----------------------------------\n";
  nodes.printList();
  std::cout << "-----------------------------------\n";
  nodes.deleteWithValue(12);
  nodes.printList();
  std::cout << "-----------------------------------\n";
  nodes.reverse();
  nodes.printList();

	return 0;
}
