#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: subset
*/
using namespace std;

long long save[40][781];

main(){
	long long inp,target;
	ifstream fin("subset.in");
	ofstream fout("subset.out");
	fin>>inp;
	target=inp*(inp+1)/2;
	if(target%2==1){
		fout<<"0"<<endl;
	}else{
		for(long long i=0;i<40;i++){
			save[i][0]=1;
		}
		for(long long i=1;i<=inp;i++){
			for(long long j=0;j<=(target/2);j++){
				save[i][j]=0;
			}
		}
		for(long long i=1;i<=inp;i++){
			for(long long j=0;j<=(target/2);j++){
				save[i][j]=save[i-1][j];
				if(j-i>-1){
					save[i][j]+=save[i-1][j-i];
				}
			}
		}
		fout<<save[inp][target/2]/2<<endl;
	}
}
