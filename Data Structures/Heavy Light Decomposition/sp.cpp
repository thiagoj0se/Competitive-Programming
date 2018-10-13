#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define level 18

vector <int> tree[MAXN];
int depth[MAXN], charge[MAXN];
int parent[MAXN][level];

// pre-compute the depth for each node and their
// first parent(2^0th parent)
// time complexity : O(n)
void dfs(int cur, int prev)
{
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for (int i=0; i<tree[cur].size(); i++)
    {
        if (tree[cur][i] != prev)
            dfs(tree[cur][i], cur);
    }
}

// Dynamic Programming Sparse Matrix Approach
// populating 2^i parent for each node
// Time complexity : O(nlogn)
void precomputeSparseMatrix(int n)
{
    for (int i=1; i<level; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            if (parent[node][i-1] != -1)
                parent[node][i] =
                    parent[parent[node][i-1]][i-1];
        }
    }
}

// Returning the LCA of u and v
// Time complexity : O(log n)
int LCA(int u, int v)
{
    if (depth[v] < depth[u])
        swap(u, v);

    int diff = depth[v] - depth[u];

    // Step 1 of the pseudocode
    for (int i=0; i<level; i++)
        if ((diff>>i)&1)
            v = parent[v][i];

    // now depth[u] == depth[v]
    if (u == v)
        return u;

    // Step 2 of the pseudocode
    for (int i=level-1; i>=0; i--)
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }

    return parent[u][0];
}

void addEdge(int u,int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}

int query(int a, int b, int c, int d) {
    int lca_ab = LCA(a, b);

    int save_a = a, save_b = b;
    while(a != lca_ab) {
        charge[a] = 1;
        a = parent[a][0];
    }
    while(b != lca_ab) {
        charge[b] = 1;
        b = parent[b][0];
    }
    charge[lca_ab] = 1;

    int lca_cd = LCA(c, d);
    int sum = 0;

    while(c != lca_cd) {
        sum += charge[c];
        c = parent[c][0];
    }
    while(d != lca_cd) {
        sum += charge[d];
        d = parent[d][0];
    }
    sum += charge[lca_cd];

    a = save_a, b = save_b;
    while(a != lca_ab) {
        charge[a] = 0;
        a = parent[a][0];
    }
    while(b != lca_ab) {
        charge[b] = 0;
        b = parent[b][0];
    }
    charge[lca_ab] = 0;

    return sum;
}

int main() {
    int N, M, v1, v2, v3, v4;
    cin >> N >> M;

    for(int i=0;i<N-1; i++) {
        cin >> v1 >> v2;
        addEdge(v1,v2);
        charge[i] = 0;
    }
    charge[N-1] = 0;

    // running dfs and precalculating depth
    // of each node.
    dfs(1,0);

    // Precomputing the 2^i th ancestor for evey node
    precomputeSparseMatrix(N+1);
    for(int i=0; i<M; i++) {
        cin >> v1 >> v2 >> v3 >> v4;
        cout << query(v1, v2, v3, v4) << endl;
    }
    return 0;
}
