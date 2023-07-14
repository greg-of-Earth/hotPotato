#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <iostream>


using namespace std;

class LinkedList {
  public:
    LinkedList(int numNodes=0); // default constructor
    LinkedList(const LinkedList& copy); //copy constructor
    LinkedList& operator=(const LinkedList& copy); //copy assignment 
    ~LinkedList(); // destructor


    void AddNode(int data);
    void DeleteNode(int data);
    void MakeEmpty(); 
    void Print();
    int GetLength() const;
    int TraverseList(int);
    void ExceptionHandling(string);
  
  

  private:
    Node* head = nullptr; // track head of list
    Node* potato = nullptr; 
    int length = 0;
};

#endif