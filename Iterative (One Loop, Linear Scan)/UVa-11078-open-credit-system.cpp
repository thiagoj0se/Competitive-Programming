//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2019

#include <iostream>
#include <limits.h>

using namespace std;
typedef long long int ll;

int main()
{
	ll T, N, score, score_ant; cin >> T;
	ll biggest, lowest, answer;

	while (T--)
	{
		cin >> N;
		biggest = INT_MIN; lowest = INT_MAX;
		score_ant = INT_MIN; answer = INT_MIN;

		for (ll i = 0; i < N; i++)
		{
			cin >> score;
			if (biggest < score_ant)
			{
				biggest = score_ant;
				lowest = INT_MAX;
			}
			lowest = min(lowest, score);
			answer = max(answer, biggest - lowest);
			score_ant = score;
		}
		cout << answer << endl;
	}
	return 0;
}