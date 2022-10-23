#include "bits/stdc++.h"
using namespace std;
// Graphs
void addEdge(vector< vector<int> >&graph, int x, int y)
{
	graph[x].push_back(y);
	//graph[y].push_back(x);
}
// Topological Sort DFS
void Srt(vector<vector<int>>&graph, vector<bool>&visited, stack<int>&s, int start)
{
	visited[start] = true;
	for(int i = 0; i < graph[start].size(); i++)
	{
		if(!visited[graph[start][i]]) Srt(graph, visited, s, graph[start][i]);
	}
	s.push(start);
}
void TopoSort(vector<vector<int>>&graph)
{
	stack<int>s;
	vector<bool>visited(graph.size(), false);
	for(int i = 0; i < graph.size(); i++)
	{
		if(!visited[i]) Srt(graph, visited, s, i);
	}
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
// Topological Sort BFS (kahn's Algo)
void Topo2Sort(vector<vector<int>>&graph)
{
	vector<int>deg(graph.size(), 0);
	vector<int>ans;
	for(int i = 0; i < graph.size(); i++)
	{
		for(int j = 0; j < graph[i].size(); j++)
		{
			deg[graph[i][j]]++;
		}
	}
	queue<int>q;
	for(int i = deg.size()-1; i >= 0; i--)
	{
		if(deg[i] == 0) q.push(i);
	}
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		for(int i = 0; i < graph[temp].size(); i++)
		{
			deg[graph[temp][i]]--;
			if(!deg[graph[temp][i]]) q.push(graph[temp][i]);
		}
		ans.push_back(temp);
	}
	for(int i = 0;  i < ans.size(); i++)
	{
		cout << ans[i] << " ";
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
		vector< vector<int> > graph(n, vector<int>());
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			addEdge(graph, x, y);
		}
		TopoSort(graph);
		Topo2Sort(graph);
		if(t != 0) cout << endl;
	}
 	return 0;
}