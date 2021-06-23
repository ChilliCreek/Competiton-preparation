/*
ID: chiig.e1
LANG: C++
TASK: barn1
*/
#include<bits/stdc++.h>
 
using namespace std;
 
main(){
	ofstream fout ("barn1.out");
	ifstream fin ("barn1.in");
	int i,j,inp,m,s,c,arr[201],arr1[201],c_save;
	fin>>m>>s>>c;
	for(i=0;i<c;i++){
		fin>>arr1[i];
	}
	sort(arr1,arr1+c);
	c_save=c;
	j=0;
	for(i=1;i<c;i++){
		if(arr1[i]-arr1[i-1]-1!=0){
			arr[j]=arr1[i]-arr1[i-1]-1;
			j++;
		}else{
			c_save--;
		}
	}
	if(j>0){
		sort(arr,arr+j);
	}
	i=0;
	while(c_save>m){
		c+=arr[i];
		c_save--;
		i++;
	}
	fout<<c<<endl;
} 
