#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: sort3
*/
using namespace std;

int arr[1001],arr1[1001],data[4][4];

main(){
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	int i,j,n,res=0;
	fin>>n;
	for(i=0;i<n;i++){
		fin>>arr[i];
		arr1[i]=arr[i];
	}
	sort(arr1,arr1+n);
	for(i=0;i<n;i++){
		data[arr1[i]][arr[i]]++;
	}
	i=min(data[1][2],data[2][1]);
	data[1][2]-=i;
	data[2][1]-=i;
	res+=(i*3);
	i=min(data[1][3],data[3][1]);
	data[1][3]-=i;
	data[3][1]-=i;
	res+=(i*3);
	i=min(data[2][3],data[3][2]);
	data[2][3]-=i;
	data[3][2]-=i;
	res+=(i*3);
	for(i=1;i<4;i++){
		for(j=1;j<4;j++){
			if(i!=j){
				res+=data[i][j]*2;
			}
		}
	}
	fout<<res/3<<endl;
}
