# C_B_Graph_Algorithms
#include<bits/stdc++.h>
using namespace std;

class graph
{
	int V;
	list<pair<int, int>> l;
public:
	graph(int V)
	{
		this->V = V;
	}
	void addedge(int x, int y)
	{
		l.push_back(make_pair(x, y));
	}

	int findset(int x, int parent[])
	{
		if (parent[x] == -1)
		{
			return x;
		}
		return parent[x] = findset(parent[x], parent);
	}

	void union_set(int x, int y, int parent[], int rank[])
	{
		int s1 = findset(x, parent);
		int s2 = findset(y, parent);
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

	bool is_cycle()
	{
		int* parent = new int[V];
		int* rank = new int[V];
		for (int i = 0; i < V; i++)
		{
			parent[i] = -1;
			rank[i] = 1;
		}
		for (auto p : l)
		{
			int a = p.first;
			int b = p.second;

			int s1 = findset(a, parent);
			int s2 = findset(b, parent);
			if (s1 != s2)
			{
				union_set(s1, s2, parent, rank);
			}
			else
			{
				cout << s1 << "," << s2 << endl;
				return true;
			}

		}
		delete [] parent;
		return false;
	}
};

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	graph g(4);
	g.addedge(0, 1);
	g.addedge(1, 2);
	g.addedge(2, 3);
	//g.addedge(3, 0);

	if (g.is_cycle())
	{
		cout << "cycle present";
	}
	else
	{
		cout << "cycle absent";
	}
}
