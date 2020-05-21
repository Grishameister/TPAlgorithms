#include "MatrixGraph.h"
#include "ListGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

void test() {
    ArcGraph graph(7);

    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(2, 4);
    graph.AddEdge(3, 4);
    graph.AddEdge(1, 6);
    graph.AddEdge(4, 2);
    graph.AddEdge(5, 3);
    graph.AddEdge(3, 5);
    graph.AddEdge(1, 0);
    graph.AddEdge(5, 2);
    graph.AddEdge(6, 2);
    graph.AddEdge(5, 4);

    MatrixGraph graph1(graph);
    ListGraph graph2(graph1);
    SetGraph graph3(graph2);

    graph2.equal(graph1);
    graph3.equal(graph2);
    graph1.equal(graph);
}

int main() {
    test();
    return 0;
}



