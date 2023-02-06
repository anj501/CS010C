#include <iostream> //Collborated with Casey Le and help from outside resources
#include <fstream>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <vector>
using namespace std;

#include "WordLadder.h"

WordLadder::WordLadder(const string& inputFile) {
    ifstream inFS;
    string input;
    inFS.open(inputFile);
    if (!inFS.is_open()) {
        cout << "Error." << endl;
        return;
    }

    while (inFS >> input) {
        if (input.size() != 5) {
            cout << "Error." << endl;
            return;
        }
        else {
            dict.push_back(input);
        }
    }
}

void WordLadder::outputLadder(const string &start, const string &end, const string& outputFile) {
    ofstream outFS;
    string helper;
    int s = 0;
    int e = 0;
    int j;
    outFS.open(outputFile);
    if (!outFS.is_open()) {
        cout << "Error." << endl;
        return;
    }

    queue<stack<string>> queuelist;
    stack<string> nStack;
    list<string>::iterator i;

    nStack.push(start);
    queuelist.push(nStack);

    for (i = dict.begin(); i != dict.end(); ++i) {
        if (*i == start) {
            s = s + 1;
        }

        if (*i == end) {
            e = e + 1;
        }
    }

    if ((s == 0) || (e == 0)) {
        cout << "Error." << endl;
        return;
    }

    if (start == end) {
        outFS << start;
        return;
    }

    while (queuelist.size() != 0) {
        helper = queuelist.front().top();
        for (i = dict.begin(); i != dict.end(); ++i) {
            int dwork = 0;
            bool check;
            for (j = 0; j < 5; ++j) {
                if (helper.at(j) != (*i).at(j)) {
                    dwork = dwork + 1;
                }
            }
            if (dwork == 1) {
                check = true;
            }
            else {
                check = false;
            }

            if (check) {
                stack<string> copy = queuelist.front();
                copy.push(*i);

                if (*i == end) {
                    //you are done, only outputting to outputFile
                    vector<string> copyS;
                    int count = 0;
                    while (copy.size() != 0) {
                        copyS.push_back(copy.top());
                        count = count + 1;
                        copy.pop();
                    }

                    while (count > 0) {
                        count = count - 1;
                        outFS << copyS.at(count);

                        if (copyS.size() != 1) {
                            outFS << " ";
                        }
                    }
                    return;      
                }
                else {
                    queuelist.push(copy);
                    i = dict.erase(i);
                    --i;
                }
            }
        }
        queuelist.pop();
    }
    outFS << "No Word Ladder Found." << endl;
}