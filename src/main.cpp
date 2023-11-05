#include <iostream>
#include "graph.h"
#include "sorter.h"
#include <sstream>
#include <stdexcept>

using namespace std;

int main(int argc, char *argv[]) {
    char sort_method;
    UI vertex_num;

    string line;
    getline(cin, line);
    istringstream stream(line);

    stream >> sort_method >> vertex_num;
    Graph g(vertex_num);
    Sorter s(g);

    switch (sort_method) {
        case 'b':
            s.bubble_sort();
            break;
        case 's':
            s.selection_sort();
            break;
        case 'i':
            s.insert_sort();
            break;
        case 'q':
            s.quick_sort();
            break;
        case 'm':
            s.merge_sort();
            break;
        case 'p':
            s.heap_sort();
            break;
        case 'y':
            s.my_sort();
            break;
        default:
            throw invalid_argument("The sorting algorithm selected is invalid.");
    }

    g.is_greedy() ? cout << "1 " << g : cout << "0";
    cout << endl;

}



