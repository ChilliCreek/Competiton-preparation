#include<bits/stdc++.h>

using namespace std;

main(){
	int n;
	cin>>n;
	int arr[n+1];
	arr[1]=3;arr[2]=8;
	for(int i=3;i<=n;i++){
		arr[i]=arr[i-1]*2+arr[i-2]*2;
	}
	cout<<arr[n];
}
