#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef int ll;
typedef vector<ll> vct;

int main(){ 
	ll N, Q, number,  sol; int counter; 
	vector<ll>::iterator it;
	vector<ll> marble, querie;

	counter = 0;
	while(cin >> N >> Q) {
		if(N || Q) {
			printf("CASE# %d:\n", ++counter);
			while(N--) {
				cin >> number;
				marble.push_back(number);
			}
			while(Q--) {
				cin >> number;
				querie.push_back(number);
			}
			sort(marble.begin(), marble.end());
			for(ll i = 0; i < querie.size(); i++) {
				sol = lower_bound(marble.begin(), marble.end(), querie.at(i)) - marble.begin();
				if(sol < marble.size()) {
					if(marble.at(sol) == querie.at(i)) 
						printf("%d found at %d\n", querie.at(i), sol + 1);
					else
						printf("%d not found\n", querie.at(i));
				}
				else
					printf("%d not found\n", querie.at(i));
			}			
		} else return 0;
		querie.clear(); marble.clear();
	}
}