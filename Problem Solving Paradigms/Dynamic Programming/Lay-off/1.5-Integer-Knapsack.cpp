//A knapsack has max capacity C and there are n items each with weight w[i]
//and value v[i]. Maximize the value in the knapsack without exceeding its
//max capacity.

#include <bits/stdc++.h>
using namespace std;
typedef long long int Integer;

//Recursive non-DP solution
Integer recursiveKnapSack(Integer C, Integer n, Integer *w, Integer *v) {
    if(n < 0 || C < 0)
        return 0;
    return max(recursiveKnapSack(C, n - 1, w, v), v[n] + recursiveKnapSack(C - w[n], n - 1, w, v));
}

//Interative DP solution
Integer iterativeKnapSack(Integer C, Integer n, Integer *w, Integer *v) {
    Integer table[n + 1][C + 1];
    for(Integer i = 0; i <= n; i++) {
        for(Integer j = 0; j <= C; j++) {
            if(i == 0 || j == 0)
                table[i][j] = 0;
            else if(w[i-1] <= j)
                table[i][j] = max(v[i-1] + table[i-1][j - w[i-1]], table[i-1][j]);
            else
                table[i][j] = table[i-1][j];
        }
    }
    return table[n][C];
}


