#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include "graph.h"
using namespace std;

void error(string msg){
	cerr << "Error: " << msg << endl; 
}

//--------------DisjointSet----------

    DisjointSet::DisjointSet(int numVertices){
		 subsets.resize(numVertices);

		for (Vertex i = 0; i < numVertices; i++) {
			makeSet(i);
		}
	}

    void DisjointSet::makeSet(Vertex x){
			subsets[x].parent = x;
		
	}

    Vertex DisjointSet::findSet(Vertex x){
		if(subsets[x].parent != x){
			subsets[x].parent = findSet(subsets[x].parent);
			}
		return subsets[x].parent;

	}

    void DisjointSet::unionSets(Vertex x, Vertex y){
		Vertex rootx = findSet(x);
		Vertex rooty = findSet(y);

		if(rootx == rooty){
			return;
		}
		subsets[rooty].parent = rootx;	}

//---------------Graph---------------
    // each vertex is an integer in range 0..numVertices-1
    // returns a copy of graph with edges sorted ascending by edge weight
    Graph Graph::sort_edges() const{
		Graph copy = *this;
		sort(copy.begin(), copy.end(),
        [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });		
		return copy;
	}

    VertexList Graph::edges_from(Vertex vertex) const{
		VertexList result;
		for(const Edge& edge : *this){
			if(edge.u == vertex){
				result.push_back(edge.v);
			}
		}
		return result;
	}
//--------------Krukals----------------
EdgeList Kruskals(const Graph& G){
	EdgeList F;                
	DisjointSet ds(G.numVertices);

    Graph sorted = G.sort_edges();

    for (const Edge& edge : sorted) {
        Vertex u = edge.u;
        Vertex v = edge.v;

        if (ds.findSet(u) != ds.findSet(v)) {
            F.push_back(edge);
            ds.unionSets(u, v);
        }
    }
    return F;
}
int sum_weights(EdgeList const& L){
	int sum = 0;
	for(const Edge& edge : L){
		sum += edge.weight;
	}
	return sum;
} // important for testing - the total cost of MST

void file_to_graph(string filename, Graph & G){
    ifstream in(filename);

    if (!in) {
        error("could not open file: " + filename);
        return;
    }

    in >> G.numVertices;

    Edge edge;
    while (in >> edge) {
        G.push_back(edge);
    }
}
//---------------DFS------------
VertexList dfs(const Graph& graph, Vertex startVertex){
    VertexList result;

    vector<bool> visited(graph.numVertices, false);

    stack<Vertex> S;

    visited[startVertex] = true;

    S.push(startVertex);

    while (!S.empty()) {

        Vertex v = S.top();
        S.pop();

        result.push_back(v);

        VertexList neighbors =
            graph.edges_from(v);

        for (Vertex w : neighbors) {

            if (!visited[w]) {

                visited[w] = true;

                S.push(w);
            }
        }
    }

    return result;
	}

//---------------BFS------------
VertexList bfs(const Graph& graph, Vertex startVertex){
    VertexList result;

    vector<bool> visited(graph.numVertices, false);

    queue<Vertex> Q;

    visited[startVertex] = true;
    Q.push(startVertex);

    while (!Q.empty()) {
        Vertex v = Q.front();
        Q.pop();

        result.push_back(v);

        VertexList neighbors = graph.edges_from(v);

        for (Vertex w : neighbors) {
            if (!visited[w]) {
                visited[w] = true;
                Q.push(w);
            }
        }
    }

    return result;

}
//---------------Measurments---------------
string get_arg(int argc, char *argv[], string def){
	if(argc > 1){
		return argv[1];
	}
	return def;
}
