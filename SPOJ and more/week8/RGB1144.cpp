#include<bits/stdc++.h>

using namespace std;
int arr[20]={0};
main(){
	int i,j;
	int a_cap,b_cap,c_cap;
	cin>>a_cap>>b_cap>>c_cap;
	for(i=c_cap;i>=0 && b_cap>=c_cap-i;i-=a_cap){
		arr[i]=1;
	}
	if(b_cap>=c_cap){
		for(j=0;j<=c_cap;j+=a_cap){
			arr[j]=1;
		}
	}else{
		for(j=c_cap-b_cap;j<=c_cap;j+=a_cap){
			arr[j]=1;
		}
	}
	for(i=0;i<=(c_cap/a_cap);i++){
		if(b_cap>=c_cap-a_cap*i){
			arr[i*a_cap]=1;
		}
	}
	for(i=0;i<=c_cap;i++){
		if(arr[i]==1)cout<<i<<" ";
	}
}
