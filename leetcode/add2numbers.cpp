#include <bits/stdc++.h>
using namespace std;

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode head(0);
        ListNode *dummy = &head;

        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = carry +
                      (l1 ? l1->val : 0) +
                      (l2 ? l2->val : 0);
            carry = sum / 10;
            dummy->next = new ListNode(sum % 10);
            dummy = dummy->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        ListNode *soln = dummy->next;
        delete &head;
        return soln;
    }
};

// boost for leetode
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return std::ios_base::sync_with_stdio(false);
}();

int main() {}
