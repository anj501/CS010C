#include <iostream> //Collborated with Casey Le and help from outside resources
#include <iostream> 
#include <string>
#include "Node.h"
using namespace std;

class AVLTree {
    public:
        void insert(const string &); //Insert an item to the binary search tree and perform rotation if necessary.
        int balanceFactor(Node*); //Return the balance factor of a given node.
        void printBalanceFactors(); //Traverse and print the tree in inorder notation. Print the string followed 
                                    //by its balance factor in parentheses followed by a , and one space.
        void visualizeTree(const string &); //Generate dotty file and visualize the tree using dotty program. Call 
                                            //this function before and after rotation.
        Node* root = nullptr;
    private:
        Node* findUnbalancedNode(); //Find and return the closest unbalanced node (with balance factor of 2 or -2) to the inserted node.
        void rotate(Node* helper); //Implement four possible imbalance cases and update the parent of the given node.
        void rotateLeft(Node* n); //Rotate the subtree to left at the given node
        void rotateRight(Node* n); //Rotate the subtree to right at the given node
        void printBalanceFactors(Node *);
        void visualizeTree(ofstream &, Node *);
        void heighthelper(Node* n, int nHeight, int& cHeight);
        int height(Node* n);
        void replacechild(Node*, Node*, Node*);
        void setchild(Node*, string , Node*);
};
