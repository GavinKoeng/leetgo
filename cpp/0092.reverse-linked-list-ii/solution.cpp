// Created by gavin at 2026/08/08 11:25
// leetgo: 1.4.17
// https://leetcode.cn/problems/reverse-linked-list-ii/

#include <bits/stdc++.h>
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
private:
    void reverseLinkedList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* prev = dummyHead;
        for (int i = 0; i < left - 1; i++) prev = prev->next;
        ListNode* rightNode = prev;
        for (int i = 0; i < right - left + 1; i++) rightNode = rightNode->next;
        ListNode* leftNode = prev->next;
        prev->next = nullptr;
        ListNode* afterNode = rightNode->next;
        rightNode->next = nullptr;
        reverseLinkedList(leftNode);
        prev->next = rightNode;
        leftNode->next = afterNode;
        return dummyHead->next;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);
	int left;
	LeetCodeIO::scan(cin, left);
	int right;
	LeetCodeIO::scan(cin, right);

	Solution *obj = new Solution();
	auto res = obj->reverseBetween(head, left, right);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
