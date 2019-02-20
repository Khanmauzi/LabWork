//extendible hashing insertion
#include<iostream>
#include<math.h>
using namespace std;
int maxkey=2;
struct bucket
{
	int key[2];
	int count=0;int d1;
};
typedef bucket *bptr;
/*void hash(int k)
{
	
}*/
int extract(int k,int d)
{
	int l=0;
	int a[10];
	while(k!=0)
	{
		a[l++]=k%2;k++;
	}
	l--;
	int sum=0;
	for(int i=0;i<d;i++)
	{
		sum=sum+a[l--]*pow(2,i);
	}
	return sum;
}
void expanddir(bptr hash[],int &d)
{
	int i;
	for(i=pow(2,d)-1;i>=0;i--)
	{
		hash[2*i+1]=hash[i];
		hash[2*i]=hash[i];
	}
	d=d+1;
}
void split(bptr &ob,bptr &nb,int &td)
{
	nb=new bucket;
	nb->count=0;
	nb->d1=td;
	int data[10];
	int l=ob->count;
	int i;
	for(i=0;i<l;i++)
	{
		data[i]=ob->key[i];
	}
	ob->count=0;
	for(i=0;i<l;i++)
	{
		int t1=extract(data[i],td+1);
		if(t1==1)
		{
			nb->key[nb->count++]=data[i];
		}
		else
		{
			ob->key[ob->count++]=data[i];
		}
	}
	td=td+1;
	ob->d1=td;
	nb->d1=td;
}
void add(bptr hash[],int k,int &d)
{
	int h=k;
	int index=extract(h,d);
	int valid=0;
	int t=hash[index]->count;
	if(t<maxkey)
	{
		hash[index]->key[t]=k;
		hash[index]->count++;
		valid=1;
	}
	if(valid==0)
	{
		int td=hash[index]->d1;
		if(td==d)
		{
			expanddir(hash,d);
		}
		int first,last;
		first=pow(2,d-td)*extract(h,d);
		last=first+pow(2,d-td)-1;
		bptr nb,ob=hash[index];
		split(ob,nb,td);
		first=first+(last-first+1)/2;
		for(int i=first;i<=last;i++)
		{
			hash[i]=nb;
		}
		add(hash,k,d);
	}
}
void print(bptr hash[],int d)
{
	int i,j;
	for(i=0;i<pow(2,d);i++)
	{
		bptr b=hash[i];
		if(b!=NULL)
		{
			cout<<"bucket -"<<i<<" : ";
			for(j=0;j<b->count;j++)
			{
				cout<<b->key[i]<<"  ";
			}
			cout<<endl;
		}
	}
}
int main()
{
	int d=1;
	bptr hash[16];
	for(int i=0;i<16;i++)
	{
		hash[i]==NULL;
	}
	bptr b=new bucket;
	b->count=0;b->d1=0;
	hash[0]=b;
	hash[1]=b;
	int k;
	while(1)
	{
		cout<<"enter the data (-1 to terminate ) ";
		cin>>k;
		if(k==-1)
		break;
		add(hash,k,d);
	}
	cout<<"hash file is : "<<endl;
	print(hash,d);
	return 0;
}
