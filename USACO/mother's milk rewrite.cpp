#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: milk3
*/
#define MAX 20

using namespace std;

struct State {
    int yoyo[3];
};

int seen[MAX+1][MAX+1][MAX+1];
int res[MAX+1];
int cap[3];

State pour(State curr, int from, int to){
	int temp;
    if(cap[to]>=curr.yoyo[from]+curr.yoyo[to]){
    	temp=curr.yoyo[from];
	}else{
		temp=cap[to]-curr.yoyo[to];
	}
	curr.yoyo[from]-=temp;
	curr.yoyo[to]+=temp;
	return curr;
}
void search(State curr){
    int i,j;
    if(seen[curr.yoyo[0]][curr.yoyo[1]][curr.yoyo[2]])return;
    seen[curr.yoyo[0]][curr.yoyo[1]][curr.yoyo[2]]=1;
    if(curr.yoyo[0]==0){
    	res[curr.yoyo[2]]=1;
	}
    for(i=0; i<3; i++){
    	for(j=0; j<3; j++){
    		search(pour(curr,i,j));	
		}
	}
}
main(){
	int i,j;
	State curr;
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");

    fin>>cap[0]>>cap[1]>>cap[2];
    curr.yoyo[0]=0;
    curr.yoyo[1]=0;
    curr.yoyo[2]=cap[2];
    search(curr);
    j=0;
    for(i=0;i<=MAX;i++){
		if(res[i]==1){
			if(j!=0){
	    		fout<<" ";
			}
			fout<<i;
			j=1;
		}
	}
	fout<<endl;
}
