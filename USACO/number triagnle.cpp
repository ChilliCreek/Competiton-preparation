#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: numtri
*/
 
using namespace std;
 
int a[1002][1002]={0};
main(){
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");
	int i,j,r;
	fin>>r;
	
	for(i=1;i<=r;i++){
		for(j=1;j<=i;j++){
			fin>>a[i][j];
			a[i][j]+=max(a[i-1][j],a[i-1][j-1]);
		}
	}
	j=0;
	for(i=1;i<=r;i++){
		if(j<a[r][i]){
			j=a[r][i];
		}
	}
	fout<<j<<endl;
}  
