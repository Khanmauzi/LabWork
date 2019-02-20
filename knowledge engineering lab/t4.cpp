#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;
int main(){
	ifstream fin;
	fin.open("t2.txt");
	ofstream fout;
	fout.open("t4.txt");
	int k=4;     				//threshold frequency
	while(!fin.eof()){
		char ch[20];
		string s="I";
		fin.getline(ch,20,'\n');
		if(!fin.eof()){
			int i=1;
			char temp;
			temp=ch[i++];
			s=s+temp;
			//cout<<s;
			char num[10];
			while((ch[i]-'0')<0||(ch[i]-'0')>9)
			i++;
		//	cout<<i<<" ";
			int j=0;
			while((ch[i]-'0')>0&&(ch[i]-'0')<=9)
			num[j++]=ch[i++];
			int n;
			n=atoi(num);
		//	cout<<n<<" ";
			if(n>=k)
			fout<<s<<"  : "<<n<<endl;
			
		}
	}
	fout.close();
	fin.close(); 
	return 0;
}

