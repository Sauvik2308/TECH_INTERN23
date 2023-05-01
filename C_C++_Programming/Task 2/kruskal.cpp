#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_EDGES 100
#define MAX_VERTICES 100

// Define a structure for each edge in the graph
struct Edge {
    int source, destination, weight;
};

// Define a structure for the graph
struct Graph {
    Edge edges[MAX_EDGES];
    int numEdges, numVertices;
};

// Define a structure for each subset in the union-find algorithm
struct Subset {
    int parent, rank;
};

// Find the parent of a subset in the union-find algorithm
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Perform a union operation on two subsets in the union-find algorithm
void unionSubsets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for sorting edges by weight in non-decreasing order
bool compareEdges(Edge edge1, Edge edge2) {
    return edge1.weight < edge2.weight;
}

// Find the minimum spanning tree of the graph using Kruskal's algorithm
void kruskal(Graph graph) {
    Edge result[MAX_VERTICES];
    int e = 0, i = 0;

    std::sort(graph.edges, graph.edges + graph.numEdges, compareEdges);

    Subset subsets[MAX_VERTICES];
    for (i = 0; i < graph.numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    i = 0;
    while (e < graph.numVertices - 1) {
        Edge nextEdge = graph.edges[i++];

        int x = find(subsets, nextEdge.source);
        int y = find(subsets, nextEdge.destination);

        if (x != y) {
            result[e++] = nextEdge;
            unionSubsets(subsets, x, y);
        }
    }

    std::cout << "Minimum spanning tree:\n";
    for (i = 0; i < e; i++) {
        std::cout << result[i].source << " -- " << result[i].destination << " == " << result[i].weight << "\n";
    }
}

// Main function for testing the algorithm
int main() {
    Graph graph = {
        .edges = {
            {0, 1, 10},
            {0, 2, 6},
            {0, 3, 5},
            {1, 3, 15},
            {2, 3, 4}
        },
        .numEdges = 5,
        .numVertices = 4
    };

    kruskal(graph);

    return 0;
}
