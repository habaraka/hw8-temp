#include <gtest/gtest.h>

#include "graph.h"

TEST(Graph, SortEdges) {
    Graph g;
    g.numVertices = 4;

    g.push_back({0,1,10});
    g.push_back({0,2,5});
    g.push_back({1,3,2});

    Graph sorted = g.sort_edges();

    EXPECT_EQ(sorted[0].weight, 2);
    EXPECT_EQ(sorted[1].weight, 5);
    EXPECT_EQ(sorted[2].weight, 10);
}

TEST(Graph, EdgesFrom) {
    Graph g;
    g.numVertices = 4;

    g.push_back({0,1,10});
    g.push_back({0,2,5});
    g.push_back({2,3,7});

    VertexList result = g.edges_from(2);

    EXPECT_EQ(result.size(), 2);

    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 3);
}

TEST(Kruskals, SmallGraphMST) {
    Graph g;
    g.numVertices = 4;

    g.push_back({0, 1, 4});
    g.push_back({0, 3, 1});
    g.push_back({3, 1, 2});
    g.push_back({1, 2, 3});
    g.push_back({0, 2, 10});

    EdgeList mst = Kruskals(g);

    EXPECT_EQ(mst.size(), 3);
    EXPECT_EQ(sum_weights(mst), 6);
}

TEST(SumWeights, AddsAllEdgeWeights) {
    EdgeList edges;

    edges.push_back({0, 1, 5});
    edges.push_back({1, 2, 7});
    edges.push_back({2, 3, 3});

    EXPECT_EQ(sum_weights(edges), 15);
}

TEST(DFS, TraversesFromStartVertex) {
    Graph g;
    g.numVertices = 4;

    g.push_back({0, 1, 1});
    g.push_back({0, 2, 1});
    g.push_back({2, 3, 1});

    VertexList result = dfs(g, 0);

    EXPECT_EQ(result.size(), 4);
    EXPECT_EQ(result[0], 0);
}

TEST(BFS, TraversesFromStartVertex) {
    Graph g;
    g.numVertices = 4;

    g.push_back({0, 1, 1});
    g.push_back({0, 2, 1});
    g.push_back({2, 3, 1});

    VertexList result = bfs(g, 0);

    VertexList expected = {0, 1, 2, 3};

    EXPECT_EQ(result, expected);
}

