//apriory algorithm
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string.h>

using namespace std;

void getfirstc(istream &in,vector<pair<vector<int>,int> > &c)
{
	int imax=0;
	map <int,int>m;
	while(!in.eof()){
		string s;
		getline(in,s);
		//cout<<s<<endl;
		{
			int i;
			for(i=0;i<s.length();++i){
				if(s[i]=='I')
				break;
			}
			int sum=0;
			int j;
			for(j=i;j<s.length();j++){
				if(s[j]=='I'){
					if(sum>imax){
						imax=sum;
					}
					if(m.find(sum)==m.end()){
						m[sum]=0;
					}
					m[sum]++;
					sum=0;
				}
				else if(s[j]>='0'&&s[j]<='9'){
					sum=sum*10+(s[j]-'0');
				}
				else{
					continue;
				}
			}
			if(sum>imax)
			imax=sum;
			if(m.find(sum)==m.end()){
				m[sum]=0;
			}
			m[sum]++;
		}
	}
			for(int i=0;i<=imax;i++){
				int count=0;
				if(m.find(i)==m.end()){
					count=0;
				}
				else{
					count=m[i];
				}
				vector <int>temp;
				temp.push_back(i);
				c.push_back(make_pair(temp,count));
			}
}

void printc(vector<pair<vector<int>,int> >c,int i){
	
	cout<<"Printing C"<<i<<endl;
	
	for(int i=0;i<c.size();i++){
		
		for(int j=0;j<c[i].first.size();j++){
			
			cout<<"I"<<c[i].first[j];
			
			if(j!=c[i].first.size()){
				
				cout<<" ";
			}
		}
		cout<<"    "<<c[i].second<<endl;
	}
}
void printl(vector<pair<vector<int>,int> >c,int i){
	cout<<"Printing L"<<i<<endl;
	
	for(int i=0;i<c.size();i++){
		
		for(int j=0;j<c[i].first.size();j++){
			
			cout<<"I"<<c[i].first[j];
			
			if(j!=c[i].first.size()){
				
				cout<<" ";
			}
		}
		
		cout<<"      "<<c[i].second<<endl;
	}
}

void change(vector<pair<vector<int>,int> >c,vector<pair<vector<int>,int> >&l,int thval){
	
	l.clear();
	for(int i=0;i<c.size();i++){
		
		if(c[i].second>=thval){
			l.push_back(c[i]);
		}
	}
}

bool check(vector<int>v1,vector<int>v2){
	
	if(v1.size()==1)
	return true;
	
	int i=0;int j=0;
	
	while(i<v1.size()-1){
		
		if(v1[i]!=v2[j])
		return false;
		i++;
		j++;
	}
	return true;
}

void join(vector<vector<int> >&v,vector<pair<vector<int>,int> >l){
	v.clear();
	for(int i=0;i<l.size();i++){
		
		vector <int>temp1=l[i].first;
		for(int j=i+1;j<l.size();j++){
			vector<int>temp2=l[j].first;
			if(check(temp1,temp2)){
				
				vector<int>temp3=temp1;
				temp3.push_back(temp2[temp2.size()-1]);
				v.push_back(temp3);
			}
		}
	}	
}

bool find(vector <int>hs,vector <int>n){
	
	for(int i=0;i<n.size();i++){
		int j;
		for(j=0;j<hs.size();j++){
			if(n[i]==hs[j]);
			break;
		}
		if(j==hs.size())
		return false;
	}
	return true;
}

vector<pair<vector<int>,int> > getcount(istream &in,vector<vector<int> >&v){
	vector<pair<vector<int>,int> >c;
	
	for(int i=0;i<v.size();i++){
		c.push_back(make_pair(v[i],0));
	}
	
	while(!in.eof()){
		
		vector<int>temp;
		string s;
		getline(in,s);
		int i;
		for(i=0;i<s.length();i++){
			
			if(s[i]=='I')
			break;
		}
		int sum=0;int j;
		for(j=i;j<s.length();j++){
			
			if(s[j]=='I'){
				//cout<<sum<<endl;
				temp.push_back(sum);
				sum=0;
			}
			else if(s[j]>='0'&&s[j]<='9'){
				sum=sum*10+(s[j]-'0');
			}
			else
			continue;
		}
		temp.push_back(sum);
		for(i=0;i<v.size();i++){
			
			if(find(temp,v[i])){
				c[i].second++;
			}
			//cout<<"i= "<<i<<" "<<c[i].second;
			
		}
//	for(int i=0;i<temp.size();i++)
//	cout<<temp[i]<<" ";
//	cout<<endl;
	}
	
	
	
//	cout<<"hi"<<endl;
	return c;
}

void printv(vector<vector<int> >v,int i){
	cout<<"Printing V"<<i<<endl;
	
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			
			cout<<"I"<<v[i][j];
			if(j!=v[i].size()-1)
			cout<<" ";
		}
		cout<<endl;
	}
}


int main(){
	int thval=4;
	
	ifstream in;
	in.open("t1.txt");
	vector<pair<vector<int>,int> >c,l;
	int rep=1;
	getfirstc(in,c);
	in.close();
	printc(c,rep);
	//cout<<"hello ";
	change(c,l,thval);
	printl(l,rep);
	cout<<"hello ";
	vector<vector<int> >v;
	
	while(l.size()!=0)
	{
		rep++;
		join(v,l);
		if(v.size()==0)
		break;
	//	cout<<"hello";
		printv(v,rep);
		ifstream in1;
		in1.open("t1.txt");
		c=getcount(in1,v);
		in1.close();
		printc(c,rep);
		change(c,l,thval);
		printl(l,rep);
	}
	return 0;
}
