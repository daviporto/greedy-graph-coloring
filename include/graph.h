#ifndef TP2_GRAPH_H
#define TP2_GRAPH_H

#include "vertex.h"

class Graph {
public:
    Graph(UI size);

    ~Graph();

    UI get_vertex_num() const;

    UI vertex_num, *colors;

    Vertex **vertexes;

    bool is_greedy();
    friend std::ostream& operator<<(std::ostream& os, const Graph& g);

};


#endif //TP2_GRAPH_H
