//implemantation of simple hashing
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void insert(fstream &o,int l,int n,int k )
{
	int f=0;
	int h;
	h=(k%n);
	int tempoff=l*h;
	o.seekg(tempoff,ios::beg);
	char ch;
	o>>ch;
	cout<<"tempoff = "<<tempoff<<endl;
	o.seekp(tempoff,ios::beg);
	char temp[10];
	itoa(k,temp,10);
	int p=strlen(temp);
	int j;
	for(j=0;j<p;j++)
	{
		o<<temp[j];
	}		
	for(j=strlen(temp);j<l/2;j++)
	{
		o<<"*";
	}	
}
int search(fstream &o,int k,int n,int l)
{
	int f=-1;
	int f1=0;int i=0;int h;
	{
		h=k%n;
		char ch;
		int tempoff=h*l;
		o.seekg(tempoff,ios::beg);
		char temp[5];
		o.getline(temp,5,'*');
		o.seekg(tempoff,ios::beg);
		o>>ch;
		int p;
		p=atoi(temp);
		if(ch=='*')
		{
			f1=1;
		}
		else if(p==k)
		{
			f=tempoff;
			f1=1;
		}
	}
	return f;
}
int main()
{
	fstream o1;
	o1.open("hash1.txt");
	int l=10;
	int n=10;
	int k,i;
	for(i=0;i<n*l;i++)
	{
		o1<<"*";
	};
	cout<<"enter the data (-1 to exit) ";
	while(1)
	{
		cin>>k;
		if(k==-1)
		break;
		else
		insert(o1,l,n,k);
	}
	cout<<"enter the key to be searched for : ";
	cin>>k;
	int f;
	f=search(o1,k,n,l);
	if(f==-1)
	{
		cout<<"key not found  :";
	}
	else
	{
		cout<<"key found at location "<<f<<endl;
	}
	o1.close();
	return 0;
}
