#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int main(){
	string t="t";
	int n=10;
	string s="t";
	char temp[10];
	itoa(n,temp,10);
	//cout<<temp;
	t=t+temp;
	s=s+temp;
	cout<<t;
	if(t==s)
	cout<<"yes";
	return 0;
}
