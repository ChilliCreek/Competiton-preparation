//https://cses.fi/problemset/task/2431
#include <bits/stdc++.h>
using namespace std;
 
long long kth(long long num, long long k){
	num /= poww(10, k - 1);
	return num % 10;
}

long long poww(long long f, long long s){
	long long res = 1;
	for(long long i = 0; i < s; i++){
		res *= 10;
	}
	return res;
}

int main()
{
	long long t, k, digits, quo, rem;
	long long digitNums[18];
	cin >> t;
	digitNums[1] = 9;
	for(long long i = 2; i < 18; i++){
		digitNums[i] = 9 * poww(10, i - 1) * i;
	}
    for(long long i = 0; i < t; i++){
    	cin >> k;
    	digits = 1;
    	while(digitNums[digits] < k){
    		k -= digitNums[digits];
    		digits++;
		}
		quo = (k - 1) / digits;
		rem = (k - 1) % digits;
		string nice = to_string(poww(10, digits - 1) + quo);
		cout << nice[rem] << '\n';
	}
}
