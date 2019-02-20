//pack and unpack functions for variable lenth record
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct stud
{
	char 
	name[100];
	int rno;
}s;
void pack(ostream &fout);
void unpack(ifstream &fin);
int main()
{
	ofstream out;
	out.open("b.txt");
	cout<<"enter the input : "<<endl;
	cout<<"enter the number of students : ";
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	pack(out);
	out.close();
	ifstream in;
	in.open("b.txt");
	struct stud s2[n];

	in.close();
	return 0;
}
void pack(ostream &fout)
{
	char *buffer;
	buffer=new char[100];
	cout<<"enter student name : ";
	cin>>s.name;
	int l1,l2;
	l1=strlen(s.name);
	strcpy(buffer,s.name);
	strcat(buffer,"|");
	cout<<"enter the roll number : ";
	cin>>s.rno;
	char temp[6];
	itoa(s.rno,temp,10);
	strcat(buffer,temp);
	l2=strlen(temp);
	strcat(buffer,"$");
	char b1[100];
	strcpy(b1,buffer);
	fout.write(b1,l2+l1+2);
}
void unpack(istream &fin,stud &s1)
{
	char buffer[30];
	fin.getline(buffer,30,'$');
	strcat(buffer,"@");
	int i=0;
	char *str;
	str=new char[10];
	while(buffer[i]!='|')
	{
	str[i]=buffer[i];
	i++;
	}
	strcpy(s1.name,str);
	delete[]str;
	i++;
	char *temp1;
	temp1=new char [10];int j=0;
	while(buffer[i]!='@')
	{
	temp1[j]=buffer[i];i++;j++;
	}
	s1.rno=atoi(temp1);
	delete[]temp1;
	cout<<s1.name<<s.rno;
}
