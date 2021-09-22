//https://cses.fi/problemset/task/1632
#include<bits/stdc++.h>
 
using namespace std;
 
main(){
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>> vp(n);
	for(int i = 0; i < n; i++){
		cin >> vp[i].second >> vp[i].first;
	} 
	sort(vp.begin(), vp.end());
	
	multiset<int> end_times; // times when members will finish watching movies
	for (int i = 0; i < k; ++i){
		end_times.insert(0);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		auto it = end_times.upper_bound(vp[i].second);
		if (it == end_times.begin()){
			continue;
		}
		end_times.erase(--it);
		end_times.insert(vp[i].first);
		ans++;
	}
	cout << ans;
}
