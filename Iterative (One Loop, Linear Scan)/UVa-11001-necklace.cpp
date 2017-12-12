//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1942

#include <iostream>
#include <math.h>

using namespace std;
typedef double ll;

ll comp(ll x, ll y)
{
	return (abs(x - y) < pow(10, -6));
}

ll diam(ll V, ll Vo)
{
	if (V <= Vo)
		return 0;
	else
		return 0.3*sqrt(V - Vo);
}

ll explore(ll V, ll Vo)
{
	ll save_i, bigger, result;
	bigger = 0;  save_i = 0;

	for (ll i = 1; V / i > Vo; i++)
	{
		result = i*diam(V / i, Vo);
		if (result >= bigger)
		{
			if (comp(result, bigger)) 
				return 0;
			save_i = i;
			bigger = result;
		}
	}

	return save_i;
}

int main()
{
	ll V, Vo;

	while (true)
	{
		cin >> V >> Vo;
		if (V == Vo && !V)
			return 0;
		else
			cout << explore(V, Vo) << endl;
	}
	return 0;
}