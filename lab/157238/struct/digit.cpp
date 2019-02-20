#include<iostream>
using namespace std;
int main()
{
	int i,n;
	string a[100000];
	a[0]="";
	a[1]=" one ";
	a[2]=" two ";
	a[3]=" three ";
	a[4]=" four ";
	a[5]=" five ";
	a[6]=" six ";
	a[7]=" seven ";
	a[8]=" eight ";
	a[9]=" nine ";
	a[10]=" ten ";
	a[11]=" eleven ";
	a[12]=" twelve ";
	a[13]=" thirteen ";
	a[14]=" fourteen ";
	a[15]=" fifteen ";
	a[16]=" sixteen ";
	a[17]=" seventeen ";
	a[18]=" eighteen ";
	a[19]=" nineteen ";
	a[20]=" twenty ";
	a[30]=" thirty ";
	a[40]=" forty ";
	a[50]=" fifty ";
	a[60]=" sixty ";
	a[70]=" seventy ";
	a[80]=" eighty ";
	a[90]=" ninety ";
	for(i=21;i<100;i++)
	a[i]=a[(i/10)*10]+a[i%10];
	for(i=100;i<1000;i++)
	a[i]=a[(i/100)]+" hundred "+a[i%100];
	for(i=1000;i<100000;i++)
	a[i]=a[i/100]+" thousand "+a[i%1000];
	cout<<"enter the number below 100000 :"<<endl;
	cin>>n;
	cout<<a[n];
	return 0;
}
