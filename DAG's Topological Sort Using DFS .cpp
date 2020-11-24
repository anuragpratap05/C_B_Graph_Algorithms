# C_B_Graph_Algorithms

#include<bits/stdc++.h>
using namespace std;

class graph
{
    map<string, list<string>> l;

public:
    void addedge(string x, string y)
    {
        l[x].push_back(y);
        //l[y].push_back(x);
    }

    /*void print()
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
    }*/

    void bfs_helper(string src, map<string, bool> &visited, list<string> & ordering)
    {
        //cout << src << " ";
        visited[src] = true;
        for (auto nbr : l[src])
        {
            if (!visited[nbr])
            {
                bfs_helper(nbr, visited, ordering);
            }
        }
        ordering.push_front(src);
        return;
    }

    void bfs()
    {
        //queue<string> q;
        map<string, bool> visited;
        list<string> ordering;
        for (auto node_pair : l)
        {
            string node = node_pair.first;
            visited[node] = false;;
        }

        for (auto p : l)
        {   //cout << cnt << "-->";

            string node = p.first;
            if (!visited[node])
            {

                bfs_helper(node, visited, ordering);

                //cout << endl;
            }

        }
        for (auto z : ordering)
        {
            cout << z << endl;
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
    g.addedge("python", "data preprocessing");
    g.addedge("python", "pytorch");
    g.addedge("python", "ML");
    g.addedge("data preprocessing", "ML");
    g.addedge("pytorch", "DL");
    g.addedge("ML", "DL");
    g.addedge("DL", "face recognition");
    g.addedge("data set", "face recognition");

    //g.print();

    g.bfs();

}
