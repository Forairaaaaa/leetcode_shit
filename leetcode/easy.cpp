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
#include <unordered_map>


using namespace LEETCODE;


/* Two Sum (https://leetcode.com/problems/two-sum/description/) */
std::vector<int> EASY::twoSum(std::vector<int>& nums, int target)
{
    dbg(nums);
    /* Pre alloc memory */
    std::vector<int> result = {-1, -1};



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

    // int expect_value = 0;
    // for (int i = 0; i < (nums.size() - 1); i++)
    // {
    //     expect_value = target - nums[i];
        
    //     /* Search expect value */
    //     for (int j = (i + 1); j < nums.size(); j++)
    //     {
    //         if (nums[j] == expect_value)
    //         {
    //             result.push_back(i);
    //             result.push_back(j);
    //             break;
    //         }
    //     }
    // }


    /* Store nums in a hash table */
    std::unordered_map<int, int> nums_hash_table;
    for (int i = 0; i < nums.size(); i++)
    {
        nums_hash_table[nums[i]] = i;
    }
    dbg(nums_hash_table);
    

    int expect_value;
    std::unordered_map<int, int>::iterator iter;
    int i_max = nums.size() - 1;
    for (int i = 0; i < i_max; i++)
    {
        expect_value = target - nums[i];
        dbg(expect_value);
        
        /* Search expect value in hash table */
        // auto iter = nums_hash_table.find(expect_value);
        iter = nums_hash_table.find(expect_value);

        if (iter != nums_hash_table.end())
        {
            /* Exclude self adding */
            if (iter->second == i)
                continue;
            
            /* Since we only have one answer */
            /* in case like [3,0,1,2,3], hash key "3" will be linked to "4" */
            /* When i = 0, get expect_value = 3, "4" is what we get in hash table */
            /* So we're good */

            // result.push_back(i);
            // result.push_back(iter->second);
            result[0] = i;
            result[1] = iter->second;
            break;
        }
    }



    return result;
}


/* Palindrome Number (https://leetcode.com/problems/palindrome-number/description/) */
bool EASY::isPalindrome(int x)
{



    return false;
}
