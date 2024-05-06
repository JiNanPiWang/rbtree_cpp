#include "rbtree.h"
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include "utils/iptools.h"


int main(int argc, char *argv[])
{
    uint64_t n = std::atoll(argv[1]);
    uint64_t *data = new uint64_t[n];
    rb_tree<long long> tree;
    std::cout << "test_rb_tree: insert" << std::endl;

    auto ips = iptools::readIpAddresses(argv[4]);
    // auto ips = iptools::readIpAddresses("../datasets/generated_ips/random_ips_10k.txt");

    for (uint64_t i = 0; i < n; i++)
    {
        // dense, sorted
        // data[i] = i + 1;
        data[i] = ips[i];
    }
    if (atoi(argv[2]) == 1)
    {
        // dense, random
        std::random_shuffle(data, data + n);
    }
    if (atoi(argv[2]) == 2)
    {
        // "pseudo-sparse" (the most-significant leaf bit gets lost)
        for (uint64_t i = 0; i < n; i++)
            data[i] = (static_cast<uint64_t>(rand()) << 32) | static_cast<uint64_t>(rand());
    }

    auto start = std::chrono::system_clock::now();
    for (auto i = 0; i < n; ++i)
    {
        tree.insert(data[i]);
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double, std::micro> elapsed_microseconds = end - start; // 修改这里
    std::cout << "insert time: " << elapsed_microseconds.count() << "us\n"; // 修改这里

    // std::cout << "Size of tree node: " << sizeof(rb_tree_node<long long>) << " bytes" << std::endl;
    std::cout << "Total memory used: " << (double)sizeof(rb_tree_node<long long>) * n / 1024 / 1024 << " MBs" << std::endl;

    for (auto i = 0; i < n; ++i)
    {
        auto debug = data[i];
        tree.erase(debug);
        // tree.dump();
    }

    return 0;
}