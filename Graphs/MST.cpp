#include "bits/stdc++.h"
using namespace std;
// Graph Matrix
void MST(vector<vector<int>>&graph)
{
	vector<int>parent(graph.size());
	parent[0] = -1;
	vector<int>dist(graph.size(), (int) INT_MAX/20);
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
	pq.push({0, 0});
	dist[0] = 0;
	while(!pq.empty())
	{
		int temp = pq.top().second;
		pq.pop();
		for(int i = 0; i < graph.size(); i++)
		{
			if(graph[temp][i] &&  i != temp && dist[i] > graph[temp][i])
			{
				parent[i] = temp;
				dist[i] = graph[temp][i];
				pq.push({dist[i], i});
			}
		}
	}
	for(int i = 1; i < graph.size(); i++)
	{
		cout << parent[i] << " - " << i << " " <<  graph[parent[i]][i] << endl;
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector< vector<int> >graph(n, vector<int>(n, 0));
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int x, y, dist;
			cin >> x >> y >> dist;
			graph[x][y] = dist;
			graph[y][x] = dist;
		}
		MST(graph);
		if(t != 0) cout << endl;
	}
 	return 0;
}