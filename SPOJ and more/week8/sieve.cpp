#include<bits/stdc++.h>

using namespace std;
bool arr[100000000];
main(){
	int i,j;
	for(i=0;i<10000000;i++){
		arr[i]=(i+1)%2;
	}
	for(i=3;i<sqrt(10000000);i+=2){
		if(arr[i]==0){
			for(j=i*i;j<=10000000-i*2;j+=i*2){
			    arr[j]=true;
		    }
		}
	}
	arr[1]=true;
	arr[2]=false;
	int n,inp;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>inp;
		if(arr[inp]==0){
			cout<<"SECOND"<<endl;
		}else{
			cout<<"FIRST"<<endl;
		}
	}
}
