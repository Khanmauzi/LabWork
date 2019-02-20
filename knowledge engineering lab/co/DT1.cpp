#include<bits/stdc++.h>
using namespace std;
struct tnode;
typedef tnode *tptr;
struct tnode{
	vector<tptr> child;
	string clname;
	string atname;
	string partname;
};
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
int attribute_selection(vector<map<string,string> > trdata,vector<string> trclass,vector<string> att,vector<vector<string> > attvalue)
{
	double info_d=getinfo(trclass);
	//cout<<"info_d="<<info_d<<endl;
	double size=trdata.size();
	int ans=0;double imax=INT_MIN;
	string s;
	for(int i=0;i<attvalue.size();i++)
	{
	//	cout<<"i="<<i<<endl;
		double info_a=0,gain_a=0;
		for(int j=0;j<attvalue[i].size();j++)
		{
			s=attvalue[i][j];
			vector<string> trc;
			for(int k=0;k<trclass.size();k++)
			{
				if(trdata[k][att[i]]==s)
				{
					trc.push_back(trclass[k]);
				}
			}
			double p=trc.size()/size;
			if(p!=0)
			info_a+=(p*getinfo(trc));
		}
		gain_a=info_d-info_a;
		if(imax<gain_a)
		{
			imax=gain_a;ans=i;
		}
	}
	cout<<"selection="<<att[ans]<<" with ";
	cout<<"gain="<<imax<<endl;
//	PRITNING PART:
/*
	vector<string> curval=attvalue[ans];
	for(int j=0;j<curval.size();j++)
	{
		cout<<"value="<<curval[j]<<endl;
		for(int k=0;k<trdata.size();k++)
		{
			if(trdata[k][att[ans]]==curval[j])
			{
				print1(trdata[k]);
			}
		}
	}
	*/
	return ans;
}
tptr getnode(vector<map<string,string> > &trdata,vector<string> &trclass,vector<string> &att,vector<vector<string> > &attvalue)
{
//	cout<<"FUNCTION STARTS"<<endl;
	tptr t=new tnode();
//	cout<<"size="<<trclass.size()<<endl;
	bool flag=true;string s=trclass[0];
	for(int i=1;i<trclass.size();i++)
	{
		if(trclass[i]!=s)
		{
			flag=false;break;
		}
	}
//	cout<<"check"<<endl;
	if(flag)
	{
	//	cout<<"FLAG"<<endl;
		t->clname=s;return t;
	}
//	if(att.size()=0)
//	{
//cout<<"NOT FLAG CASE"<<endl;
		map<string,int> count;
		for(int i=0;i<trclass.size();i++)
		{
			if(count.find(trclass[i])==count.end())
			{
				count[trclass[i]]=0;
			}
			count[trclass[i]]++;
		}
		int imax=INT_MIN;string smax;
		for(map<string,int>::iterator it=count.begin();it!=count.end();it++)
		{
			if(imax<it->second)
			{
				imax=it->second;smax=it->first;
			}
		}
	//	cout<<"COUNTING COMPLETED"<<endl;
		if(att.size()==0)
		{
			t->clname=smax;return t;
		}
//		cout<<"ATTRIBUTES EXISTS"<<endl;
//	}
	int k=attribute_selection(trdata,trclass,att,attvalue);
	string attname=att[k];
	vector<string> curval=attvalue[k];
	t->atname=att[k];
	att.erase(att.begin()+k);
	attvalue.erase(attvalue.begin()+k);
	tptr tt;
	for(int j=0;j<curval.size();j++)
	{
		s=curval[j];
		//cout<<"s="<<s<<endl;
		vector<map<string,string> > trd;vector<string> trc;
		for(int p=0;p<trdata.size();p++)
		{
			if(s==trdata[p][attname])
			{

				trd.push_back(trdata[p]);
				trc.push_back(trclass[p]);
			}
		}
		if(trc.size()==0)
		{
			tt=new tnode();tt->clname=smax;
		}
		else
		{
			//cout<<"hello"<<endl;
			tt=getnode(trd,trc,att,attvalue);
		//	cout<<"s="<<s<<endl;
			tt->partname=s;
		}
		t->child.push_back(tt);	
	}
	return t;
}
void search(tptr t,map<string,string> m)
{
	if(t->child.size()==0)
	{
		cout<<"CLASS:"<<t->clname<<endl;
	}
	else
	{
		string att_name=t->atname;
		string ans=m[att_name];
		//cout<<att_name<<endl;
		for(int i=0;i<t->child.size();i++)
		{
			if(t->child[i]->partname==ans)
			{
				search(t->child[i],m);return;
			}
		}
	}
}
int main()
{
	vector<map<string,string> > trdata;
	vector<string> trclass;
	vector<string> att;
	vector<vector<string> > attvalue;
	gettrdata(trdata,trclass,att,attvalue);
	tptr t=getnode(trdata,trclass,att,attvalue);
	map<string,string> m;
	m["age"]="senior";
	m["income"]="medium";
	m["student"]="yes";
	m["credit_rating"]="fair";
	search(t,m);
	return 0;
}
