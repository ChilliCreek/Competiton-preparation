#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: sprime
*/
using namespace std;
ifstream fin("sprime.in");
ofstream fout("sprime.out");
bool anhniiyu(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
void printboi(int n,int num){
	if(n==0){
		fout<<num<<endl;
		return;
	}
	for(int i=num*10+1;i<=num*10+9;i+=2){
		if(anhniiyu(i)==true){
			printboi(n-1,i);
		}
	}
}

main(){
	int i,j,n;
	fin>>n;
	printboi(n-1,2);
	printboi(n-1,3);
	printboi(n-1,5);
	printboi(n-1,7);
}
