#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

struct myClass{
	double a;
	int b;
	bool operator <(const myClass& x)const{
		return a<x.a;
	}
};
main(){
	int n,k,i,j;
	cin>>n>>k;
	int bases[n][2];
	double distToCenter[n],res=0;
	
	
	for(int i=0;i<n;i++){
		cin>>bases[i][0]>>bases[i][1];
	}
	for(i=0;i<n;i++){
		distToCenter[i]=sqrt(double(bases[i][0])*double(bases[i][0])+double(bases[i][1])*double(bases[i][1]));
	}
	
}
