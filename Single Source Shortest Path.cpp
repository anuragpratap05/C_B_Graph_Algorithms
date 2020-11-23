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

	void bfs(int src)
	{
		queue<int> q;
		map<int, int> dist;
		for (auto node_pair : l)
		{
			int node = node_pair.first;
			dist[node] = INT_MAX;
		}
		q.push(src);
		dist[src] = 0;

		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			//cout << node << " ";
			for (auto nbr : l[node])
			{
				if (dist[nbr] == INT_MAX)
				{
					q.push(nbr);
					dist[nbr] = dist[node] + 1;
				}
			}

		}
		for (auto z : dist)
		{
			//int node = node_pair.first;
			//int d = dist[node];
			//cout << node << " is at distance " << d << " from source" << endl;
			cout << z.first << "is at distance" << " " << z.second << "from source" << endl;
		}
	}




};

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
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
