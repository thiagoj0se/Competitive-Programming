#include <bits/stdc++.h>

#define pb push_back
using namespace std;
typedef vector<unsigned> vct;
typedef unsigned bit;

bit X, Y;
string entry;

void eval(unsigned m) {
    for(int i = 0; i < entry.size(); i++) {
        if(entry[i] == '(') {
            for(int j = i; i < entry.size(); j++) {
                if(entry[j] == ')') {
                    entry.erase(entry.begin() + i);
                    entry.erase(entry.begin() + j - 1);
                    eval(i);
                    break;
                }
            }
        }
    }

    if(entry.size() >= 3) {
        vct answer; char oper;
        while(answer.size() < 2) {
            if(entry[m] == '1') answer.pb(1);
            else if(entry[m] == '0') answer.pb(0);
            else if(entry[m] == 'X') answer.pb(X);
            else if(entry[m] == 'Y') answer.pb(Y);
            else oper = entry[m];
            entry.erase(entry.begin() + m);
        }
        unsigned left = answer.front() && answer.back();
        unsigned right = answer.front() || answer.back();
        if(oper == '.')
            entry.insert(m, to_string(left));
        else if(oper == '+')
            entry.insert(m, to_string(right));
    }
    return;
}

int main() {
    char key;
    cout << "Guide: . is AND, + is OR, ~ is NOT." << endl
         << "Type values of X and Y: " << endl;
    cin >> X >> Y; getchar();
    cout << "Now type your expression:" << endl;
    while(scanf("%c", &key), key != '\n') {
        if(key != ' ') entry.pb(key);
    }
    eval(0);
    cout << "Result: "<< endl << entry << endl;
    return 0;
}
