#include <iostream>
#include "graph.h"
#include "sorter.h"
#include <sstream>
#include <stdexcept>
#include <sys/time.h>
#include <cstdlib>
#include <ctime>
#include <sys/resource.h>
using namespace std;

float diffUserTime(struct rusage *start, struct rusage *end) {
    return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
           1e-6 * (end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}

float diffSystemTime(struct rusage *start, struct rusage *end) {
    return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) +
           1e-6 * (end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}

double diffClockTime(struct timespec *start, struct timespec *end) {
    return (end->tv_sec - start->tv_sec) +
           1e-9 * (end->tv_nsec - start->tv_nsec);
}


int main(int argc, char *argv[]) {
    char sort_method;
    UI vertex_num;

    string line;
    getline(cin, line);
    istringstream stream(line);

    stream >> sort_method >> vertex_num;
    Graph g(vertex_num);
    Sorter s(g);


    struct rusage start, end;
    getrusage(RUSAGE_SELF, &start);

    struct timespec clockStart, clockEnd;
    clock_gettime(CLOCK_REALTIME, &clockStart);

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

    clock_gettime(CLOCK_REALTIME, &clockEnd);
    getrusage(RUSAGE_SELF, &end);

//    std::cout << std::endl << "User time: " << diffUserTime(&start, &end) << " sec" << std::endl;
//    std::cout << "System time: " << diffSystemTime(&start, &end) << " sec" << std::endl;
    std::cout  <<  diffClockTime(&clockStart, &clockEnd)  << std::endl;
//
//    g.is_greedy() ? cout << "1 " << g : cout << "0";
//    cout << endl;

}



