#include <iostream>
#include <unordered_map>
#include <string.h>
using namespace std;

class node{
    public:
    //char data;

    pair<char,string> p;
    unordered_map<pair<char,string>, node*> m;
    bool terminal;
    //string number;

    node(char d)
    {
        //data=d;
        p.first=d;
        p.second=" ";
        isTerminal=false;
        //number='0';
    }
};
class trie{

    
    node* root;
    //node* end;
    public:

    trie(){
		root = new node('\0');
	}
    void add_contact(string contact, string num)
    {
        node* temp=root;
        for(int i=0;contact[i]!='\0';i++)
        {
            pair<char,string> p1;
            p1.first=contact[i];
            p1.second=" ";
            //char ch=contact[i];
            if(temp->m.count(p1)==0)
            {
                node* child=new node(p1.first);
                temp->m[p1]=child;
                temp=child;
            }
            else
            {
                temp=temp->m[p1];
            }
        }
        pair<char,string> p2;
        p2.first="\0";
        p2.second=num;
        temp->m.insert(make_pair(p2,temp));
        temp->terminal=true;
        //end=temp;
        //node *end=new node('\0');
        //temp->terminal=true;
        //end->number=num;    
    }

    string display(string contact)
    {
        node* temp=root;
        for(int i=0;contact[i]!='\0';i++)
        {
            //char ch=contact[i];
            pair<char,string> p1;
            p1.first=contact[i];
            p1.second=" ";
            if(temp->m.count(p1)==0){
				return NULL;
			}
			else{
				temp = temp->m[p1];
                //cout<<temp->number<<endl;
			}
		}
        //cout<<temp->number<<endl;
		string s=temp->number; 
        return s;  
    }
};
int main() {
    trie t;
	// char words[][10] = {"apple","ape","not","news"};

	for(int i=0;i<4;i++){
        string words;
        string num;
        cin>>words;
        cin>>num;
		t.add_contact(words,num);
	}
    cout<<"sdd"<<endl;
	string w;
	cin>>w;
    string ans;
    ans=t.display(w);
    cout<<ans;
	return 0;
}
