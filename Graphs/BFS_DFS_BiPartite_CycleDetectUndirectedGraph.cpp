#include "bits/stdc++.h"
using namespace std;
// Graphs
void addEdge(vector< vector<int> >&graph, int x, int y)
{
	graph[x].push_back(y);
	graph[y].push_back(x);
}
void BFS(vector< vector<int> >&graph, int start)
{
	vector<bool>visited(graph.size(), false);
	queue<int>q;
	q.push(start);
	visited[start] = true;
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		cout << temp << " ";
		for(int i = 0; i < graph[temp].size(); i++)
		{
			if(visited[graph[temp][i]] == false)
				{
					q.push(graph[temp][i]);
					visited[graph[temp][i]] = true;
				}
		}
	}
	return;
}
void DFStraversal(vector< vector<int> >&graph, vector<bool>&visited, int start)
{
	cout << start << " ";
	visited[start] = true;
	for(int i = 0; i < graph[start].size(); i++)
	{
		if(visited[graph[start][i]] == false) DFStraversal(graph, visited, graph[start][i]);
	}
	return;
}
void DFS(vector< vector<int> >&graph, int start)
{
	vector<bool> visited(graph.size(), false);
	DFStraversal(graph, visited, start);
}
bool isTCBFS(vector<vector<int>>&graph, vector<bool>&visited, int start)
{
	queue<pair<int, int>>q;
	q.push({start, -1});
	visited[start] = true;
	while(!q.empty())
	{
		int temp = q.front().first;
		int parent = q.front().second;
		q.pop();
		for(int i = 0; i < graph[temp].size(); i++)
		{
			if(!visited[graph[temp][i]])
			{
				q.push({graph[temp][i], temp});
				visited[graph[temp][i]] = true;
			}
			else
			{
				if(graph[temp][i] == parent) continue;
				else return true;
			}
		}
	}
	return false;
}
bool isThereCycleBFS(vector<vector<int>>&graph)
{
	vector<bool>visited(graph.size(), false);
	for(int i = 1; i < graph.size(); i++)
	{
		if(!visited[i]) {if(isTCBFS(graph, visited, i)) return true;}
	}
	return false;
}
bool isTCDFS(vector<vector<int>>&graph, vector<bool>&visited, int start, int parent)
{
	visited[start] = true;
	for(int i = 0; i < graph[start].size(); i++)
	{
		if(!visited[graph[start][i]])
		{
			if(isTCDFS(graph, visited, graph[start][i], start)) return true;
		} 
		else
		{
			if(graph[start][i] == parent) continue;
			else return true;
		}
	}
	return false;
}
bool isThereCycleDFS(vector<vector<int>>&graph)
{
	vector<bool>visited(graph.size(), false);
	for(int i = 1; i < graph.size(); i++)
	{
		if(!visited[i]) {if(isTCDFS(graph, visited, i, -1)) return true;}
	}
	return false;
}
bool isBBFS(vector<vector<int>>&graph, vector<int>&visited, int start)
{
	queue<int>q;
	visited[start] = 0;
	q.push(start);
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		int color = visited[temp];
		for(int i = 0; i < graph[temp].size(); i++)
		{
			if(visited[graph[temp][i]] == -1)
			{
				q.push(graph[temp][i]);
				visited[graph[temp][i]] = 1 - color;
			}
			else
			{
				if(visited[graph[temp][i]] == color) return false;
			}
		}
	}
	return true;
}
bool isBipartiteBFS(vector<vector<int>>&graph)
{
	vector<int>visited(graph.size(), -1);
	for(int i = 1; i < graph.size(); i++)
	{
		if(visited[i]==-1){ if(!isBBFS(graph, visited, i)) return false;} 
	}
	return true;
}
bool isBDFS(vector<vector<int>>&graph, vector<int>&visited, int start)
{
	int color = visited[start];
	for(int i = 0; i < graph[start].size(); i++)
	{
		if(visited[graph[start][i]] == -1)
		{
			visited[graph[start][i]] = 1 - color;
			if(!isBDFS(graph, visited, graph[start][i])) return false;
		}
		else
		{
			if(visited[graph[start][i]] == color) return false;
		}
	}
	return true;
}
bool isBipartiteDFS(vector<vector<int>>&graph)
{
	vector<int>visited(graph.size(), -1);
	for(int i = 1; i < graph.size(); i++)
	{
		if(visited[i]==-1) {
			visited[i] = 0;
			if(!isBDFS(graph, visited, i)) return false;
		}
	}
	return true;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector< vector<int> > graph(n+1, vector<int>());
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			addEdge(graph, x, y);
		}
		int startfrom;
		cin >> startfrom;
		BFS(graph, startfrom);
		cout << endl;
		cin >> startfrom;
		DFS(graph, startfrom);
		cout << endl;
		cout << isThereCycleBFS(graph) << endl << isThereCycleDFS(graph) << endl;
		cout << isBipartiteBFS(graph) <<  endl << isBipartiteDFS(graph) << endl;
		if(t != 0) cout << endl;
	}
 	return 0;
}