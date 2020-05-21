#include "IGraph.h"

bool IGraph::equal(const IGraph& rhs) {
    assert(VerticesCount() == rhs.VerticesCount());

    for (int i = 0; i < VerticesCount(); i++) {
        std::vector<int> result = GetNextVertices(i);
        std::vector<int> rhs_result = rhs.GetNextVertices(i);

        std::sort(result.begin(), result.end());
        std::sort(rhs_result.begin(), rhs_result.end());

        assert(result == rhs_result);

        std::vector<int> prev_result = GetPrevVertices(i);
        std::vector<int> prev_rhs_result = rhs.GetPrevVertices(i);

        std::sort(prev_result.begin(), prev_result.end());
        std::sort(prev_rhs_result.begin(), prev_rhs_result.end());

        assert(prev_result == prev_rhs_result);
    }
    return true;
}
