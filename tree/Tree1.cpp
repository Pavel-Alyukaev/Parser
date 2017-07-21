#include "Tree1.h"


Tree::Tree(string value, string name)
{
	
	Node *node = new Node(value, name, 0);
	node->_prewId = 0;
	_head = node;
}

void Tree::Read(string value, string name, int level)
{
	_head->NodeAdd(value, name,level);
}

void Tree::DeleteTree()
{
	_head->NodeDelete();
}

void Tree::print(ofstream &ofs)
{
	_head->print(ofs);
}

string Tree::getHeadName()
{
	return _head->_name;
}

void Tree::setHeadVal(string val, string name)
{
	_head->_name = name;
	_head->_value = val;
}

