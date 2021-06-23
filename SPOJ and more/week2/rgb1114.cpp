/*
ID: your_id_here
TASK: beads
LANG: C++                 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ofstream fout ("beads.out");
    ifstream fin ("beads.in");
	int n;
	fin >> n;
	char a[350];
	for(int i=0; i<n; i++){
		fin >> a[i];
	}
	int i=0,max=0,count=1,j=1,k=1,p,q,x=1,ex=0;
	while(i<n){
		if(a[i]==119){
			i++;
			if(i==n)max=n;
			continue;
		}
		count=1;
		count=count+x-1;
		j=1;
		k=1;
		p=i;
		if(p+j==n)p=-j;
		while(a[i]==a[p+j] || a[p+j]==119){
			j++;
			count++;
			if(p+j==n)p=-j;
			if(p+j==i){
				ex++;
				break;
			}	
		}
		if(ex==1){
			max=count;
			break;
		}
		count++;
		q=p;
		if(q+j+k==n)q=-j-k;
		while(a[p+j]==a[q+j+k] || a[q+j+k]==119){
			k++;
			count++;
			if(q+j+k==i+1-x)break;
			if(q+j+k==n)q=-j-k;
		}
		x=1;
		if(p+j-x==-1)p=n-j+x-1;
		while(a[p+j-x]==119){
			x++;
			if(p+j-x==-1)p=n-j+x-1;
		}
		if(count>max)max=count;
		i=i+j;
	}
	fout << max << endl;
	return 0;
}
