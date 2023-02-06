#ifndef WORDENTRY_H //Collborated with Casey Le and help from outside resources
#define WORDENTRY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class WordEntry {

 private:
	string word;
	int numAppearances;
	int totalScore;
 public:
	WordEntry(const string &, int);
	void addNewAppearance(int);
	const string & getWord();
	double getAverage();
};
#endif