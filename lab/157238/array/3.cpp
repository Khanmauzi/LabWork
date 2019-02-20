#include<iostream>
using namespace std;
int main()
{
	char a[100],b[100];
	cout<<"enter the first string : ";
	gets(a);
	cout<<"first string is : "<<endl;
	puts(a);
	cout<<endl;
	cout<<"enter the second string : "<<endl;
	gets(b);
	int i,j,l,m;
	for(i=0;a[i]!='\0';i++);
	for(j=0;b[j]!='\0';j++)
	m=j;


		j=0;
		for(i=0;a[i]!='\0'&&b[j]!='\0';i++)
		{
			if(b[j]==a[i])
			j++;
		}
		if(j==m+1)
	cout<<"strings can be formed : .";
	else cout<<"stirng can not be formed :";
	return 0;
	
}
