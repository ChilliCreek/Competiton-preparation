#include<bits/stdc++.h>

using namespace std;

int main(){
	long long t, x, y;
	cin >> t;
	for(int p = 0; p < t; p++){
		cin >> x >> y;
		if(x > y){
			if(x%2 == 0){
				cout << x * x - y + 1 << '\n';
			}
			else{
				cout << (x - 1) * (x - 1) + y << '\n';
			}
		}
		else{
			if(y % 2 == 0){
				cout << (y - 1) * (y - 1) + x << '\n';
			}
			else{
				cout << y * y - x + 1 << '\n';
			}
		}
	}
}
