// to count the frequency of each transacton

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <queue>
using namespace std;
int main(){
	ifstream fin;
	fin.open("t1.txt");
	ofstream fout;
	fout.open("t2.txt");
	int cnt=0;
	priority_queue <string>q;
	while(!fin.eof()){
		char ch;
		fin>>ch;
		string s="I";
		if(ch=='I'){
			fin>>ch;
			s=s+ch;
			q.push(s);
		//	cout<<s<<endl;
		//	cnt++;
		}
	}
	while(!q.empty()){
		string t1;
		t1=q.top();
		int cnt=1;
		q.pop();
		while(q.top()==t1&&!q.empty()){
			cnt++;
			q.pop();
		}
		cout<<t1<<" : "<<cnt<<endl;
		fout<<t1<<" : "<<cnt<<endl;
		
	}
//	cout<<cnt;
	return 0;
}

