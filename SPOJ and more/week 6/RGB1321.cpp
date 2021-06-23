#include<bits/stdc++.h>

using namespace std;

main(){
	int n;
	cin>>n;
	int arr[10][4],i,a,res=1;
	for(a=1;a<=n;a++){
		i=a;
		while(i%10==0){
			i/=10;
		}
		i%=10;
		res*=i;
		while(res%10==0){
			res/=10;
		}
		res%=10;
	}
	cout<<res;
}
