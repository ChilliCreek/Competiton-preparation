#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: pprime
*/
using namespace std;
bool ifpal(int i){
	stringstream gg;
	gg<<i;
	string n=gg.str();
	string n1=n;
	reverse(n1.begin(),n1.end());
	if(n1==n){
		return true;
	}
	return false;
}
main(){
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	int i,j,n,n1,in;
	cin>>n>>n1;
	
} 
