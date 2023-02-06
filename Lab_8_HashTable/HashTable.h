#ifndef HASHTABLE_H //Collborated with Casey Le and help from outside resources
#define HASHTABLE_H

#include <string>
#include <list>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include "WordEntry.h"

using namespace std;

class HashTable {

 private:
	list<WordEntry> *hashTable;
	int size;

 public:
	HashTable(int);
	bool contains(const string &);
	double getAverage(const string &);
	void put(const string &, int);
 
 private:
	int computeHash(const string &);
};

#endif