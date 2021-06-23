#include<bits/stdc++.h>
/*
ID: chiig.e1
TASK: crypt1
LANG: C++                 
*/
using namespace std;

int arr[10],n,res=0;

bool ifinlist(int b){
	int j;
	while(b>0){
		j=0;
		for(int i=0;i<n;i++){
			if(arr[i]==b%10){
				j=1;
			}
		}
		if(j==0){
			return false;
		}
		b/=10;
	}
	return true;
}
void duud(int step,int mainn,int one,int two){
	if(step<3){
		for(int i=0;i<n;i++){
			duud(step+1,mainn*10+arr[i],one,two);
		}
	}else if(step==3){
		for(int i=0;i<n;i++){
			if(arr[i]*mainn<1000 && ifinlist(arr[i]*mainn)){
				duud(step+1,mainn,mainn*arr[i],two);
			}
		}
	}else if(step==4){
		for(int i=0;i<n;i++){
			if(arr[i]*mainn<1000 && ifinlist(arr[i]*mainn)){
				duud(step+1,mainn,one,mainn*arr[i]);
			}
		}
	}else if(step==5){
		if((one+two*10)<10000 && ifinlist(one+two*10)){
			res++;
		}
	}
}


main(){
	ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
	int i,j;
	fin>>n;
	for(i=0;i<n;i++){
		fin>>arr[i];
	}
	duud(0,0,0,0);
	fout<<res<<endl;
}
