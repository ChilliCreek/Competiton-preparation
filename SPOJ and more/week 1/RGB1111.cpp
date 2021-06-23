#include<bits/stdc++.h>

using namespace std;
/*
ID: chiig.e1
TASK: ride
LANG: C++                 
*/
main(){
	long long i,j,onenum=1,twonum=1;
	string one,two;
	ofstream fout ("ride.out");
    ifstream fin ("ride.in");
	fin>>one>>two;
	for(i=0;i<one.size();i++){
		onenum*=one[i]-64;
	}
	for(i=0;i<two.size();i++){
		twonum*=two[i]-64;
	}
	if(onenum%47==twonum%47){
		fout<<"GO"<<endl;
	}else{
		fout<<"STAY"<<endl;
	}
}
