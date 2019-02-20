#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter the number you want to enter : ";
	cin>>n;
	int a[n],max=-99999,min=11111;
	cout<<"enter the number : "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int x;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
		if(a[i]<min)
		min=a[i];
	}
	int cnt=0;

	
	while(1)
	{
			cout<<"enter any even number : ";
		cin>>x;
		int i=0;
		while(x!=a[i])
		{
			i++;
			if(i==n)
			break;
		}
		
	if(x%2!=0||x>max||x<min||i==n)
	{
		cout<<"wrong input !!"<<endl;;
	
	}
	else 
	{
	   for(int i=0;i<n;i++)
	   if(a[i]>x&&a[i]%2!=0)
	   cnt++;
	   cout<<"number of odd integer greater than " <<x<<" is : "<<cnt;
	}
	if(x%2==0&&i<n)
	break;
    }
	
	return 0;
}
