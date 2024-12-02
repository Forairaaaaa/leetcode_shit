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
#include <vector>
#include <mooncake_log.h>

namespace helper {

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* helper_create_list(std::vector<int> shit)
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

void helper_print_list(ListNode* head)
{
    ListNode* current = head;
    while (current) {
        fmt::print("{} ", current->val);
        current = current->next;
    }
    fmt::print("\n");
}

} // namespace helper
