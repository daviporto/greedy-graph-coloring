#ifndef TP2_SORTER_H
#define TP2_SORTER_H

#include "graph.h"

class Sorter {
    Graph *g;

    void split(int Esq, int Dir, int *i, int *j);

    void _quick_sort(int Esq, int Dir);

    void _merge_sort(UI Esq, UI Dir);

    void merge(UI esq, UI meio, UI dir);

    void remake_heap(UI left, UI right);

    void build_heap();


public:
    Sorter(Graph &g);

    void bubble_sort();

    void selection_sort();

    void insert_sort();

    void heap_sort();

    void stalin_sort();

    void merge_sort(){
        _merge_sort(0, this->g->vertex_num - 1);
    }


    void quick_sort() {
        _quick_sort(0, (int)this->g->vertex_num - 1);
    }

};


#endif //TP2_SORTER_H
