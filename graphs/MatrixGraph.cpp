#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(size_t vertices_count): edges(vertices_count) {
    for (auto& line: edges) {
        line.assign(vertices_count, false);
    }
}


MatrixGraph::MatrixGraph(const IGraph& graph) {
    edges.resize(graph.VerticesCount());
    for (auto& line: edges) {
        line.assign(graph.VerticesCount(), false);
    }

    for (int from = 0; from < graph.VerticesCount(); from++) {
        std::vector<int> vertices = graph.GetNextVertices(from);
        for (auto& vertex: vertices) {
            AddEdge(from, vertex);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    edges[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return edges.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < edges.size(); i++) {
        if (edges[vertex][i] == true) {
            result.push_back(i);
        }
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i][vertex] == true) {
            result.push_back(i);
        }
    }
    return result;
}
