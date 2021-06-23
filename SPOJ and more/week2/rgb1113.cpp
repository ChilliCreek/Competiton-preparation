#include<bits/stdc++.h>
 /*
ID: chiig.e1
TASK: friday
LANG: C++                 
*/
using namespace std;

int g[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

main(){
	ofstream fout ("friday.out");
    ifstream fin ("friday.in");
	int n,i,arr[8]={0},month=1,garig=13;
	fin>>n;
	
	arr[6]++;
	i=1900;
	while(i<n+1900){
		garig+=g[month];
		if(month==2){
			if(i%400==0){
				garig++;
			}else{
				if(i%100!=0 && i%4==0){
					garig++;
				}
			}
		}
		arr[garig%7]++;
		if(month==12){
			month=1;
			i++;
		}else{
			month++;
		}
	}
	arr[garig%7]--;
	fout<<arr[6];
	for(i=0;i<6;i++){
		fout<<" "<<arr[i];
	}
	fout<<endl;
}
