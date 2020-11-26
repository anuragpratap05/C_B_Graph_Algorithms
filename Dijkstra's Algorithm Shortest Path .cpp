# C_B_Graph_Algorithms
#include<bits/stdc++.h>
using namespace std;

class graph
{
	map<string, list<pair<string, int>>> m;
public:
	void addedge(string x, string y, int d)
	{
		m[x].push_back(make_pair(y, d));

		m[y].push_back(make_pair(x, d));

	}

	void dijkstra(string src)
	{
		map<string, int> dist;

		for (auto city : m)
		{
			dist[city.first] = INT_MAX;
		}

		set<pair<int, string>> s;

		dist[src] = 0;
		s.insert(make_pair(0, src));
		while (!s.empty())
		{
			auto p = *(s.begin());
			string node = p.second;
			int node_dist = p.first;
			s.erase(s.begin());
			for (auto nbr : m[node])
			{
				if (node_dist + nbr.second < dist[nbr.first])
				{
					string dest = nbr.first;
					auto f = s.find(make_pair(dist[dest], dest));
					if (f != s.end())
					{
						s.erase(f);
					}
					dist[dest] = node_dist + nbr.second;
					s.insert(make_pair(dist[dest], dest));

				}
			}
		}

		for (auto x : dist)
		{
			cout << x.first << " is located at a distance of " << x.second << endl;
		}
	}

};

int main()
{

	graph india;

	india.addedge("amritsar", "delhi", 1);
	india.addedge("amritsar", "jaipur", 4);
	india.addedge("jaipur", "delhi", 2);
	india.addedge("jaipur", "mumbai", 8);
	india.addedge("bhopal", "agra", 2);
	india.addedge("mumbai", "bhopal", 3);
	india.addedge("amritsar", "delhi", 1);
	india.addedge("agra", "delhi", 1);

	india.dijkstra("amritsar");

}
