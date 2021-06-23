#include<iostream>
#include<stdio.h>
#include<string.h>
main(){
	int events_num,t,t1;
	char inp;
	int arr[10];
	for(t=0;t<10;t++){
		arr[t]=0;
	}
	std::cin>>events_num;
	for(t=0;t<events_num;t++){
		std::cin>>inp;
		if(inp=='L'){
			for(t1=0;t1<10;t1++){
				if(arr[t1]==0){
					arr[t1]=1;
					break;
				}
			}
		}else if(inp=='R'){
			for(t1=9;t1>=0;t1--){
				if(arr[t1]==0){
					arr[t1]=1;
					break;
				}
			}
		}else{
			arr[inp-'0']=0;
		}
	}
	for(t=0;t<10;t++){
		std::cout<<arr[t];
	}
}
