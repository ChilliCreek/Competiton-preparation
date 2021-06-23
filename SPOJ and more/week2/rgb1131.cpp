/*
ID: chiig.e1
LANG: C++
TASK: milk
*/
#include<bits/stdc++.h>

using namespace std;

class milk{
	public:
		long long a;
		long long b;
		bool operator<(const milk& i)const{
			return a<i.a;
		}
};
main(){
	long long target,typ,i,price=0;
	ofstream fout ("milk.out");
    ifstream fin ("milk.in");
	fin>>target>>typ;
	milk table[typ];
	for(i=0;i<typ;i++){
		fin>>table[i].a>>table[i].b;
	}
	sort(table,table+typ);

	i=0;
	while(1){
		if(table[i].b>=target){
			price+=target*table[i].a;
			break;
		}else{
			price+=table[i].a*table[i].b;
			target-=table[i].b;
		}
		i++;
	}
	fout<<price<<endl;
}
