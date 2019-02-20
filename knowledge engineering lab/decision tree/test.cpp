//test

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){
	string name;
	cin>>name;
	int l=name.length();
	char s[l];
	for(int i=0;i<l;i++){
		s[i]=name[i];
	}
	s[l]=' ';
	//cin>>s;
	//s=s+".txt";
	cout<<s<<endl;
	ofstream fout;
	fout.open(s);
	ifstream fin;
	fin.open("data.txt");
	while(!fin.eof()){
		string s;
		getline(fin,s);
		fout<<s<<endl;
	}
	fin.close();
	fout.close();
	double x;
	x=5;
	cout<<x;
	
}
