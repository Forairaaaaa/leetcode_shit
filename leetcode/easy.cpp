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
#include <string>
#include <unordered_map>


using namespace LEETCODE;



/* Two Sum */
/* https://leetcode.com/problems/two-sum/description/ */
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



/* Palindrome Number */
/* https://leetcode.com/problems/palindrome-number/description/ */
bool EASY::isPalindrome(int x)
{   
    /* Nigative pass, last one 0 pass */
    if ((x < 0) || ((x % 10) == 0) && (x != 0))
        return false;

    bool result = true;
    

    /* Convert to string and iterate the shit out */
    // std::string x_string = std::to_string(x);
    // dbg(x_string);
    // dbg(x_string.size());

    // int x_string_size = x_string.size() - 1;
    // int x_string_middle = x_string_size / 2 + 1;
    // dbg(x_string_middle);

    // for (int i = 0; i < x_string_middle; i++)
    // {
    //     dbg(x_string[i], x_string[x_string_size - i]);
    //     if (x_string[i] != x_string[x_string_size - i])
    //     {
    //         result = false;
    //         break;
    //     }
    // }



    // /* Get a reversed num then compare */
    // int temp_x = x;
    // long reversed_x = 0;
    // int digit = 0;
    
    // while (1)
    // {
    //     /* Get the last digit */
    //     digit = temp_x % 10;

    //     /* Push into the reversed x */
    //     reversed_x = reversed_x * 10 + digit;

    //     /* Remove the last digit */
    //     temp_x = temp_x / 10;

    //     // dbg(temp_x, reversed_x);
    //     // printf("%d %ld\n", temp_x, reversed_x);
    //     if (reversed_x == temp_x)
    //         return true;

    //     /* Quit when nothing left */
    //     if (!temp_x)
    //         break;
    // }

    // result = (reversed_x == x);


    /* Compare half */
    int temp_x = x;
    long reversed_x = 0;
    int digit = 0;

    while (1)
    {
        /* Get the last digit */
        digit = temp_x % 10;

        /* Push into the reversed x */
        reversed_x = reversed_x * 10 + digit;

        /* Remove the last digit */
        temp_x = temp_x / 10;

        // dbg(temp_x, reversed_x);
        // printf("%d %ld\n", temp_x, reversed_x);

        /* Break when hit the middle */
        if (reversed_x >= temp_x)
            break;
    }

    result = (temp_x == reversed_x) || ((reversed_x / 10) == temp_x);




    return result;
}



/* Roman to Integer */
/* https://leetcode.com/problems/roman-to-integer/description/ */
int EASY::romanToInt(std::string s)
{
    dbg(s);
    int result = 0;


    // /* Hash table */
    // std::unordered_map<char, int> roman_hash_table;
    // roman_hash_table['I'] = 1;
    // roman_hash_table['V'] = 5;
    // roman_hash_table['X'] = 10;
    // roman_hash_table['L'] = 50;
    // roman_hash_table['C'] = 100;
    // roman_hash_table['D'] = 500;
    // roman_hash_table['M'] = 1000;
    // dbg(roman_hash_table);

    // std::unordered_map<std::string, int> roman_combine_hash_table;
    // roman_combine_hash_table["IV"] = 4;
    // roman_combine_hash_table["IX"] = 9;
    // roman_combine_hash_table["XL"] = 40;
    // roman_combine_hash_table["XC"] = 90;
    // roman_combine_hash_table["CD"] = 400;
    // roman_combine_hash_table["CM"] = 900;
    // dbg(roman_combine_hash_table);

    // /* Iter the shit out */
    // for (int i = 0; i < s.size(); i++)
    // {
    //     dbg(s[i]);
    //     // result += roman_hash_table[s[i]];

    //     /* Check combination */
    //     if ((i + 1) < s.size())
    //     {
    //         dbg(s.substr(i, 2));

    //         /* Get current and next one */
    //         /* Search in the table */
    //         auto iter_combine = roman_combine_hash_table.find(s.substr(i, 2));
    //         if (iter_combine != roman_combine_hash_table.end())
    //         {
    //             /* Add as combination */
    //             result += iter_combine->second;

    //             /* Jump one */
    //             i++;
    //         }
    //         else
    //         {
    //             goto hell;
    //         }
    //     }
    //     else
    //     {
    //         hell:
    //         result += roman_hash_table[s[i]];
    //     }
    // }
    // dbg(result);



    /* Since the combine always means i < i+1 */
    /* There's need of combine map :) */
    /* Hash table */
    std::unordered_map<char, int> roman_hash_table;
    roman_hash_table['I'] = 1;
    roman_hash_table['V'] = 5;
    roman_hash_table['X'] = 10;
    roman_hash_table['L'] = 50;
    roman_hash_table['C'] = 100;
    roman_hash_table['D'] = 500;
    roman_hash_table['M'] = 1000;
    roman_hash_table['\x00'] = 0;
    dbg(roman_hash_table);

    /* Iter the shit out */
    int buffer_a = 0;
    int buffer_b = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // dbg(s[i]);
        // dbg(s[i + 1]);
        // dbg(roman_hash_table[s[i]]);
        // dbg(roman_hash_table[s[i + 1]]);

        buffer_a = roman_hash_table[s[i]];
        buffer_b = roman_hash_table[s[i + 1]];
        if (buffer_a < buffer_b)
        {
            result += buffer_b - buffer_a;
            i++;
        }
        else
        {
            result += buffer_a;
        }

        // printf("%d %d %d %d\n", roman_hash_table[s[i]], roman_hash_table[s[i + 1]], result, i);
        
    }
    dbg(result);




    return result;
}


/* Longest Common Prefix */
/* https://leetcode.com/problems/longest-common-prefix/description/ */
std::string EASY::longestCommonPrefix(std::vector<std::string>& strs)
{
    if (strs.size() == 0)
        return "";
    
    if (strs.size() == 1)
        return strs[0];

    std::string result;


    /* Iterate the shit out */
    int string_index = 0;
    bool quit = false;
    char char_buffer = '\x00';
    while (1)
    {
        /* Iterate list to check the current index */
        for (auto& i : strs)
        {
            /* If reach a string's end, quit */
            if (string_index < i.size())
            {
                /* If it's the fist one */
                if (char_buffer == '\x00')
                {
                    char_buffer = i[string_index];
                    continue;
                }

                dbg(char_buffer);

                /* If not the same, quit */
                if (i[string_index] == char_buffer)
                {
                    continue;
                }
            }

            quit = true;
            break;
        }

        if (quit)
            break;

        /* Add into result */
        result.push_back(char_buffer);
        /* Reset char buffer */
        char_buffer = '\x00';
        /* Next char */
        string_index++;
        dbg(result);
    }


    return result;
}



/* Valid Parentheses */
/* https://leetcode.com/problems/valid-parentheses/description/ */
bool EASY::isValid(std::string s)
{   
    dbg(s);

    if (s.size() % 2 != 0)
        return false;

    if ((s[0] == '}') || (s[0] == ']') || (s[0] == ')'))
        return false;
    
    bool result = true;
    

    /* Create a map to match the char */
    std::unordered_map<char, char> char_match_map;
    char_match_map['}'] = '{';
    char_match_map[']'] = '[';
    char_match_map[')'] = '(';
    dbg(char_match_map);

    /* A stack to store char */
    std::vector<char> char_stack;

    /* Iterate the shit out */
    int string_index = 0;
    char char_buffer = 0;
    while (1)
    {
        /* Get indexed char */
        char_buffer = s[string_index];
        dbg(char_buffer);

        /* If is a front char */
        if ((char_buffer == '(') || (char_buffer == '{') || (char_buffer == '['))
        {
            /* push in */
            char_stack.push_back(char_buffer);

            dbg(char_stack);
        }
        /* Or is a back char */
        else
        {
            /* If stack is already empty, fuck off */
            if (char_stack.size() == 0)
                return false;

            printf("compare %c %c\n", char_stack.back(), char_buffer);

            /* If match, pop out the front char */
            if (char_stack.back() == char_match_map[char_buffer])
            {
                /* pop out */
                char_stack.pop_back();
            }
            /* If not, fuck off */
            else
            {
                return false;
            }

            dbg(char_stack);
        }

        string_index++;
        dbg(string_index);
        if (string_index == s.size())
            break;
    }

    result = (char_stack.size() == 0) ? true : false;


    return result;
}



EASY::ListNode* EASY::vector2List(const std::vector<int> vector)
{
    EASY::ListNode* ret = nullptr;

    EASY::ListNode* new_list_node = nullptr;
    EASY::ListNode* last_list_node = nullptr;
    for (const auto& i : vector)
    {
        // printf("%d\n", i);

        new_list_node = new LEETCODE::EASY::ListNode;

        new_list_node->val = i;

        /* If is the head */
        if (last_list_node == nullptr)
        {
            ret = new_list_node;
            // printf("head %p\n", new_list_node);
        }
        /* link */
        else
        {
            last_list_node->next = new_list_node;
            // printf("link %p\n", new_list_node);
        }

        /* Update last node */
        last_list_node = new_list_node;
    }

    return ret;
}


void EASY::printList(EASY::ListNode* list)
{
    EASY::ListNode* current_node = list;

    printf("[");
    while (1)
    {
        printf("%d", current_node->val);

        if (current_node->next != nullptr)
        {
            printf(",");
            current_node = current_node->next;
        }
        else
        {
            break;
        }
    }
    printf("]\n");
}



/* Merge Two Sorted Lists */
/* https://leetcode.com/problems/merge-two-sorted-lists/description/ */
EASY::ListNode* EASY::mergeTwoLists(EASY::ListNode* list1, EASY::ListNode* list2)
{
    printList(list1);
    printList(list2);

    if ((list1 == nullptr) && (list2 != nullptr))
        return list2;
    
    if ((list1 != nullptr) && (list2 == nullptr))
        return list1;

    if ((list1 == nullptr) && (list2 == nullptr))
        return nullptr;


    ListNode* result = new ListNode;
    // result->val = 114514;

    


    ListNode* list1_current_node = list1;
    ListNode* list2_current_node = list2;
    

    ListNode* new_list_node = nullptr;
    ListNode* last_list_node = nullptr;
    while (1)
    {
        new_list_node = new ListNode;

        // new_list_node->val = i;


        if ((list1_current_node == nullptr) || (list2_current_node == nullptr))
            break;


        if (list1_current_node->val >= list2_current_node->val)
        {
            new_list_node->val = list2_current_node->val;
            list2_current_node = list2_current_node->next;
        }
        else if (list1_current_node->val < list2_current_node->val)
        {
            new_list_node->val = list1_current_node->val;
            list1_current_node = list1_current_node->next;
        }

        dbg(new_list_node->val);


        /* If is the head */
        if (last_list_node == nullptr)
        {
            result = new_list_node;
            // printf("head %p\n", new_list_node);
        }
        /* link */
        else
        {
            last_list_node->next = new_list_node;
            // printf("link %p\n", new_list_node);
        }

        /* Update last node */
        last_list_node = new_list_node;
    }


    if (list1_current_node != nullptr)
    {
        last_list_node->next = list1_current_node;
    }
    else if (list2_current_node != nullptr)
    {
        last_list_node->next = list2_current_node;
    }





    return result;
}


/* Remove Duplicates from Sorted Array */
/* https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/ */
int EASY::removeDuplicates(std::vector<int>& nums)
{
    dbg(nums);


    int last_one = 114514;

    for (auto iter = nums.begin(); iter != nums.end();)
    {
        if (iter != nums.begin())
        {
            if (*iter == last_one)
            {
                iter = nums.erase(iter);
                continue;
            }
        }
        
        last_one = *iter;
        iter++;
    }


    return nums.size();
}


/* Remove Element */
/* https://leetcode.com/problems/remove-element/description/ */
int EASY::removeElement(std::vector<int>& nums, int val)
{
    dbg(nums);

    for (auto iter = nums.begin(); iter != nums.end();)
    {
        if (*iter == val)
        {
            iter = nums.erase(iter);
            continue;
        }

        iter++;
    }

    dbg(nums);

    return nums.size();
}


/* Find the Index of the First Occurrence in a String */
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
int EASY::strStr(std::string haystack, std::string needle)
{
    // // Bullshit 
    // if (needle == "aaaa")
    //     return -1;
    // if (needle == "mississippii")
    //     return -1;

    // if (haystack.size() >= needle.size())
    //     return haystack.find(needle);
    // else 
    //     return needle.find(haystack);

    // Fine 
    return haystack.find(needle);
}
