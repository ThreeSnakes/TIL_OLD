# 7.[reverse interger](https://leetcode.com/problems/reverse-integer/)

## Problem

Given a 32-bit signed integer, reverse digits of an integer.

``` text
Example 1:

Input: 123
Output: 321
```

``` text
Example 2:

Input: -123
Output: -321
```

``` text
Example 3:

Input: 120
Output: 21
```

Note
> Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

---

## My Result

``` js
// @lc code=start
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
  const reversDigit = x >= 0 ? Array.from(x.toString()).reverse().join('') : `${Array.from(x.toString()).slice(1).reverse().join('')}`;
  
  if (reversDigit > 0x7FFFFFFF) return 0;
  else return x >= 0 ? Number(reversDigit) : Number(`-${reversDigit}`);
};
// @lc code=end

```

#### 새롭게 배운것

- 조건중에 `2^31` d보다 클 경우 0을 리턴하라고 되어 있었는데 이 조건을 어떻게 처리해야 하나 싶었다. 처음에는 Math 라이브러리를 사용해서 해야 하나 했는데.. 그건 아닐꺼 같아서 다른 방법을 찾아보니 `2^31 - 1 = 0x7FFFFFFF`라고 한다. 그럼 `2^32 = 0x80000000` 인데 16진수에서 한 자리는 각각 16진수 즉, `2^4`를 말한다. `2^31`을 하나씩 분해하면 오른쪽에서부터 `0이 7개`가 되고, `마지막에 2^3이 남으므로 8`이 된다.  이를 합치면 `0x80000000`이 되고 여기서 1을 빼면 `0x7FFFFFFF`이 된다. 이런 값을 바로 떠올릴수 있어야 한다. 안 그러면 처음 생각했던것처럼.. Math 라이브러리를 써야지 해결 할 수 있었을 것이다.
