//https://cses.fi/problemset/task/1642
#include<bits/stdc++.h>

#define ll long long
using namespace std;

struct thr{
	int first;
	int second;
	int third;
	bool operator<(const thr& other)const{
		return first < other.first || (first == other.first && (second < other.second || (second == other.second && third < other.third)));
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, target;
	thr res1, res2;
	cin >> n >> target;
	vector<int> temp(n);
	vector<thr> vec(n * (n - 1) / 2 + 1);
	for(int i = 0; i < n; i++){
		cin >> temp[i];
	}
	int p = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			vec[p].first = temp[i] + temp[j];
			vec[p].second = i;
			vec[p].third = j;
			p++;
		}
	}
	sort(vec.begin(), vec.begin() + p);
	bool found = false;
	int l = 0, r = p - 1;
	while(l < r){
		if(vec[l].second != vec[r].second && vec[l].second != vec[r].third && vec[l].third != vec[r].second && vec[l].third != vec[r].third &&(vec[l].first + vec[r].first) == target){
			res1 = vec[l]; res2 = vec[r];
			found = true;
			break;
		}
		if((vec[l].first + vec[r].first) < target){
			l++;
		}
		else{
			r--;
		}
	}
	if(found){
		cout << res1.second + 1 << " " << res1.third + 1 << " " << res2.second + 1 << " " << res2.third + 1;
	}
	else{
		cout << "IMPOSSIBLE";
	}
}
