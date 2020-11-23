# C_B_Graph_Algorithms
#include<bits/stdc++.h>
using namespace std;

class graph
{
	map<string, list<pair<string , int>>>l;

public:
	void addedge(string x, string y, bool bidir, int wt)
	{
		l[x].push_back(make_pair(y, wt));
		if (bidir)
		{
			l[y].push_back(make_pair(x, wt));
		}
	}

	void print_adj_list()
	{
		for (auto p : l)
		{
			string city = p.first;
			list<pair<string, int>> nbrs = p.second;
			cout << city << "->";
			for (auto nbr : nbrs)
			{
				string dest = nbr.first;
				int dist = nbr.second;
				cout << dest << " " << dist << ",";
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
	//graph g(4);
	graph g;
	g.addedge("A", "B", true, 20);
	g.addedge("B", "D", true, 40);
	g.addedge("A", "C", true, 10);
	g.addedge("C", "D", true, 30);
	g.addedge("A", "D", false, 50);
	g.print_adj_list();
}
