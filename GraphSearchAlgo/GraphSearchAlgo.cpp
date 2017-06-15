// GraphSearchAlgo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	int V = -1; // the number of nodes in graph
	int E = -1; // the number of edges in graph
	int i = 0, j = 0;  // iterator variables
	int counter = 0;
	vector<char> G[256];
	
	/*
		I / O codes
	*/
	scanf("%d %d", &V, &E);
	//fflush(stdin);
	while(V != 0 && E != 0)
	{
		counter++;
		for (i = 0; i < E; i++)
		{
			// from s to t
			char s, t;
			rewind(stdin);
			scanf_s("%c %c", &s, 1, &t, 1);
			//fflush(stdin);
			G[s].push_back(t);
			G[t].push_back(s); // undirected graph. s->t, t->s
			sort(G[s].begin(), G[s].end()); // sort via character sequence so that visit via character sequence
			sort(G[t].begin(), G[t].end());
		}
	/*
		I / O codes
	*/

		printf("Graph #%d\n", counter);
		BFS_Traversal(G);
		DFS_Traversal(G);

		for (i = 0; i < 256; i++)
		{
			G[i].clear();
		}
		rewind(stdin);
		scanf("%d %d", &V, &E);
		//fflush(stdin);
	}

    return 0;
}

void BFS_Traversal(vector<char> * G)
{
	queue<char> VQueue; // use queue to control visit sequence
	char startV; // pick the starting node
	char i = 'a'; // iterator char variable
	bool visited[256] = {false}; // we won't visit those visited node
	unsigned int j = 0; // iterator unsigned int variable
	vector<char> visitOrder; // store visit sequence, at last print out

	for (i = '1'; i <= 'z'; i++) // pick the starting node in alphabetical order
	{
		if (G[i].size() != 0) // if current node connect some node
		{
			startV = i;  // pick it as starting node
			break;
		}
	}
	//VStack.push_back(startV);
	VQueue.push(startV); // push the starting node in visit sequence, and this node will be visit first
	visited[startV] = true; // the starting node has been visited
	visitOrder.push_back(startV); // push the starting node in print out sequence

	while (!VQueue.empty())  // when VQueue is empty represent that all node have been visited
	{
		char currentNode = VQueue.front(); // visit nodes which connect to the front node in queue
		for (vector<char>::iterator it = G[currentNode].begin(); it != G[currentNode].end(); it++)
		{
//			VStack.push_back(*it);
			if (!visited[*it]) // if the node connect to this node and is not visited
			{
				VQueue.push(*it);
				visitOrder.push_back(*it);
				visited[*it] = true;
			}
		}
		VQueue.pop();
	}

	printf("BFS = ");
	fflush(stdout);
	for (vector<char>::iterator it = visitOrder.begin(); it != visitOrder.end(); it++)
	{
		printf("%c ", *it);
	}
	printf("\n");

	return;
}


void DFS_Traversal(vector<char> * G)
{
	char startV;
	char i = 0; // iterator char variable
	stack<char> VStack; // use stack to control visit sequence
	bool visited[256] = { false };
	vector<char> visitOrder;

	for (i = '1'; i <= 'z'; i++) // pick the starting node in alphabetical order
	{
		if (G[i].size() != 0) // if current node connect some node
		{
			startV = i;  // pick it as starting node
			break;
		}
	}
	VStack.push(startV);
	visited[startV] = true;
	visitOrder.push_back(startV);

	while (!VStack.empty())
	{
		char currentNode = VStack.top();
		for (vector<char>::iterator it = G[currentNode].begin(); it != G[currentNode].end(); it++)
		{
			if (!visited[*it])
			{
				VStack.push(*it);
				visited[*it] = true;
				visitOrder.push_back(*it);
				break;
			}
			if (it == G[currentNode].end() - 1)
				VStack.pop();
		}
		
	}

	printf("DFS = ");
	fflush(stdout);
	for (vector<char>::iterator it = visitOrder.begin(); it != visitOrder.end(); it++)
	{
		printf("%c ", *it);
	}
	printf("\n");

	return;
}
