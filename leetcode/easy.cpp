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


/* Two Sum (https://leetcode.com/problems/two-sum/description/) */
std::vector<int> EASY::twoSum(std::vector<int>& nums, int target)
{
    dbg(nums);
    std::vector<int> result;



    // /* Iterate the shit out */
    // for (int i = 0; i < (nums.size() - 1); i++)
    // {
    //     for (int j = (i + 1); j < nums.size(); j++)
    //     {
    //         if ((nums[i] + nums[j]) == target)
    //         {
    //             result.push_back(i);
    //             result.push_back(j);
    //             break;
    //         }
    //     }
    // }



    /* Hashing approach? */
    /* https://medium.com/swlh/understanding-leetcode-the-two-sum-problem */

    int expect_value = 0;
    for (int i = 0; i < (nums.size() - 1); i++)
    {
        expect_value = target - nums[i];
        
        /* Search expect value */
        for (int j = (i + 1); j < nums.size(); j++)
        {
            if (nums[j] == expect_value)
            {
                result.push_back(i);
                result.push_back(j);
                break;
            }
        }
    }



    return result;
}


