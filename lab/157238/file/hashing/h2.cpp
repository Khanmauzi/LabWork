#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct stud
{
	int rno;
	char name[10];
};
void pack(ostream &o,stud s)
{
	char *buffer;
	buffer=new char[100];
	strcpy(buffer,s.name);
	strcat(buffer,"|");
	char *temp;
	temp=new char[10];
	itoa(s.rno,temp,10);
	strcat(buffer,temp);
	strcat(buffer,"#");
	int l;
	l=strlen(s.name)+strlen(temp)+2;
	o.write(buffer,l);
}
void unpack(istream &i1,stud &s)
{
	char *buffer;
	buffer=new char[100];
	i1.getline(s.name,10,'|');
	char temp[10];
	i1.getline(temp,10,'#');
	s.rno=atoi(temp);
}
void insert(fstream &o,int l,int n,int k,int store )
{
	int f=0;int i=0;
	int h;
	while(f==0)
	{
		if(i==n)
		{
			cout<<"i = "<<i<<" ,n = "<<n<<endl;
			cout<<"hash file is full : "<<endl;
			break;
		}
		h=((k+i)%n);
		int tempoff=l*h;
		o.seekg(tempoff,ios::beg);
		char ch;
		o>>ch;
		if(ch=='*')
		{
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
			char temp1[10];
			itoa(store,temp1,10);
			p=strlen(temp1);
			for(j=0;j<p;j++)
			{
				o<<temp1[j];
			}
			for(j=strlen(temp);j<l/2;j++)
			{
				o<<"*";
			}
			f=1;
		}
		else
		{
			i++;
		}
	}
}
int search(fstream &o,int k,int n,int l)
{
	int f=-1;
	int f1=0;int i=0;int h;
	while(f1==0)
	{
		h=(k+i)%n;
		char ch;
		int tempoff=h*l;
		o.seekg(tempoff,ios::beg);
		char temp[5];
		o.getline(temp,5,'*');
		o.seekg(tempoff,ios::beg);
		o>>ch;
		if(ch=='*')
		{
			f1=1;
			break;
		}
		int p;
		p=atoi(temp);
		if(p==k)
		{
			f=tempoff,f1=1;
			break;
		}
		i++;
	}
	return f;
}
int main()
{
	fstream o1;
	o1.open("hash2.txt");
	int m;
	cout<<"enter the number of student: ";
	cin>>m;
	int i,j;
	ofstream o;
	o.open("data2.txt");
	int l=10;int n=10;
	for(i=0;i<n*l;i++)
	{
		o1<<"*";
	}
	for(i=0;i<m;i++)
	{
		struct stud s;
		cout<<"enter the name : ";
		cin>>s.name;
		cout<<"enter the roll number : ";
		cin>>s.rno;
		int store;
		store=o.tellp();
		insert(o1,l,n,s.rno,store);
		pack(o,s);
	}
	o.close();
	int k;
	ifstream in;
	in.open("data2.txt");
	cout<<"enter the key to be searched for: ";
	cin>>k;
	int f;
	f=search(o1,k,n,l);
	if(f==-1)
	{
		cout<<"key not found : "<<endl;
	}
	else
	{
		cout<<"key is found at location : "<<f<<endl;
		o1.seekg(f,ios::beg);
		o1.seekg(l/2,ios::cur);
		char temp1[5];
		o1.getline(temp1,5,'*');
		int store=atoi(temp1);
		in.seekg(store,ios::beg);
		struct stud s;
		unpack(in,s);
		cout<<"details of the student : "<<endl;
		cout<<"name : "<<s.name<<endl;
		cout<<"roll number : "<<s.rno<<endl;
	}
	o1.close();
	return 0;
}
