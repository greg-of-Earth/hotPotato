#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

//class LinkedList; 

class Node {
  public:
    Node(int data=0, Node* n_next=nullptr);

    int GetData() const;
    void SetData(int);
    Node* GetNext() const;
    void SetNext(Node*);
  
    friend class LinkedList;
    
  private:
    int data;
    Node* next; 
};

#endif