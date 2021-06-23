#include<bits/stdc++.h>

using namespace std;

main(){
	int n,i,j;
	cin>>n;
	int arr[100][100]={0};
	arr[1][1]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			arr[i][j]=arr[i-1][j]+arr[i][j-1]+arr[i][j];
		}
	}
	cout<<arr[n][n];
}
