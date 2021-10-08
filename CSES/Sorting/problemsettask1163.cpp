//https://cses.fi/problemset/task/1163
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int len, n;
	cin >> len >> n; 
	multiset<int> intervals;
	set<int> points;
	points.insert(0);points.insert(len);
	intervals.insert(len);
	for(int p = 0; p < n; p++){
		int temp;
		cin >> temp;
		points.insert(temp);
		auto it = points.lower_bound(temp);
		auto save = it;
		auto next = ++it;
		it = save;
		auto prev = --it;
		it = save;
		int big = *(next) - *(prev), left = *(it) - *(prev), right = *(next) - *(it);
		auto it1 = intervals.find(big);
		intervals.erase(it1);
		intervals.insert(left); intervals.insert(right);
		cout << *(intervals.rbegin()) << " ";
	}
}


