//https://cses.fi/problemset/task/1092
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	if(((n + 1) / 2) % 2 == 0){
		cout << "YES" << '\n';
		if(n % 2 == 0){
			cout << n / 2 << '\n';
			for(int i = 1; i <= n / 4; i++){
				cout << i << " " << n + 1 - i << " ";
			}
			cout << '\n' << n / 2 << '\n';
			for(int i = n / 4 + 1; i <= n / 2; i++){
				cout << i << " " << n + 1 - i << " ";
			}
		}
		else{
			int mid = n / 2 + 1, fqrt = mid / 2, tqrt = mid + n / 4 + 1;
			cout << n / 2 + 1 << '\n';
			for(int i = 1; i <= n / 4; i++){
				cout << i << " " << n + 1 - i << " ";
			}
			cout << mid << " " << fqrt << " " << '\n';
			cout << n / 2 << '\n';
			for(int i = fqrt + 1; i < mid; i++){
				cout << i << " " << n + 1 - i << " ";
			}
			cout << tqrt;
		}
	}
	else{
		cout << "NO";
	}
}
