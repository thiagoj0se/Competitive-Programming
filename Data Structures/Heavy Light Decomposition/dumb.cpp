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
    ll chain_count;
public:
    HLD (ll source) {
        depth[source] = height[source] = 0;
        dfs(source, -1);
        chain_count = 0;
        build(source, chain_count++, 1);
    }
    ll dfs(ll v, ll p) {
        ll size = 1, preffered = 0;
        parent[v] = p;
        for(ll i=0; i<graph[v].size(); i++) {
            ll cur = graph[v][i];
            if(cur == p) continue;
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
    ll query(ll a, ll b, ll c, ll d) {
        ll lca_ab = LCA(a,b), lca_cd = LCA(c, d);
        if(LCA(lca_ab, c) != lca_ab && LCA(lca_ab, d) != lca_ab)
            return 0;
        if(LCA(lca_cd, a) != lca_cd && LCA(lca_cd, b) != lca_cd)
            return 0;
        ll left =  max(abs(height[LCA(a,c)]-height[lca_ab]),
            abs(height[LCA(b,c)] - height[LCA(a,b)]));
        ll right = max(abs(height[LCA(a,d)]-height[lca_ab]),
            abs(height[LCA(b,d)] - height[LCA(a,b)]));
        return left + right + 1;
    }
};

int main() {
    ll N, M, v1, v2, v3, v4;
    cin >> N >> M;
    graph.resize(MX);
    for(ll i=0;i<N-1; i++) {
        cin >> v1 >> v2;
        graph[v1].pb(v2);
        graph[v2].pb(v1);
    }
    HLD decomp(v1);
    return 0;
    for(ll i=0; i<M; i++) {
        cin >> v1 >> v2 >> v3 >> v4;
        //cout << decomp.query(v1, v2, v3, v4) << endl;
    }
    return 0;
}
