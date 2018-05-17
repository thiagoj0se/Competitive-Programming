//Given an array of integers, compute the largest sum continuous sub-array
//Kadane algorithm

#include <bits/stdc++.h>
using namespace std;
typedef long long int Integer;

Integer maxSubArraySum(const vector <Integer> &array) {
    Integer max_so_far, max_sum_ending_here;
    max_so_far = max_sum_ending_here = 0;

    for(Integer i = 0; i < array.size(); i++) {
        max_sum_ending_here += array[i];
        if(max_sum_ending_here < 0) {
            max_sum_ending_here = 0;
        }
        if(max_sum_ending_here > max_so_far) {
            max_so_far = max_sum_ending_here;
        }
    }
    return max_so_far;
}

int main() {

}

