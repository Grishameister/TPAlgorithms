#ifndef GRAPHS_IGRAPH_H
#define GRAPHS_IGRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

struct IGraph {
    virtual ~IGraph() = default;

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const  = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;

    bool equal(const IGraph& rhs);
};


#endif //GRAPHS_IGRAPH_H
