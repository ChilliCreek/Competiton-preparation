#include<bits/stdc++.h>

#define ll long long
using namespace std;

ll n, k, sum1 = 0, sum2 = 0;
multiset<int> first;
multiset<int> second;

void del(int value){
	auto it = first.find(value);
	if(it != first.end()){
		first.erase(it);
		sum1 -= value;
	}
	else{
		it = second.find(value);
		if(it != second.end()){
			second.erase(it);
		}
		sum2 -= value;
	}
	if(first.size() < second.size()){
		sum1 += *(second.begin());
		sum2 -= *(second.begin());
		first.insert(*(second.begin()));
		second.erase(second.find(*(second.begin())));
	}
}

void insert(int value){
	if(value > *(first.rbegin())){
		second.insert(value);
		sum2 += value;
		if(second.size() > k / 2){
			sum1 += *(second.begin());
			sum2 -= *(second.begin());
			first.insert(*(second.begin()));
			second.erase(second.find(*(second.begin())));
		}
	}
	else{
		first.insert(value);
		sum1 += value;
		if(first.size() > (k + 1) / 2){
			sum2 += *(first.rbegin());
			sum1 -= *(first.rbegin());
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
	sum1 += arr[0];
	for(int i = 1; i < k; i++){
		insert(arr[i]);
	}
	
	if(k % 2 == 0){
		cout << sum2 - sum1 << " ";
	}
	else{
		cout << sum2 - sum1 + *(first.rbegin()) << " ";
	}
	
	for(int i = k; i < n; i++){
		if(k == 1){
			insert(arr[i]);
			del(arr[i - k]);
		}
		else{
			del(arr[i - k]);
			insert(arr[i]);
		}

		if(k % 2 == 0){
			cout << sum2 - sum1 << " ";
		}
		else{
			cout << sum2 - sum1 + *(first.rbegin()) << " ";
		}
	}
}
