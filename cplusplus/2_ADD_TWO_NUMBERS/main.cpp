#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){};
    ListNode(int x, ListNode *node):val(x),next(node){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
        if(!l1 || !l2)
            return nullptr;
        ListNode *head = nullptr, *pre_ptr = nullptr;
        int carry = 0;
        while(l1 || l2){
            // 注意双目运算符得使用
            int l1_val = l1? l1->val:0;
            int l2_val = l2? l2->val:0;
            int total_sum = l1_val + l2_val + carry;
            carry = total_sum / 10;
            int sum = total_sum - carry * 10;
            if(!head)
                //注意重新生成新的链表
                head = pre_ptr = new ListNode(sum);
            else {
                ListNode *node = new ListNode(sum);
                pre_ptr->next = node;
                pre_ptr = pre_ptr->next;
            }
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carry){
            ListNode *tmp = new ListNode(1);
            pre_ptr->next = tmp;
            pre_ptr = pre_ptr->next;
        }
        return head;
    }
};

int main()
{
    // 0 1 2 3 4 5 6 7 8 9
    ListNode *head1 = new ListNode(3);
    for(int i = 2; i >= 0 ;i--){
        ListNode *tmp = new ListNode(i,head1);
        head1 = tmp;
    }
    // 0 1 2 3
    ListNode *head2 = new ListNode(3);
    for(int i = 2; i >= 0 ;i--){
        ListNode *tmp = new ListNode(i,head2);
        head2 = tmp;
    }
//    while(head1){
//        cout<< head1->val << endl;
//        head1 = head1->next;
//    }
    Solution sol;
    ListNode *result = sol.addTwoNumbers(head1,head2);
    while(result){
        cout<< result->val << endl;
        result = result->next;
    }
    cout << "Hello World!" << endl;
    return 0;
}
