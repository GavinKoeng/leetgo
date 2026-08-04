// Created by gavin at 2026/08/04 13:14
// leetgo: 1.4.17
// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int N = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            N++;
        }
        cur = dummy;
        for (int i = 0; i < N - n; i++) {
            cur = cur->next;
        }
        ListNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        
        head = dummy->next;
        delete dummy;
        return head;

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);
	int n;
	LeetCodeIO::scan(cin, n);

	Solution *obj = new Solution();
	auto res = obj->removeNthFromEnd(head, n);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
