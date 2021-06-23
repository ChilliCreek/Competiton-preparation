#include<bits/stdc++.h>

using namespace std;

main(){
	int i=0,j,i1,inp,m,s,c,arr[201],arr1[201],boardnum=0,c_save;
	cin>>m>>s>>c;
	for(i=0;i<c;i++){
		cin>>arr[i];
	}
	
	if(boardnum>0){
		sort(arr,arr+boardnum-1);
	}
	i=0;
	while(c_save>m){
		c+=arr[i];
		c_save--;
		i++;
	}
	cout<<c;
}
