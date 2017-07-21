#include"Tree1.h"
#include"Node.h"
#include<iostream>
#include<vector>
#include<Windows.h>
#include<fstream>
#include<regex>
#include<string>
#include<locale>

using namespace std;
bool parsNode(string &str, int &level, Tree tree);
void dialog(int comand, string& resultString);

void main()
{
	setlocale(LC_ALL,"rus");
	bool flag = true; //������������ ������� ������� ������
	int level = 0;//������� ������
	string str;
	string fileName;

	Tree t1("","");
	dialog(0, fileName);//������ � �������������

	ifstream ifs(fileName);
	if (ifs.good())
	{
		while (getline(ifs, str) && flag)
		{
			flag=parsNode(str, level, t1);
		}
		ifs.close();
		if (level != 0)flag = false;
		if (flag)//���� ��� ���� ��������� �������
		{
			dialog(1, fileName);
			ofstream ofs(fileName);
			if (ofs.good())	t1.print(ofs);//���������� � �������� ����
			ofs.close();
		}
		else
		{
			string s;
			dialog(2, s);
		}
		t1.DeleteTree();//������� ������
	}
	
	system("pause");
}

bool parsNode(string &str, int &level, Tree tree)
{
	bool boolResult = true;
	int countTopNode = 0;
	smatch result;

	string pat1 = " *(\\D\\w*) *= *[{] *";// ��� = {
	string pat2 = " *(\\D\\w*) *= *[\"]([^\"]*)[\"] *";// ��� = "��������"
	string pat3 = " *(\\D\\w*) *= *[{]((" + pat2 + ")*)[}]";// ��� = {��� = "��������"...}
	string pat4 = " *[}] *";// }
	string pat5 = " *";// �������� �� ������ �������



	regex reg1(pat1);
	regex reg2(pat2);
	regex reg3(pat3);
	regex reg4(pat4);
	regex reg5(pat5);

	

	if (regex_match(str, result, reg1))// ���������  ��� = {
	{
		if (tree.getHeadName() == "")
			tree.setHeadVal("", result.str(1));
		else
			tree.Read("", result.str(1), level);
		level++;
	}
	else 	if (regex_match(str, result, reg2))// ���������  ��� = "��������"
	{
		tree.Read(result.str(2), result.str(1), level);

	}
	else if (regex_match(str, result, reg3))// ���������   ��� = {��� = "��������"...}
	{
		tree.Read("", result.str(1), level);
		level++;

		smatch match;                                         // ���������  ��� = "��������"
		sregex_iterator next(str.begin(), str.end(), reg2);
		sregex_iterator end;
		while (next != end)
		{
			smatch match = *next;
			tree.Read(match.str(2), match.str(1), level);
			next++;
		}
		level--;
	}
	else if (regex_match(str.begin(), str.end(), reg4))// ���������
	{
		level--;
		if (level < 0) boolResult = false;
	}
	else if (regex_match(str.begin(), str.end(), reg5));// ���������
	else // ����� ������
	{
		string s; 
		dialog(2, s);
		boolResult = false;
	}
	return boolResult;
}

void dialog(int comand, string& resultString)
{
	switch (comand)
	{
	case 0:
		cout << "�������� �������� ����: ";
		cin >> resultString;
		break;

	case 1: 	
		cout << "�������� �������������� ����: ";
		cin >> resultString;
		break;
	case 2:
		cout << "������ ������� �������� ������"<<endl;
		resultString = "";
		break;
	}
}