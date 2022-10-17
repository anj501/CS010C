#include <iostream>
using namespace std;

#include "IntList.h"

int main() {
    IntList test;
    int testnumber;
    cout << "Outputting empty list (testing default constructor..." << endl;
    cout << test;
    cout << "Enter one number to add to front of list (list will be input, 4 ,7, 2)" << endl;
    cin >> testnumber;
    test.push_front(2);
    test.push_front(7);
    test.push_front(4);
    test.push_front(testnumber);
    cout << "List:" << endl;
    cout << test << endl;
    cout << "Testing pop_front() function..." << endl;
    test.pop_front();
    cout << "List:" << endl;
    cout << test << endl;
    cout << "Enter number to push_back() (add to end of list)" << endl;
    cin >> testnumber;
    test.push_back(testnumber);
    cout << "List:" << endl;
    cout << test << endl;
    cout << "Testing pop_back() function..." << endl;
    test.pop_back();
    cout << test << endl;
    cout << "Testing empty() function..." << endl;
    if (test.empty() == true) {
        cout << "List is empty besides header and tail" << endl;
    }
    else {
        cout << "There are nodes besides header and tail in the list" << endl;
    }
    cout << "List:" << endl;
    cout << test << endl;
    cout << "List in reverse:" << endl;
    test.printReverse();
    cout << endl;
    cout << "Emptying list" << endl;
    test.pop_front();
    test.pop_front();
    test.pop_front();
    cout << "Testing empty() function..." << endl;
    if (test.empty() == true) {
        cout << "List is empty besides header and tail" << endl;
    }
    else {
        cout << "There are nodes besides header and tail in the list" << endl;
    }
}