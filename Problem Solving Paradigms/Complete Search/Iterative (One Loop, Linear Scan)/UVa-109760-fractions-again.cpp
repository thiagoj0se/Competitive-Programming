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
typedef int ll;

class Sol {
public:
	ll x, y;
};

void find(ll k, vector<Sol> &solutions) {
	Sol sol;
	for (ll y = k << 1; y > k; y--)
		if (!((y * k) % (y - k))) {
			sol.x = (y * k) / (y - k); sol.y = y;
			solutions.pb(sol);
		}
	return;
}

int main() {
	ll k;
	vector<Sol> solutions;
	while (cin >> k) {
		find(k, solutions);
		cout << solutions.size() << endl;
		for (ll i = solutions.size() - 1; i >= 0; i--)
			printf("1/%d = 1/%d + 1/%d\n", k, solutions.at(i).x, solutions.at(i).y);
		solutions.clear();
	}
	return 0;
}