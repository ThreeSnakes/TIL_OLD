# 2.[Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/)

## Problem

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

``` test
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```

---

## My Result

``` js
var addTwoNumbers = function(l1, l2) {
  let result = new ListNode(0);
  let current = result;
  let list1 = l1
  let list2 = l2
  let carry = 0

  while(list1 !== null || list2 !== null || carry) {
    const sum = (list1 !== null ? list1.val : 0 ) + (list2 !== null ? list2.val : 0) + carry;
    carry = sum >= 10 ? 1 : 0;
    current.val = sum >= 10 ? sum - 10 : sum

    list1 = list1 !== null ? list1.next: null;
    list2 = list2 !== null ? list2.next: null;

    if (list1 === null && list2 === null && !carry) {
      current.next = null;
    } else {
      current.next = new ListNode(0);
      current = current.next;
    }
  }

  return result;
};
```

처음에 문제를 풀때 개별 리스트를 순회하면서 숫자를 뽑아낸 다음에 이를 합친후 다시 ListNode로 바꾸도록 했었는데... 제출 하고 테스트를 하니깐 특정 케이스에서 깨지는 경우가 있었는데... -_-;; 리스트가 되게 길어서 이를 숫자로 변경할 경우 지수로 나오는 경우였다. 결국 처음 방법은 포기하고 리스트를 한칸씩 이동하면서 값을 구하는 방법으로 변경하여 풀었다. 그런데 처음 방법은 안좋은 방법이라는 것을 느낀게 위 방법으로 할 경우 제일 긴 리스트 + 1 만큼만 동작하는데.. 처음 방법은 리스트1 길이 + 리스트2 길이 * 2 만큼 동작을 해야 한다. 결국 이 방법이 맞는것 같다.
