# C_B_Graph_Algorithms
#include<bits/stdc++.h>
using namespace std;

class graph
{
	vector<pair<int, int>> *l;
	int V;
public:
	graph(int n)
	{
		V = n;
		l = new vector<pair<int, int>>[n];
	}
	void addedge(int x, int y, int w)
	{
		l[x].push_back({y, w});
		l[y].push_back({x, w});
	}
	int prim_mst()
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
		bool* visited = new bool[V] {0};
		Q.push({0, 0});
		int ans = 0;
		while (!Q.empty())
		{
			auto best = Q.top();
			Q.pop();

			int to = best.second;
			int weight = best.first;

			if (visited[to])
			{
				continue;
			}
			ans += weight;
			visited[to] = 1;
			for (auto nbr : l[to])
			{
				if (visited[nbr.first] == 0)
				{
					Q.push({nbr.second, nbr.first});
				}
			}
		}
		return ans;
	}
};
int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;

	graph g(n);
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		g.addedge(x, y, w);
	}
	cout << g.prim_mst() << endl;
}
