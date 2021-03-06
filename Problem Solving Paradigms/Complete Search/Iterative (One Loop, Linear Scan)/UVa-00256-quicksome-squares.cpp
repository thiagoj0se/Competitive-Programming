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
typedef vector<ll> vct;

void fill_table(vct &table) {
	for (ll i = 0; i < 1e+4; i++)
		table.pb(i*i);
	return;
}

int main() {
	ll n, inf_lim, sup_lim;
	vct table; fill_table(table);

	while (scanf("%u", &n) != EOF) {
		inf_lim = (ll)pow(10, n << 1); sup_lim = (ll)pow(10, n);
		for (ll i = 0; i < table.size(); i++)
			if (table.at(i) >= sup_lim)
				break;
			else if (pow(table.at(i) / inf_lim + table.at(i) % inf_lim, 2) == table.at(i))
				cout << setfill('0') << setw(n) << table.at(i) << endl;
	}
	return 0;
}