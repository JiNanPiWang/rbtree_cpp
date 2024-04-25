#include "rbtree.h"
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>

const int max_len = 5000000;
long long data[max_len + 10];

int main(int argc, char *argv[])
{
    auto n = max_len;
    rb_tree<long long> tree;
    std::cout << "test_rb_tree: insert" << std::endl;

    for (uint64_t i = 0; i < n; i++)
    {
        // dense, sorted
        data[i] = i + 1;
    }
    if (atoi(argv[1]) == 1)
    {
        // dense, random
        std::random_shuffle(data, data + n);
    }
    if (atoi(argv[1]) == 2)
    {
        // "pseudo-sparse" (the most-significant leaf bit gets lost)
        for (uint64_t i = 0; i < n; i++)
            data[i] = (static_cast<uint64_t>(rand()) << 32) | static_cast<uint64_t>(rand());
    }

    auto start = std::chrono::system_clock::now();
    for (auto i = 0; i < max_len; ++i)
    {
        tree.insert(data[i]);
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Elapsed time for insertion: " << elapsed_seconds.count() << "s\n";

    // std::cout << "Size of tree node: " << sizeof(rb_tree_node<long long>) << " bytes" << std::endl;
    std::cout << "Total memory used: " << (double)sizeof(rb_tree_node<long long>) * max_len / 1024 / 1024 << " MBs" << std::endl;

    for (auto i = 0; i < max_len; ++i)
    {
        auto debug = data[i];
        tree.erase(debug);
        // tree.dump();
    }

    return 0;
}