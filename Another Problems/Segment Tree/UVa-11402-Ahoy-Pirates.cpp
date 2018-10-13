#include <bits/stdc++.h>

#define pb push_back
#define pp pop_back
#define mp make_pair
#define lwb lower_bound
#define upb upper_bound
#define all(E) E.begin(), E.end()
#define e_min min_element
#define e_max max_element
#define bin_s binary_search
#define ff find

#define NOR 0
#define CLR 1
#define SET 2
#define FLP 3

#define left(idx) (idx << 1)
#define right(idx) ((idx << 1) + 1)

using namespace std;
typedef long int ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;

class SegmentTree {
private:
    vct arr, states, st;
public:
    void build(ll idx, ll L, ll R) {
        states[idx] = NOR;
        if(L == R) {
            st[idx] = arr[L];
        } else {
            ll mid = (L+R) >> 1;
            build(left(idx), L, mid);
            build(right(idx), mid+1, R);
            st[idx] = st[left(idx)] + st[right(idx)];
        }
    }
    //OK
    ll flipState(ll idx) {
        if(states[idx] == NOR)
            return FLP;
        if(states[idx] == FLP)
            return NOR;
        if(states[idx] == CLR)
            return SET;
        if(states[idx] == SET)
            return CLR;
    }
    void update(ll idx, ll L, ll R) {
        if(states[idx] == NOR)
            return;
        if(states[idx] == CLR)
            st[idx] = 0;
        if(states[idx] == SET)
            st[idx] = R - L + 1;
        if(states[idx] == FLP)
            st[idx] = (R - L + 1) - st[idx];
        if(L != R) {
            ll mid = (L+R) >> 1;
            if(states[idx] == CLR || states[idx] == SET)
                states[left(idx)] = states[right(idx)] = states[idx];
            else {
                states[left(idx)] = flipState(left(idx));
                states[right(idx)] = flipState(right(idx));
            }
        }
        states[idx] = NOR;
    }
    //OK
    ll RMQ(ll idx, ll i, ll j, ll L, ll R) {
        if(R < i || L > j) return 0;
        update(idx, L, R);
        if(i <= L && R <= j) {
            return st[idx];
        }
        else {
            ll mid = (L+R) >> 1;
            ll leftPath = RMQ(left(idx), i, j, L, mid);
            ll rightPath = RMQ(right(idx), i, j, mid+1, R);
            return leftPath + rightPath;
        }
    }
    //OK
    void resetInt(ll idx, ll i, ll j, ll L, ll R) {
        update(idx, L, R);
        if(R < i || L > j) return;
        ll mid = (L+R) >> 1;
        if(i <= L && R <= j) {
            st[idx] = 0;
            states[left(idx)] = states[right(idx)] = CLR;
            return;
        }
        resetInt(left(idx), i, j, L, mid);
        resetInt(right(idx), i, j, mid+1, R);
        st[idx] = st[left(idx)] + st[right(idx)];
    }
    void setInt(ll idx, ll i, ll j, ll L, ll R) {
        update(idx, L, R);
        if(R < i || L > j) return;
        ll mid = (L+R) >> 1;
        if(i <= L && R <= j) {
            st[idx] = R - L + 1;
                states[left(idx)] = states[right(idx)] = SET;
            return;
        }
        setInt(left(idx), i, j, L, mid);
        setInt(right(idx), i, j, mid+1, R);
        st[idx] = st[left(idx)] + st[right(idx)];
    }
    void flipInt(ll idx, ll i, ll j, ll L, ll R) {
        update(idx, L, R);
        if(R < i || L > j) return;
        ll mid = (L+R) >> 1;
        if(i <= L && R <= j) {
            st[idx] = (R - L + 1) - st[idx];
            states[left(idx)] = flipState(left(idx));
            states[right(idx)] = flipState(right(idx));
            return;
        }
        flipInt(left(idx), i, j, L, mid);
        flipInt(right(idx), i, j, mid+1, R);
        st[idx] = st[left(idx)] + st[right(idx)];
    }
//"The real ones"
    ll RMQ(ll i, ll j) { return RMQ(1, i, j, 0, arr.size()-1); }
    void reset(ll i, ll j) { resetInt(1, i, j, 0, arr.size()-1); }
    void set(ll i, ll j) { setInt(1, i, j, 0, arr.size()-1); }
    void flip(ll i, ll j) { flipInt(1, i, j, 0, arr.size()-1); }
//Initialization
    SegmentTree(vct &arr) {
        this->arr = arr;
        st.assign(4 * arr.size() + 1, 0);
        states.assign(4 * st.size(), 0);
        build(1, 0, arr.size()-1);
    }
};

int main() {
    ll T, N, M, Q, m, n;
    string my_str;
    cin >> T;
    for(ll i = 0; i < T; i++) {
        cin >> N;
        vct arr;
        for(ll j = 0; j < N; j++) {
            cin >> M;
            cin >> my_str;
            M = my_str.size() * M;
            for(ll k = 0; k < M; k++)
                arr.pb(my_str[k % my_str.size()] == '0' ? 0 : 1);
        }
        SegmentTree st(arr);
        cin >> Q;
        printf("Case %ld:\n", i+1);
        ll counter = 1;
        for(ll j = 0; j < Q; j++) {
            cin >> my_str >> m >> n;
            if(my_str == "F")
                st.set(m, n);
            else if(my_str == "E")
                st.reset(m, n);
            else if(my_str == "I")
                st.flip(m, n);
            else if(my_str == "S")
                printf("Q%ld: %ld\n", counter++, st.RMQ(m, n));

        }
    } return 0;
}
