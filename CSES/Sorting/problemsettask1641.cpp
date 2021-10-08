//https://cses.fi/problemset/task/1641
#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, target, res1, res2, res3;
	cin >> n >> target;
	vector<pair<int, int> > vec(n);
	for(int i = 0; i < n; i++){
		cin >> vec[i].first;
		vec[i].second = i;
	}
	sort(vec.begin(), vec.begin() + n);
	bool found = false;
	for(int i = 0; i < n; i++){
		int l = 0, r = n - 1;
		while(l < r){
			if(l != i && r != i && (vec[i].first + vec[l].first + vec[r].first) == target){
				res1 = vec[i].second; res2 = vec[l].second; res3 = vec[r].second;
				found = true;
				break;
			}
			if((vec[i].first + vec[l].first + vec[r].first) < target){
				l++;
			}
			else{
				r--;
			}
		}
	}
	if(found){
		cout << res1 + 1 << " " << res2 + 1<< " " << res3 + 1;
	}
	else{
		cout << "IMPOSSIBLE";
	}
}
