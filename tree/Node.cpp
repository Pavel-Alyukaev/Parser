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
	if (level - this->_level == 1)							//���� ������� �������� ���� ������ �� 1 ������������� ����
	{														//������������ ���� ������������ � ���� � ��������
		Node* newNode = new Node(value, name, level);		//����� ����������� �� ��������� �������
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
		if (_value != "")				//���� ���� ����� �������� �� ������� �������� � �����
			ofs << _value << endl;		// ����� ������� id ��������
		else
		{
			_child.reverse();
			for (auto &i : this->_child)
				ofs << i->_id<<" ";
			ofs << endl;
		}
		
		for (auto &i : this->_child) //�������� �� ���� ���������
		{
			i->print(ofs);
		}
	}

