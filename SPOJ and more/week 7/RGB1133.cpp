#include<bits/stdc++.h>

using namespace std;

int save[2001];
pair<int,int> arr[20001][20001];


main(){
	int n,i,j,len=0;
	string inp;
	string gg;
	cin>>gg;
	for(i=0;i<gg.size();i++){
		if(65<=gg[i] && gg[i]<=90){
			inp+=gg[i]+32;
			save(inp.size()-1)=i;
		}
		if(97<=gg[i] && gg[i]<=122){
			inp+=gg[i];
			save(inp.size()-1)=i;
		}
	}
	for(i=0;i<inp.size();i++){
		arr[i][i]=make_pair(1,1);
	}
	for(j=0;j<inp.size()-1;j++){
		arr[i][i+1]=make_pair(2,1);
	}
	for(i=2;i<inp.size()-2;i++){
		
	}
}
