//1刷
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
		int add = l1->val + l2->val;
		int divide = add / 10;
		int mod = add % 10;
		ListNode *node = new ListNode(mod);
		ListNode *l3 = node;
		l1 = l1->next;
		l2 = l2->next;
		while ((divide != 0) || l1 || l2) {
			if (l1&&l2) {
				add = l1->val + l2->val + divide;
				mod = add % 10;
				divide = add / 10;
				node->next = new ListNode(mod);
				node = node->next;
				l1 = l1->next;
				l2 = l2->next;
			}
			else if ((l1 == NULL) || (l2 == NULL)) {
				if ((l1 == NULL) && (l2 != NULL)) {
					add = l2->val + divide;
					mod = add % 10;
					divide = add / 10;
					node->next = new ListNode(mod);
					node = node->next;
					l2 = l2->next;
				}
				else if ((l2 == NULL) && (l1 != NULL)) {
					add = l1->val + divide;
					mod = add % 10;
					divide = add / 10;
					node->next = new ListNode(mod);
					node = node->next;
					l1 = l1->next;
				}
				else {
					add = divide;
					mod = add % 10;
					divide = add / 10;
					node->next = new ListNode(mod);
					node = node->next;
				}
			}
		}
		return l3;
	}
};

/*2刷
前面的几个分析都太过复杂
直接按顺序分析就行
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
		if (l1 == NULL) {
			return l2;
		}
		if (l2 == NULL) {
			return l1;
		}
		int sum, mod;
		int flag = 0;
		ListNode *h = NULL;
		ListNode *head = NULL;
		while (l1 || l2) {
			sum = 0;
			if (l1 != NULL) {
				sum = l1->val + sum;
				l1 = l1->next;
			}
			if (l2 != NULL) {
				sum = l2->val + sum;
				l2 = l2->next;
			}
			sum = sum + flag;
			mod = sum % 10;
			flag = sum / 10;
			if (head == NULL) {
				head = new ListNode(mod);
				h = head;
			}
			else {
				h->next = new ListNode(mod);
				h = h->next;
			}
		}
		if (flag != 0) {
			h->next = new ListNode(flag);
		}
		return head;
	}
};
