/* É suficiente procurar o valor que atende a função usando a técnica Divide and Conquer.
Nesse tipo de problema, observe [se existe] um valor que se maximiza ou não a função,
as condições que tornam impossível a solução, e as condições que mudam como a recursão deve 
ser chamada novamente caso seja provável uma solução. */ 

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>

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
typedef long int ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 8> VL;

ll p, q, r, s, t, u;

bool compare(const ll &x, const ll &y) {
    return (abs(x - y) < 1e-8);
}

ll eval(ll x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
}

bool conquer(ll bottom, ll top, ll &sol) {

	ll eval_bottom = eval(bottom);
	ll eval_top = eval(top);

	if(abs(eval_bottom) < 1e-8) {
		sol = bottom; return true;
	}
	if(abs(eval_top) < 1e-8) {
		sol = top; return true;
	}

	if(eval_bottom > 0 && eval_top > 0 ||
		eval_bottom < 0 && eval_top < 0)
	return false;
	
	ll mid = (bottom + top)/2.0;
	ll eval_mid = eval(mid);

	if(abs(eval_mid) < 1e-8){
		sol = mid; return true;
	}

	if(eval_mid <= 0 && eval_top > 0 ||
		eval_mid >= 0 && eval_top < 0)
		return conquer(mid, top, sol);
	else if(eval_bottom < 0 && eval_mid >= 0 ||
			eval_bottom > 0  && eval_mid <= 0)
		return conquer(bottom, mid, sol);

	return false;
}

int main(){ 
	ll sol;
	while(cin >> p >> q >> r >> s >> t >> u) {
		if(conquer(0, 1, sol))
			printf("%.4lf\n", sol);
		else
			printf("No solution\n");
	}
	return 0;
}