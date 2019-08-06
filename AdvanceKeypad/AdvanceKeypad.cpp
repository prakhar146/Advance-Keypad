#include<iostream>
#include <cstdlib>
using namespace std;
int main()
{
	for(int i=0;i<6;i++)
	{
		cout<<" ";
	}
	for(int i=0;i<4;i++)
	{
		cout<<"*";
	}
	cout<<"ADVANCE KEYPAD";
	for(int i=0;i<4;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	system("D:\\College\\6th\\sublime_cpp\\CB-InterPrep\\AdvanceKeypad\\Display\\displayNum.exe");
	int n=1;
	while(n!=-1)
	{
		system("D:\\College\\6th\\sublime_cpp\\CB-InterPrep\\AdvanceKeypad\\Choices\\displayChoice.exe");
		cout<<endl<<"Enter -1 to exit... Any other digit to continue operations  on PHONEBOOK"<<endl;
		cin>>n;
	}
	cout<<endl;
	return 0;
}