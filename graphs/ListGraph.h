#ifndef GRAPHS_LISTGRAPH_H
#define GRAPHS_LISTGRAPH_H
#include "IGraph.h"


class ListGraph: public IGraph {
public:
    explicit ListGraph(size_t vertices_count);
    ListGraph(const IGraph& graph);

    ~ListGraph() = default;

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> vertices;
};


#endif //GRAPHS_LISTGRAPH_H
