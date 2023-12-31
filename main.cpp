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
    // int x = 1234554320;
    // int x = 999999999;
    // bool result;

    // std::string s = "MCMXCIV";
    std::string s = "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII";
    int ret = 0;


    for (auto _ : state)
    {
        // std::vector<int> result = LEETCODE::EASY::twoSum(nums, target);
        // result = LEETCODE::EASY::isPalindrome(x);
        ret = LEETCODE::EASY::romanToInt(s);

    }
}
BENCHMARK(BM_LEETCODE);

BENCHMARK_MAIN();
#endif


using namespace LEETCODE::EASY;


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


    // /* Palindrome Number (https://leetcode.com/problems/palindrome-number/description/) */
    // // int x = 123454321;
    // int x = 1234554321;
    // // int x = 999999999;
    // // int x = 0;
    // // int x = 1234567899;
    // bool ret = LEETCODE::EASY::isPalindrome(x);
    // dbg(ret);


    // /* Roman to Integer */
    // /* https://leetcode.com/problems/roman-to-integer/description/ */
    // // std::string s = "III";
    // // std::string s = "LVIII";
    // std::string s = "MCMXCIV";
    // int ret = LEETCODE::EASY::romanToInt(s);
    // dbg(ret);


    // /* Longest Common Prefix */
    // /* https://leetcode.com/problems/longest-common-prefix/description/ */
    // // std::vector<std::string> strs = {"flower","flow","flight"};
    // // std::vector<std::string> strs = {"dog","racecar","car"};
    // // std::vector<std::string> strs = {""};
    // // std::vector<std::string> strs = {"a"};
    // std::vector<std::string> strs = {"", ""};
    // // std::vector<std::string> strs = {"12", "1234", "12345"};
    // std::string ret = LEETCODE::EASY::longestCommonPrefix(strs);
    // dbg(ret);


    // /* Valid Parentheses */
    // /* https://leetcode.com/problems/valid-parentheses/description/ */
    // // std::string s = "()[]{}{{{{{{{{{{{{(((((([[[[[]]]]]))))))}}}}}}}}}}}}";
    // std::string s = "(){}}{";
    // // std::string s = "())]{}";
    // bool ret = LEETCODE::EASY::isValid(s);
    // dbg(ret);


    // /* Merge Two Sorted Lists */
    // /* https://leetcode.com/problems/merge-two-sorted-lists/description/ */
    // std::vector<int> list_1_src = {1, 2, 4};
    // std::vector<int> list_2_src = {1, 3, 4};
    // // std::vector<int> list_1_src = {1, 2, 4, 6, 7, 8, 9};
    // // std::vector<int> list_2_src = {1, 5, 6};

    // ListNode* list1 = vector2List(list_1_src);
    // ListNode* list2 = vector2List(list_2_src);
    // // printList(list1);
    // // printList(list2);
    
    // ListNode* ret = mergeTwoLists(list1, list2);
    // printf("ret:\n");
    // printList(ret);

    

    // // std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    // std::vector<int> nums = {1,1,2};
    // auto ret = removeDuplicates(nums);
    // dbg(ret);
    // dbg(nums);


    // std::vector<int> nums = {3,2,2,3};
    // auto ret = removeElement(nums, 3);
    // dbg(ret);
    // dbg(nums);


    // auto ret = strStr("leetcode", "leeto");
    // // auto ret = strStr("sssadbutsad", "sad");
    // dbg(ret);


    // std::vector<int> nums = {1,3,5,6};
    // auto ret = searchInsert(nums, 5);
    // dbg(ret);
    // dbg(nums);


    // auto ret = lengthOfLastWord("Hello World");
    auto ret = lengthOfLastWord("   fly me   to   the moon  ");
    dbg(ret);


    return 0;
}
#endif
