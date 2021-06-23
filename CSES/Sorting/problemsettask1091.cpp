#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tNum, cNum, customer;
	cin >> tNum >> cNum;
	multiset<int> tickets;
	int temp;
	for(int i = 0; i < tNum; i++){
		cin >> temp;
		tickets.insert(temp);
	}
	for(int i = 0; i < cNum; i++){
		cin >> customer;
		auto index = tickets.upper_bound(customer);
		if(index == tickets.begin()){
			cout << -1 << '\n';
		}
		else{
			cout << *(--index) << '\n';
			tickets.erase(index); 
		}
	}
}
