#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <utility>
using namespace std;
struct t5{
	string s;
	string s1;
};
int main(){
	ifstream fin;
	fin.open("t4.txt");
	ofstream fout;
	fout.open("t5.txt");
	vector <int>v;
	while(!fin.eof()){
		char ch[20];
		fin.getline(ch,20,'\n');
		if(!fin.eof()){
			char t=ch[1];
			int n=int(t)-48;
			v.push_back(n);
		}
	}
	int size=v.size();
	size=(size-1)*size/2;
//	cout<<size<<endl;
	struct t5 t[size];
	
	int cnt=0;
	vector <int> ::reverse_iterator it;
	for(it=v.rbegin();it!=v.rend();++it)
	{
		vector <int> ::reverse_iterator it1;
	
		for(it1=it+1;it1!=v.rend();++it1){
			string s="I";
			string s1="I";
			int n;
			char ch[10];
			itoa(*it,ch,10);
			s=s+ch;
			itoa(*it1,ch,10);
			s1=s1+ch;
		//	m.pair()
			//cout<<s<<" "<<s1<<endl;
			t[cnt].s=s;
			t[cnt++].s1=s1;
			fout<<"{ "<<s<<"  ,  "<<s1<<" }"<<endl;
			//cnt++;
		}
	}
	/*for(int i=0;i<size;++i){
		cout<<t[i].s<<"  "<<t[i].s1<<endl;
	}*/
	fin.close();
	fout.close();
	fin.open("t1.txt");
	fout.open("c5.txt");
	int a[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;++j)
		a[i][j]=-1;
	}
	cnt=0;
	//cout<<"hello "<<endl;
	while(!fin.eof()){
		char ch[100];
		fin.getline(ch,100,'\n');
		if(!fin.eof()){
			int i=0;
		//	cout<<i<<" ";
			while(i<100){
				//cout<<ch[i]<<endl;
				if(ch[i]=='I'){
				i++;
				int x=ch[i]-'0';
				a[cnt][x]=1;}
				else
				i++;
			}
		}
		cnt++;
	}
	cnt=cnt-1;
/*	for(int i=0;i<cnt;i++){
		for(int j=0;j<10;++j)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}*/
	int f[size];
	ofstream fout1;
	fout1.open("l5.txt");
	int th=5;
	for(int i=0;i<size;++i){
		char ch1=t[i].s[1];
		char ch2=t[i].s1[1];
		int n1,n2;
		n1=ch1-'0';
		n2=ch2-'0';
		int cnt1=0;
		for(int j=0;j<cnt;++j){
			if(a[j][n1]==1&&a[j][n2]==1)
			cnt1++;
		}
		fout<<" { "<<t[i].s<<" , "<<t[i].s1<<" }  "<<cnt1<<endl;
		f[i]=cnt1;
		if(f[i]>=th)
		fout1<<" { "<<t[i].s<<" , "<<t[i].s1<<" }  "<<f[i]<<endl;
	}	
	fin.close();
	fout.close();
	fout1.close();
	fout.open("t6.txt");
	//cout<<cnt;
	return 0;
	
}
