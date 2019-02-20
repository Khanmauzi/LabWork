#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter the size of the array : ";
	cin>>n;
	int a[n];
	int i,j;
	cout<<"enter the elements of the array  :"<<endl;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	{
		cout<<"for "<<a[i]<<" : ";
		 int max=-9999;
		 int flag=-1;
		for(j=i+1;j<n-1;j++)
		{
			if(a[j]>a[i])
			max=a[j];
			if(max>a[i])
			cout<<max;
			else 
			cout<<flag;
		}
		cout<<endl;
	}
	return 0;
	
}
