// Created by Gavin at 2025/12/13 21:56
// leetgo: 1.4.15
// https://leetcode.cn/problems/merge-k-sorted-lists/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
      if ((!a) || (!b)) return a ? a : b;
      ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
      while (aPtr && bPtr) {
        if (aPtr->val < bPtr->val) {
          tail->next = aPtr;
          aPtr = aPtr->next;
        } else {
          tail->next = bPtr;
          bPtr = bPtr->next;
        }
        tail = tail->next;
      }
      tail->next = (aPtr ? aPtr : bPtr);
      return head.next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode *ans = nullptr;
      for (size_t i = 0; i < lists.size(); ++i) {
        ans = mergeTwoLists(ans, lists[i]);
      }
      return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<ListNode*> lists;
	LeetCodeIO::scan(cin, lists);

	Solution *obj = new Solution();
	auto res = obj->mergeKLists(lists);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
