#include <stdio.h>
#include <limits.h>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int L, R, H, max_size; max_size = -1;
    vector<int> sol;

    int *map = new int[(int)pow(10, 4)];

    while(scanf("%d %d %d", &L, &H, &R) != EOF){
        for(int j = L; j < R; j++){
            if(map[j] < H)
                map[j] = H;
        }
        if(R > max_size)
            max_size = R;
    }

    int last; last = 0;
    for(int i = 0; i < R + 1; i++){
        if(map[i] != last){
            sol.push_back(i);
            sol.push_back(map[i]);
            last = map[i];
        }
    }

    printf("%d", sol.at(0));
    for(int i = 1; i < sol.size(); i++)
        printf(" %d", sol.at(i));
    return 0;
}
