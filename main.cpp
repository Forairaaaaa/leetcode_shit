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
#include <algorithm>
#include <benchmark/benchmark.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

// #define GO_BENCHMARK

#ifdef GO_BENCHMARK
#define DBG_MACRO_DISABLE
#endif
#include <dbg.h>

/* -------------------------------------------------------------------------- */
/*                                  Algorithm                                 */
/* -------------------------------------------------------------------------- */
using namespace std;
void keep_printing_shit()
{
    for (int i = 0; i < 114514; i++) {
    }
}

/* -------------------------------------------------------------------------- */
/*                                 Normal Main                                */
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
        addBinary("1010", "1011");
    }
}
BENCHMARK(BM_LEETCODE);

BENCHMARK_MAIN();
#endif
