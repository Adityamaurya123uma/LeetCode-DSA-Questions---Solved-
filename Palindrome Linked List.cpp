class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> val;
    ListNode* temp = head;
    while(temp!=nullptr){
        val.push_back(temp->val);
        temp = temp->next;
    }
    int i=0,j=val.size()-1;
    while(i<j){
        if(val[i]!=val[j]) return false;
        ++i,--j;
    }
    return true;
    }
};