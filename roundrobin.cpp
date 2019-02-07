#include<iostream>
using namespace std;
#define max 10
class roundrobin
{
	public:
		int n,t,tq;
		int l=0,bt[max],wt[max],rmbt[max],tat[max]; float avgtat=0,avgwt=0;
		bool done;
		void get()
		{
			cout<<"Enter no. of process\n";
			cin>>n;
			
			
			cout<<"Enter time Quantum\n";
			cin>>tq;			
			
			cout<<"Enter Burst Time of  Process\n";
			for(int i=0;i<n;i++) 
			{
				cin>>bt[i];
				rmbt[i]=bt[i];
			}
			
			
		}
		
		void calc()
		{ while(true)
		{   done=true;
			for(int i=0;i<n;i++)
			{
				if(rmbt[i]>0)
				{  done=false;
					if(rmbt[i]>tq)
					{
						t=t+tq;
						rmbt[i]=rmbt[i]-tq;
					}
				
				else
				   {
						t=t+rmbt[i];
						rmbt[i]=0;
						wt[i]=t-bt[i];
						tat[i]=t;					
				    }
			    }
			}
			if(done==true)
			break;
		}
			
			
		}
		
		void avg()
		{
			for(int i=0;i<n;i++)
			{
				avgtat+=tat[i];
				cout<<"Avg tat = "<<avgtat<<endl; 
				avgwt+=wt[i];
				cout<<"Avg wt = "<<avgwt<<endl;
			}
			
			avgtat=avgtat/n;
			avgwt=avgwt/n;
		}
		
		
		void show()
		{
			cout<<"Wt is   tat is\n";
			for(int i=0;i<n;i++) cout<<"   "<<wt[i]<<"   "<<tat[i]<<endl;
			cout<<"\n\n";
			cout<<"Avg Turn around time is = "<<avgtat<<endl;
			cout<<"Avg Waiting time is ="<<avgwt<<endl;
			
			
		}
	
};

main()
{
	roundrobin x;
	x.get();
	x.calc();
	x.avg();
	x.show();
}

