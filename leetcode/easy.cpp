/**
 * @file easy.cpp
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-08-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "leetcode.h"

using namespace LEETCODE;


std::vector<int> EASY::twoSum(std::vector<int>& nums, int target)
{
    dbg(nums);
    std::vector<int> result;


    struct Sum_t
    {
        int index_1;
        int index_2;
        int sum;
    };


    /* Get a sum up list */
    std::vector<Sum_t> sum_list;
    Sum_t sum_buffer;
    for (int i = 0; i < (nums.size() - 1); i++)
    {
        for (int j = (i + 1); j < nums.size(); j++)
        {
            printf("[%d][%d]\n", i, j);

            sum_buffer.index_1 = i;
            sum_buffer.index_2 = j;
            sum_buffer.sum = nums[i] + nums[j];
            sum_list.emplace_back(sum_buffer);
        }
    }
    


    /* Match target */
    for (const auto& i : sum_list)
    {
        if (i.sum == target)
        {
            result.emplace_back(i.index_1);
            result.emplace_back(i.index_2);
            break;
        }
    }
    

    return result;
}
