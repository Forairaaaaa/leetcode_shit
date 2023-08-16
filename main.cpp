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
#include <iostream>
#include <leetcode.h>


int main(int, char**)
{
    std::cout << "Hello, from leetcode_shit!\n";




    /* Two Sum (https://leetcode.com/problems/two-sum/description/) */
    // std::vector<int> nums = {2,7,11,15};
    // int target = 9;
    std::vector<int> nums = {3,2,4};
    int target = 6;
    std::vector<int> result = LEETCODE::EASY::twoSum(nums, target);
    dbg(result);
    
}
