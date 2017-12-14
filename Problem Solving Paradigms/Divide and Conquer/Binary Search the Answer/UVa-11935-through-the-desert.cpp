#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;
typedef double ll;

class Cmd
{
public:
	Cmd(int n);
	double consumed;
	double consume;
	double leak;
	double pos;
	
	string str;
	double num;
	double _max;

	bool get_cmd() {
		cin >> num >> str;

		consumed += (num - pos) * (consume/100.0 + leak); 
		_max = max(consumed, _max);
		pos = num;
		if(str == "Fuel") cin >> str >> consume;
		if(str == "Gas") {
			consumed = 0;
			cin >> str;
		}
		if(str == "Mechanic") leak = 0;
		if(str == "Goal") return false;
		if(str == "Leak") leak++;
		return true;
	}
};

Cmd::Cmd(int n = 0){
	consumed = 0;
	consume = n;
	leak = 0;
	pos = 0;
	_max = 0;
}

int main(){ 
	double n; string str;
	Cmd *car;

	while(cin >> n) {
		cin >> str >> str >> n;
		if(n) {
			car = new Cmd(n);
			while(car->get_cmd());
			printf("%.3lf\n", car->_max);
		}
		else break;
	}
}