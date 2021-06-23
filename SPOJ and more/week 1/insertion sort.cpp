#include<bits/stdc++.h>

using namespace std;

main(){
	int n,i,j,a,b,c;
	vector <int> arr;
	vector <int>::iterator it;
	
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	
	for(a=1;a<arr.size();a++){
		b=a;
		while(arr[b-1]<arr[a]){
			b--;
		}
		arr.insert(arr.begin()+b,arr[a]);
		arr.erase(arr.begin()+a+1);
	}
	
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
