//Counts the number of expressions containing n pairs of parentheses which are correctly
//matched. (e.g. C(3) = 5 represents - ((())) ()(()) ()()() (())() (()()) - )

#include <bits/stdc++.h>
typedef long long int Integer;

Integer getCatalanNumber(Integer n, Integer *table) {
    if(table[n])
        return table[n];
    if(n == 1)
        return table[n] = 1;

    Integer sum = 0;
    for(Integer i = 0; i < n; i++) {
        sum += getCatalanNumber(i, table) * getCatalanNumber(n - i - 1, table);
    }

    return table[n] = sum;
}

Integer getCatalanNumberFaster(Integer n, Integer *table) {
    if(table[n])
        return table[n];
    if(n == 1)
        return table[n] = 1;

    Integer sum = 0;
    for(Integer i = 0; i < n/2; i++) {
        sum += getCatalanNumber(i, table) * getCatalanNumber(n - i - 1, table);
    }

    sum *= 2;
    if(!(n % 2)) {
        sum += getCatalanNumber(n, table) * getCatalanNumber(n, table);
    }

    return table[n] = sum;
}

int main() {

}


