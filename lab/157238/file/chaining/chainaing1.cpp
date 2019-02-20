//chaining without replacement.
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
void insert(int chain[][2],int x,int n)
{
	int i,j,h;
	h=x%n;
	if(chain[h][0]==0)
	{
		chain[h][0]=x;
	}
	else
	{
		i=0;
		j=h;
		while(chain[h+i][0]!=0)
		i++;
		//k=h+i;
		chain[h+i][0]=x;
		while(chain[h][1]!=-1)
		 h=chain[h][1];
		chain[h][1]=i+j;
	
	}
	
}
void display(int chain[][2],int n)
{
	int i;
	cout<<"key              chain : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<chain[i][0]<<"                "<<chain[i][1];
		cout<<endl;
	}
}
int search(int chain[][2],int x,int n)
{
	int flag=-1;
	int h;
	h=x%n;
	for(int i=0;i<n;i++)
	{
		if(h==-1)
		break;
		if(chain[h][0]==x)
		{
			flag=h;
			break;
		}
		else
		h=chain[h][1];
	}
	return flag;
}
int main()
{
	int n;
	cout<<"enter the size : ";
	cin>>n;
	int chain[50][2],i;
	for(i=0;i<n;i++)
	{
		chain[i][1]=-1;
		chain[i][0]=0;
	}
	int x;
	int cnt=0;
	while(1)
	{
		cout<<"enter the element (-1 to termnate ) ";
		cin>>x;
		if(x==-1)
		break;
		if(cnt==n)
		cout<<"overflow : "<<endl;
		else
		{
			insert(chain,x,n);
			cnt++;
			display(chain,n);
		}
	}
	while(1)
	{
	cout<<"enter the element to search (-1 to break): "<<endl;
	cin>>x;
	if(x==-1)
	break;
	cnt=search(chain,x,n);
	if(cnt==-1)
	cout<<"not found : "<<endl;
	else
	cout<<" found at position : "<<cnt<<endl;
   }
}

