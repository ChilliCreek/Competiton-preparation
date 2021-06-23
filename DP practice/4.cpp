#include<bits/stdc++.h>

using namespace std;

int n;
int arr[100][100],arr1[100][100];

void print_path(int a,int b){
	if(a-1>-1){
		if(b-1>-1){
			if(arr[a-1][b]<arr[a][b-1]){
				print_path(a-1,b);
			}else{
				print_path(a,b-1);
			}
		}else{
			print_path(a-1,b);
		}
	}else{
		if(b-1>-1){
			print_path(a,b-1);
		}
	}
	cout<<arr1[a][b]<<" ";
}
main(){
	int i,j,too1,too2;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>arr[i][j];
			arr1[i][j]=arr[i][j];
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
	cout<<arr[n-1][n-1]<<endl;
	print_path(n-1,n-1);
}
