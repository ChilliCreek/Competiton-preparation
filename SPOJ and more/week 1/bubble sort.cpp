#include<iostream>

using namespace std;

main(){
	int i,j,count,arr[1000],n;
	
	cin>>n;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	
	count=1;
	while(count>0){
		count=0;
		for(i=0;i<n-1;i++){
			if(arr[i]<arr[i+1]){
				j=arr[i+1];
				arr[i+1]=arr[i];
				arr[i]=j;
				count++;
			}
		}
	}
	
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	
}
