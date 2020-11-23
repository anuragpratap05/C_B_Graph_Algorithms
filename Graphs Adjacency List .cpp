#include<bits/stdc++.h>
using namespace std;

class graph
{
	int V;
	list<int> *l;
public:
	graph(int z)
	{
		V = z;
		l = new list<int>[V];
	}

	void addedge(int x, int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void print_adj_list()
	{
		for (int i = 0; i < V; i++)
		{
			cout << "vertex" << i << "->";
			for (auto nbr : l[i])
			{
				cout << nbr << ",";
			}
			cout << endl;
		}
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
	g.addedge(0, 2);
	g.addedge(2, 3);
	g.addedge(1, 2);
	g.print_adj_list();
}
