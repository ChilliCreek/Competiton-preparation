#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, ans = 0, temp;
	cin >> n;
	multiset<int> towers;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		auto it = towers.upper_bound(temp);
		if(it != towers.end()){
			towers.erase(it);
		}
		towers.insert(temp);
	}
	cout << towers.size();
}

