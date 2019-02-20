#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char ch;
	cout<<"enter data into the file : "<<endl;
	ofstream fout("abc.txt");
	{
	cin>>ch;
	fout.close();
}
	ifstream fin("abc.txt");
	while(!fin.eof());
	cout<<ch;
	return 0;
}
