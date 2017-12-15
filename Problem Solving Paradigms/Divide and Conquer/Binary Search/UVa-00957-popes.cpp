/* É suficiente procurar posição limite em anos (atual + período) e subtrair os índices
índice(atual + periodo) - índice(atual) para achar a quantidade de papas eleitos. Daí
resta selecionar a menor.
Como tal distância pode ser muito grande, use upper_bound ou lower_bound. */

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef long int ll;
typedef vector<ll> vct;

ll conquer(ll Y, ll P, vector<ll> const popes, vector<ll> &sol) {
	ll i_final, elected, b_electd;
	i_final = elected = b_electd = 0;

	for(ll i = 0; i < P; i++) {
		i_final = lower_bound(popes.begin() + i, popes.end(), 
			popes.at(i) + Y) - popes.begin();
		elected = i_final - i;
		if(b_electd < elected) {
			b_electd = elected;
			sol.clear();
			sol.push_back(popes.at(i));
			sol.push_back(popes.at(i_final-1));
		}
	}
	return b_electd;
}

int main(){ 
	ll Y, P, year;
	vector<ll> popes, sol;
	while(cin >> Y >> P) {		
		for(ll i = 0; i < P; i++) {
			cin >> year;
			popes.push_back(year);
		}
		printf("%ld ", conquer(Y, P, popes, sol));
		printf("%ld %ld\n", sol.front(), sol.back());
		popes.clear(); sol.clear();
	}
	return 0;
}