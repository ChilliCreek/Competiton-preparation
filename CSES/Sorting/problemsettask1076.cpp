//https://cses.fi/problemset/task/1076
#include<bits/stdc++.h>

#define ll long long
using namespace std;

int n, k;
multiset<int> first;
multiset<int> second;

void del(int value){
	auto it = first.find(value);
	if(it != first.end()){
		first.erase(it);
	}
	else{
		it = second.find(value);
		if(it != second.end()){
			second.erase(it);
		}
	}
	if(first.size() < second.size()){
		first.insert(*(second.begin()));
		second.erase(second.find(*(second.begin())));
	}
}

void insert(int value){
	if(value > *(first.rbegin())){
		second.insert(value);
		if(second.size() > k / 2){
			first.insert(*(second.begin()));
			second.erase(second.find(*(second.begin())));
		}
	}
	else{
		first.insert(value);
		if(first.size() > (k + 1) / 2){
			second.insert(*(first.rbegin()));
			first.erase(first.find(*(first.rbegin())));
		}
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	first.insert(arr[0]);
	for(int i = 1; i < k; i++){
		insert(arr[i]);
	}
	cout << *(first.rbegin()) << endl;
	for(int i = k; i < n; i++){
		if(k == 1){
			insert(arr[i]);
			del(arr[i - k]);
		}
		else{
			del(arr[i - k]);
			insert(arr[i]);
		}
		cout << *(first.rbegin()) << '\n';
	}
}
