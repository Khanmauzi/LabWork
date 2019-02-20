//operator overloading
#include<iostream>
#include<fstream>
using namespace std;
struct stud
{
	int roll;
	char name[20];
	float cgpa;
};
ostream & operator<<(ostream & ofile,struct stud s)
{
	ofile<<"roll : "<<s.roll<<" / "<<endl;
	ofile<<"name : "<<s.name<<" / "<<endl;
	ofile<<"cgpa : "<<s.cgpa<<" / "<<endl;
	return ofile;
}
istream& operator>>(istream &ifile,struct stud &s)
{
	char ch;
	ifile>>s.roll;
	ifile>>ch;
	ifile.getline(s.name,20,'/');
	ifile>>s.cgpa;
	return ifile;
}
int main()
{
	struct stud s,s1;
	ofstream of;
	of.open("student.txt");
	cout<<"enter the details "<<endl;
	cout<<"\n roll : ";
	cin>>s.roll;
	cout<<"NAME  : "<<endl;
	cin>>s.name;
	cout<<"cgpa : "<<endl;
	cin>>s.cgpa;
	of<<s;
	of.close();
	ifstream f;
	f.open("student.txt");
	cout<<"roll : "<<s.roll<<endl;
	cout<<"name :"<<s.name<<endl;
	cout<<"cgpa :"<<s.cgpa<<endl;
	return 0;
}
