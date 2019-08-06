#include<iostream>
#include<vector>
#include<cstring>
#include "D:\\College\\6th\\sublime_cpp\\CB-InterPrep\\AdvanceKeypad\\Header\\trie.h"
using namespace  std;
//vector<string> v;
char table[][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void combinations(char *input,char *output,int i,int j,vector<string> &v)
{
	if(input[i]=='\0')
	{
		output[j]='\0';
		string temp=output;
		v.push_back(temp);
		return;
	}
	int digit=input[i]-'0';
	for(int k=0;table[digit][k]!='\0';k++)
	{
		output[j]=table[digit][k];
		combinations(input,output,i+1,j+1,v);
	}
	return;
}
void displayContacts(vector<string> v)
{
	for (int i = 0; i < 10; ++i)
	{
		cout<<"*";
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
	phonebook1.close();
	for(vector<string>::iterator it=v.begin();it!=v.end();it++)
	{
		string str=*it;
		t.printContact(str);
	}
	for (int i = 0; i < 10; ++i)
	{
		cout<<"*";
	}
	cout<<endl;
	return;
}
int main()
{
	for (int i = 0; i < 10; ++i)
	{
		cout<<"--";
		if(i==4)
		{
			cout<<"CALL";
		}
	}
	cout<<endl;
	cout<<"ENTER NUMBER: ";
	char input[1000];
	char output[1000];
	cin>>input;
	vector<string> v;
	combinations(input,output,0,0,v);
	displayContacts(v);
	for (int i = 0; i < 12; ++i)
	{
		cout<<"--";
	}
	return 0;
}