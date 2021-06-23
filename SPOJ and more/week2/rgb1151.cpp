#include<bits/stdc++.h>

using namespace std;

int arr[1002][1002];

main(){
	int i,j,R;
	cin>>R;
	
	for(i=0;i<R;i++){
		for(j=0;j<i+1;j++){
			cin>>arr[i][j];
		}
	}
	
	for(i=R-2;i>-1;i--){
		for(j=0;j<R;j++){
			arr[i][j]+=max(arr[i-1][j],arr[i-1][j+1]);
		}
	}
}
