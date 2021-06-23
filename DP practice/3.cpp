#include<bits/stdc++.h>

using namespace std;

main(){
	int n,i,j,too1,too2;
	cin>>n;
	int arr[100][100]={0};
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i-1>-1){
				if(j-1>-1){
					arr[i][j]=min(arr[i-1][j],arr[i][j-1])+arr[i][j];
				}else{
					arr[i][j]=arr[i-1][j]+arr[i][j];
				}
			}else{
				if(j-1>-1){
					arr[i][j]=arr[i][j-1]+arr[i][j];
				}
			}
		}
	}
	cout<<arr[n-1][n-1];
}
