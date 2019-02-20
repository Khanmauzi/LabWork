#include<iostream>
#include<fstream>
using namespace std;
int main(){
int i=0,s=0;
char ch;
ofstream file1;
file1.open("rem.txt");
file1<<"raju is good.raju is the kathi.raju is nothing like any thing.";
file1.close();
ifstream file2;
file2.open("rem.txt");

while(file2)
{	
file2>>ch;
cout<<ch;
if(ch==' ')
{
	i++;
}

	else if(ch=='.')
{

s++;
}
}
file2.close();
cout<<"lines"<<s-1<<endl;;
cout<<"words"<<i;


}
	
	
	


