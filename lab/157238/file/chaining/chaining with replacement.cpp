//chaining with replacement : 
#include<iostream>
using namespace std;
int func(int d)
{
	return d%10;
}
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void create(int arr[][2],int n,int d)
{
	int flag=0;int k=func(d);int prev=1000;int prev1=1000;int i;
	if(arr[k][0]==0)
	{
		arr[k][0]=d;
		flag=1;
	}
	else
	{
		int t=arr[k][0];
		if(func(t)==func(d))
		{
			prev=k;
			if(arr[k][1]==-1)
			k=(k+1)%n;
			else 
			k=arr[k][1];
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(arr[i][10]==k)
				prev=i;
			}
			if(arr[k][1]!=-1)
			prev1=arr[k][1];
			arr[k][0]=d;d=t;
			arr[k][1]=-1;
			k=func(d);
		}
	}
	while(flag==0)
	{
		if(arr[k][0]==0)
		{
			arr[k][0]=d;
			flag=1;
			if(prev!=1000)
			{
				arr[prev][1]=k;
			}
		}
		else
		{
			int t=arr[k][0];
			if(func(t)==func(d))
			{
				if(arr[k][1]==-1)
				{
					prev=k;
					k=(k+1)%n;
				}
				else
				{
					prev=k;
					k=arr[k][1];
				}
			}
			else
			k=(k+1)%n;
		}
	}
}
/*int search(int arr[][2],int d,int n)
{
	int k=func(d);
	int f=-1;
	while(true)
	{
		if(arr[k][0]==0)
		{
			break;
		}
		else
		{
			if(arr[k][0]==d)
			{
				f=k;
				break;
			}
			else
			{
				int temp=arr[k][0];
				if(func(temp)==func(d))
				{
					if(arr[k][1]==-1)
					{
						break;
					}
					else
					{
						k=arr[k][1];
					}
				}
			}
		}
	}
	return f;
}*/
int search2(int arr[][2],int d,int n)
{
	int f=-1;
	int k=func(d);
	int t=arr[k][0];
	if(t==0)
	{
		return f;
	}
	if(t==d)
	{
		f=k;
		return f;
	}
	if(func(t)!=func(d))
	{
		return f;
	}
	while(true)
	{
		k=arr[k][1];
		if(k==-1)
		{
			return f;
		}
		t=arr[k][0];
		if(t==d)
		{
			f=k;
			return f;
		}
	}
}
int main()
{
	int n;
	cout<<"enter the size : ";
	cin>>n;
	int i;
	int arr[10][2];
	for(i=0;i<10;i++)
	{
		arr[i][1]=-1;
		arr[i][0]=0;
	}
	int d;
	int cnt=0;
	while(1)
	{
		cout<<"enter the key (-1 to terminate ) ";
		cin>>d;
		if(d==-1)
		break;
		if(cnt==n)
		cout<<"overflow "<<endl;
		if(cnt!=n)
		create(arr,n,d);
		cnt++;
	}
	cout<<"chain file is : "<<endl;
	cout<<" key                         chain "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<arr[i][0]<<"            "<<arr[i][1]<<endl;
	}
	cout<<"enter the element to search : ";
	cin>>d;
	int f;
	f=search2(arr,d,n);
	if(f==-1)
	cout<<"element not found : "<<endl;
	else 
	cout<<"element found at element  "<<f<<endl;
	return 0;
}
