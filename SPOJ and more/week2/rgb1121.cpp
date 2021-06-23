/*
ID: 100021881
LANG: C++
PROG: milk2
*/
#include<bits/stdc++.h>
 
using namespace std;
 
main(){
	ifstream fin("milk2.in");
    ofstream fout("milk2.out");
	long long n,i,j,st,en,res1=0,res2=0;
	bool mod=true;
	map<long long,long long> schedule;
	map<long long,long long>::iterator it;
	fin>>n;
	for(i=0;i<n;i++){
		fin>>st>>en;
		
		schedule[st]++;
		schedule[en]--;
	}
	j=0;
	st=schedule.begin()->first;
	for(it=schedule.begin();it!=schedule.end();it++){
		//cout<<it->first<<" "<<it->second<<endl;
		if(mod==false){
			if(res2<it->first-st){
				res2=it->first-st;
			}
			mod=true;
			st=it->first;
		}
		j+=it->second;
		if(j==0){
			if(mod==true){
				if(res1<it->first-st){
					res1=it->first-st;
				}
				mod=false;
				st=it->first;
			}
		}
	}
	fout<<res1<<" "<<res2<<endl;
}  
