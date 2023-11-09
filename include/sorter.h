#ifndef TP2_SORTER_H
#define TP2_SORTER_H

#include "graph.h"

/**
 * @class Sorter
 * @brief A class that provides various sorting algorithms for a graph.
 *
 * This class provides the necessary methods to sort a graph using different algorithms, including bubble sort,
 * selection sort, insertion sort, heap sort, merge sort, quick sort, and a custom sort method.
 */
class Sorter {
    Graph *g; ///< The graph to be sorted.

    /**
     * @brief Split the array into two halves.
     *
     * This method is used in the quick sort algorithm to split the array into two halves.
     * It uses a pivot element and rearranges the array such that all elements less than the pivot come before the pivot,
     * and all elements greater than the pivot come after it.
     */
    void split(int left, int right, int *i, int *j);

    /**
     * @brief The quick sort algorithm.
     *
     * This method implements the quick sort algorithm.
     * It recursively divides the array into two halves around a pivot element and sorts each half.
     */
    void _quick_sort(int left, int right);

    /**
     * @brief The merge sort algorithm.
     *
     * This method implements the merge sort algorithm.
     * It recursively divides the array into two halves, sorts each half, and then merges them back together.
     */
    void _merge_sort(UI left, UI right);

    /**
     * @brief Merge two sorted halves.
     *
     * This method is used in the merge sort algorithm to merge two sorted halves.
     * It creates temporary arrays for each half, compares the first elements of each array to find the smallest one,
     * and then moves it to the original array.
     */
    void merge(UI left, UI middle, UI right);

    /**
     * @brief Rebuild the heap.
     *
     * This method is used in the heap sort algorithm to rebuild the heap.
     * It moves the root element to its correct position in the heap.
     */
    void remake_heap(UI left, UI right);

    /**
     * @brief Build the heap.
     *
     * This method is used in the heap sort algorithm to build the heap.
     * It rearranges the array into a heap, a specialized tree-based data structure.
     */
    void build_heap();

public:
    /**
     * @brief Construct a new Sorter object.
     *
     * This constructor initializes the Sorter with a given graph.
     *
     * @param g The graph to be sorted.
     */
    explicit Sorter(Graph &g);

    /**
     * @brief The bubble sort algorithm.
     *
     * This method implements the bubble sort algorithm.
     * It repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
     */
    void bubble_sort();

    /**
     * @brief The selection sort algorithm.
     *
     * This method implements the selection sort algorithm.
     * It divides the input list into a sorted and an unsorted region, and repeatedly picks the smallest element from the unsorted region and moves it to the sorted region.
     */
    void selection_sort();

    /**
     * @brief The insertion sort algorithm.
     *
     * This method implements the insertion sort algorithm.
     * It builds a sorted array one item at a time, with each movement shifting elements one space to the right to make room for the inserted item.
     */
    void insert_sort();

    /**
     * @brief The heap sort algorithm.
     *
     * This method implements the heap sort algorithm.
     * It builds a max heap from the input data, then repeatedly swaps the maximum element from the end of the heap, reduces the size of the heap by one, and heapifies the root element.
     */
    void heap_sort();

    /**
     * @brief A custom sort algorithm.
     *
     * This method implements a custom sort algorithm.
     * The details of this algorithm should be described here.
     */
    void my_sort();

    /**
     * @brief The merge sort algorithm.
     *
     * This method is a public interface for the merge sort algorithm.
     * It calls the private _merge_sort method with the appropriate parameters.
     */
    void merge_sort() {
        _merge_sort(0, this->g->vertex_num - 1);
    }

    /**
     * @brief The quick sort algorithm.
     *
     * This method is a public interface for the quick sort algorithm.
     * It calls the private _quick_sort method with the appropriate parameters.
     */
    void quick_sort() {
        _quick_sort(0, (int) this->g->vertex_num - 1);
    }
};

#endif //TP2_SORTER_H
