#include <iostream> //Collborated with Casey Le and help from outside resources
#include <iostream> 
#include <string>
#include "Node.h"
using namespace std;

Node::Node(string d) {
    data = d;
    count = 1;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}