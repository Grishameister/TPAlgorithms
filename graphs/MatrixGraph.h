#ifndef GRAPHS_MATRIXGRAPH_H
#define GRAPHS_MATRIXGRAPH_H
#include "IGraph.h"

class MatrixGraph: public IGraph {
public:
    explicit MatrixGraph(size_t vertices_count);

    explicit MatrixGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::vector<bool>> edges;
};


#endif //GRAPHS_MATRIXGRAPH_H
