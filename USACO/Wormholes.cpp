#include<bits/stdc++.h>
/*
ID: chiig.e1
LANG: C++
TASK: wormhole
*/

using namespace std;

#define MAX_N 12

int pairings[MAX_N+1]={0},wormholes[MAX_N+1][2],nextworm[MAX_N+1]={0},n;
 
bool if_cycles(){
 	int posi;
 	for(int i=1;i<=n;i++){
 		posi=i;
 		for(int j=1;j<=n;j++){
 			posi=nextworm[pairings[posi]];
		}
		if(posi!=0){
			return true;
		}
	}
	return false;
}
int rec(){
 	int i,j,total=0;
 	for(i=1;i<=n;i++){
 		if(pairings[i]==0){
 			break;
		}
    }
    if(i>n){
    	if(if_cycles()){
    		return 1;
		}else{
			return 0;
		}
	}
	for(j=i+1;j<=n;j++){
		if(pairings[j]==0){
			pairings[j]=i;
			pairings[i]=j;
			total+=rec();
			pairings[j]=0;
			pairings[i]=0;
		}
	}
    return total;
}
main(){
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");
	int i,j,a;
	fin>>n;
	for(a=1;a<=n;a++){
		fin>>wormholes[a][0]>>wormholes[a][1];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(wormholes[i][1]==wormholes[j][1] && wormholes[i][0]<wormholes[j][0]){
				if(nextworm[i]==0 || wormholes[nextworm[i]][0]-wormholes[i][0] > wormholes[j][0]-wormholes[i][0]){
					nextworm[i]=j;
				}
			}
		}
	}
	a=rec();
	fout<<a<<endl;
}
