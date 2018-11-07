#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define max_s 30100
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
        printf("There are %lld ways to produce %lld cents change.\n",
                dp[K], K);
    return 0;
}
