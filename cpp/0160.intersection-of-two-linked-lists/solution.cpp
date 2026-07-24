// Created by Gavin at 2026/01/23 11:45
// leetgo: 1.4.15
// https://leetcode.cn/problems/intersection-of-two-linked-lists/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int intersectVal;
	LeetCodeIO::scan(cin, intersectVal);
	ListNode* listA;
	LeetCodeIO::scan(cin, listA);
	ListNode* listB;
	LeetCodeIO::scan(cin, listB);
	int skipA;
	LeetCodeIO::scan(cin, skipA);
	int skipB;
	LeetCodeIO::scan(cin, skipB);

	Solution *obj = new Solution();
	auto res = obj->getIntersectionNode(intersectVal, listA, listB, skipA, skipB);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
