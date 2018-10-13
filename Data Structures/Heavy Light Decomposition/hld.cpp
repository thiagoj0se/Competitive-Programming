#include <bits/stdc++.h>

#define pb push_back
#define pp pop_back

using namespace std;
typedef long ll;
typedef vector<ll> vct;
typedef vector< vct > ADL;

#define MX 100001

ADL graph;

class HLD {
private:
    //Node related
    ll heavy[MX], depth[MX], set[MX], parent[MX],
       height[MX], chain_idx[MX], chain_iden[MX];
    vct chain[MX];
    bitset<MX> visited;
    ll chain_count;
public:
    HLD (ll source) {
        depth[source] = height[source] = 0;
        visited.reset();
        dfs(source, -1);
        chain_count = 0;
        build(source, chain_count++, 1);
    }
    ll dfs(ll v, ll p) {
        ll size = 1, preffered = 0; visited[v] = 1;
        parent[v] = p;
        for(ll i=0; i<graph[v].size(); i++) {
            ll cur = graph[v][i];
            if(cur == p || visited[cur]) continue;
            parent[cur] = v;
            height[cur] = height[v]+1;
            ll subtree = dfs(cur, v);
            if(subtree > preffered)
                heavy[v] = cur, preffered = subtree;
            size += subtree;
        }
        return size;
    }
    void build(ll v, ll ch, ll h) {
        chain_iden[v] = ch;
        chain_idx[v] = chain[ch].size();
        chain[ch].pb(v);
        for(ll i=0; i<graph[v].size(); i++) {
            ll cur = graph[v][i];
            if(cur != parent[v]) {
                if(cur == heavy[v]) {
                    build(cur, ch, h+1);
                } else {
                    set[chain_count] = v;
                    depth[chain_count] = h;
                    build(cur, chain_count++, h+1);
                }
            }
        }
    }
    ll LCA(ll v, ll u) {
        ll cv = chain_iden[v], cu = chain_iden[u];
        while(cv != cu) {
            if(depth[cv] > depth[cu])
                v = set[cv];
            else u = set[cu];
            cv = chain_iden[v], cu = chain_iden[u];
        }
        if(chain_idx[v] < chain_idx[u]) return v;
        return u;
    }
    ll dis(ll a, ll b){
        return depth[a] + depth[b] - 2*(depth[LCA(a, b)]);
    }
};

int main() {
    ll N, M, a, b, c, d;
    cin >> N >> M;
    graph.resize(MX);
    for(ll i=0;i<N-1; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    HLD dec(a);
    return 0;
}
