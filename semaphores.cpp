#include<iostream>
using namespace std;
#define max 10
void wait(int &s)
{
	--s;
}
void signal(int &s)
{
	++s;
}
int main()
{
	int a[5];
	int S=1;
	int e=5;
	int f=0;
	while(1)
	{
		cout<<"enter your choice 1.produce 2.consume 3.exit"<<endl;
		int s;
		cin>>s;
		if(s==1)
		{
			if(e!=0&&S==1)
			{
				cout<<"enter the data"<<endl;
				wait(e);
				wait(S);
				cin>>a[f];
				signal(S);
				signal(f);			
		}
		else cout<<"buffer is full"<<endl;}
		else if(s==2)
		{
			if(f>0&&S==1)
			{
				wait(f);
				wait(S);
				cout<<"data is "<<a[f]<<endl;
				signal(S);
				signal(e);
			}
			else cout<<"buffer is empty"<<endl;
		}
		else break;
	}
	return 0;
}
