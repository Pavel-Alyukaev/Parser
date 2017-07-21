#pragma once
#include<string>
#include<list>
#include<string>
#include<fstream>

using namespace std;

class Node {
	

public:
	int _level;
	static int count;
	int _id;
	int _prewId;
	std::string _name;
	std::string _value;
	std::list<Node*>_child;


	Node(string value, string name,int level);

	void NodeAdd(string value, string name, int level);
	void NodeDelete();
	void print(ofstream &ofs);

};
