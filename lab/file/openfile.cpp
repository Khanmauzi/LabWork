#include<iostream>
#include<fstream>
using namespace std;
int main(){
	char ch[100];
	
	ofstream file1;
	file1.open("afile.txt");
	cout<<"write in file";
	cin.getline(ch,100);
	file1<<ch<<endl;
	cout<<"enter age";  
	cin>>ch;
	cin.ignore();
	file1<<ch<<endl;    
	file1.close();
	ifstream infile;
	infile.open("afile.txt");
	infile>>ch;
	cout<<ch<<endl;
	infile>>ch;
	cout<<ch<<endl;
	infile.close();
	return 0;
	
	
}
