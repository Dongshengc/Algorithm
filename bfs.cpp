#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph
{
public:
	Graph(const int &);

	void addEdge(const int &, const int &);
	void bfsTraversal(const int &);

private:
	int num_of_nodes;
	list<int> *adj_list;
	bool *visit_list;
	
};

Graph::Graph(const int &_num): num_of_nodes(_num)
{
	adj_list = new list<int>[_num];
	visit_list = new bool[_num]{false};
}

void Graph::addEdge(const int &node1, const int &node2)
{
	adj_list[node1].push_back(node2);
}

void Graph::bfsTraversal(const int &start)
{
	int _start = start;
	queue<int> bfs_queue;
	bfs_queue.push(_start);
	visit_list[start] = true;
	while (!bfs_queue.empty())
	{
		cout << "Node: " << _start << "visited" << endl;
		for (auto beg = adj_list[_start].begin(); beg != adj_list[_start].end(); ++beg)
		{
			if (!visit_list[*beg])
			{
				bfs_queue.push(*beg);
			}
		}
		bfs_queue.pop();
		_start = bfs_queue.front();
	}
}

int	main(int argc, char const *argv[])
{
	// formulate graph
	Graph G(14);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 3);
	G.addEdge(1, 4);
	G.addEdge(2, 5);
	G.addEdge(2, 6);
	G.addEdge(3, 7);
	G.addEdge(4, 8);
	G.addEdge(4, 9);
	G.addEdge(6, 10);
	G.addEdge(6, 11);
	G.addEdge(8, 12);
	G.addEdge(9, 13);

	G.bfsTraversal(0);

	return 0;
}