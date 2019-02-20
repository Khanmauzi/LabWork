//to map items with each transaction

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
	fout.open("t3.txt");
	int cnt=0;
	priority_queue <string>q;
	int a[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
		a[i][j]=0;
	}
	//int cnt=0;
	while(!fin.eof()){
		char ch[100];
		fin.getline(ch,100,'\n');
		//cout<<ch<<endl;
		if(!fin.eof())
		{
		int i=0;
		while(i!=100){
			if(ch[i]=='I')
			{
				i++;
				int x=ch[i]-'0';
				a[x][cnt]=1;
			}
			else i++;
		}
		cnt++;}
		
	}
	for(int i=0;i<10;i++){
		cout<<"transactions of item : "<<i<<endl;
			fout<<"transactions of item : "<<i<<endl;
		for(int j=0;j<10;j++){
			if(a[i][j]==1){
				cout<<j<<" ";
				fout<<j<<" ";
			}
		}
		fout<<endl;
		cout<<endl;
	}
	
	return 0;
}

