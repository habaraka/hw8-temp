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
