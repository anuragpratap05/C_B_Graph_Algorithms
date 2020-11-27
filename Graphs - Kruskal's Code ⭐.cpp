# C_B_Graph_Algorithms
#include<bits/stdc++.h>
using namespace std;

class DSU
{
    int* parent;
    int* rank;
public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int i)
    {
        if (parent[i] == -1)
        {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class graph
{
    vector<vector<int>> edgelist;
    int V;
public:
    graph(int V)
    {
        this->V = V;
    }
    void addedge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }
    int kruksal_mst()
    {
        DSU d(V);
        sort(edgelist.begin(), edgelist.end());
        int ans = 0;
        for (auto edge : edgelist)
        {
            int weight = edge[0];
            int f = edge[1];
            int s = edge[2];
            if (d.find(f) != d.find(s))
            {
                d.unite(f, s);
                ans += weight;
            }
        }
        return ans;
    }
};
int main()
{
    graph g(4);
    g.addedge(0, 1, 1);
    g.addedge(0, 3, 3);
    g.addedge(3, 2, 4);
    g.addedge(2, 0, 2);
    g.addedge(0, 3, 2);
    g.addedge(1, 2, 2);

    cout << g.kruksal_mst() << endl;
}
