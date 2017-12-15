/* Resolvi este problema criando um vector de vector que guarda na posição[letra]'..
os índices sempre que [letra] aparece no texto.
Depois, como o vector em [letra] é ordenado naturalmente pela ordem em que eles aparecem,
resta fazer uma busca binária por toda a palavra atualizando a posição mínima possível 
de cada letra e fazendo tal busca por upper_bound. 
Obs: O vector de vector é desnessário e poderia ser substituido facilmente por um
array de vectors ou outra estrutura imaginária.*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long int ll;
typedef vector<ll> vct;
typedef vector< vector<ll> > vvct;

bool is_subset(vvct &data, string &beta, vct &sol) {
 	ll last_i;
 	vct::iterator low;

 	last_i = -1;
 	for(ll i = 0; i < beta.size(); i++) {
 			low = upper_bound(data.at(beta[i]).begin(), data.at(beta[i]).end(), last_i);

			if(low != data[beta[i]].end()) {
 				last_i = data.at(beta[i]).at(low - data.at(beta[i]).begin());
 				if(i == 0 || i + 1 == beta.size())
 					sol.push_back(data.at(beta[i]).at(low - data.at(beta[i]).begin()));
 			}
 			else return false;
 		}
 		return true;
 }

int main() { 
	vct sol; vvct data;
	string alpha, beta;
	ll Q;

	data.resize(1 << 8);

	cin >> alpha;
	for(ll i = 0; i < alpha.size(); i++) 
		data.at(alpha.at(i)).push_back(i);	
	
	cin >> Q;
	while(Q--) {
		cin >> beta;
		if(is_subset(data, beta, sol)) {
			printf("Matched ");
			printf("%ld %ld\n", sol.front(), sol.back());
		}
		else
			printf("Not matched\n");
		beta.clear(); sol.clear();
	}
	return 0;
}