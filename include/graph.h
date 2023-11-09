#ifndef TP2_GRAPH_H
#define TP2_GRAPH_H

#include "vertex.h"

/**
 * @class Graph
 * @brief A class that represents a graph data structure.
 *
 * This class provides the necessary methods to manipulate a graph, including getting the number of vertices,
 * checking if the graph coloration is generated from greedy algorithm is greedy, and outputting the graph.
 */
class Graph {
public:
    /**
     * @brief Construct a new Graph object.
     *
     * This constructor initializes the graph with a given size.
     *
     * @param size The size of the graph.
     */
    explicit Graph(UI size);

    /**
     * @brief Destroy the Graph object.
     *
     * This destructor cleans up the memory used by the graph.
     */
    ~Graph();

    UI vertex_num, *colors; ///< The number of vertices and the colors of the vertices.

    Vertex **vertexes; ///< The vertices of the graph.

    /**
     * @brief Check if the graph's coloration is greedy.
     *
     * This method checks if the coloration of the graph follows a greedy algorithm. In a greedy algorithm,
     * vertices are colored in such a way that no two adjacent vertices share the same color. This method
     * checks if each vertex's color is either the same or higher than its neighbors' colors, and if there
     * are no missing colors in the sequence from 1 to the maximum color used. If these conditions are met,
     * the coloration is considered to be greedy.
     *
     * @return True if the graph's coloration is greedy, false otherwise.
    */
    bool is_greedy() const;

    /**
     * @brief Output the graph.
     *
     * This method outputs the graph to a given output stream.
     *
     * @param os The output stream.
     * @param g The graph to be output.
     * @return The output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Graph &g);
};

#endif //TP2_GRAPH_H
