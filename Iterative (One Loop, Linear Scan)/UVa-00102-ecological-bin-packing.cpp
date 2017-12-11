#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long int ll;

ll sum_others(ll *bin, ll c_bin)
{
	return bin[(c_bin + 3) % 9] + bin[(c_bin + 6) % 9];
}

bool can_replace(string &perm, string &sol)
{
	for (ll i = 0; i < 2; i++)
		if (perm.at(i) < sol.at(i))
			return true;
	return false;
}

int main()
{
	ll *bin = new ll[9]; string perm = "BCG"; string sol;
	ll sum, minimum; minimum = INT_MAX;

	while (scanf("%lld", &bin[0]) != EOF)
	{
		for (ll i = 1; i < 9; i++)
			cin >> bin[i];
		do
		{
			sum = 0;
			for (ll i = 0; i < 3; i++)
			{
				if (perm.at(i) == 'B') sum += sum_others(bin, 0 + i * 3);
				else if (perm.at(i) == 'G') sum += sum_others(bin, 1 + i * 3);
				else if (perm.at(i) == 'C') sum += sum_others(bin, 2 + i * 3);
			}
			if (sum < minimum)
			{
				minimum = sum;
				sol.clear();
				sol = perm;
			}
		} while (next_permutation(perm.begin(), perm.end()));
	}
	cout << sol << " " << minimum << endl;
	return 0;
}