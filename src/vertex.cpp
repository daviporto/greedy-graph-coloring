#include "vertex.h"
#include "iostream"

using namespace std;

Vertex::Vertex(std::istream &stream, UI label) {
    stream >> this->neighbors_num;
    this->neighbors = new UI[this->neighbors_num];
    this->label = label;
    for (UI i = 0; i < this->neighbors_num; i++)
        stream >> this->neighbors[i];

}

Vertex::~Vertex() {
        delete[] this->neighbors;
}

bool Vertex::operator<(const Vertex &v) const {
    return this->color < v.color || (this->color == v.color && this->label < v.label);
}

bool Vertex::operator<=(const Vertex &v) const {
    return this->color <= v.color || (this->color == v.color && this->label <= v.label);
}

void Vertex::set_color(std::istream &stream) { stream >> this->color; }
