#pragma once
#include"Node.h"
#include<iostream>
#include<string>
#include<list>
#include<fstream>
using namespace std;

class Tree {
private:
	Node *_head;
public:

	Tree();
	Tree(string value, string name);
	void Read(string value,  string name, int level);
	void DeleteTree();
	void print(ofstream &ofs);
	string getHeadName();
	void setHeadVal(string val, string name);
};