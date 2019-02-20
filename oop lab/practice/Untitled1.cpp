#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream fin;
	fin.open("input.txt");
	ofstream fout;
	fout.open("output.txt");
	char ch;
	while(1)
	{
		fin.get(ch);
		if(fin.eof())
		break;
		else
		{
		 if(isupper(ch))
		 ch=tolower(ch);
		 cout<<ch;
		 fout.put(ch);
			
		}
	}
	fin.close();
	fout.close();
	return 0;
}
