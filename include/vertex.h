#ifndef TP2_VERTEX_H
#define TP2_VERTEX_H
#define UI unsigned int

#include <istream>

class Vertex {
public:
    UI neighbors_num, *neighbors, color, label;

    Vertex() : neighbors_num(0), neighbors(nullptr), color(0), label(0) {}

    Vertex(std::istream &stream, UI label);

    ~Vertex();

    void set_color(std::istream &stream);

    bool operator<(const Vertex &v) const;

    bool operator<=(const Vertex &v) const;
};

#endif //TP2_VERTEX_H
