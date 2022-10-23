#include "bits/stdc++.h"
using namespace std;
// Floyd Warshall Algo
#define INF 99999
void FloydWarshall(vector<vector<int>>&graph, vector<vector<int>>&dist)
{
	for(int k = 1; k < graph.size(); k++)
	{
		for(int i = 1; i < dist.size(); i++)
		{
			for(int j = 1; j < dist.size(); j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
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
		int negdes;
		cin >> negdes;
		vector<vector<int>>graph(n+1, vector<int>(n+1, INF));
		for(int i = 0; i < n+1; i++) graph[i][i] = 0;
		for(int i = 0; i < negdes; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;if(t != 0) cout << endl;
			graph[x][y] = z;
		}
		vector<vector<int>>dist = graph;
		FloydWarshall(graph, dist);
		for(int i = 1; i < dist.size(); i++)
		{
			for(int j = 1; j < dist.size(); j++)
			{
				if(dist[i][j] == INF)
				{
					cout << "INF" << " ";
				}
				else
				{
					cout << dist[i][j] << " ";
				}
			}
			cout << endl;
		}
		if(t != 0) cout << endl;
	}
 	return 0;
}