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
#include <stack>
#include <regex>
#include "helper.h"

// #define GO_BENCHMARK

#ifdef GO_BENCHMARK
#define DBG_MACRO_DISABLE
#endif
#include <dbg.h>

using namespace mooncake;
using namespace std;
using namespace leetcode_helper;

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
