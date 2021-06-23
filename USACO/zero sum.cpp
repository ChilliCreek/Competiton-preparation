#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: zerosum
*/
using namespace std;

int N;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

void dp(int sum, int last, int n, string res){
	if(n == N + 1){
		if(sum == 0){
			fout << res << endl;
		}
	}else{
		string temp;
		int last1 = last;
		temp = res;
		for(int i = n; i <= N; i++){
			last1 *= 10;
			if(last > 0)last1 += i;
			else last1 -= i;
			temp = temp + " " + to_string(i);
			dp(sum - last + last1, last1, i + 1, temp);
		}
		temp = res;
		temp = temp + "+" + to_string(n);
		dp(sum + n, n, n + 1, temp);
		temp = res;
		temp = temp + "-" + to_string(n);
		dp(sum - n, -n, n + 1, temp);
	}
}
int main() {
    fin >> N;
    dp(1, 1, 2, "1");
}
