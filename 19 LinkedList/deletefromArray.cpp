#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        // Put nums into a set for O(1) lookup
        unordered_set<int> st(nums.begin(), nums.end());

        // Dummy node to handle deletions at head
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *curr = dummy;
        while (curr->next != nullptr)
        {
            if (st.count(curr->next->val))
            {
                // delete node
                ListNode *temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            else
            {
                curr = curr->next;
            }
        }

        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
