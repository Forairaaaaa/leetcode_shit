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
/*                                 Normal shit                                */
/* -------------------------------------------------------------------------- */
using namespace std;
string addBinary(string a, string b)
{
    string result;

    bool carry = false;
    bool bit_a = false;
    bool bit_b = false;
    int bit_on_num = 0;

    int max_len = 0;
    if (a.size() > b.size())
        max_len = a.size();
    else
        max_len = b.size();

    for (int index = 0; index < max_len + 1; index++)
    {
        dbg("---------------------");
        dbg(index);

        // Get bit
        if (index < a.size())
            bit_a = a[a.size() - index - 1] == '1';
        else
            bit_a = false;

        if (index < b.size())
            bit_b = b[b.size() - index - 1] == '1';
        else
            bit_b = false;

        dbg(bit_a);
        dbg(bit_b);
        dbg(carry);

        // Count 1 num
        bit_on_num = 0;
        if (bit_a)
            bit_on_num++;
        if (bit_b)
            bit_on_num++;
        if (carry)
            bit_on_num++;
        dbg(bit_on_num);

        // Add
        if (bit_on_num == 0)
        {
            result.insert(result.begin(), '0');
            carry = false;
        }
        else if (bit_on_num == 1)
        {
            result.insert(result.begin(), '1');
            carry = false;
        }
        else if (bit_on_num == 2)
        {
            result.insert(result.begin(), '0');
            carry = true;
        }
        else if (bit_on_num == 3)
        {
            result.insert(result.begin(), '1');
            carry = true;
        }
    }

    // Remove 0 at front
    auto first_0_index = result.find_first_not_of('0');
    if (first_0_index == std::string::npos)
        result = "0";
    else
        result = result.substr(first_0_index);

    dbg(result);
    return result;
}

#ifndef GO_BENCHMARK
int main()
{
    addBinary("11", "1");
    addBinary("11", "001");
    addBinary("1010", "1011");
    addBinary("0", "0");
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
