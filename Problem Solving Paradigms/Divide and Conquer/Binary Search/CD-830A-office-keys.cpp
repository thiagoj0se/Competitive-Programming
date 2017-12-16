#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long int ll;
typedef vector<ll> vct;

ll count(vct const & positions, vct &keys, ll P) {
	vct::iterator it_min_next; ll count = 0;

	for(ll i = 0; i < positions.size(); i++) {
		it_min_next = lower_bound(keys.begin(), keys.end(), positions.at(i));
		if(it_min_next == keys.end()) {
			if(keys.size()) {
				it_min_next--;
			} else return count;
		}
		if(it_min_next - keys.begin() > 0)
			if(abs(keys.at(it_min_next - keys.begin()) - positions.at(i)) + abs(keys.at(it_min_next - keys.begin()) - P) > 
			abs(keys.at(it_min_next - keys.begin() - 1) - positions.at(i)) + abs(keys.at(it_min_next - keys.begin() - 1) - P))
				it_min_next--;

		count = max(count, abs(keys.at(it_min_next - keys.begin()) - positions.at(i)) + abs(keys.at(it_min_next - keys.begin()) - P));
		keys.erase(it_min_next);
	}	

	return count;
}
int main() {
	ll num, N, K, P;
	vct positions, keys;
	
	cin >> N >> K >> P;
	
	for(ll i = 0; i < N; i++) {
		cin >> num;
		positions.push_back(num);
	}
	for(ll i = 0; i < K; i++) {
		cin >> num;
		keys.push_back(num);
	}
	sort(positions.begin(), positions.end());
	sort(keys.begin(), keys.end());	
	cout << count(positions, keys, P);
	return 0;
}