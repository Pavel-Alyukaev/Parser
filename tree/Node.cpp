#include"Node.h"
#include <iostream>

int Node::count = 0;

Node::Node(string value, string name, int level)
{
	_id=Node::count++;
	_value = value;
	_level = level;
	_name = name;
}

void Node::NodeAdd(string value, string name, int level)
{
	if (level - this->_level == 1)							//если уровень текущего узла меньше на 1 дописываемого узла
	{														//дописываемый узел записывается в дети к текущему
		Node* newNode = new Node(value, name, level);		//иначе поднимаемся на следующий уровень
		newNode->_prewId = this->_id;
		this->_child.push_front(newNode);
	}
	else
		(*(this->_child.begin()))->NodeAdd(value, name, level);
}

	void Node::NodeDelete()
	{
		for (auto i : this->_child)
		{
			i->NodeDelete();
		}
		delete this;
	}

	void Node::print(ofstream &ofs)
	{
		ofs << _id << " " << _prewId << " " << _name << " ";
		if (_value != "")				//если узел имеет значение то заводим значение в поток
			ofs << _value << endl;		// иначе выводим id потомков
		else
		{
			_child.reverse();
			for (auto &i : this->_child)
				ofs << i->_id<<" ";
			ofs << endl;
		}
		
		for (auto &i : this->_child) //проходим по всем элементам
		{
			i->print(ofs);
		}
	}

