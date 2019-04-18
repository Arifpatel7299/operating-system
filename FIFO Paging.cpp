#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<stdlib.h>
//using namespace std;
#define max 100
class fifo
{
private:
int frame[10], mrstr[max];
int f,r,tot,nof,fault;
public:
fifo()
{
f=r=-1;
fault=0;
}
void getdata();
void push();
void pop();
void dis();
};
void fifo::getdata()
{
int pno,i=0;
cout<<“\nEnter the No. of Page Frames:”;
cin>>nof;
cout<<“\nEnter the memory reference string:(Press -1 to end)\n”;
do
{
cin>>pno;
mrstr[i++]=pno;
}while(pno!=-1);
tot=i-1;
}
void fifo::push()
{
int x,i,flag=0;//,fault=0;
for(i=0;i<nof;i++)
frame[i]=-1;
cout<<“\nThe Page Frames are:\tNo.of Page Faults”;
for(i=0;i<tot;i++)
{
x=mrstr[i];
for(int j=0; j<nof; j++)
{
if(frame[j]==x)
{
flag=1;
break;
}
else
flag=0;
}
if(flag==0)
{
if(r==nof-1)
{
++f;
r=++r%nof;
frame[r]=x;
}
else
frame[++r]=x;
fault++;
dis();
}

}
cout<<“\nTotal Page Faults :”<<fault;
}
void fifo::dis()
{
int i=0;
cout<<“\n———-\n”;
while(i<nof)
{
cout<<“|  “<<frame[i]<<”  “;
i++;
}
cout<<“|     “<<fault;
}
void main()
{
fifo fp;
fp.getdata();
fp.push();
return 0;
}


