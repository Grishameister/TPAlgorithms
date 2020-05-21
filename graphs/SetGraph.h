#ifndef GRAPHS_SETGRAPH_H
#define GRAPHS_SETGRAPH_H
#include <unordered_set>

#include "IGraph.h"

class SetGraph: public IGraph {
public:
    explicit SetGraph(size_t vertices_count);
    SetGraph(const IGraph& graph);

    ~SetGraph() = default;

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::unordered_set<int>> vertices;
    std::vector<std::unordered_set<int>> reverse_vertices;
};


#endif //GRAPHS_SETGRAPH_H
