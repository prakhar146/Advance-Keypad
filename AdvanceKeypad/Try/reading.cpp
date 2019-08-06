#include<iostream>
#include "D:\\College\\6th\\sublime_cpp\\CB-InterPrep\\AdvanceKeypad\\Header\\trie.h"
#include<fstream>
using namespace std;
int main()
{
	int n;
	ifstream file;
	file.open("D:\\College\\6th\\sublime_cpp\\CB-InterPrep\\AdvanceKeypad\\Choices\\PhoneBook\\phonebook.txt");
	while(!file.eof())
	{
		string name,number;
		file>>name>>number;
		cout<<name<<" "<<number<<endl;
	}
	file.close();
	return 0;
}