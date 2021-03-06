//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3678

#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long int ll;

class CarData
{
public:
	string enterprise;
	ll lowest;
	ll highest;
};

void find_database(vector<CarData> const & cars)
{
	ll save_i, count, value; cin >> value;
	count = 0;

	for (ll i = 0; i < cars.size(); i++)
	{
		if (value >= cars.at(i).lowest && value <= cars.at(i).highest)
		{
			save_i = i;
			count++;
		}
	}

	if (!(count - 1))
		cout << cars.at(save_i).enterprise << endl;
	else
		cout << "UNDETERMINED" << endl;
}

int main()
{
	CarData car; vector<CarData> cars;
	ll T, D, n_search; cin >> T;

	while (T--)
	{
		cin >> D; cars.clear();
		for (ll i = 0; i < D; i++)
		{
			cin >> car.enterprise >> car.lowest >> car.highest;
			cars.push_back(car);
		}
		cin >> n_search;
		for (ll i = 0; i < n_search; i++)
			find_database(cars);
		if (T)
			cout << endl;
	}
	return 0;
}