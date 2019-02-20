#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main(){
	char ch[100];
	int i=0,s=0;
	ofstream file1;
	file1.open("file.txt");
	cout<<"write in file";
	cin.getline(ch,100);
	file1<<ch<<endl;


	file1.close();
	ifstream infile;
	infile.open("file.txt");
	while(infile){
	
	infile>>ch;
		if(ch==' '){
			if(ch+1==' ')
		i++;}	
	  else if(ch=='.')
	s++;
}
cout<<"words"<<i;
cout<<"/nlines"<<s;

  

}
