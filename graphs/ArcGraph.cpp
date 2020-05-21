#include "ArcGraph.h"

ArcGraph::ArcGraph(size_t vertices_count): vertices(vertices_count) {
}

ArcGraph::ArcGraph(const IGraph& graph) {
    vertices = graph.VerticesCount();
    for (int from = 0; from < graph.VerticesCount(); from++) {
        std::vector next_vertices = graph.GetNextVertices(from);
        for (auto& vertex: next_vertices) {
            AddEdge(from, vertex);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    edges.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return vertices;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for (const auto& edge : edges) {
        if (edge.first == vertex) {
            result.push_back(edge.second);
        }
    }

    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (const auto& edge : edges) {
        if (edge.second == vertex) {
            result.push_back(edge.first);
        }
    }
    return result;
}
