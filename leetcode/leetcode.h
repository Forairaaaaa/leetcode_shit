/**
 * @file leetcode.h
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-08-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
 #pragma once
#include <dbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>


namespace LEETCODE
{
    namespace EASY
    {
        std::vector<int> twoSum(std::vector<int>& nums, int target);

        bool isPalindrome(int x);

        int romanToInt(std::string s);

        std::string longestCommonPrefix(std::vector<std::string>& strs);

        bool isValid(std::string s);

        struct ListNode
        {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
        };
        ListNode* vector2List(const std::vector<int> vector);
        void printList(ListNode* list);
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
        
        int removeDuplicates(std::vector<int>& nums);

        int removeElement(std::vector<int>& nums, int val);

        int strStr(std::string haystack, std::string needle);

        int searchInsert(std::vector<int>& nums, int target);
    }
};