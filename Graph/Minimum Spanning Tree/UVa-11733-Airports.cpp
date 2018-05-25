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

using namespace std;
typedef long int ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

#define INF -1

ADL graph;
vct taken;
vct min_dist;
priority_queue< pair<ll, ii> > pq;
ll total_cost, airport_count;

void process(ll vertex) {
    taken[vertex] = 1;
    for(ll i = 0; i < graph[vertex].size(); i++) {
        ii current = graph[vertex][i];
        ll weight = current.second;
        ll adj_vertex = current.first;
        if(!taken[adj_vertex]) {
            pq.push(mp(-weight, mp(-vertex, -adj_vertex)));
        }
    }
    return;
}

void prim(ll source, ll airport_cost) {
    min_dist[source] = 0;
    total_cost += airport_cost; airport_count++;
    process(source);
    while(!pq.empty()) {
        pair<ll, ii> current = pq.top(); pq.pop();
        ll weight = -current.first;
        ii edge = current.second;
        ll vertex = -edge.first;
        ll adj_vertex = -edge.second;

        if(!taken[adj_vertex]) {
            if(!min_dist[vertex]) {
                if(2*airport_cost <= weight) {
                    total_cost +=airport_cost; airport_count++;
                    min_dist[adj_vertex] = 0;
                } else {
                    total_cost += weight;
                    min_dist[adj_vertex] = 1;
                }
            } else {
                if(airport_cost <= weight) {
                    total_cost += airport_cost; airport_count++;
                    min_dist[adj_vertex] = 0;
                } else {
                    total_cost += weight;
                    min_dist[adj_vertex] = 1;
                }

            }
            process(adj_vertex);
        }
    }
    return;
}

int main() {
    ll T, N, M, A;
    ll v1, v2, cost;

    cin >> T;
    for(ll i = 0; i < T; i++) {
        cin >> N >> M >> A;
        graph.clear();
        graph.resize(N + 1);
        taken.assign(N + 1, 0);
        min_dist.assign(N + 1, 1);
        total_cost = airport_count = 0;

        for(ll j = 0; j < M; j++) {
            cin >> v1 >> v2 >> cost;
            graph[v1].pb(mp(v2, cost));
            graph[v2].pb(mp(v1, cost));
        }

        for(ll j = 1; j <= N; j++) {
            if(!taken[j])
                prim(j, A);
        }
        if(i) cout << endl;
        printf("Case #%ld: %ld %ld", i + 1, total_cost, airport_count);
    }
    return 0;
}
