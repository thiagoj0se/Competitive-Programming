#include <iostream> 
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;
typedef unsigned long long int ll;
typedef vector<ll> vct;

void fill_table(vct &table)
{
	for (ll i = 0; i < 10000; i++)
		table.push_back(i*i);
	return;
}

int main()
{
	ll n, inf_lim, sup_lim;
	vct table; fill_table(table);

	while (scanf("%u", &n) != EOF)
	{
		inf_lim = pow(10, n / 2); sup_lim = pow(10, n);
		for (ll i = 0; i < table.size(); i++)
			if (table.at(i) >= sup_lim)
				break;
			else if (pow(table.at(i) / inf_lim + table.at(i) % inf_lim, 2) == table.at(i))
				cout << setfill('0') << setw(n) << table.at(i) << endl;
	}
	return 0;
}