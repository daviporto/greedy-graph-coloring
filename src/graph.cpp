#include "graph.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Graph::Graph(UI size) {
    this->vertex_num = size;
    this->vertexes = new Vertex *[size];

    string line;
    for (UI i = 0; i < size; i++) {
        getline(cin, line);
        istringstream stream(line);
        this->vertexes[i] = new Vertex(stream, i);
    }

    getline(cin, line);
    istringstream stream(line);
    this->colors = new UI[size];
    for (UI i = 0; i < this->vertex_num; i++) {
        this->vertexes[i]->set_color(stream);
        this->colors[i] = this->vertexes[i]->color;
    }
}

Graph::~Graph() {
    for (UI i = 0; i < this->vertex_num; i++) delete this->vertexes[i];
    delete[] this->vertexes;
    delete[] this->colors;
}

UI Graph::get_vertex_num() const { return this->vertex_num; }

bool Graph::is_greedy() {
    auto min = this->vertexes[0]->color;

    for (UI i = 0; i < this->vertex_num; i++) {
        if (this->vertexes[i]->color != min) {
            for (UI j = 0; j < this->vertex_num && this->vertexes[j]->color < this->vertexes[i]->color; j++) {
                bool exists = false;
                for (UI k = 0; k < this->vertexes[i]->neighbors_num; k++) {
                    if (this->vertexes[j]->color == this->colors[this->vertexes[i]->neighbors[k]]) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) return false;
            }
        }
    }

    return true;
}

std::ostream &operator<<(ostream &os, const Graph &g) {
    for (UI i = 0; i < g.vertex_num; ++i) os << g.vertexes[i]->label << " ";
    os << endl;

    return os;
}
