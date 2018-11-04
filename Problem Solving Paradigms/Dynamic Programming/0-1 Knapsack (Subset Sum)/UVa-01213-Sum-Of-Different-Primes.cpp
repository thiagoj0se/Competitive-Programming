#include <bits/stdc++.h>

#define pb push_back
#define pp pop_back
#define bin_s binary_search
#define all(E) E.begin(), E.end()

using namespace std;
typedef long long ll;
typedef vector<ll> vct;
typedef bitset<1125> mask;

vct primes;
ll N, K;
ll dp[1125][1125][20];

void sieve(ll sieve_size) {
    mask is_prime;
    is_prime.set();
    for(ll i=2;i<sieve_size;i++) {
        if(is_prime[i]) {
            for(ll j=i*i; j<sieve_size; j+=i)
                is_prime[j] = 0;
            primes.pb(i);
        }
    }
}

ll solve(ll idx, ll sum, ll ch) {
    if(idx == primes.size())
        return 0;
    if(ch == 0 && sum == 0)
        return 1;
    if(ch == 0 && sum != 0)
        return 0;
    if(sum < 0)
        return 0;
    if(dp[idx][sum][ch] == -1) {
        ll with = solve(idx+1, sum-primes[idx], ch-1);
        ll without = solve(idx+1, sum, ch);
        dp[idx][sum][ch] = with + without;
    }
    return dp[idx][sum][ch];
}

int main() {
    memset(dp, -1, sizeof(dp));
    sieve(1125);
    while(cin >> N >> K, N!=0 || K!=0)
        cout << solve(0, N, K) << endl;
    return 0;
}
