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

bool Graph::is_greedy() const {
    auto min = this->vertexes[0]->color;

    for (UI i = 0; i < this->vertex_num; i++) {

        if (this->vertexes[i]->color != min) {
            for (UI color = min; color < this->vertexes[i]->color; color++) {
                bool exists = false;
                for (UI j = 0; j < this->vertexes[i]->neighbors_num; j++) {
                    if (color == this->colors[this->vertexes[i]->neighbors[j]]) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) return exists;
            }
        }
    }

    return true;
}

std::ostream &operator<<(ostream &os, const Graph &g) {
    for (UI i = 0; i < g.vertex_num; ++i) os << g.vertexes[i]->label << " ";
    return os;
}

