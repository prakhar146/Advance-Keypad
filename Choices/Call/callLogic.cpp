#include<iostream>
#include<vector>
#include<cstring>
#include "D:\\College\\6th\\sublime_cpp\\CB-InterPrep\\AdvanceKeypad\\Header\\trie.h"
#include <conio.h>
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
	cout<<endl;
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
void getInput()
{
	char input[1000];
	char output[1000];
	int idx=0;
	//char ch=_getch();
	while(1)
	{
		char ch=_getch();
		if(ch=='\r' or ch=='e')
		{
			break;
		}
		if(ch=='\b')
		{
			if(idx>=1)
			{
				input[idx-1]='\0';
				idx=idx-2;
			}
			else
			{
				cin.ignore(ch);
			}
		}
		else
		{
			input[idx]=ch;
			idx++;
		}
		vector<string> v;
		system("cls");
			for (int i = 0; i < 10; ++i)
			{
				cout<<"--";
				if(i==4)
				{
					cout<<"CALL";
				}
			}
			cout<<endl;
			cout<<"ENTER NUMBER: "<<input;
		combinations(input,output,0,0,v);
		displayContacts(v);
		//while(!(_kbhit)){ };
	}
}
int main()
{
	system("cls");
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
	getInput();
	//cin>>input;
	//combinations(input,output,0,0,v);
	//displayContacts(v);
	for (int i = 0; i < 12; ++i)
	{
		cout<<"--";
	}
	return 0;
}