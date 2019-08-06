#include<iostream>
#include <cstdlib>
using namespace std;
void choiceSelect(int choice)
{
	while(choice<1 or choice >2)
	{
		cout<<"PLEASE SELECT VALID OPTION!"<<endl;
		cin>>choice;
	}
	if(choice==1)
	{
		system("D:\\College\\6th\\sublime_cpp\\CB-InterPrep\\AdvanceKeypad\\Choices\\AddEntry\\addEntry.exe");
	}
	else if(choice==2)
	{
		system("D:\\College\\6th\\sublime_cpp\\CB-InterPrep\\AdvanceKeypad\\Choices\\Call\\callLogic.exe");
	}
	//EXCEPTION HANDLING
	return;
}
int main()
{
	for(int i=0;i<11;i++)
	{
		cout<<"--";
		if(i==5)
		{
			cout<<"SELECT";
		}
	}
	cout<<endl<<endl;
	cout<<"1--> "<<"Add Entry"<<endl;
	//cout<<"2--> "<<"Update Entry"<<endl;
	cout<<"2--> "<<"Call"<<endl<<endl;
	for(int i=0;i<14;i++)
	{
		cout<<"--";
		// if(i==9)
		// {
		// 	cout<<"SELECT";
		// }
	}
	cout<<endl;
	int choice;
	cout<<"OPTION: ";
	cin>>choice;
	choiceSelect(choice);
	return 0;
}