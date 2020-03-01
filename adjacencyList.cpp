#include<bits/stdc++.h>
using namespace std;

struct graphUD{
	vector<vector<int>> adj;
	int v;
	bool *visited;
	int countCon=0;
	graphUD(int x)
	{
		v=x;
		adj.resize(x);
		visited = new bool[v]{false};
	}
	
	void show()
	{
		for(int i=0; i<adj.size(); i++)
		{
			cout<<i;
			for(int j=0; j<adj[i].size(); j++)
				cout<<"->"<<adj[i][j];
			cout<<endl;
		}		
	}
	
	void edge(int s, int e)
	{
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	
	void BFSrec(int s)
	{
		countCon++;
		queue<int> q;
		q.push(s);
		visited[s]=true;
		while(!q.empty())
		{
			int v = q.front();
			q.pop();
			cout<<v<<" ";
			for(int u : adj[v])
			{
				if(!visited[u])
				{
					q.push(u);
					visited[u]=true;
				}
			}
		}
	}
	void BFS(int s)
	{
		BFSrec(s);
		for(int i=0; i<v; i++)
		{
			if(!visited[i])
				BFSrec(i);
		}
	againTraverse();
	}
	
	int noOfConnectedComp()
	{
		return countCon;
	}
	
	void againTraverse()
	{
		for(int i=0; i<v; i++)
			visited[i]=false;
	}
	
	void DFSrec(int s)
	{
		visited[s]=true;
		cout<<s<<" ";
		for(int u : adj[s])
		{
			if(!visited[u])
				DFSrec(u);
		}	
	}
	void DFS(int s)
	{
		DFSrec(s);
		for(int i=0; i<v; i++)
		{
			if(!visited[i])
				DFSrec(i);
		}
		againTraverse();
	}
	
	void ShortestPathrec(int s, int *dist)
	{
		dist[s]=0;
		queue<int> q;
		q.push(s);
		visited[s]=true;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(int t : adj[u])
			{
				if(!visited[t])
				{
					q.push(t);
					visited[t]=true;
					dist[t] = dist[u]+1;
				}
			}
		}
	}
	void ShortestPath(int s)
	{
		int dist[v]{-1};
		ShortestPathrec(s, dist);
		for(int i=0; i<v; i++)
		{
			if(!visited[i])
				ShortestPathrec(s, dist);
		}
		for(int i : dist)
			cout<<i<<" ";
		againTraverse();
	}
	
	bool isCyclicDrec(int s, int par)
	{
		visited[s]=true;
		for(int u : adj[s])
		{
			if(!visited[u])
			{
				if(isCyclicDrec(u, s))
					return true;
			}
			else if(u != par)
				return true;
		}
		return false;
	}
	bool isCyclicD(int s)
	{
		if(isCyclicDrec(s, -1))
		{
			againTraverse();
			return true;
		}
		for(int i=0; i<v; i++)
		{
			if(!visited[i])
			{
				if(isCyclicDrec(i, -1))
				{
					againTraverse();
					return true;
				}
			}		
		}
		againTraverse();
		return false;
	}
	
	bool isCyclicBrec(int s, int par)
	{
		int u;
		queue<int> q;
		q.push(s);
		visited[s]=true;
		int size=q.size();
		while(!q.empty())
		{
			while(size--)
			{	
			u = q.front();
			q.pop();
			for(int t : adj[u])
			{
				if(!visited[t])
				{
					q.push(t);
					visited[t]=true;
				}
				else if(t != par)
					return true;
			}
			}
			par=u;
			size=q.size();
		}
		return false;
	}
	bool isCyclicB(int s)
	{
		if(isCyclicBrec(s, -1))
		{
			againTraverse();
			return true;
		}
		for(int i=0; i<v; i++)
		{
			if(!visited[i])
			{
				if(isCyclicBrec(i, -1))
				{
					againTraverse();
					return true;	
				}		
			}
		}
		againTraverse();
		return false;
	}
};

main()
{
	cout<<"Enetr the number of vertex : ";
	int v;
	cin>>v;
	graphUD g1(v);
	cout<<"\nEnter the number of edges : ";
	int e;
	cin>>e;
	for(int i=0; i<e; i++)
	{
		int s,e;
		cout<<"Enter starting vertex : ";
		cin>>s;
		cout<<"Enter ending vertex : ";
		cin>>e;
		g1.edge(s,e);
	}
	g1.show();
	g1.BFS(0);
	cout<<endl<<g1.noOfConnectedComp()<<endl;
	g1.DFS(0);
	cout<<endl;
	g1.ShortestPath(0);
	cout<<endl;
	if(g1.isCyclicD(0))
		cout<<"Cyclic";
	else
		cout<<"Not Cyclic";
	cout<<endl;
	if(g1.isCyclicB(0))
		cout<<"Cyclic";
	else
		cout<<"Not Cyclic";	
}
