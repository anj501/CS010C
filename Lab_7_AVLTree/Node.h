#include <iostream> //Collborated with Casey Le and help from outside resources
#include <iostream> 
#include <string>
using namespace std;

#ifndef NODE_H
#define NODE_H

class Node {
    public:
        string data;
        int count;
        Node* left;
        Node* right;
        Node* parent;
        Node(string d);
};

#endif