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
		map<int, bool> visited;
		q.push(src);
		visited[src] = true;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			cout << node << " ";
			for (auto nbr : l[node])
			{
				if (!visited[nbr])
				{
					q.push(nbr);
					visited[nbr] = true;
				}
			}
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
	g.addedge(3, 4);
	g.addedge(4, 5);

	g.bfs(0);
}
