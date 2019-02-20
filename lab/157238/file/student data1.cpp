#include<iostream>
#include<fstream>
#include<cstring>
#include<stdio.h>
using namespace std;
struct student
{
	int roll;
	float cgpa;
};
int main()
{
	student s[20];
		for(int i=0;i<5;i++)
		{
		s[i].roll=i+1;
		s[i].cgpa=i+4;
        }
	ifstream fin;
	ofstream fout;
	fout.open("oldsturec.txt");
	for(int i=0;i<5;i++)
	{
		fout<<"roll: "<<s[i].roll<<endl;
		fout<<"cgpa: "<<s[i].cgpa<<endl;
	}
	cout<<"enter the details of new student : "<<endl;
	cout<<"enter roll number : ";
	cin>>s[5].roll;
	cout<<"enter cgpa : ";
	cin>>s[5].cgpa;
	fout<<"roll : "<<s[5].roll<<endl;
	fout<<"cgpa : "<<s[5].cgpa<<'*';
	fout.close();
	fin.open("oldsturec.txt");
	fout.open("newsturec.txt");
	int p=0;
	char ch;
	string line;
	while(!fin.eof())
	{
		getline(fin,line,'*');
		if(fin.eof())break;
		if(p!=2)
		fout<<line<<'*';
		p++;
	}
	fin.close();
	fout.close();
	remove("oldsturec.txt");
	rename("oldsturec.txt","newsturec.txt");
	return 0;
}
