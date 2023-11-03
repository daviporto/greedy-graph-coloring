#include <iostream>
#include "graph.h"
#include "sorter.h"
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    char sort_method;
    UI vertex_num;

    string line;
    getline(cin, line);
    istringstream stream(line);

    stream >> sort_method >> vertex_num;
    sort_method = 'q';
    Graph g(vertex_num);
    Sorter s(g);
    cout << g << endl << endl;
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
            s.heap_sort();
            break;
        case 'm':
            s.merge_sort();
            break;
        case 'p':
            s.heap_sort();
            break;
        case 'y':
            s.merge_sort(); //todo change to stalin sort
            break;
    }
    cout << g;
//    g.is_greedy() ? cout << "1 " << g : cout << "0";
//    cout << endl;

}



