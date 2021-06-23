#include<bits/stdc++.h>

using namespace std;

bool arr[100000010]={true};

void printboi(int n,int num){
	if(n==0){
		cout<<num<<endl;
	}else{
		for(int i=num*10+1;i<=num*10+9;i++){
			if(arr[i]==true){
				printboi(n-1,i);
			}
		}
	}
}

main(){
	int i,j,n;
	cin>>n;
	for(i=2;i<=50000000;i++){
		if(arr[i]==true){
			for(j=2;j<=100000000/i;j++){
				arr[i*j]=false;
			}
		}
	}
	for(i=2;i<10;i++){
		if(arr[i]==true){
			printboi(n-1,i);
		}
	}
}
