#include<iostream>
using namespace std;
void f(int a[],int n,int y);
int main()
{
	int n;
	cout<<"enter the number of elements u want :";
	cin>>n;
	int a[n];
	cout<<"enter the elements of array : "<<endl;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	f(a,n,n);
	return 0;
}
void f(int a[],int n,int y)
{
	static int max=-99999,min=99999;
	static float sum=0;
	float avg;
	if(n==0)
	{
		cout<<"max is "<<max<<endl;
		cout<<"min is "<<min<<endl;
		cout<<"sum is "<<sum<<endl;
		avg=sum/y;
		cout<<"average is "<<avg<<endl;
	}
	else
	{
		sum=sum+a[n];
		if(a[n]>max)
		max=a[n];
		if(a[n]<min)
		min=a[n];
		f(a,n-1,y);
	}
}
