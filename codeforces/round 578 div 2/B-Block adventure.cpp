#include<iostream>
#define int long long
main(){
	int test_num,cases,t1,n,m,k,t;
	int arr[1001];
	bool sf;
	std::cin>>test_num;
	for(cases=0;cases<test_num;cases++){
		std::cin>>n>>m>>k;
		sf=true;
		for(t=0;t<n;t++){
			std::cin>>arr[t];
		}
		for(t=0;t<n-1;t++){
			if(arr[t+1]-arr[t]<=k){
				if(arr[t+1]<=k){
					m+=arr[t];
				}else{
					m+=(k-arr[t+1]+arr[t]);
				}
			}else{
				if(arr[t+1]-arr[t]-k<=m){
					m=m-arr[t+1]+arr[t]+k;
				}else{
					sf=false;
					break;
				}
			}
		}
		if(sf==false){
			std::cout<<"NO"<<std::endl;
		}else{
			std::cout<<"YES"<<std::endl;
		}
	}
}
