#include <iostream>
#include <vector>
#include "Graph.h"
#include "globals.h"
#include <queue>
#include <list>

using namespace std;
int roman()
{
    vector<Edge> edges;
    edges.push_back({ 0, 1, 5 });
    edges.push_back({ 0, 2, 7});
    edges.push_back({ 0, 3, 2});
    edges.push_back({ 1, 3, -2});
    edges.push_back({ 2, 3, -1});
    edges.push_back({ 3, 4, 3});
    edges.push_back({ 3, 5, 8});
    edges.push_back({ 4, 5, 1});
    edges.push_back({ 5, 4, -1});


    // construct graph
    Graph graph(edges, 6);
    graph.generateRandomWeights();
    // print adjacency list representation of a graph



    cout << "\nshortest path form node 0 to node " << graph.nodes_count() - 1 << " is:  "
        << graph.BellmanFordSP(0, graph.nodes_count() - 1) << '\n';

    return 1;


}
