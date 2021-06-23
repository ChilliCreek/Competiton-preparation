#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n; 
	set<int> points;
	for(int i = 1; i <= n; i++){
		points.insert(i);
	}
	int num = 0;
	for(set<int>::iterator it = points.begin(); !points.empty(); ){
		num++;
		if(num == 2){
			num = 0; 
			auto save = it++;
			cout << *(save) << " ";
			points.erase(save);
		}
		else{
			it++;
		}
		if(it == points.end()){
			it = points.begin();
		}
	}
}


