#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <limits.h>
#include <math.h>

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
typedef double ll;
typedef vector<ll> vct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 8> VL;

ll comp(ll x, ll y) {
	return (abs(x - y) < 1e-6);
}

ll diam(ll V, ll Vo) {
	if (V <= Vo) return 0;
	else return 0.3*sqrt(V - Vo);
}

ll explore(ll V, ll Vo)
{
	ll save_i, bigger, result;
	bigger = save_i = 0;
	for (ll i = 1; V / i > Vo; i++) {
		result = i*diam(V / i, Vo);
		if (result >= bigger) {
			if (comp(result, bigger)) 
				return 0;
			save_i = i, bigger = result;
		}
	}
	return save_i;
}

int main() {
	ll V, Vo;
	while (true) {
		cin >> V >> Vo;
		if (V == Vo && !V) return 0;
		else cout << explore(V, Vo) << endl;
	}
	return 0;
}