#include "D:\\College\\6th\\sublime_cpp\\CB-InterPrep\\AdvanceKeypad\\Header\\trie.h"
#include <bits/stdc++.h>
using namespace std;
bool isValidNumber(string num)
{
	if(num.length()>10 or num.length()<10)
	{
		return false;
	}
	return true;
}	
bool nameExists(string contact,Trie t)
{
	if(t.searchContact(contact))
	{
		return true;
	}
	return false;
}
void addEntry()
{
	for(int i=0;i<10;i++)
	{
		cout<<"--";
	}
	cout<<endl;


	ifstream phonebook1;
	phonebook1.open("D:\\College\\6th\\sublime_cpp\\CB-InterPrep\\AdvanceKeypad\\Choices\\PhoneBook\\phonebook.txt");
	//phonebook<<name<<"\n"<<number<<"\n";
	int n;
	Trie t;
	while(!phonebook1.eof())
	{
		string name,number;
		phonebook1>>name;
		phonebook1>>number;
		t.addContact(name,number);
	}

	string name,number;
	cout<<"ENTER NAME: ";
	getline(cin,name);
	while((nameExists(name,t)))
	{
		if(nameExists(name,t))
		{
			cout<<"NAME ALREADY EXISTS!"<<endl;
		}
		cout<<"ENTER NAME: ";
		getline(cin,name);
	}
	phonebook1.close();
	cout<<"ENTER "<<name<<"'S PHONE NUMBER: ";
	getline(cin,number);
	while(!(isValidNumber(number)))
	{
		if(!isValidNumber(number))
		{
			cout<<"ENTER VALID NUMBER!";
		}	
		cout<<"ENTER "<<name<<"'S PHONE NUMBER: ";
		getline(cin,number);
	}



	cout<<"writing to phonebook..."<<endl;
	ofstream phonebook;
	phonebook.open("D:\\College\\6th\\sublime_cpp\\CB-InterPrep\\AdvanceKeypad\\Choices\\PhoneBook\\phonebook.txt",ios::app);
	phonebook<<name<<"\n"<<number<<"\n";
	phonebook.close();


	for(int i=0;i<10;i++)
	{
		cout<<"--";
	}
	cout<<endl;
	return;
}
int main()
{
	addEntry();
	return 0;
}