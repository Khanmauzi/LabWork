#include<iostream>
using namespace std;
int main()
{
	int o;
	cout<<"enter the value of m"<<endl;
	cin>>o;
		struct s5
	{
		int m;
		int n;
		
	};
	union s6
	{
		int r;
		char q;
	};
	union s7
	{
		int x;
		float y;
		struct s3 *z;
	};
	struct s1
	{
		struct s1 *l;
		struct s5 k;
		int tag ;
		union s6 j;
	};
	struct s2
	{
		struct s1 *h;
		int g;
		struct s2 *f;
	};
	struct s3
	{
		struct s3 *e;
		struct s2 *f;
	};
	struct s4
	{
		int a;
		struct s2 *c;
		struct s4 *d;
		int flag;
		union s7 b;
	};

	struct s4 *p;
	p=new(s4);
	p->c=new(s2);
	p->c->h=new(s1);
	p->c->h->k.m=o;
	cout<<"value of m is "<<p->c->h->k.m;
	return 0;
}
