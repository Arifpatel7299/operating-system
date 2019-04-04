#include<iostream>
using namespace std;
main()
{
	int pro,blks;
	cout<<"No. of processes";
	cin>>pro;
	cout<<"No. of blocks in memory";
	cin>>blks;
	int a[pro],aa[blks],s[blks]={0},an[pro]={0},re[blks]={0};
	
	cout<<"Enter process size";
	for(int i=0;i<pro;i++) cin>>a[i];
	
	cout<<"Enter size of memory blocks\n";
	cout<<"1. For Used \n 2. For hole\n";
	for(int i=0;i<blks;i++) { cin>>re[i];cin>>aa[i]; }
	
	int flag[blks]; for(int i=0;i<blks;i++) flag[i]=0;
	
	for(int i=0;i<blks;i++)
	{  
		for(int j=0;j<blks;j++)
		{   s[i]+=aa[j];
			//cout<<"s[i] at "<<i<<"time is "<<s[i]<<endl;
			if(aa[j]>=a[i]&&flag[j]==0&&re[j]==2)
			{an[i]=s[i]-aa[j];
				aa[j-1]=aa[j]+a[i];
				aa[j]=aa[j]-a[i];
				if(aa[j]>0) flag[j]=0; 
				else flag[j]=1; 
				break;
			}
	
		}
	}
	
	cout<<"Starting addresses are\n";
	for(int i=0;i<pro;i++) cout<<"For p"<<i+1<<" "<<an[i]<<"  \n";
}
