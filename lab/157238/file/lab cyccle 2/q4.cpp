//search using name;
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#define null NULL
using namespace std;
struct stud
{
	int rno;
	char name[10];
};
struct array
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
	int l=strlen(temp)+strlen(s.name)+2;
	o.write(buffer,l);
}
void unpack(istream &i1, stud &s)
{
	char *buffer;
	buffer=new char[100];
	i1.getline(buffer,100,'#');
	strcat(buffer,"#");
	int i=0;int j=0;
	while(buffer[i]!='|')
	{
		s.name[j]=buffer[i];
		i++;
		j++;
	}
	s.name[j]=null;
	i++;
	char *temp;
	temp=new char[10];
	j=0;
	while(buffer[i]!='#')
	{
		temp[j]=buffer[i];
		i++;
		j++;
	}
	temp[j]=null;
	s.rno=atoi(temp);
}
int search(array b[][2],char k[],int n)
{
	//cout<<k<<endl;
	int f=0;int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(b[i][0].name,k)==0)
		{
			f=1;
			break;
		}
	}
	if(f==0)
	return -1;
	else return i;
}
int main()
{
	ofstream o;
	o.open("q4.txt");
	int n;
	cout<<"enter the number of students..."<<endl;
	cin>>n;
	int a[n][2];
	struct array b[n][2];
	int i,j;
	for(i=0;i<n;i++)
	{
		a[i][1]=o.tellp();
		cout<<"enter the detail of "<<i+1<<" student "<<endl;
		struct stud s;
		cout<<"enter the name ..";
		cin>>s.name;
		cout<<"enter the roll numnber..";
		cin>>s.rno;
		a[i][0]=s.rno;
		strcpy(b[i][0].name,s.name);
		b[i][1].rno=s.rno;
		pack(o,s);
	}
	o.close();
	cout<<"primary file is ..."<<endl;
	cout<<"roll num.         offset "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i][0]<<"               "<<a[i][1]<<endl;
	}
	cout<<"secondary file is .."<<endl;
	cout<<"name               roll num "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<b[i][0].name<<"               "<<b[i][1].rno<<endl;
	}
	ifstream in;
	in.open("q4.txt");
	char k[10];
	cout<<"enter the name to be search for..(. to terminate)"<<endl;
	cin>>k;
//	cout<<k;
	int f;
	f=search(b,k,n);
//	cout<<f;
	if(f==-1)
	{
		cout<<"enter student record is not found "<<endl;
	}
	else
	{
		int temp,tempoff;
		temp=b[f][1].rno;
		for(i=0;i<n;i++)
		{
			if(temp==a[i][0])
			{
				break;
			}
		}
	
	tempoff=a[i][1];
//	cout<<"#@$%4"<<endl;
	in.seekg(tempoff,ios::beg);
//	cout<<"$#@%@#4"<<endl;
	struct stud s;
//	cout<<"####"<<endl;
	unpack(in,s);
	//cout<<"$#%$#^"<<endl;
	cout<<"details of student is "<<endl;
	int l=strlen(s.name);
	cout<<"name : ";
	for(i=0;i<l;i++)
	{
		if(s.name[i]>='a'&&s.name[i]<='z')
		cout<<s.name[i];
	}
	cout<<endl;
	cout<<"roll number .."<<s.rno;
	}

in.close();
return 0;
}
