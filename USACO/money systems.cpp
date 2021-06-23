#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: money
*/
using namespace std;

long long k, n, money[10001] = {0};

ifstream fin("money.in");
ofstream fout("money.out");

int main() {
    fin >> k >> n;
    vector<long long> coins(k);
    for(long long i = 0; i < k; i++){
    	fin >> coins[i];
	}
	money[0] = 1;
	sort(coins.begin(), coins.end(), greater<long long>());
	for(long long i = 0; i < k; i++){
		for(long long j = 1; j <= n; j++){
			if(j - coins[i] >= 0){
				money[j] += money[j - coins[i]];
			}
		}
	}
	fout << money[n] << endl;
}
