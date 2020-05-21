#include "SetGraph.h"

SetGraph::SetGraph(size_t vertices_count): vertices(vertices_count), reverse_vertices(vertices_count) {
}

SetGraph::SetGraph(const IGraph &graph) {
    vertices.resize(graph.VerticesCount());
    reverse_vertices.resize(graph.VerticesCount());
    for (int from = 0; from < graph.VerticesCount(); from++) {
        std::vector<int> next_vertices = graph.GetNextVertices(from);
        for (auto& vertex: next_vertices) {
            AddEdge(from, vertex);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    vertices[from].insert(to);
    reverse_vertices[to].insert(from);
}

int SetGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    result.resize(vertices[vertex].size());
    std::copy(vertices[vertex].begin(), vertices[vertex].end(), result.begin());

    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    result.resize(reverse_vertices[vertex].size());
    std::copy(reverse_vertices[vertex].begin(), reverse_vertices[vertex].end(), result.begin());

    return result;
}

