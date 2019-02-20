#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main(){int i=0;
char s[100];
	char ch2;
	string line;
	ofstream neel;
	neel.open("ram.txt");
neel<<"hi ra neelu ";
	neel.close();
	ifstream kanth;
	
	kanth.open("ram.txt");
	while(kanth){
		
		kanth>>ch2;
		cout<<ch2;i++;
		
		
	}
	cout<<i;
kanth.close();
return 0;
}
