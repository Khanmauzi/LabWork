#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter the number of term you want : ";
	cin>>n;
	int a[n];
	cout<<"enter the term : ";
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int cnt=0,j=0;
		if(a[i]%2!=0)
		{
		while(a[j]<=a[i])
		{
			if(a[j]%2==0)
			cnt++;
			j++;
			
		}
		cout<<"number of even integer less than "<<a[i]<<" is "<<cnt<<endl;
	}
		
	}
	return 0;
}
