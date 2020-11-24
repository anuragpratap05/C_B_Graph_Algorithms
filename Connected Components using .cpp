# C_B_Graph_Algorithms

#include<bits/stdc++.h>
using namespace std;

class graph
{
    map<int, list<int>> l;

public:
    void addedge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void print()
    {
        for (auto z : l)
        {
            int a = z.first;
            cout << a << "-->";
            list<int> nbrs = z.second;
            for (auto nbr : nbrs)
            {
                cout << nbr << ",";
            }
            cout << endl;
        }
        return;
    }

    void bfs_helper(int src, map<int, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;
        for (auto nbr : l[src])
        {
            if (!visited[nbr])
            {
                bfs_helper(nbr, visited);
            }
        }
        return;
    }

    void bfs(int src)
    {
        //queue<int> q;
        map<int, bool> visited;
        for (auto node_pair : l)
        {
            int node = node_pair.first;
            visited[node] = false;;
        }
        int cnt = 0;
        for (auto p : l)
        {   //cout << cnt << "-->";

            int node = p.first;
            if (!visited[node])
            {
                cout << cnt << "-->";
                bfs_helper(node, visited);
                cnt++;
                cout << endl;
            }

        }
    }
};

int main()
{
#ifndef ONLINE_jUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
#endif
    //graph g(4);
    graph g;
    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(0, 3);
    g.addedge(0, 4);
    g.addedge(5, 6);
    g.addedge(6, 7);
    g.addedge(8, 8);

    g.print();

    g.bfs(0);

}
