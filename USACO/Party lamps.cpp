#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: lamps
*/
using namespace std;
int goal_lamps[6]={2,2,2,2,2,2};
map< vector<int>,int > result;
vector <int> buttons(int f,vector <int> lamps){
	if(f==1){
		for(int i=0;i<6;i++){
			if(lamps[i]==0){
				lamps[i]=1;
			}else if(lamps[i]==1){
				lamps[i]=0;
			}
		}
	}else if(f==2){
		for(int i=1;i<6;i+=2){
			if(lamps[i]==0){
				lamps[i]=1;
			}else if(lamps[i]==1){
				lamps[i]=0;
			}
		}
	}else if(f==3){
		for(int i=0;i<6;i+=2){
			if(lamps[i]==0){
				lamps[i]=1;
			}else if(lamps[i]==1){
				lamps[i]=0;
			}
		}
	}else if(f==4){
		for(int i=0;i<6;i+=3){
			if(lamps[i]==0){
				lamps[i]=1;
			}else if(lamps[i]==1){
				lamps[i]=0;
			}
		}
	}
	return lamps;
}
void func(int act,int n,vector <int> lamps){
	if(n==0){
		int j,i;
		for(i=0;i<6;i++){
			if(goal_lamps[i]!=2 && lamps[i]!=goal_lamps[i]){
				return;
			}
		}
		result[lamps]=1;
	}else{
		int i;
		for(i=act;i<=4;i++){
			func(i,n-1,buttons(i,lamps));
		}
	}
}
main(){
	vector <int> g;
	int inp,num_lamps,num_switches;
	map<vector<int>,int>::iterator it;
	ifstream fin("lamps.in");
	ofstream fout("lamps.out");

	fin>>num_lamps;
	fin>>num_switches;
	fin>>inp;
	while(inp!=-1){
		goal_lamps[(inp-1)%6]=1;
		fin>>inp;
	}
	
	fin>>inp;
	while(inp!=-1){
		goal_lamps[(inp-1)%6]=0;
		fin>>inp;
	}
	
	for(int i=0;i<6;i++){
		g.push_back(1);
	}
	
	if(num_switches>4){
		if(num_switches%2==0){
			num_switches=4;
		}else{
			num_switches=3;
		}
	}
	func(1,num_switches,g);
	for(it=result.begin();it!=result.end();it++){
		for(int j=0;j<num_lamps;j++){
			fout<<it->first[j%6];
		}
		fout<<endl;
	}
	if(result.size()==0){
		fout<<"IMPOSSIBLE"<<endl;
	}
}
