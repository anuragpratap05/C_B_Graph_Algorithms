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

        bfs_helper(src, visited);

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
    g.addedge(3, 0);
    g.addedge(3, 4);
    g.addedge(4, 5);

    g.bfs(0);

}
