#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    unsigned i;
    for (i = index + 1; i < vals.size(); ++i) {
        if (vals.at(i) < vals.at(index)) {
            index = i;
        }
    }

    return index;
}

template <typename T>
void selection_sort(vector<T> &vals) {
    unsigned i;
    unsigned minIndex;
    unsigned indexSmallest;
    T temp;
    for (i = 0; i < vals.size(); ++i) {
        indexSmallest = i;
        minIndex = min_index(vals, indexSmallest);
        temp = vals.at(i);
        vals.at(i) = vals.at(minIndex);
        vals.at(minIndex) = temp;
    }
}

template <typename T>
T getElement(vector<T> vals, int index) {
    long unsigned int i;
    T helper;
    long unsigned int indexHelper = index;
    if ((indexHelper < 0) || (indexHelper >= vals.size())) {
        throw out_of_range("out of range exception occured");
    }
    for (i = 0; i < vals.size(); ++i) {
        if (i == indexHelper) {
            helper = vals.at(i);
        }
    }

    return helper;
}

vector<char> createVector() {
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main() {
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    long unsigned int i;
    int numOfRuns = 10;
    char reply;
    while(--numOfRuns >= 0) {
        try {
            cout << "Enter a number: " << endl;
            cin >> index;
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
            cout << "List:" << endl;
            for (i = 0; i < vals.size(); ++i) {
                cout << vals.at(i) << " ";
            }
            cout << endl;
            cout << "Would you like to you use selection sort? (Reply with 'Y' or 'N')" << endl;
            cin >> reply;
            if (reply == 'Y') {
                selection_sort(vals);
            }
            for (i = 0; i < vals.size(); ++i) {
                cout << vals.at(i) << " ";
            }
            cout << endl;
        }
        catch (out_of_range& excpt) {
            cout << excpt.what() << endl;
        }
    }


    return 0;
}