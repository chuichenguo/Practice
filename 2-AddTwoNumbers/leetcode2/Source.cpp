using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 /*
 ���ӬO�ݭn�Τj�ƥ[�k�A�D�ػ��Ʀr�i���100��ơC
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sentinel = new ListNode(0);
        ListNode* l3 = sentinel;
        int sum = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum = sum + l2->val;
                l2 = l2->next;
            }
            l3->next = new ListNode(sum % 10);
            l3 = l3->next;
            sum = sum / 10;
        }
        if (sum != 0) {
            l3->next = new ListNode(sum % 10);
        }
        return sentinel->next;
    }
};