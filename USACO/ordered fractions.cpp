#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: frac1
*/
using namespace std;

main(){
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	int i,j,n;
	double temp;
	map <double,pair<int,int> >res;
	map <double,pair<int,int> >::iterator it;
	fin>>n;
	for(i=1;i<=n;i++){
		for(j=0;j<=i;j++){
			temp=1.0*j/i;
			if(res.find(temp)==res.end()){
				res[temp]=make_pair(j,i);
			}
		}
	}
	for(it=res.begin();it!=res.end();it++){
		fout<<it->second.first<<"/"<<it->second.second<<endl;
	}
}
