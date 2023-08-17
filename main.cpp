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
#include <iostream>
#include <leetcode.h>



#ifdef GO_BENCHMARK
static void BM_LEETCODE(benchmark::State& state)
{

    // std::vector<int> nums = {3,2,4};
    // int target = 6;

    // int x = 1234554321;
    int x = 1234554320;
    bool result;


    for (auto _ : state)
    {


        // std::vector<int> result = LEETCODE::EASY::twoSum(nums, target);

        result = LEETCODE::EASY::isPalindrome(x);


    }
}
BENCHMARK(BM_LEETCODE);

BENCHMARK_MAIN();
#endif




#ifndef GO_BENCHMARK
int main(int argc, char const *argv[])
{
    

    // /* Two Sum (https://leetcode.com/problems/two-sum/description/) */
    // // std::vector<int> nums = {2,7,11,15};
    // // int target = 9;
    // std::vector<int> nums = {3,2,4};
    // int target = 6;
    // std::vector<int> result = LEETCODE::EASY::twoSum(nums, target);
    // dbg(result);


    /* Palindrome Number (https://leetcode.com/problems/palindrome-number/description/) */
    // int x = 123454321;
    // int x = 123455321;
    // int x = 999999999;
    // int x = 0;
    int x = 1234567899;
    bool ret = LEETCODE::EASY::isPalindrome(x);
    dbg(ret);



    return 0;
}
#endif
