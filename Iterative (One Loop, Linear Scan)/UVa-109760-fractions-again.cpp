//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1917

#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef int ll;

class Sol
{
public:
	ll x, y;
};

void find(ll k, vector<Sol> &solutions)
{
	Sol sol;
	for (ll y = 2 * k; y > k; y--)
		if (!((y * k) % (y - k)))
		{
			sol.x = (y * k) / (y - k); sol.y = y;
			solutions.push_back(sol);
		}
	return;
}

int main()
{
	ll k;
	vector<Sol> solutions;
	while (cin >> k)
	{
		find(k, solutions);
		cout << solutions.size() << endl;
		for (ll i = solutions.size() - 1; i >= 0; i--)
			printf("1/%d = 1/%d + 1/%d\n", k, solutions.at(i).x, solutions.at(i).y);
		solutions.clear();
	}
	return 0;
}