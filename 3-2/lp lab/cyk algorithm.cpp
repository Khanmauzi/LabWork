// CYK ALGORITHM IMPLEMENTATION
/*
	NAME : MOJAMMIL	
	CLASS : III YEAR, CSE
	ROLL : 157238
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>


using namespace std;
struct production{
	string ch;
	string s;
	
};


void display(vector<production>v){
	cout<<"Productions rule are : "<<endl;
	for(int i=0;i<v.size();i++){
		production p=v[i];
		cout<<p.ch<<"      "<<p.s<<endl;
	}
}


string getdata(string base[],vector<production>v,int j){
	string s="";
	for(int i=0;i<v.size();i++){
		production p=v[i];
		if(p.s==base[j]){
			s=s+p.ch;
		}
		
	}
	if(s==""){
		s=s+"^";
	}
	return s;
	
}

string getdata(string s1,string s2,vector<production){
	
	for(int i=0;i<s1.length();i++){
		for(int j=0;j<s2.length();j++)
	}
	
	
}



int main(){
	vector<production>v;
	while(1){
		string ch;
		string s;
		cout<<"Enter starting production : (. to stop)";
		cin>>ch;
		if(ch==".")
		break;
		cout<<"Enter the production (^ for null production): ";
		cin>>s;
		production p;
		p.ch=ch;
		p.s=s;
		v.push_back(p);
	}
	display(v);
	
	string l;
	cout<<"enter the language : ";
	cin>>l;
	int n=l.length();
	string base[n];
	for(int i=0;i<n;i++){
		base[i]=l[i];
	}
	string a[n][n];
	int cnt=0;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<n-cnt;j++){
			if(i==n-1){
				string s=getdata(base,v,j);
				a[i][j]=s;
			
			}
			else if(i==n-2){
				string s=getdata1(a[i+1][j],a[i+1][j+1],v);
				a[i][j]=s;
			}
		}
		cnt++;
	}
	
	
	/*for(int i=n-1;i>=0;i--){
		for(int j=0;j<n-cnt;j++){
			if(i==n-1){
			
				cout<<a[i][j]<<" ";
			
			}
			else break;
		}
	}*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
