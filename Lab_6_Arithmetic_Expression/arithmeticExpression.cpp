#include <iostream> //Collborated with Casey Le and help from outside resources
#include <string>
#include <cstdlib>
#include <stack>
#include <fstream>
#include <sstream>
using namespace std;

#include "arithmeticExpression.h"

arithmeticExpression::arithmeticExpression(const string& iExpression) {
    infixExpression = iExpression;
    root = nullptr;
}

arithmeticExpression::~arithmeticExpression() {

}

void arithmeticExpression::buildTree() {
    long unsigned int i;
    int p;
    string postfix = infix_to_postfix();
    stack<TreeNode*> tree;
    char helper = 'a';

    for (i = 0; i < postfix.size(); ++i) {
        TreeNode* temp = new TreeNode(postfix.at(i), helper);
        p = priority(postfix.at(i));
        if (p >= 1) {
            temp->right = tree.top();
            tree.pop();
            temp->left = tree.top();
            tree.pop();
        }
        
        tree.push(temp);
        root = temp;
        helper = helper + i;
    }
}

void arithmeticExpression::infix() {
    infix(root);
}

void arithmeticExpression::prefix() {
    prefix(root);
}

void arithmeticExpression::postfix() {
    postfix(root);
}

void arithmeticExpression::prefix(TreeNode* n) {
    if(n) {
        cout << n->data;
        prefix(n->left);
        prefix(n->right);
    }
}

void arithmeticExpression::postfix(TreeNode* n) {
    if(n) {
        postfix(n->left);
        postfix(n->right);
        cout << n->data;
    }
}

void arithmeticExpression::infix(TreeNode* n) {
    if(n) {
        if (n->left != nullptr) {
            cout << "(";
        }

        infix(n->left);
        cout << n->data;
        infix(n->right);

        if (n->left != nullptr) {
            cout << ")";
        }
    }
}

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void arithmeticExpression::visualizeTree(ofstream& outFS, TreeNode* n) {
    
}