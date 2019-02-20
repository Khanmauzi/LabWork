#include <iostream>
#include <map>
using namespace std;
int main(){
	multimap <int,int> m;
	m.insert(pair<int,int>(0,3));
	m.insert(pair<int,int>(0,5));
	m.insert(pair<int,int>(-1,4));
		m.insert(pair<int,int>(-1,2));
	map <int,int>::iterator it=m.begin();
	while(it!=m.end()){
		int k=m.count(it->first);
		int i=0;
		while(i<k){
			cout<<it->second<<" ";
			it++;
			i++;
		}
		cout<<endl;
	//	it++;
	}
	return 0;
}
