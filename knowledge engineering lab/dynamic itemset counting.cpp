#include<bits/stdc++.h>
using namespace std;
map<vector<int>,pair<int,int> > ss,sc,ds,dc;
vector<int> one;
void getfirstc(istream &in)
{
	int imax=0;
	while(!in.eof())
	{
		string s;
		getline(in,s);
		int i=0;
		while(s[i]){
			int k=0;
			if(s[i]=='I'){
				i=i+1;
				while(s[i]>='0'&&s[i]<='9'){
					k=k*10+s[i]-'0';
					i++;
				}
				vector<int>t;
				t.push_back(k);
				if(dc.find(t)==dc.end()){
					dc[t]=make_pair(0,0);
					one.push_back(k);
				}
			}
			else i++;
		}
		
	}
}
void getcurt(istream &in,int p,vector<vector<int> > &curt)
{
	curt.clear();
	for(int i=0;i<p;i++)
	{
		vector<int> temp;
		string s;
		getline(in,s);
		int j=0;
		while(s[j]){
			if(s[j]=='I'){
			j++;
			int k=0;
			while(s[j]>='0'&&s[j]<='9'){
				k=k*10+s[j]-'0';
				j++;
			}
			temp.push_back(k);
		}
		else j++;
		}
		curt.push_back(temp);
	}
}
void print(map<vector<int>,pair<int,int> > m)
{
	//cout<<"printing new map:"<<endl;
	for(map<vector<int>,pair<int,int> >::iterator it=m.begin();it!=m.end();it++)
	{
		vector<int> temp=it->first;
		for(int i=0;i<temp.size();i++)
		{
			cout<<"I"<<temp[i];
			if(i!=temp.size()-1)
			{
				cout<<",";
			}
		}
		cout<<"     ";
		cout<<it->second.first<<"   "<<it->second.second;
		cout<<endl;
	}
	cout<<endl<<endl;
}
void fileprint(map<vector<int>,pair<int,int> > m)
{
	//cout<<"printing new map:"<<endl;
	ofstream out;
	out.open("dynoutput.txt");
	for(map<vector<int>,pair<int,int> >::iterator it=m.begin();it!=m.end();it++)
	{
		vector<int> temp=it->first;
		for(int i=0;i<temp.size();i++)
		{
			out<<"I"<<temp[i];
			if(i!=temp.size()-1)
			{
				out<<",";
			}
		}
		out<<"     ";
		out<<it->second.first;
		//<<"   "<<it->second.second;
		out<<endl;
	}
	cout<<endl<<endl;
}
void printv(vector<int> one)
{
	cout<<"PRINTING ONE:";
	for(int i=0;i<one.size();i++)
	{
		cout<<one[i]<<" ";
	}
	cout<<endl;
}
void display(vector<vector<int> >v){
	for(int i=0;i<v.size();i++){
		vector<int> temp;
		temp=v[i];
		vector<int>::iterator it;
		for(it=temp.begin();it!=temp.end();it++){
			cout<<"I"<<*it<<"  , ";
		}
		cout<<endl;
	}
}
int main()
{
	int p=3;int cur=0;int thre=2;int len=9;
	vector<vector<int> > curt;
	ifstream in;in.open("trans.txt");
	getfirstc(in);
	sort(one.begin(),one.end());
	printv(one);
	int c=0;
//	cout<<"hello "<<endl;
	cout<<"PRINTING INITIAL DC:"<<endl;
	print(dc);
	while(ds.size()!=0||dc.size()!=0)
	{
		cout<<"ITERATION "<<c<<"STARTS"<<endl;
		if(cur==0)
		{
			in.close();	
			c++;			//one complete scanning is over , now go for next scan
			in.open("trans.txt");
		}
		cur=(cur+p)%len;			// to know which partition executing
		getcurt(in,p,curt);
	//	cout<<"printing curt : "<<endl;
		//display(curt);
		for(int i=0;i<curt.size();i++)										// to find all the super super set
		{
			vector<int> here=curt[i];
			int l=here.size();
			for(int j=1;j<pow(2,l);j++)
			{
				vector<int> temp;
				for(int k=0;k<l;k++)
				{
					if(j>>k & 1)
					{
						temp.push_back(here[k]);
					//	cout<<"i : "<<i<<" j: "<<j<<"  k : "<<k<<"  "<<here[k]<<endl;
					}
				}
				if(ds.find(temp)!=ds.end())
				{
					ds[temp].first++;
				}
				if(dc.find(temp)!=dc.end())
				{
					dc[temp].first++;
				}
			}
		}
		map<vector<int>,pair<int,int> > t=dc;
		vector<vector<int> > add;
	//	print(ds);
		//print(dc);
		for(map<vector<int>,pair<int,int> >::iterator it=dc.begin();it!=dc.end();it++)
		{
			if(it->second.first>=thre)
			{
				ds[it->first]=it->second;
			//	cout<<"inserting the item set:";
			//	printv(it->first);
				t.erase(it->first);
				vector<int> super=it->first;int flag=0,flag2=1,flag3;
				vector<int> supert;
				for(int i=0;i<one.size();i++)
				{
					flag3=0;
					for(int j=0;j<super.size();j++)
					{
						if(one[i]==super[j])
						{
							flag3=1;break;
						}
					}
					if(flag3) continue;
					supert=super;supert.push_back(one[i]);
					int l=supert.size();flag=0;
				//	cout<<"subsets start:"<<endl;
					for(int j=1;j<pow(2,l)-1;j++)
					{
						vector<int> temp;
						for(int k=0;k<l;k++)
						{
							if(j>>k & 1)
							{
								temp.push_back(supert[k]);
							}
						}
					//	printv(temp);
						if(ds.find(temp)!=ds.end())
						{
							flag=1;
						}
						else if(ss.find(temp)!=ss.end())
						{
							flag=1;
						}
						if(flag==0)
						{
							flag2=0;
							break;
						}
					}
				//	cout<<"subsets end"<<endl;
					if(flag2)
					{
						//ds[supert]=make_pair(0,0);
						add.push_back(supert);
					}
					
				}
			}
		}
		dc=t;
		for(map<vector<int>,pair<int,int> >::iterator it=dc.begin();it!=dc.end();it++)
		{
			int k=it->second.second;
			k+=p;
			if(k>=len)
			{
				sc[it->first]=it->second;
				sc[it->first].second+=p;
				t.erase(it->first);
			}
			else
			{
				t[it->first].second+=p;
			}
		}
		dc=t;
		t=ds;
		for(map<vector<int>,pair<int,int> >::iterator it=ds.begin();it!=ds.end();it++)
		{
			int k=it->second.second;
			k+=p;
			if(k>=len)
			{
				ss[it->first]=it->second;
				ss[it->first].second+=p;
				t.erase(it->first);
			}
			else
			{
				t[it->first].second+=p;
			}
		}
		for(int i=0;i<add.size();i++)
		{
			dc[add[i]]=make_pair(0,0);
		}
		ds=t;
		cout<<"AFTER ITERATION:"<<c<<endl;
	//	c++;
		cout<<"PRINTING SS:"<<endl;
		print(ss);
		cout<<"PRINTING SC:"<<endl;
		print(sc);
		cout<<"PRINTING DS:"<<endl;
		print(ds);
		cout<<"PRINTING DC:"<<endl;
		print(dc);
	}
	cout<<"FINAL ANSWER IS :"<<endl;
	print(ss);
	cout<<"EXECUTED SUCCESSFULLY"<<endl;
	fileprint(ss);
}
