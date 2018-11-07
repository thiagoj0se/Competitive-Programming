#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define max_s 8000
ll coins[] = {1,5,10,25,50};
ll dp[max_s], K;

int main() {
    memset(dp, 0,sizeof(dp));
    dp[0] = 1;
    for(ll i=0;i<=4;i++) {
        for(ll j=coins[i]; j<=max_s; j++)
            dp[j] = dp[j] + dp[j-coins[i]];
    }
    while(cin>>K)
        cout<<dp[K]<<endl;
    return 0;
}
