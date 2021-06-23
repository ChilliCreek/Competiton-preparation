//https://codeforces.com/contest/1520/problem/B
#include<bits/stdc++.h>
using namespace std;

#define LOG(x) cout << x << endl

long long main(){
	long long t, n, digits, result;
	cin >> t;
	long long divisor = 1;
	for(long long j = 0; j < t; j++){
		cin >> n;
		long long tmp = n;
		digits = 0;result = 0;divisor = 0;
		while(tmp > 0){
			digits++;
			tmp/=10;
			divisor = divisor * 10 + 1;
		}
		result = (digits - 1) * 9 + n / divisor;
		LOG(result);
	}
}
