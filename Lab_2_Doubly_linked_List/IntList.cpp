#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList() {
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);

    dummyHead->next = dummyTail;
    dummyHead->prev = dummyHead;
}

IntList::~IntList() {
    IntNode* temp = nullptr;
    IntNode* curr = dummyHead;
    while (curr != nullptr) {
        temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void IntList::push_front(int value) {
    IntNode* temp = new IntNode(value);
    temp->next = dummyHead->next;
    temp->prev = dummyHead;
    dummyHead->next->prev = temp;
    dummyHead->next = temp;
}

void IntList::pop_front() {
    IntNode* curNode = dummyHead->next;
    IntNode* sucNode = curNode->next;
    IntNode* predNode = curNode->prev;

    if (sucNode != nullptr) {
        sucNode->prev = predNode;
    }
    if (predNode != nullptr) {
        predNode->next = sucNode;
    }
}

void IntList::push_back(int value) {
    IntNode* temp = new IntNode(value);
    if (empty()) {
        temp->next = dummyHead->next;
        temp->prev = dummyHead;
        dummyHead->next->prev = temp;
        dummyHead->next = temp;
    }
    else {
        temp->prev = dummyTail->prev;
        temp->next = dummyTail;
        dummyTail->prev->next = temp;
        dummyTail->prev = temp;
    }
}

void IntList::pop_back() {
    IntNode* curNode = dummyTail->prev;
    IntNode* sucNode = curNode->next;
    IntNode* predNode = curNode->prev;

    if (sucNode != nullptr) {
        sucNode->prev = predNode;
    }
    if (predNode != nullptr) {
        predNode->next = sucNode;
    }
}

bool IntList::empty() const {
    bool helper;
    if (dummyHead->next == dummyTail) {
        helper = true;
    }
    else {
        helper = false;
    }

    return helper;
}

ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode* curNode = rhs.dummyHead->next;

    if (!rhs.empty()) {
        while (curNode != rhs.dummyTail->prev) {
            out << curNode->data << " ";
            curNode = curNode->next;
        }

        out << curNode->data;
    }

    return out;
}

void IntList::printReverse() const {
    IntNode* curNode = dummyTail->prev;

    if (!empty()) {
        while (curNode != dummyHead->next) {
            cout << curNode->data << " ";
            curNode = curNode->prev;
        }
        cout << curNode->data;
    }
}
