/*
	decision tree to find the buyers who buys laptop
	fout<<"RID age income student credit rating Class: buys computer"<<endl;
	fout<<"1 @youth #high $no %fair ^no"<<endl;

	@:age
	#:income
	$:student or not
	%:credit rating
	^: buys laptop or not.
*/

#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <math.h>
#include <iterator>
#define null NULL
using namespace std;



struct node{
	string clas;
	vector <node*> child;
};

int yes=0;
int no=0;
double getinfo(double yes,double no){
	double temp=0;
//	cout<<log(double(9)/double(14))
	temp=-(double(yes)/(double(yes+no))*(log(double(yes)/double(yes+no))/log(2)))-((double(no)/double((yes+no)))*(log(double(no)/double(yes+no))/log(2)));
//	cout<<temp<<" ";
	return temp;
}

double getinfoat(ifstream &fin,char ch,char temp[]){
	fin.open(temp);
	double y=0;
	double n=0;
	double t=0;
	double info=0;
	while(!fin.eof()){
		string s;
		getline(fin,s);
		int i=0;
		while(s[i])
		
	}
}
char getatt(ifstream &fin,vector<char>&att,char temp[]){
	double d=getinfo(yes,no);
	cout<<d<<" ";
	vector<char>::iterator it;
	vector<double>temp1;
	for(it=att.begin();it!=att.end();it++){
		char ch=*it;
		//double temp=getinfoat(fin,ch,temp);
	}
	return ' ';
}


bool check(ifstream &fin,char temp[]){
	int y=0;
	int n=0;
	fin.open(temp);
	while(!fin.eof()){
		string s;
		getline(fin,s);
		int i=0;
		//cout<<s<<endl;
		while(s[i]){
			while(s[i]!='^')
				i++;
			i++;
			if(s[i]=='n')
				n++;
			else if(s[i]=='y')
				y++; 
			break;
		}
	}
	fin.close();
//	cout<<y<<" "<<n<<endl;
	if(y>0&&n>0)
	return false;
	else return true;
}

node *gettree(ifstream &fin, node *t,vector<char>&att){
	bool flag;
	int l=t->clas.length();
	char temp[l];
	for(int i=0;i<l;i++){
		temp[i]=t->clas[i];
	}
	
	temp[l]=' ';
//	cout<<temp;
	flag=check(fin,temp);
	/*if(flag==true){
		cout<<"all belong to same class"<<endl;
	}
	else{
		cout<<"all belong to diff class "<<endl;
	}*/
	if(flag){
		return t;
	}
	else{
		char ch=getatt(fin,att,temp);
	}
}
void getbuy(ifstream &fin){
	while(!fin.eof()){
		string s;
		getline(fin,s);
	//	cout<<s<<endl;
		int i=0;
		while(s[i]){
			while(s[i]!='^')
				i++;
			i++;
			if(s[i]=='n')
				no++;
			else if(s[i]=='y')
				yes++; 
			break;
		}
	}
}
int main(){
	ifstream fin;
	fin.open("data.txt");
	getbuy(fin);
	fin.close();
	//cout<<yes<<"  "<<no<<endl;
	node *t;
	t=null;
	t=new(node);
	t->clas="data.txt";
	t->child.push_back(null);
	vector<char>c;
	c.push_back('@');
	c.push_back('#');
	c.push_back('$');
	c.push_back('%');
	t=gettree(fin,t,c);
}
