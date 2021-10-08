//https://cses.fi/problemset/task/1644
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, a, b;
    cin >> n >> a >>b;
    vector<ll> prefixsum(n + 1);
    prefixsum[0] = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        prefixsum[i] = prefixsum[i - 1] + x;
    }
    multiset<ll> curr;
    ll ans = LONG_LONG_MIN;
    for(int i = a; i <= n; i++){
        if(i > b){
            curr.erase(curr.find(prefixsum[i - b - 1]));
        }
        curr.insert(prefixsum[i - a]);
        ans = max(ans, prefixsum[i] - *curr.begin());
    }
    cout << ans <<"\n";
}
