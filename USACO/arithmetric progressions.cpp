#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: ariprog
*/
using namespace std;
int arr[125001],n;

struct pairr{
	int a;
	int b;
};

vector<pairr> res;

bool srt(pairr one,pairr two){
	if(one.b==two.b){
		if(one.a<two.a)return true;
		else return false;
	}else if(one.b>two.b)return false;
	else return true;
}
void tryy(int start,int d){
	int proglen=1,num=start;
	while(proglen<n && num+d<125000 && arr[num+d]==1){
		proglen++;
		num+=d;
	}
	if(proglen==n){
		pairr temp;
		temp.a=start;
		temp.b=d;
		res.push_back(temp);
	}
}
main(){
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	int m,i,j;
	vector <int> bisq;
	set<int> temps;
	set<int>::iterator it;
	fin>>n>>m;
	for(i=0;i<=m;i++){
		for(j=i;j<=m;j++){
			arr[i*i+j*j]=1;
			temps.insert(i*i+j*j);
		}
	}
	for(it=temps.begin();it!=temps.end();it++){
		bisq.push_back(*it);
	}
	sort(bisq.begin(),bisq.end());
	for(i=0;i<bisq.size();i++){
		for(j=i+1;j<bisq.size();j++){
			//cout<<bisq[i]<<" "<<bisq[j]-bisq[i]<<endl;
			tryy(bisq[i],bisq[j]-bisq[i]);
		}
	}
	sort(res.begin(),res.end(),srt);
	if(res.size()==0){
		fout<<"NONE"<<endl;
	}else{
		for(i=0;i<res.size();i++){
			fout<<res[i].a<<" "<<res[i].b<<endl;
		}
	}
} 
