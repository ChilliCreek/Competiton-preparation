#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; 
	cin >> n;
	vector<pair<int, int> > values;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		values.push_back(make_pair(l, 1));
		values.push_back(make_pair(r, -1));
	}

	sort(values.begin(), values.end());

	int sum = 0;
	int res = 0;
	for (auto x : values) {
		sum += x.second;
		res = max(res, sum);
	}
	cout << res << '\n';
}

