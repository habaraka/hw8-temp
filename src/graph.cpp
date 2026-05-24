#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
using namespace std;

void error(string msg){
	cerr << "Error: " << msg << endl; 
}


class DisjointSet {
    struct Set {
        Vertex parent;
    };
    vector<Set> subsets;
public:
    DisjpintSet::DisjointSet(int numVertices){

	}

    void DisjointSet::makeSet(Vertex x){
		int count = count(subset.begin(), subset.end(), x);
		if(count == 0){
			subsets[x].parent = x;
		
	}

    Vertex DisjointSet::findSet(Vertex x){
		if(subsets[x].parent!= x){
			subsets[x].parent = findSet(subsets[x].parent;
			return subsets[x].parent;
		}
		return x;

	}

    void DisjointSet::unionSets(Vertex x, Vertex y){
		Vertex rootx = findSet(x);
		Vertex rooty = findSet(y);

		if(rootx == rooty){
			return;
		}
		subsets[rooty].parent = rootx;	}


using EdgeList = vector<Edge>;
using VertexList = vector<Vertex>;

struct Graph : public EdgeList
{
    int numVertices = 0;
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


	}
   
EdgeList Kruskals(const Graph& G);
int sum_weights(EdgeList const& L); // important for testing - the total cost of MST
void file_to_graph(string filename, Graph & G);

VertexList dfs(const Graph& graph, Vertex startVertex);
VertexList bfs(const Graph& graph, Vertex startVertex);
string get_arg(int argc, char *argv[], string def);
