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
#include <cstdio>
#include <iostream>

// #define GO_BENCHMARK

#ifdef GO_BENCHMARK
#define DBG_MACRO_DISABLE
#endif
#include <dbg.h>


/* -------------------------------------------------------------------------- */
/*                                 Normal shit                                */
/* -------------------------------------------------------------------------- */
#ifndef GO_BENCHMARK
int main()
{
    dbg("????");
    return 0;
}
#endif


/* -------------------------------------------------------------------------- */
/*                                  Benchmark                                 */
/* -------------------------------------------------------------------------- */
#ifdef GO_BENCHMARK

static void _test_function()
{
    auto a = 1 + 1;
    auto b = a * a;
}

static void BM_LEETCODE(benchmark::State& state)
{
    for (auto _ : state)
    {
        _test_function();
    }
}
BENCHMARK(BM_LEETCODE);

BENCHMARK_MAIN();
#endif
