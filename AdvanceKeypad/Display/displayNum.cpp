#include<iostream>
using namespace std;
char table[][10]={" ","$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void displayNumpad()
{
	for(int i=1;i<10;i++)
	{
		// for(int j=0;j<3;j++)
		// {
		// 	cout<<(i+j)<<"("<<table[i+j]<<") \t";
		// }
		cout<<i<<"-"<<table[i]<<endl;
		//cout<<endl;
	}
	cout<<endl;
}
int main()
{
	displayNumpad();
	return 0;
}