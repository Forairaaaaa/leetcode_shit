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


    /* Last Stone Weight II (https://leetcode.com/problems/last-stone-weight-ii/description/) */
    std::vector<int> stones {31,26,33,21,40};
    // std::vector<int> stones {2,7,4,1,8,1};
    LEETCODE::STONE::lastStoneWeightII(stones);


}
