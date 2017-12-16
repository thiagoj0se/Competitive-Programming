/* É suficiente procurar o valor que atende a função usando a técnica Divide and Conquer.
Nesse tipo de problema, observe [se existe] um valor que se maximiza ou não a função,
as condições que tornam impossível a solução, e as condições que mudam como a recursão deve 
ser chamada novamente caso seja provável uma solução. 
Neste problema, estude o que acontece com a função perto de -1, 0, 1, e inf. */ 

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef double ll;
typedef vector<ll> vct;

ll eval(ll IRR, const vct &cf) {
	ll sum = 0;
	for(ll i = 1; i < cf.size(); i++)
		sum += cf.at(i)/pow(1 + IRR, i);
	return sum;
}

bool conquer(ll bottom, ll top, const vct &cf, vct &sol) {
	if(bottom <= top) {
		ll mid = (bottom + top)/2.0;
		ll eval_mid = eval(mid, cf);
		
		if(abs(eval_mid - cf.front()) < 1e-9) {
			sol.push_back(mid);
			return true;
		}

		if(bottom >= 0 && top <= 1 && bottom <= top &&
			bottom <= eval_mid && eval_mid <= top) {
			if(eval_mid < cf.front())
				return conquer(mid, top, cf, sol);
			return conquer(bottom, mid, cf, sol);
		} else {
			if(eval_mid < cf.front())
				return conquer(bottom, mid, cf, sol);
			conquer(mid, top, cf, sol);
		}
	}
	else return false;	
}

int main(){ 
	vct cf, sol; ll T, num;
	while(cin >> T) {
		if(T) {
			for(ll i = 0; i < T + 1; i++) {
				cin >> num;
				cf.push_back(num);
			}
			cf.front() *= -1;
			if(conquer(-1, 1e+6, cf, sol)) {
				if(!(sol.size() - 1))
					printf("%.2lf\n", sol.front());
				else
					cout << "Too many" << endl;
			}
			else cout << "No" << endl;
		}
		else return 0;
		cf.clear(); sol.clear();
	}
}