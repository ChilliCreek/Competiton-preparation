//https://cses.fi/problemset/task/1621
#include<bits/stdc++.h>

using namespace std;

int main(){
	set<int> theset;
	int n, temp;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		theset.insert(temp);
	}
	cout << theset.size();
}
