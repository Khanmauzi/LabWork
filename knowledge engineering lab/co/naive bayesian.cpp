#include<bits/stdc++.h>
using namespace std;
map<string,int> class_count;
int total;
void gettrdata(vector<map<string,string> > &trdata,vector<string> &trclass,vector<string> &att,vector<vector<string> > &attvalue)
{
	vector<string> temp;
	att.push_back("age");
	attvalue.push_back(temp);
	attvalue[0].push_back("youth");
	attvalue[0].push_back("middle_aged");
	attvalue[0].push_back("senior");
	att.push_back("income");
	attvalue.push_back(temp);
	attvalue[1].push_back("high");
	attvalue[1].push_back("low");
	attvalue[1].push_back("medium");
	att.push_back("student");
	attvalue.push_back(temp);
	attvalue[2].push_back("yes");
	attvalue[2].push_back("no");
	att.push_back("credit_rating");
	attvalue.push_back(temp);
	attvalue[3].push_back("excellent");
	attvalue[3].push_back("fair");
	ifstream fin;
	fin.open("trans.txt");
	string s;
	while(getline(fin,s))
	{
		stringstream ss;ss<<s;
		string t;int i=0;
		map<string,string> m;
		//cout<<"s="<<s<<endl;
		while(ss>>t)
		{
			//cout<<t<<"    ";
			//cout<<"i="<<i<<endl;
			if(i==5)
			{
		//		cout<<"check"<<endl;
				trclass.push_back(t);
			}
			else if(i>0)
				m[att[i-1]]=t;
			i++;
		}
		//cout<<endl;
		trdata.push_back(m);
	}
	fin.close();
}
double getinfo(vector<string> trclass)
{
	if(trclass.size()==0)
	 return 0;
	 	double info_d=0;
	map<string,int> cla;
	double size=trclass.size();
	 for(int i=0;i<trclass.size();i++)
	{
		if(cla.find(trclass[i])==cla.end())
		{
			cla[trclass[i]]=0;
		}
		cla[trclass[i]]++;
	}
	for(map<string,int>::iterator it=cla.begin();it!=cla.end();it++)
	{
		double p=it->second/size;
		if(p!=0)
		info_d+=(p)*(log(p)/log(2));
	}
	info_d=-info_d;
	return info_d;
}
void print1(map<string,string> m)
{
	for(map<string,string>::iterator it=m.begin();it!=m.end();it++)
	{
		cout<<it->first<<"-"<<it->second<<"   ";
	}
	cout<<endl;
}
void getcount(vector<string> trclass)
{
	for(int i=0;i<trclass.size();i++)
	{
		if(class_count.find(trclass[i])==class_count.end())
		{
			class_count[trclass[i]]=0;
		}
		class_count[trclass[i]]++;
	}
	total=trclass.size();
}
double getprob(string attname,string attvalue,vector<map<string,string> > trdata,vector<string> trclass,string clname)
{
	int count=0;
	for(int i=0;i<trdata.size();i++)
	{
		if(trclass[i]==clname&&trdata[i][attname]==attvalue)
		{
			count++;
		}
	}
	return count;
}
void search(vector<map<string,string> > trdata,vector<string> trclass,map<string,string> m)
{
	double imax=INT_MIN;string ans;
	for(map<string,int>::iterator it=class_count.begin();it!=class_count.end();it++)
	{
		double cur=1;
		for(map<string,string>::iterator it2=m.begin();it2!=m.end();it2++)
		{
			cur*=(getprob(it2->first,it2->second,trdata,trclass,it->first)/it->second);
		}
		if(cur>imax)
		{
			imax=cur;ans=it->first;
		}
	}
	cout<<"CLASS IT BELONGS:"<<ans<<endl;
}
int main()
{
	vector<map<string,string> > trdata;
	vector<string> trclass;
	vector<string> att;
	vector<vector<string> > attvalue;
	gettrdata(trdata,trclass,att,attvalue);
	map<string,string> m;
	getcount(trclass);
	m["age"]="middle_aged";
	m["income"]="high";
	m["student"]="no";
	m["credit_rating"]="fair";
	search(trdata,trclass,m);
	return 0;
}
