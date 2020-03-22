
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> a = ListNodeToNum(l1);
    stack<int> b = ListNodeToNum(l2);
    int carry = 0;
    ListNode* cur = nullptr;
    while (!empty(a) || !empty(b) || carry != 0) {
      int x = empty(a) ? 0 : a.top();
      int y = empty(b) ? 0 : b.top();
      if (!empty(a)) {
        a.pop();
      }
      if (!empty(b)) {
        b.pop();
      }
      int sum = x + y + carry;
      carry = sum / 10;
      sum = sum % 10;
      ListNode* node = new ListNode(sum);
      node->next = cur;
      cur = node;
    }
    return cur;
  }

  stack<int> ListNodeToNum(ListNode* l) {
    stack<int> res;
    ListNode* p = l;
    while (p) {
      res.emplace(p->val);
      p = p->next;
    }
    return res;
  }
};
