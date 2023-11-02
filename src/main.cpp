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
    Graph g(vertex_num);
    Sorter s(g);
    s.stalin_sort();
cout << g;
    cout << g.is_greedy();


}



