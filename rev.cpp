#include <bits/stdc++.h>

#define pb push_back
#define pp pop_back
#define mp make_pair
#define lwb lower_bound
#define upb upper_bound
#define all(E) E.begin(), E.end()
#define bin_s binary_search
#define ff find

using namespace std;
typedef long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector< ii > vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

ll gcd(ll a, ll b) { return b == 0? a : gcd(b, a%b);}
ll lcm(ll a, ll b) { return a*(b/gcd(a,b));}

//Math related
VL sieve_ls;
vct primes;
void Sieve() {
    ll sieve_size = 1 << 20;
    sieve_ls.set();
    sieve_ls[0] = sieve_ls[1] = 0;
    for(ll i = 2; i < sieve_size; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < sieve_size; j+=i)
                sieve_ls[j] = 0;
            primes.pb(i);
        }
    }
}

ll numDiv(ll N) {
    ll sqrtN = sqrt(N);
    vii fact;
    for(ll i = 0; primes[i] < sqrtN; i++) {
        if(N % primes[i] == 0) {
            N /= primes[i];
            if(fact.size()) {
                if(fact[fact.size()-1].first == primes[i])
                    fact[fact.size()-1].second++;
                else fact.pb(mp(primes[i], 1));
            } else fact.pb(mp(primes[i], 1));
        }
    }
    if(N > 1)
        fact.pb(mp(N, 1));
    ll ans = 1;
    for(ll i = 0; i < fact.size(); i++)
        ans *= (fact[i].second + 1);
    return ans;
}

ll sumDiv(ll N) {
    ll sqrtN = sqrt(N);
    vii fact;
    for(ll i = 0; primes[i] < sqrtN; i++) {
        if(N % primes[i] == 0) {
            N /= primes[i];
            if(fact.size()) {
                if(fact[fact.size()-1].first == primes[i])
                    fact[fact.size()-1].second++;
                else fact.pb(mp(primes[i], 1));
            } else fact.pb(mp(primes[i], 1));
        }
    }
    if(N > 1)
        fact.pb(mp(N, 1));
    ll ans = 1;
    for(ll i = 0; i < fact.size(); i++)
        ans *= (pow(fact[i].first, fact[i].second + 1) - 1)/(fact[i].first - 1);
    return ans;
}

ll eulerPhi(ll N) {
    ll sqrtN = sqrt(N);
    vii fact;
    for(ll i = 0; primes[i] < sqrtN; i++) {
        if(N % primes[i] == 0) {
            N /= primes[i];
            if(fact.size()) {
                if(fact[fact.size()-1].first == primes[i])
                    fact[fact.size()-1].second++;
                else fact.pb(mp(primes[i], 1));
            } else fact.pb(mp(primes[i], 1));
        }
    }
    if(N > 1)
        fact.pb(mp(N, 1));
    double ans = N;
    for(ll i = 0; i < fact.size(); i++)
        ans *= (1.0 - 1.0/fact[i].first);
    return ans;
}

//Graph
void Kahn(ll source) {
    vvct graph;
    vct degree, topo;
    queue<ll> quu;
    //Queue operations:
    // quu.front(), quu.push(), quu.pop()
    quu.push(source);
    while(!quu.empty()) {
        ll cur = quu.front();
        topo.pb(cur);
        for(ll i = 0; i < graph[cur].size(); i++) {
            degree[graph[cur][i]]--;
            if(degree[graph[cur][i]] == 0)
                quu.push(graph[cur][i]);
        }
    }
}

void bipartite(ll source) {
    vvct graph;
    queue<ll> quu;
    quu.push(source);
    #define CLR -1
    vct color(graph.size(), CLR);
    color[source] = 0;
    bool isBipartite = true;
    while(!quu.empty() && !isBipartite) {
        ll cur = quu.front();
        for(ll i = 0; i < graph[cur].size(); i++) {
            ll v = graph[cur][i];
            if(color[v] == CLR) {
                color[v] = 1 - color[cur];
                quu.push(v);
            } else {
                if(color[v] == color[cur]) {
                    isBipartite = false;
                    break;
                }
            }
        }
    }
}

vct taken;
ADL graph;
priority_queue<ii> pqu;
//Priority queue operations
// pqu.top(), pqu.push(), pqu.pop()
void process(ll vertex) {
    taken[vertex] = 1;
    for(ll i = 0; i < graph[vertex].size(); i++) {
        ll adj_vertex = graph[vertex][i].first;
        ll weight = graph[vertex][i].second;
        if(!taken[adj_vertex]) {
            pqu.push(mp(-weight, -adj_vertex));
        }
    }
}

void prim() {
    ll mst_cost;
    while(!pqu.empty()) {
        ii cur = pqu.top();
        ll weight = -cur.first;
        ll vertex = -cur.second;
        if(!taken[vertex]) {
            mst_cost += weight;
            process(vertex);
        }
    }
}

void dijsktra(ll source) {
    vct dist;
    pqu.push(mp(0, -source));
    dist[source] = 0;
    while(!pqu.empty()) {
        ii cur = pqu.top();
        ll weight = -cur.first;
        ll vertex = -cur.second;
        for(ll j = 0; j < graph[vertex].size(); j++) {
            ii next = graph[vertex][j];
            ll adj_v = next.first;
            ll weight = next.second;
            if(dist[adj_v] > dist[vertex] + weight) {
                dist[adj_v] = dist[vertex] + weight;
                pqu.push(ii(dist[adj_v], adj_v));
            }
        }
    }
}

void SPFA(ll source) {
    queue<ll> quu;
    vct visited, dist;
    quu.push(source);
    while(!quu.empty()) {
        ll cur = quu.front();
        visited[cur] = 0;
        for(ll i = 0; i < graph[cur].size(); i++) {
            ll adj_v = graph[cur][i].first;
            ll weight = graph[cur][i].second;
            dist[adj_v] = min(dist[adj_v], dist[cur] + weight);
            if(!visited[adj_v]) {
                visited[adj_v] = 1;
                quu.push(adj_v);
            }
        }
    }
}

void Bellman() {
    ll V = graph.size();
    vct dist(V, 1000000);
    dist[0] = 0;
    for(ll i = 0; i < V -1; i++) {
        for(ll u = 0; u < V; u++) {
            for(ll j = 0; j < graph[u].size(); j++) {
                ii cur = graph[u][j];
                dist[cur.first] = min(dist[cur.first], dist[u] + cur.second);
            }
        }
    }
}

void Floyd() {
    ll V = graph.size();
    ll min_dist[V][V];
    for(ll k = 0; k < V; k++) {
        for(ll i = 0; i < V; i++) {
            for(ll j = 0; j < V; j++) {
                min_dist[i][j] = min(min_dist[i][j], min_dist[i][k] + min_dist[k][j]);
            }
        }
    }
}

list<ll> tour;
void EulerTour(list<ll>::iterator i, ll u) {
    for(ll j = 0; j < graph[u].size(); j++) {
        ii next = graph[u][j];
        ll adj_vertex = next.first;
        ll weight = next.second;
        if(weight) {
            weight = 0;
            for(ll k = 0; k < graph[adj_vertex].size(); k++) {
                ii rev = graph[adj_vertex][k];
                if(rev.first == u && rev.second != 0) {
                    rev.second = 0;
                    break;
                }
            }
            EulerTour(tour.insert(i, u), adj_vertex);
        } 
    }
}

class UnionFind {
private:
    vct p,rank;
public:
    UnionFind(ll N) {
        rank.assign(N, 0);
        p.resize(N);
        for(ll i = 0; i < N; i++)
            p[i] = i;
    }
    ll findSet(ll idx) { return p[idx] == idx ? idx : findSet(p[idx]); }
    ll isSameSet(ll a, ll b) { return findSet(a) == findSet(b); }
    void UnionSet(ll a, ll b) {
        if(!isSameSet(a, b)) {
            if(rank[a] > rank[b]) {
                p[b] = a;
            } else {
                p[a] = b;
                if(rank[a] == rank[b])
                    rank[b]++;
            }
        }
    }
};

class FenwickTree {
private:
    vct ft;
public:
    FenwickTree(ll N) {
        ft.assign(N+1, 0);
    }
    ll rsq(ll idx) {
        ll sum = 0;
        for(; idx; idx -= (idx&-idx))
            sum += ft[idx];
        return sum;
    }
    void adjust(ll idx, ll value) {
        for(; idx < ft.size(); idx += (idx & -idx)) 
            ft[idx] += value;
    }
};

class SparseTable {
private:
    vvct spt;
    vct arr;
    ll N;
public:
    SparseTable(vct &arr) {
        this->arr = arr;
        N = arr.size();
        spt.resize(N);
        for(ll i = 0; i < N; i++) {
            spt[i].resize((ll)log2(N) + 1);
            spt[i][0] = i;
        }
        for(ll j = 1; (1<<j) < N; j++) {
            for(ll i = 0; i + (1<<j) - 1 < N; i++) {
                if(arr[spt[i][j-1]] < arr[spt[i+(1<<(j-1))][j-1]])
                    spt[i][j] = spt[i][j-1];
                else
                    spt[i][j] = spt[i+(1<<(j-1))][j-1];
            }
        }
    }
    ll query(ll i, ll j) {
        ll k = log2(j - i + 1);
        return min(spt[i][k], spt[j-(1<<k)+1][k]); 
    }
};

ll LIS(vct &arr) {
    if(!arr.size())
        return 0;
    vct subs;
    ll len = 1;
    subs.assign(arr.size()+1, INT_MAX);
    for(ll i = 0; i < arr.size(); i++) {
        if(arr[i] < subs[0]) {
            subs[0] = arr[i];
        } else if(arr[i] > subs[len-1]) {
            subs[len++] = arr[i];
        } else {
            ll idx = lwb(subs.begin(), subs.begin() + len, arr[i]) -  subs.begin();
            subs[idx] = arr[i];
        }
    }
    return len;
}








