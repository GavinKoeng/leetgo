// Created by gavin at 2026/08/13 09:35
// leetgo: 1.4.17
// https://leetcode.cn/problems/add-two-numbers/

#include <bits/stdc++.h>
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        return dummyHead->next;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* l1;
	LeetCodeIO::scan(cin, l1);
	ListNode* l2;
	LeetCodeIO::scan(cin, l2);

	Solution *obj = new Solution();
	auto res = obj->addTwoNumbers(l1, l2);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
