#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
	Graph(const int &);

	void addEdge(const int &, const int &);
	void dfsTraversal(const int &);

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

void Graph::dfsTraversal(const int &start)
{
	cout << "Node: " << start << " visited" << endl;
	visit_list[start] = true;
	for (auto beg = adj_list[start].begin(); beg != adj_list[start].end(); ++beg)
	{
		if (!visit_list[*beg])
		{
			dfsTraversal(*beg);
		}
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

	G.dfsTraversal(0);

	return 0;
}