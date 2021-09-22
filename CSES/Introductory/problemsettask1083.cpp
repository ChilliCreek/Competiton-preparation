//https://cses.fi/problemset/task/1083
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, temp;
	cin >> n;
	bool arr[n] = {false};
	for(int i = 0; i < n - 1; i++){
		cin >> temp;
		arr[temp - 1] = true;
	}
	for(int i = 0; i < n; i++){
		if(!arr[i]){
			cout << i + 1;
		}
	}
}
