//BABYLONIAN ALGORITHM
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	float n,r,g,t1,t2,x;
	cout<<"enter the numeber : ";
	cin>>n;
	g=n/2;
	t1=g;
	r=n/g;
	g=(g+r)/2;
	t2=g;
	while(1)
	{
		if(((t1-t2)/t1)*100<.005)
		break;
		else
		{
			t1=g;
			r=n/g;
			g=(g+r)/2;
			t2=g;
		}
	}
	x=t2;
	cout<<"square root is : "<<x<<endl;
	return 0;
	
}
