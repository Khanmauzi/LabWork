//programme to create pack and unpack function for for a fixed lenth record :
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct stud 
{
	char name[10];
	int rno;
}s;
void pack(ofstream &fout);
struct stud unpack(ifstream &fin);
int main()
{
	ofstream out;
	out.open("a.txt");
	cout<<"enter record : "<<endl;
	cout<<"enter the number of students : ";
	int n,i;
	cin>>n;
	struct stud s2[n];
	for(i=0;i<n;i++)
	pack(out);
	out.close();
	ifstream in;
	in.open("a.txt");
	cout<<"data is : "<<endl;
	for(i=0;i<n;i++)
	{
		s2[i]=unpack(in);
	}
	cout<<"details of student "<<endl;
	cout<<"name          rollno."<<endl;
	for(i=0;i<n;i++)
	{
		
		cout<<s2[i].name<<"     "<<s2[i].rno<<endl;
	}
	in.close();
	return 0;
}
void pack(ofstream &fout)
{
	char *buffer;
	buffer=new char[100];
	cout<<"enter name : ";
	cin>>s.name;
	int l1,l2,i;
	l1=strlen(s.name);
	strcpy(buffer,s.name);
	for(i=l1;i<10;i++)
	buffer[i]='*';
	cout<<"enter roll number : ";
	cin>>s.rno;
	char temp[10];
	itoa(s.rno,temp,10);
	strcat(buffer,temp);
	l2=strlen(temp);
	strcat(buffer,"$");
	char b1[100];
	strcpy(b1,buffer);
	fout.write(b1,11+l2);
}

struct stud unpack(ifstream &fin)
{
	struct stud s1;
	char buffer[30];
	fin.getline(buffer,30,'$');
	strcat(buffer,"@");
	int i=0;
	char *str;
	str=new char[10];
	while(buffer[i]!='*')
	{
		str[i]=buffer[i];
		i++;
	}
   	strcpy(s1.name,str);
   		delete[]str;
   	while(buffer[i]=='*')
   			i++;
	char *temp1;
	temp1=new char[10];
	int j=0;
	while(buffer[i]!='@')
	{
	temp1[j]=buffer[i];i++;j++;
	}
	s1.rno=atoi(temp1);
//	cout<<s1.rno;
	delete[]temp1;
	return s1;
}
