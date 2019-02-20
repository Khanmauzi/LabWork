#include<iostream>
using namespace std;
int main()
{
		union contact
	{
		int security;
		char mobile[10];
	};
	struct std
	{
		int rno;
		char name[20];
		int tag;
		union contact x;
		float cgpa;
	};

	int n,i;
	cout<<"enter the number of student : ";
	cin>>n;
	struct std s[n];
	cout<<"enter the student data : "<<endl;
	for(i=0;i<n;i++)
	{
		int m;
		cout<<"enter the roll number : "<<endl;
		cin>>s[i].rno;
		cout<<"enter the student name : "<<endl;
		cin>>s[i].name;
		cout<<"enter contact informaiton : for security number press 1 for mobile number press 2"<<endl;
		cin>>m;
		s[i].tag=m;
		if(m==1)
		cin>>s[i].x.security;
		else
		cin>>s[i].x.mobile;
		cout<<"enter cgpa : ";
		cin>>s[i].cgpa;
	}
	cout<<"student data is : "<<endl;
	cout<<"r.no"<<"\t"<<"name"<<"    "<<" contact    "<<"   "<<" cgpa"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<s[i].rno<<"\t"<<s[i].name<<"\t";
		if(s[i].tag==1)
		cout<<s[i].x.security<<"\t"<<"\t";
		else
		cout<<s[i].x.mobile<<"\t";
		cout<<s[i].cgpa;
		cout<<endl;
	}
	return 0;
}
