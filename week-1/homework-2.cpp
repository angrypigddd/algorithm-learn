/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * tmp = new ListNode();
        ListNode * tmp_l = tmp;
        ListNode* tmp_list1 = list1, * tmp_list2 = list2;
        while(tmp_list1 && tmp_list2){
            if(tmp_list1->val < tmp_list2->val){
                tmp_l->next =  tmp_list1;
                tmp_list1 = tmp_list1->next;
            }
            else{
                tmp_l->next =  tmp_list2;
                tmp_list2 = tmp_list2->next;
            }
            tmp_l = tmp_l->next;
        }
        tmp_l->next = tmp_list1 ? tmp_list1 : tmp_list2;
        return tmp->next;
    }
};
