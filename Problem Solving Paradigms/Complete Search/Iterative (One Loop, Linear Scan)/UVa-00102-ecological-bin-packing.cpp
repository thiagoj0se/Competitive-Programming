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
typedef long long int ll;

ll sum_others(ll *bin, ll c_bin) {
	return bin[(c_bin + 3) % 9] + bin[(c_bin + 6) % 9];
}

int main() {
	ll *bin = new ll[9]; string perm = "BCG"; string sol;
	ll sum, minimum; minimum = INT_MAX;

	while (scanf("%lld", &bin[0]) != EOF) {
		for (ll i = 1; i < 9; i++)
			cin >> bin[i];
		do {
			sum = 0;
			for (ll i = 0; i < 3; i++) {
				if (perm.at(i) == 'B') sum += sum_others(bin, 0 + i * 3);
				else if (perm.at(i) == 'G') sum += sum_others(bin, 1 + i * 3);
				else if (perm.at(i) == 'C') sum += sum_others(bin, 2 + i * 3);
			}
			if (sum < minimum) {
				minimum = sum;
				sol.clear();
				sol = perm;
			}
		} while (next_permutation(all(perm)));
	}
	cout << sol << " " << minimum << endl;
	return 0;
}