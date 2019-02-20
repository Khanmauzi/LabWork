//converting the time into digital military time :
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
string gettime(string s1,string s2)
{
	int n;
	n=s1.length();
	int i;
	char ch[10];
	i=0;
	int j=0;
	while(s1[j]!=':')
	{
		ch[i++]=s1[j++];
	}
	ch[i]=NULL;
	int x;
	x=atoi(ch);
	i=0;
	j=j+1;
	while(j<n)
	ch[i++]=s1[j++];
	ch[i]=NULL;
	int y;
	y=atoi(ch);
	if(s2[0]=='P'||s2[0]=='p'&&x!=12)
	x=x+12;
	if(s2[0]=='A'||s2[0]=='a'&&x==12)
	x=0;
	string s,temp;
	itoa(x/10,ch,10);
	s=s+ch;
	itoa(x%10,ch,10);
	s=s+ch;
	itoa(y/10,ch,10);
	s=s+ch;
	itoa(y%10,ch,10);
	s=s+ch;
	s=s+" hours";
	return s;
}
int main()
{
	string s1,s2,s;
	while(1)
	{
	cout<<"enter the the time if HH:MM AM/PM format : ";
	cin>>s1>>s2;
	if(s2[0]=='x')
	break;
	s=gettime(s1,s2);
	cout<<s<<endl;
	}
}
