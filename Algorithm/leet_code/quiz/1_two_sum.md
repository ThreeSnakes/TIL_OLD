# 1.[Two Sum](https://leetcode.com/problems/two-sum/description/)

## Problem

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

``` text
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

---

## My Result

``` js
var twoSum = function(nums, target) {
  const result = [];
  nums.reduce((map, current, index) => {
    if (map[target - current] !== undefined) {
      result.push(map[target - current], index)
    }

    map[current] = index;

    return map;
  }, {})
  return result;
};
```