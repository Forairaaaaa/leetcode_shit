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

/* -------------------------------------------------------------------------- */
/*                                    Shit                                    */
/* -------------------------------------------------------------------------- */
using namespace mooncake;
using namespace std;

void keep_printing_shit()
{
    for (int i = 0; i < 114514; i++) {
        std::vector<int> shit{6, 6, 6, 6, 6, 6};
        mclog::info("shit man, {}", shit);
    }
}

/* -------------------------------------------------------------------------- */
/*                                    Main                                    */
/* -------------------------------------------------------------------------- */
#ifndef GO_BENCHMARK
int main()
{
    keep_printing_shit();
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
