#include<iostream>
using namespace std;
void f1(int a);
void f2(int b);
void f3(int c,int d);
void f4(int d);
int main()
{
	int n,a,b,c,d;
	cout<<"enter any number upto four digit :";
	cin>>n;
	a=n/1000;
	n=n%1000;
	b=n/100;
	n=n%100;
	c=n;
	d=n%10;
	if(a!=0)
	{
		f1(a);
		cout<<" thousand ";
	}
	if(a!=0||b!=0)
	{
		f2(b);
		cout<<" hundred ";
	}
	if(a!=0||b!=0||c!=0)
	{

		f3(c,d);
	}
	else if(a==0&&b==0)
	f4(d);
	return 0;
}
void f1(int a)
{
	switch(a)
	{
		case 1:cout<<" one ";break;
		case 2:cout<<"two ";break;
		case 3:cout<<"three ";break;
		case 4:cout<<"four ";break;
		case 5:cout<<"five ";break;
		case 6:cout<<"six ";break;
		case 7:cout<<"seven ";break;
		case 8:cout<<"eight ";break;
		case 9:cout<<"nine ";break;
	}
}
void f2(int b)
{
	switch(b)
	{
		case 0:cout<<"";break;
			case 1:cout<<" one ";break;
		case 2:cout<<"two ";break;
		case 3:cout<<"three ";break;
		case 4:cout<<"four ";break;
		case 5:cout<<"five ";break;
		case 6:cout<<"six ";break;
		case 7:cout<<"seven ";break;
		case 8:cout<<"eight ";break;
		case 9:cout<<"nine ";break;
	}
}
void f3(int c,int d)
{
	switch(c)
	{
		case 11:cout<<"eleven ";break;
		case 12:cout<<"tweleve";break;
		case 13:cout<<"thirteen ";break;
		case 14:cout<<"fourteen ";break;
		case 15:cout<<"fifteen ";break;
		case 16:cout<<"sixteen ";break;
		case 17:cout<<"seventeen ";break;
		case 18:cout<<"eighteen  ";break;
		case 19:cout<<"nineteen ";break;
		case 20:case 21:case 22:case 23:case 24:case 25:case 26:case 27:case 28:case 29:cout<<"twenty ";f4(d);break;
		case 30:case 31:case 32:case 33:case 34:case 35:case 36:case 37:case 38:case 39:cout<<"thirty ";f4(d);break;
		case 40:case 41:case 42:case 43:case 44:case 45:case 46:case 47:case 48:case 49:cout<<"forty ";f4(d);break;
		case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:case 58:case 59:cout<<"fifty ";f4(d);break;
		case 60:case 61:case 62:case 63:case 64:case 65:case 66:case 67:case 68:case 69:cout<<"sixty ";f4(d);break;
		case 70:case 71:case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:cout<<"seventy ";f4(d);break;
		case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:case 88:case 89:cout<<"eighty ";f4(d);break;
		case 90:case 91:case 92:case 93:case 94:case 95:case 96:case 97:case 98:case 99:cout<<"ninety ";f4(d);break;
	}
}
void f4(int d)
{
	switch(d)
	{
		case 0:cout<<"";break;
			case 1:cout<<" one ";break;
		case 2:cout<<"two ";break;
		case 3:cout<<"three ";break;
		case 4:cout<<"four ";break;
		case 5:cout<<"five ";break;
		case 6:cout<<"six ";break;
		case 7:cout<<"seven ";break;
		case 8:cout<<"eight ";break;
		case 9:cout<<"nine ";break;
		
	}
}
