//generating list
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <ctime>
//#include <>
using namespace std;
struct td{
	int n;
	string tid;
	string item[10];
};
int main(){
	ofstream fout;
	fout.open("t1.txt");
	srand(time(NULL));
	int n;
	n=(rand()%10)+1;
	//cout<<" n : "<<n<<endl;
	struct td t[n];
	for(int i=0;i<n;++i){
		string tid="T";
		int temp;
		int cnt;
		char ch[10];
		itoa(i,ch,10);
		tid=tid+ch;
		 cnt=(rand()%10)+1;
		 t[i].n=cnt;
		 int flag=0;
	/*	 while(1){
		 	 tid="T";
		 	temp=(rand()%10);
		 	//cout<<temp<<endl;
		 	itoa(temp,ch,10);
		 	tid=tid+ch;
		 	int j;
		 	for(j=0;j<i;j++){
		 		if(t[j].tid==tid)
		 		break;
		 	}
		 	if(j==i)
		 	break;
		}*/
	//	cout<<i<<endl;
		t[i].tid=tid;
	//	cout<<"tid : "<<t[i].tid<<endl;
	//	cout<<t[i].n<<endl;
		for(int k=0;k<t[i].n;++k){
		    string it="I";
		   /* while(1){
		    	it="I";
				temp=(rand()%10);
				//cout<<temp<<endl;
				itoa(temp,ch,10);
				//cout<<ch;
				it=it+ch;
			//	cout<<it<<endl;
				int j;
				for(j=0;j<k;++j){
					if(t[i].item[j]==it)
					break;
				}
				if(k==j)
				break;
			}*/
			char ch[10];
			itoa(k,ch,10);
			it=it+ch;
			t[i].item[k]=it;
			//cout<<"item : "<<t[i].item[k]<<" ";
	}
	}
	//fout<<"TID              ITEM : "<<endl;
	for(int i=0;i<n;i++){
		fout<<t[i].tid<<"        ";
		for(int j=0;j<t[i].n;j++)
		fout<<t[i].item[j]<<", ";
		fout<<endl;	
	}
/*	cout<<"TID              ITEM : "<<endl;
	for(int i=0;i<n;i++){
		cout<<t[i].tid<<"        ";
		for(int j=0;j<t[i].n;j++)
		cout<<t[i].item[j]<<"  ";
		cout<<endl;	
	}*/
	return 0;
}
