#ifndef TP1_NODE_H
#define TP1_NODE_H

#include <string>
#include "evaluate.h"

/**
 * @class Node
 * @brief A class that represents a node in a binary tree.
 *
 * This class provides the necessary methods to manage the node's values and expression result.
 * It also provides methods to get and set the node's quantifier and to update a value at a specific index.
 */
class Node {
    std::string values; ///< The values associated with the node.
    byte expression_result; ///< The result of the expression evaluated at this node.
public:
    Node *left, *right; ///< Pointers to the left and right child nodes.

    /**
     * @brief Construct a new Node object.
     *
     * This constructor initializes the values associated with the node and sets the left and right child nodes to null.
     *
     * @param values The values to be associated with the node.
     */
    Node(std::string values);

    /**
     * @brief Update a value at a specific index.
     *
     * This method updates the value at the specified index with the new value.
     *
     * @param new_value The new value.
     * @param index The index at which the value is to be updated.
     */
    void update_index(char new_value, UI index);

    /**
     * @brief Get the result of the expression evaluated at this node.
     *
     * This method returns the result of the expression evaluated at this node.
     *
     * @return The result of the expression.
     */
    byte get_expression_result() const;

    /**
     * @brief Set the result of the expression evaluated at this node.
     *
     * This method sets the result of the expression evaluated at this node.
     *
     * @param expression_result The result of the expression.
     */
    void set_expression_result(byte expression_result);

    /**
     * @brief Get the quantifier associated with this node.
     *
     * This method returns the quantifier associated with this node.
     *
     * @return The quantifier.
     */
    char get_quantifier();

    /**
     * @brief Get the values associated with this node.
     *
     * This method returns the values associated with this node.
     *
     * @return The values.
     */
    std::string get_values() const;

    /**
     * @brief Set the values associated with this node.
     *
     * This method sets the values associated with this node.
     *
     * @param values The values to be associated with the node.
     */
    void set_values(std::string values);

    /**
     * @brief Set a value at a specific index.
     *
     * This method sets the value at the specified index.
     *
     * @param value The value to be set.
     * @param index The index at which the value is to be set.
     */
    void set_value(char value, UI index);
};

#endif //TP1_NODE_H
