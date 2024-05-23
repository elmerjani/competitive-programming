#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            // Union by rank
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                ++rank[rootU];
            }
        }
    }

    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }
};

class Graph {
private:
    int V;
    vector<vector<int>> adj;
    vector<int> disc, low, sccId;
    stack<int> st;
    vector<bool> inStack;
    int time, sccCount;

    void SCCUtil(int u, DSU &dsu);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void findSCCs(DSU &dsu);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
    disc.resize(V, -1);
    low.resize(V, -1);
    sccId.resize(V, -1);
    inStack.resize(V, false);
    time = 0;
    sccCount = 0;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::SCCUtil(int u, DSU &dsu) {
    disc[u] = low[u] = ++time;
    st.push(u);
    inStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            SCCUtil(v, dsu);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        while (st.top() != u) {
            int v = st.top();
            st.pop();
            inStack[v] = false;
            sccId[v] = sccCount;
            dsu.unionSets(u, v);
        }
        int v = st.top();
        st.pop();
        inStack[v] = false;
        sccId[v] = sccCount;
        dsu.unionSets(u, v);
        ++sccCount;
    }
}

void Graph::findSCCs(DSU &dsu) {
    for (int i = 0; i < V; ++i) {
        if (disc[i] == -1) {
            SCCUtil(i, dsu);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> val(V);
    for (int i = 1; i <= V; ++i) {
        cin >> val[i];
    }
    Graph g(V);
    DSU dsu(V);

    for (int i = 0; i < E; ++i) {
        int v, w;
        cin >> v >> w;
        if(!((val[w]%2)^(val[v]%2)))g.addEdge(v, w);
        
    }

    g.findSCCs(dsu);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        if (dsu.isConnected(a, b)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
