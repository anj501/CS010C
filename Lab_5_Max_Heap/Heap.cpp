#include <iostream>
using namespace std;

#include "Heap.h"

Heap::Heap() {
    numItems = 0;
    arr[0] = nullptr;
}

void Heap::enqueue(PrintJob* item) {
    int index = 0;
    int parentIndex = 0;
    PrintJob* temp = nullptr;
    if (numItems < MAX_HEAP_SIZE) {
        arr[numItems] = item;
        index = numItems;
        numItems = numItems + 1;
        while (index > 0) {
            parentIndex = (index - 1) / 2;
            if (arr[index]->getPriority() <= arr[parentIndex]->getPriority()) {
                break;
            }
            else {
                temp = arr[index];
                arr[index] = arr[parentIndex];
                arr[parentIndex] = temp;
                index = parentIndex;
            }
        }
    }
}

void Heap::dequeue() {
    if (numItems > 0) {
        arr[0] = arr[numItems - 1];
        numItems = numItems - 1;
        trickleDown(0);
    }
}

PrintJob* Heap::highest() {
    return arr[0];
}

void Heap::print() {
    if (numItems > 0) {
        cout << "Priority: " << arr[0]->getPriority();
        cout << ", Job Number: " << arr[0]->getJobNumber();
        cout << ", Number of Pages: " << arr[0]->getPages();
        cout << endl;
    }
}

void Heap::trickleDown(int index) {
    int i;
    int childIndex = (2 * index) + 1;
    int priority = arr[index]->getPriority();
    int maxPriority = -1;
    int maxIndex = -1;
    PrintJob* temp;
    while (childIndex < numItems) {
        maxPriority = priority;
        maxIndex = -1;
        for (i = 0; (i < 2) && (i + childIndex < numItems); i++) {
            if (arr[i + childIndex]->getPriority() > maxPriority) {
                maxPriority = arr[i + childIndex]->getPriority();
                maxIndex = i + childIndex;
            }
        }
        if (maxPriority == priority) {
            break;
        }
        else {
            temp = arr[index];
            arr[index] = arr[maxIndex];
            arr[maxIndex] = temp;
            index = maxIndex;
            childIndex = (2 * index) + 1;
        }
    }
}