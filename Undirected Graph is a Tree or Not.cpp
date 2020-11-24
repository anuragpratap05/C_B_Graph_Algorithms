# C_B_Graph_Algorithms
#include<bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    list<int> *l;
public:
    graph(int V)
    {
        this->V = V;
        l = new list<int>[V];

    }
    void addedge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool is_cyclic()
    {
        bool* visited = new bool[V];
        int* parent = new int[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            parent[i] = i;
        }
        queue<int> q;
        int src = 0;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto nbr : l[node])
            {
                if (visited[nbr] == true and parent[node] != nbr)
                {
                    return false;
                }
                else if (!visited[nbr])
                {
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return true;
    }

    void topological()
    {
        int* indegree = new int[V];
        for (int i = 0; i < V; i++)
        {
            indegree[i] = 0;
        }

        for (int i = 0; i < V; i++)
        {
            for (auto y : l[i])
            {
                indegree[y]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << ",";
            for (auto z : l[node])
            {
                indegree[z]--;
                if (indegree[z] == 0)
                {
                    q.push(z);
                }
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
    graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 3);
    g.addedge(3, 6);
    g.addedge(1, 2);


    if (g.is_cyclic())
    {
        cout << "graph has not any cycle";
    }
    else
    {
        cout << "graph has cycle";
    }
}
