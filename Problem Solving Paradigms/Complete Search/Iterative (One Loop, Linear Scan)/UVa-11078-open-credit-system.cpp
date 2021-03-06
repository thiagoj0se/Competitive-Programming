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

int main() {
	ll T, N, score, score_ant; cin >> T;
	ll biggest, lowest, answer;

	while (T--)	{
		cin >> N;
		biggest = INT_MIN; lowest = INT_MAX;
		score_ant = INT_MIN; answer = INT_MIN;
		for (ll i = 0; i < N; i++) {
			cin >> score;
			if (biggest < score_ant) {
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