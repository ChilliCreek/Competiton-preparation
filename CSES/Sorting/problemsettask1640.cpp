#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, target, inp;
	cin >> n >> target;
	map<int, int> save;
	bool found = false;
	
	for(int i = 0; i < n; i++){
		cin >> inp;
		if(found)continue;
		if(save.find(target - inp) != save.end()){
			cout << i + 1<< " " << save[target - inp] + 1<< '\n';
			found = true;
		}
		else{
			save[inp] = i;
		}
	}
	if(!found){
		cout << "IMPOSSIBLE";
	}
}
