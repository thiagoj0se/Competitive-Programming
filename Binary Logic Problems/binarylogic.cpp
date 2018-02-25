#include <bits/stdc++.h>

#define pb push_back
using namespace std;
typedef vector<unsigned> vct;
typedef unsigned bit;

bit X, Y;
string entry;

void eval(unsigned m) {
    for(int i = 0; i < entry.size(); i++) {
        if(entry[i] == '(')
            for(int j = i; i < entry.size(); j++)
                if(entry[j] == ')') {
                    entry.erase(entry.begin() + i);
                    entry.erase(entry.begin() + j - 1);
                    eval(i);
                    break;
                }

    if(entry.size() >= 3) {
        vct answer; char oper; bool flip;
        while(answer.size() < 2) {
            if(entry[m] == '~') {
                flip = !flip;
            } else {
                if(entry[m] == '1') answer.pb(1);
                else if(entry[m] == '0') answer.pb(0);
                else if(entry[m] == 'X') answer.pb(X);
                else if(entry[m] == 'Y') answer.pb(Y);
                else oper = entry[m];
                if((entry[m] == '1' || entry[m] =='0' ||
                   entry[m] == 'X' || entry[m] == 'Y') && flip)
                    answer.back() = !answer.back();
            }
            entry.erase(entry.begin() + m);
        }
        unsigned AND =  answer.front() && answer.back(),
                 OR  =  answer.front() || answer.back(),
                 NAND = (answer.front() == answer.back() ? 1 : 0),
                 NOR  = (answer.front() != answer.back() ? 1 : 0);
        if(oper == '.')
            entry.insert(m, to_string(AND));
        else if(oper == '+')
            entry.insert(m, to_string(OR));
        else if(oper == '&')
            entry.insert(m, to_string(NAND));
        else if(oper == '|')
            entry.insert(m, to_string(NOR));
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
