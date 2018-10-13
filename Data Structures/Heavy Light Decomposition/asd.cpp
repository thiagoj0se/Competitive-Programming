#include "bits/stdc++.h" 
using namespace std; 
#define sz 100001
  
vector < int > adj[sz];    // stores the tree 
vector < int > euler;      // tracks the eulerwalk 
vector < int > depthArr;   // depth for each node corresponding 
                           // to eulerwalk 
  
int FAI[sz];     // stores first appearence index of every node 
int level[sz];   // stores depth for all nodes in the tree 
int ptr;         // pointer to euler walk 
int dp[sz][18];  // sparse table 
int logn[sz];    // stores log values 
int p2[20];      // stores power of 2 
  
void buildSparseTable(int n) 
{ 
    // initializing sparse table 
    memset(dp,-1,sizeof(dp)); 
  
    // filling base case values 
    for (int i=1; i<n; i++) 
        dp[i-1][0] = (depthArr[i]>depthArr[i-1])?i-1:i; 
  
    // dp to fill sparse table 
    for (int l=1; l<15; l++) 
      for (int i=0; i<n; i++) 
        if (dp[i][l-1]!=-1 and dp[i+p2[l-1]][l-1]!=-1) 
          dp[i][l] = 
            (depthArr[dp[i][l-1]]>depthArr[dp[i+p2[l-1]][l-1]])? 
             dp[i+p2[l-1]][l-1] : dp[i][l-1]; 
        else
             break; 
} 
  
int query(int l,int r) 
{ 
    int d = r-l; 
    int dx = logn[d]; 
    if (l==r) return l; 
    if (depthArr[dp[l][dx]] > depthArr[dp[r-p2[dx]][dx]]) 
        return dp[r-p2[dx]][dx]; 
    else
        return dp[l][dx]; 
} 
  
void preprocess() 
{ 
    // memorizing powers of 2 
    p2[0] = 1; 
    for (int i=1; i<18; i++) 
        p2[i] = p2[i-1]*2; 
  
    // memorizing all log(n) values 
    int val = 1,ptr=0; 
    for (int i=1; i<sz; i++) 
    { 
        logn[i] = ptr-1; 
        if (val==i) 
        { 
            val*=2; 
            logn[i] = ptr; 
            ptr++; 
        } 
    } 
} 
  
/** 
 * Euler Walk ( preorder traversal) 
 * converting tree to linear depthArray 
 * Time Complexity : O(n) 
 * */
void dfs(int cur,int prev,int dep) 
{ 
    // marking FAI for cur node 
    if (FAI[cur]==-1) 
        FAI[cur] = ptr; 
  
    level[cur] = dep; 
  
    // pushing root to euler walk 
    euler.push_back(cur); 
  
    // incrementing euler walk pointer 
    ptr++; 
  
    for (auto x:adj[cur]) 
    { 
        if (x != prev) 
        { 
            dfs(x,cur,dep+1); 
  
            // pushing cur again in backtrack 
            // of euler walk 
            euler.push_back(cur); 
  
            // increment euler walk pointer 
            ptr++; 
        } 
    } 
} 
  
// Create Level depthArray corresponding 
// to the Euler walk Array 
void makeArr() 
{ 
    for (auto x : euler) 
        depthArr.push_back(level[x]); 
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

int query(int a, int b, int c, int d) {
    int lca_ab = LCA(a,b), lca_cd = LCA(c, d);

    if(LCA(lca_ab, c) != lca_ab && LCA(lca_ab, d) != lca_ab)
        return 0;

    if(LCA(lca_cd, a) != lca_cd && LCA(lca_cd, b) != lca_cd)
        return 0;

    int left =  max(abs(depth[LCA(a,c)]-depth[lca_ab]),
        abs(depth[LCA(b,c)] - depth[LCA(a,b)]));

    int right = max(abs(depth[LCA(a,d)]-depth[lca_ab]),
        abs(depth[LCA(b,d)] - depth[LCA(a,b)]));

    return left + right + 1;
}

void addEdge(int u,int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}

int main() {
    int N, M, v1, v2, v3, v4;
    cin >> N >> M;
    for(int i=0;i<N-1; i++) {
        cin >> v1 >> v2;
        addEdge(v1, v2);
    }
    dfs(1, 0);
    for(int i=0; i<M; i++) {
        cin >> v1 >> v2 >> v3 >> v4;
        cout << query(v1, v2, v3, v4) << endl;
    }
    return 0;
}
