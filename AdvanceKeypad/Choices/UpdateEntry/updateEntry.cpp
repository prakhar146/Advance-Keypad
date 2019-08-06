#include<iostream>
#include<unordered_map>
using namespace std;
class Node
{
public:
	char data;
	unordered_map<char,Node*> m;
	bool isTerminal;
	pair<string,string> p;
public:
	Node(char c)
	{
		data=c;
		p.first="\0";
		p.second="\0";
		isTerminal=false;
	}
};
class Trie
{
	Node *root;
	public:
		Trie()
		{
			root=new Node('\0');
		}
		void addWord(string s,string num)
		{
			Node *temp=root;
			for(int i=0;s[i]!='\0';i++)
			{
				char ch=s[i];
				if(temp->m.count(tolower(ch))==0)
				{
					Node *n=new Node(ch);
					temp->m[tolower(ch)]=n;
					temp=n;
				}
				else
				{
					temp=temp->m[tolower(ch)];
				}
			}
			temp->isTerminal=true;
			temp->p.first=s;
			temp->p.second=num;
			return;
		}

		void traverseBook(Node *temp)
		{
			if(temp->isTerminal==true)
			{
				cout<<temp->p.first<<" "<<temp->p.second<<endl;
				return;
			}
			for(unordered_map<char,Node*>::iterator it=temp->m.begin();it!=temp->m.end();it++)
			{
				traverseBook(it->second);
			}
			return;
		}

		void searchContact(string word)
		{
			Node *temp=root;
			for(int i=0;word[i]!='\0';i++)
			{
				char ch=tolower(word[i]);
				if(!(temp->m.count(ch)))
				{
					cout<<" no such string exists ";
					return;
				}
				else
				{
					temp=temp->m[ch];
				}
			}
			if(temp->isTerminal==true)
			{
				cout<<word<<"  "<<temp->p.second<<endl;
				pair<string,string> p1;
				p1.first=word;
				p1.second=temp->p.second;
				return;
			}
			traverseBook(temp);
			return;
		}
};
int main()
{
	Trie t;
	for(int i=0;i<4;i++)
	{
		string name,phnNum;
		//cout<<"Enter Name: ";
		cin>>name;
		//cout<<"Enter Num: ";
		cin>>phnNum;
		t.addWord(name,phnNum);
	}
	//cout<<"Enter Contact to search: ";
	string contact;
	cin>>contact;
	pair<string,string> p2;
	t.searchContact(contact);
	return 0;
}