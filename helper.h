/**
 * @file helper.h
 * @author Forairaaaaa
 * @brief
 * @version 0.1
 * @date 2024-12-02
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <mooncake_log.h>

namespace helper {

/* -------------------------------------------------------------------------- */
/*                                    List                                    */
/* -------------------------------------------------------------------------- */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* create_list(std::vector<int> shit)
{
    if (shit.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(shit[0]);
    ListNode* current = head;

    for (size_t i = 1; i < shit.size(); ++i) {
        current->next = new ListNode(shit[i]);
        current = current->next;
    }

    return head;
}

void print_list(ListNode* head)
{
    ListNode* current = head;
    while (current) {
        fmt::print("{} ", current->val);
        current = current->next;
    }
    fmt::print("\n");
}

/* -------------------------------------------------------------------------- */
/*                                    Tree                                    */
/* -------------------------------------------------------------------------- */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

} // namespace helper
