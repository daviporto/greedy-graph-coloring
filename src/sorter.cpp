#include "sorter.h"
#include <algorithm>

#define FIND_ANCESTOR_POSITION (position - 1) >> 1
#define v this->g->vertexes
#define size this->g->vertex_num

Sorter::Sorter(Graph &g) {
    this->g = &g;
}

void Sorter::bubble_sort() {
    for (UI i = 0; i < size; ++i)
        for (UI j = 1; j < size - i; ++j)
            if (*v[j] < *v[j - 1])
                std::swap(v[j], v[j - 1]);
}

void Sorter::selection_sort() {
    for (UI i = 0, min = i; i < size; ++i) {
        for (UI j = i + 1; j < size; ++j)
            if (*v[j] < *v[min]) min = j;
        std::swap(v[i], v[min]);
    }
}

void Sorter::insert_sort() {
    for (UI i = 1; i < size; ++i) {
        UI j = i - 1;
        Vertex *aux = v[i];

        while (j >= 0 && *aux < *v[j]) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = aux;
    }
}

void Sorter::split(int Esq, int Dir, int *i, int *j) {
    Vertex *pivot = v[(*i + *j) / 2];

    do {
        while (*v[*i] < *pivot) (*i)++;
        while (*pivot < *v[*j]) (*j)--;
        if (*i <= *j) {
            std::swap(v[*i], v[*j]);
            (*i)++; (*j)--;
        }
    } while (*i <= *j);

}

void Sorter::_quick_sort(int Esq, int Dir) {
    int i = Esq, j = Dir;
    split(Esq, Dir, &i, &j);
    if (Esq < j) _quick_sort(Esq, j);
    if (i < Dir) _quick_sort(i, Dir);
}

void Sorter::_merge_sort(UI Esq, UI Dir) {
    if (Esq < Dir) {
        UI meio = (Esq + Dir) / 2;
        _merge_sort(Esq, meio);
        _merge_sort(meio + 1, Dir);
        merge(Esq, meio, Dir);
    }

}

void Sorter::merge(UI esq, UI meio, UI dir) {
    UI i, j, k, n1 = meio - esq + 1, n2 = dir - meio;

    Vertex *L[n1], *R[n2];

    for (i = 0; i < n1; ++i) L[i] = v[esq + i];
    for (j = 0; j < n2; ++j) R[j] = v[meio + 1 + j];

    i = 0;
    j = 0;
    k = esq;

    while (i < n1 && j < n2) {
        if (*L[i ]<= *R[j]) {
            v[k] = L[i];
            ++i;
        } else {
            v[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        v[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        v[k] = R[j];
        ++j;
        ++k;
    }

}

void Sorter::remake_heap(UI left, UI right) {
    UI i = left, j = left << 1;
    Vertex *x = v[left];
    while (j <= right) {
        if (j < right && *v[j] < *v[j + 1]) j++;
        if (*v[j] <= *x) break;
        std::swap(v[i], v[j]);
        i = j;
        j = i << 1;
    }
    v[i] = x;
}

void Sorter::build_heap() {
    for (UI left = size / 2; left > 0; --left) remake_heap(left, size - 1);
}

void Sorter::heap_sort() {
    build_heap();
    for (UI right = size - 1; right > 0; --right) {
        std::swap(v[0], v[right]);
        remake_heap(0, right - 1);
    }
}

void Sorter::my_sort() {
    for (int k = 0; k < size - 1; ++k) if (*v[k] < *v[k + 1]) std::swap(v[k], v[k + 1]);
    quick_sort();
}




