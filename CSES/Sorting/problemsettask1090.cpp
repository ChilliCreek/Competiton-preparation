//https://cses.fi/problemset/task/1090
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, limit, gondola = 0;
	cin >> n >> limit;
	int children[n];
	for(int i = 0; i < n; i++){
		cin >> children[i];
	}
	sort(children, children + n);
	
	int start = 0, end = n - 1;
	while(start <= end){
		if(start == end){
			end--;
			gondola++;
		}
		else if(children[end] + children[start] <= limit){
			start++;
			end--;
			gondola++;
		}
		else{
			end--;
			gondola++;
		}
	}
	cout << gondola;
}
