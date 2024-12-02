/**
 * @file main.cpp
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2023-08-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <benchmark/benchmark.h>
#include <mooncake_log.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_map>

// #define GO_BENCHMARK

#ifdef GO_BENCHMARK
#define DBG_MACRO_DISABLE
#endif
#include <dbg.h>

using namespace mooncake;
using namespace std;

/* -------------------------------------------------------------------------- */
/*                                   Helper                                   */
/* -------------------------------------------------------------------------- */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* helper_create_list_node(std::vector<int> shit)
{
    if (shit.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(shit[0]);
    ListNode* current = head;

    for (size_t i = 1; i < shit.size(); ++i) {
        current->next = new ListNode(shit[i]);
        current = current->next;
    }

    return head;
}

/* -------------------------------------------------------------------------- */
/*                                    Shit                                    */
/* -------------------------------------------------------------------------- */

void shit() {}

/* -------------------------------------------------------------------------- */
/*                                    Main                                    */
/* -------------------------------------------------------------------------- */
#ifndef GO_BENCHMARK
int main()
{
    shit();
    return 0;
}
#endif

/* -------------------------------------------------------------------------- */
/*                                  Benchmark                                 */
/* -------------------------------------------------------------------------- */
#ifdef GO_BENCHMARK
static void BM_LEETCODE(benchmark::State& state)
{
    for (auto _ : state) {
        keep_printing_shit();
    }
}
BENCHMARK(BM_LEETCODE);

BENCHMARK_MAIN();
#endif
