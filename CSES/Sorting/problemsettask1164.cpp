//https://cses.fi/problemset/task/1164
#include<bits/stdc++.h>

#define ll long long
using namespace std;

int ans[200001], n, last = 1;
struct thr{
	int first;
	int second;
	int third;
	bool operator<(const thr& other)const{
		return first < other.first || (first == other.first && (second < other.second || (second == other.second && third < other.third)));
	}
};

vector<thr> vec(200001);


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> vec[i].first >> vec[i].second;
		vec[i].third = i;
	}
	sort(vec.begin(), vec.begin() + n);
	
	priority_queue<pair<int, int>> pq;
	for(int i = 0; i < n; i++){
		if(pq.empty()){
			pq.push(make_pair(-vec[i].second, last));
			ans[vec[i].third] = last;
			last++;
		}
		else{
			auto min = pq.top();
			if(-min.first < vec[i].first){
				pq.pop();
				pq.push(make_pair(-vec[i].second, min.second));
				ans[vec[i].third] = min.second;
			}
			else{
				pq.push(make_pair(-vec[i].second, last));
				ans[vec[i].third] = last;
				last++;
			}
		}
	}
	
	cout << last - 1<< '\n';
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
}
