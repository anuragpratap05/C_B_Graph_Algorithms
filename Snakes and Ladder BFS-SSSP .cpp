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
		//l[y].push_back(x);
	}

	void bfs(int src, int target)
	{
		queue<int> q;
		map<int, int> dist;
		map<int, int> parent;
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
					parent[nbr] = node;
				}
			}

		}
		for (auto z : dist)
		{
			//int node = node_pair.first;
			//int d = dist[node];
			//cout << node << " is at distance " << d << " from source" << endl;
			cout << z.first << " is at distance" << " " << z.second << "from source" << endl;
		}
		cout << endl;
		int temp = target;
		while (temp != src)
		{
			cout << temp << "<--";
			temp = parent[temp];
		}
		cout << src;
	}
	//cout << endl;




};

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//graph g(4);

	int board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;

	graph g;
	for (int i = 0; i <= 36; i++)
	{
		for (int dice = 1; dice <= 6; dice++)
		{
			int j = i + dice;
			j += board[j];
			if (j <= 36)
				g.addedge(i, j);
		}
	}
	g.addedge(36, 36);



	g.bfs(0, 36);;
}
