#include "node.h"

Node::Node(int n_data, Node* n_next) {
  this->data = n_data;
  this->next = n_next;
}

void Node::SetData(int n_data) {
  data = n_data;
}

void Node::SetNext(Node* n_next) {
  next = n_next;
}

int Node::GetData() const {
  return data;
}

Node* Node::GetNext() const {
  return next;
}
