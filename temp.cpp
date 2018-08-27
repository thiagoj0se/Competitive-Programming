#include <bits/stdc++.h>

#define pb push_back
#define pp pop_back
#define mp make_pair
#define lwb lower_bound
#define upb upper_bound
#define all(E) E.begin(), E.end()
#define e_min min_element
#define e_max max_element
#define bin_s binary_search
#define ff find

using namespace std;
typedef long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

int main() {
    ll T, N, D, v1, v2, input;
    vvct arr(1030);
    vii cord;

    cin >> T;
    while(T--) {
        cord.clear();
        cin >> D >> N;
        for(ll i = 0; i < 1030; i++)
            arr[i].assign(1030, 0);
        for(ll i = 0; i < N; i++) {
            cin >> v1 >> v2 >> input;
            arr[v1][v2] = input;
            cord.pb(mp(v1, v2));
        }
        ll best_sum = 0;
        ll best_i, best_j;
        for(ll i = 0; i < cord.size(); i++) {
            v1 = cord[i].first, v2 = cord[i].second;
            ll sum = 0;
            for(ll k = v1 - D - 1; k <= v1 + D + 1; k++)
                for(ll j = v2 - D - 1; j <= v2 + D + 1; j++)
                    if(k >= 1 && k <= 1024 && j >= 1 && j <= 1024) {
                        sum += arr[k][j];
                        printf("%lld %lld %lld\n",
                            k, j, sum);
                    }
            cout << "over" << endl;
            if(sum > best_sum) {
                best_sum = sum;
                best_i = v1, best_j = v2;
                printf("%lld %lld %lld\n",
                    best_i, best_j, best_sum);    }
        }
        printf("%lld %lld %lld\n",
                best_i, best_j, best_sum);
    }
    return 0;
}
