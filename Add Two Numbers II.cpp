class Solution {
public:
    ListNode* Helper(ListNode* l1, ListNode* l2) {
        stack<int> stack1, stack2;

        while (l1 != nullptr) {
            stack1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            stack2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* result = nullptr;
        int carry = 0;

        while (!stack1.empty() || !stack2.empty() || carry != 0) {
            int digit1 = !stack1.empty() ? stack1.top() : 0;
            int digit2 = !stack2.empty() ? stack2.top() : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            newNode->next = result;
            result = newNode;

            if (!stack1.empty())
                stack1.pop();
            if (!stack2.empty())
                stack2.pop();
        }

        return result;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = Helper(l1, l2);
        return ans;
    }
};
