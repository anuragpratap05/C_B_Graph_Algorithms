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
    graph g(6);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(2, 5);
    g.addedge(3, 5);
    g.addedge(1, 4);
    g.addedge(4, 5);

    g.topological();
}
