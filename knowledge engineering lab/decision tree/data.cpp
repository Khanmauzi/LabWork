#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream fout;
	fout.open("data.txt");
	//fout<<"RID age income student credit rating Class: buys computer"<<endl;
	fout<<"1 @youth #high $no %fair ^no"<<endl;
	fout<<"2 @youth #high $no %excellent ^no"<<endl;
	fout<<"3 @middle #high $no %fair ^yes"<<endl;
	fout<<"4 @senior #medium $no %fair ^yes"<<endl;
	fout<<"5 @senior #low $yes %fair ^yes"<<endl;
	fout<<"6 @senior #low $yes %excellent ^no"<<endl;
	fout<<"7 @middle #low $yes %excellent ^yes"<<endl;
	fout<<"8 @youth #medium $no %fair ^no"<<endl;
	fout<<"9 @youth #low $yes %fair ^yes"<<endl;
	fout<<"10 @senior #medium $yes %fair ^yes"<<endl;
	fout<<"11 @youth #medium $yes %excellent ^yes"<<endl;
	fout<<"12 @middle #medium $no %excellent ^yes"<<endl;
	fout<<"13 @middle #high $yes %fair ^yes"<<endl;
	fout<<"14 @senior #medium $no %excellent ^no"<<endl;
	return 0;

}
