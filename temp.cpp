#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;

vvct M; //Matriz
vct values, lower, bigger; //Arrays
ll levels = 0; //Quantidade de niveis, útil para printar no final

void solve(ll idx, ll k) {
    //Condição de parada
    if(idx == -1)
        return;
    //Atualize a quantidade de niveis para a maior possível
    levels = max(levels, k);
    //Calcule os valores minimos e maximos nos filhos
    ll minimum = min(M[idx][0] != -1 ? values[M[idx][0]] : INT_MAX,
                    M[idx][1] != -1 ? values[M[idx][1]] : INT_MAX);
    ll maximum = max(M[idx][0] != -1 ? values[M[idx][0]] : INT_MIN,
                    M[idx][1] != -1 ? values[M[idx][1]] : INT_MIN);
    //Atualize os maiores e menores em cada nível
    lower[k] = min(lower[k], minimum);
    bigger[k] = max(bigger[k], maximum);
    //Chame para dois nós filhos
    //Aumentando o nível k em 1
    solve(M[idx][0], k+1);
    solve(M[idx][1], k+1);
}

int main() {
    ll N, weight, child;
    //Leia N
    cin >> N;
    //Aloque espaço
    M.resize(N);
    values.resize(N);
    lower.assign(N, INT_MAX);
    bigger.assign(N, INT_MIN);
    for(ll i=0; i<N; i++)
        M[i].assign(2, -1);
    //Leia a entrada
    for(ll i=0; i<N; i++) {
        cin >> weight;
        values[i] = weight;
        for(ll j=0; j<2; j++) {
            cin >> child;
            M[i][j] = child;
        }
    }
    //Resolva
    solve(0, 1);
    bigger[0] = lower[0] = values[0];
    for(ll i=0; i<levels; i++)
        printf("Nivel %ld: Maior = %ld, Menor = %ld\n", i+1, bigger[i]
                , lower[i]);
    return 0;
}
