//implementation index file for fixed lengh
#include<iostream>
#include<fstream>
#define null NULL
#include<string.h>
#include<stdlib.h>
using namespace std;
struct student
{
	int rno;
	char name[10];
};
void pack(ostream &o,struct student s)
{
	char *buffer;
	buffer=new char[100];
	int i,j;
	i=0;j=0;
	strcpy(buffer,s.name);
	int l1;
	l1=strlen(s.name);
	for(i=l1;i<10;i++)
	{
		buffer[i]='*';
	}buffer[i]='\0';
	//cout<<buffer;
	char *temp;
	temp=new char[10];
	itoa(s.rno,temp,10);
	int l2;//cout<<"$"<<temp;
	strcat(buffer,temp);
	strcat(buffer,"#");
//	strcpy(b,buffer);
	int l;
	l2=strlen(temp);
	l=11+l2;
//	cout<<buffer;
	o.write(buffer,l);
	
}
void unpack(istream &in,struct student &s)
{
	char *buffer;
	buffer=new char[40];
	in.getline(buffer,40,'#');
	strcat(buffer,"#");
	int i,j;
	i=0;
	j=0;
	//cout<<buffer<<endl;
	while(buffer[i]!='*')
	{
		s.name[i]=buffer[i];
		i++;
	}
	s.name[i]=null;
	//cout<<s.name;
	while(buffer[i]=='*')
	{
		i++;
	}
	char *temp;
	temp=new char[10];
	while(buffer[i]!='#')
	{
		temp[j]=buffer[i];
		//cout<<temp<<endl;
		i++;
		j++;
	}
	temp[j]=null;
	s.rno=atoi(temp);
	//cout<<"*"<<s.rno;
	delete[]temp;
}
int main()
{
	int l=12;
	int n;
	cout<<"enter the student record : "<<endl;
	ofstream o;
	o.open("q2.txt");
	int i=0;
	int index[50][2];
	while(1)
	{
		cout<<"enter the roll number (-1 to stop) : ";
		cin>>n;
		if(n!=-1)
		{
			struct student s;
				cout<<"enter the name of student : ";
				cin>>s.name;
				s.rno=n;
				index[i][0]=s.rno;
				index[i][1]=i;
				pack(o,s);
				i++;
		}
		if(n==-1)
		break;
	}
	o.close();
		cout<<"index is .."<<endl;
	cout<<"roll number          rrn "<<endl;
	for(int j=0;j<i;j++)
	{ 
		cout<<index[j][0]<<"                      "<<index[j][1]<<endl;
	}
	n=i;
	ifstream in1;
	in1.open("q2.txt");
	while(1)
	{
	cout<<"enter the relative record number to be searched for .(-1 to terminate)"<<endl;
	int k;
	cin>>k;
	if(k==-1)
	break;
	int f;
	for(i=0;i<n;i++)
	{
		f=0;
		if(index[i][1]==k)
		{
			f=1;break;
		}
	}
	if(f==0)
	cout<<"no student with given rrno.."<<endl;
	else
	{
		in1.seekg(l*index[i][1],ios::beg);
		struct student s;
		unpack(in1,s);
		cout<<"details are : "<<endl;
		cout<<"name :"<<s.name<<"\t"<<"roll number: "<<s.rno<<endl;
	}
}
	in1.close();
	return 0;
}
