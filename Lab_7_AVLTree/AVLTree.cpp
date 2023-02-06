#include <iostream> //Collborated with Casey Le and help from outside resources
#include <fstream>
#include <string>
#include "AVLTree.h"
#include "Node.h"
using namespace std;

void AVLTree::insert(const string& input) {
    Node* insert = new Node(input);
    Node* curr = nullptr;
    if (root == nullptr) {
        root = insert;
        insert->parent = nullptr;
        return;
    }
    curr = root;
    while (curr != nullptr) {
        if (insert->data < curr->data) {
            if (curr->left == nullptr) {
                curr->left = insert;
                insert->parent = curr;
                curr = nullptr;
            }
            else {
                curr = curr->left;
            }
        }
        else if (insert->data > curr->data) {
            if (curr->right == nullptr) {
                curr->right = insert;
                insert->parent = curr;
                curr = nullptr;
            }
            else {
                curr = curr->right;
            }
        }
        else {
            curr->count = curr->count + 1;
            curr = nullptr;
        }
    }

    insert = insert->parent;
    while (insert != nullptr) {
        rotate(insert);
        insert = insert->parent;
    }
}

void AVLTree::rotate(Node* n) {
    if (balanceFactor(n) == -2) {
        if (balanceFactor(n->right) == 1) {
            //Double rotation case
            rotateRight(n->right);
        }
        rotateLeft(n);
    }
    else if (balanceFactor(n) == 2) {
        if (balanceFactor(n->left) == -1) {
            //Doble rotation case
            rotateLeft(n->left);
        }
        rotateRight(n);
    }
}

void AVLTree::rotateRight(Node* n) {
    Node* leftRightChild = n->left->right;
    if (n->parent != nullptr) {
        replacechild(n->parent, n, n->left);
    }
    else { //node is root
        root = n->left;
        root->parent = nullptr;
    }
    setchild(n->left, "right", n);
    setchild(n, "left", leftRightChild);
}

void AVLTree::rotateLeft(Node* n) {
    Node* rightLeftChild = n->right->left;
    if (n->parent != nullptr) {
        replacechild(n->parent, n, n->right);
    }
    else { //node is root
        root = n->right;
        root->parent = nullptr;
    }
    setchild(n->right, "left", n);
    setchild(n, "right", rightLeftChild);
}

void AVLTree::setchild(Node* parent, string whichChild, Node* child) {
    if (whichChild != "left" && whichChild != "right") {
        exit(1);
    }
    if (whichChild == "left") {
        parent->left = child;
    }
    else {
        parent->right = child;
    }

    if (child != nullptr) {
        child->parent = parent;
    }
}

void AVLTree::replacechild(Node* parent, Node* currentChild, Node* newChild) {
    if (parent->left == currentChild) {
        setchild(parent, "left", newChild);
    }
    else if (parent->right == currentChild) {
        setchild(parent, "right", newChild);
    }
}

int AVLTree::balanceFactor(Node* n) {
    int leftH = height(n->left);
    int rightH = height(n->right);

    return leftH - rightH;
}

void AVLTree::printBalanceFactors() {
    Node* n = root;
    printBalanceFactors(n);
    cout << endl;
}

void AVLTree::printBalanceFactors(Node* n) {
    if (n != nullptr) {
        printBalanceFactors(n->left);
        cout << n->data << "(" << balanceFactor(n) << "), ";
        printBalanceFactors(n->right);
    }
}

int AVLTree::height(Node* n) {
    if (n == nullptr) {
        return -1;
    }
    else {
        if (height(n->left) > height(n->right)) {
            return height(n->left) + 1;
        }
        else {
            return height(n->right) + 1;
        }
    }
}

void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS, root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
        }
    }
}