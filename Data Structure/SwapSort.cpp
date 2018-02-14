/*
 * Worst-case performance: O(n2) comparisons, swaps
 * Best-case performance: O(n) comparisons, O(1) swaps
 * Average performance: O(n2) comparions, swaps
 * Worst-case space complexity: O(n) total, O(1) auxiliary
*/

#include <bits/stdc++.h>

void SwapSort(int *array, int n) {
    int key, i, j;
    for(i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void RecursiveSwapSort(int *array, int n) {
    if(n <= 1) return;
    RecursiveSwapSort(array, n - 1);
    int key, j;
    key = array[n - 1];
    j = n - 2;
    while(j >= 0 && array[j] > key) {
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = key;
}

int main() {
}
