//primary index file
#define null NULL
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
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
	char *temp;
	temp=new char[10];
	itoa(s.rno,temp,10);
	int l2;
	strcat(buffer,temp);
	
//	strcpy(b,buffer);
	int l;
	l2=strlen(temp);
	for(int i=l1+l2;i<20;i++)
	buffer[i]='*';
	buffer[i]='\0';
	strcat(buffer,"#");
	l=21;
//	cout<<buffer;
	o.write(buffer,l);
	
}
void unpack(istream &i1,student &s)
{
	char *buffer;
	buffer=new char[100];
	i1.getline(buffer,100,'#');
//	cout<<buffer<<endl;
	strcat(buffer,"#");
	int i=0;int j=0;
	while(buffer[i]!='*')
	{
		s.name[j]=buffer[i];
	    i++;j++;
	}
	while(buffer[i]=='*')
	i++;
	s.name[j]=null;
//	cout<<s.name<<"and"<<endl;
	j=0;
	char *temp;
	temp=new char[10];
	while(buffer[i]!='#')
	{
		temp[j]=buffer[i];
		i++;
		j++;
	}
	temp[j]=null;
	s.rno=atoi(temp);
//	cout<<s.rno<<" @@@@";
	delete[] temp;
}
void search(int index[][2],istream &i1,int k)
{
	int i=0,l=12;
	for(i=0;index[i][0]!=k;i++);
	int temp;
	temp=index[i][1]*l;
	i1.seekg(temp,ios::beg);
	struct student s;
	unpack(i1,s);
	cout<<"name :"<<s.name<<endl;
	cout<<"roll number : "<<s.rno<<endl;
}
//int index[50][2];
/*void add(int i,ofstream o)
{
	//	ofstream o;
//	o.open("index1.txt",ios::app);
			struct stud s;
		cout<<"enter the name of the student : ";
		cin>>s.name;
		cout<<"enter the roll number of student : ";
		cin>>s.rno;
	 	index[i][2]=s.rno;
		index[i][1]=o.tellp();
		cout<<o.tellp();
		pack(o,s);
}*/
int main()  
{
	int n;
	char ch='y';
	cout<<"enter the number of student you want : ";
	cin>>n;
	int j;
	int index[50][2];
	ofstream o;
	o.open("index2.txt");
	cout<<"enter the student record : "<<endl;
	 int i;

	for(i=0;i<n;i++)
	{
		struct student s;
		cout<<"enter the name of the student : ";
		cin>>s.name;
		cout<<"enter the roll number of student : ";
		cin>>s.rno;
		index[i][0]=s.rno;
		index[i][1]=i;
		pack(o,s);
	}
	o.close();
	cout<<"index file is : "<<endl;
	for(i=0;i<n;i++)
	cout<<index[i][0]<<"	"<<index[i][1]<<endl;			//printing index file
	ifstream i1;
	i1.open("index2.txt");
	while(1)
	{
	cout<<"enter the roll number to be searched for : ";
	int k;
	cin>>k;
	search(index,i1,k);
	cout<<"want to search more ..(y/n): ";
	cin>>ch;
	if(ch=='n'||ch=='N')
	break;
	}
	i1.close();
	return 0;

}
