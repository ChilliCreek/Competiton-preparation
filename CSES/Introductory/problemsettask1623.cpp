//https://cses.fi/problemset/task/1623
#include <bits/stdc++.h>
using namespace std;

long long findMin(long long arr[], long long i, long long curr, long long sum)
{
    if (i==0){
    	return abs((sum - curr) - curr);
	}
	else{
		return min(findMin(arr, i-1, curr+arr[i-1], sum), findMin(arr, i-1, curr, sum));
	}
}
 
int main()
{
	long long n, sum = 0;
	cin >> n;
    long long arr[n];
    for(long long i = 0; i < n; i++){
    	cin >> arr[i];
    	sum += arr[i];
	}
    
    cout << findMin(arr, n, 0, sum);
    return 0;
}
