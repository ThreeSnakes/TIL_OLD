### [Algorithm] HackerRank - Balanced Brackets

[Balanced Brackets](https://www.hackerrank.com/challenges/balanced-brackets/problem) 문제를 푼 기록이다. 

스택을 이용하는 문제이다. `[]`, `()`, `{}` 와 같은 괄호가 입력 되었을때 짝이 맞는지 체크하는 문제이다.
`JS`로 풀었다. 아.. 멍청한 짓 해서 45분정도 걸린것 같다. 아오...
머리를 한대 때려야 하나.. 아오 ㅠㅠ

<!-- more -->

일단 코드는 다음처럼 작성 헀다.

``` js
function isBalanced(s) {
    var result = 'YES',
        arr = [];
    
    for(var i = 0, max = s.length; i < max; i += 1 ) {
        if(s[i] === "{" || s[i] === "[" || s[i] === "(") {
            arr.push(s[i]);
        } else if((s[i] === "}" || s[i] === "]" || s[i] === ")") && arr.length > 0) {
            switch(s[i]) {
                case "}":
                    if(arr[arr.length - 1] === "{") {
                        arr.pop();
                    } else {
                        result = "NO";
                    }
                    break;
                case "]":
                    if(arr[arr.length - 1] === "[") {
                        arr.pop();
                    } else {
                        result = "NO";
                    }
                    break;
                case ")":
                    if(arr[arr.length - 1] === "(") {
                        arr.pop();
                    } else {
                        result = "NO";
                    }
                    break;
            }
        } else {
            result = "NO";          
        }
    }
    
    if(arr.length !== 0) {
        result = "NO";
    }
    
    return result;   
}
```

배열을 하나 만든후 여는 괄호가 들어오면 해당 배열에 삽입해주고, 닫는 괄호가 들어오면 배열의 마지막 아이템과 짝이 맞는지 비교한다. 만약 다를 경우에는 `NO`라고 출력하고 맞으면 `YES`로 출력하면 된다. 아 근데. 처음에 30분 시간제한으로 풀었을때, 너무 멍청하게 생각해서 `for문`을 돌릴때 `NO` case가 나올때 for문 break 걸어주면 더 좋았을 것이다.

그리고 -_- 테스트 케이스 하나를 계속 통과를 못시켯는데.. 아오 멍청하게 스택대용으로 만든 배열이 다비었는지 체크를 안했다. 이경우 왜 문제가 되냐면 만약에 여는 괄호만 역속으로 들어오거나, 닫는 괄호가 모두 입력이 안되었을때에는 `push`만하다가 끝나고, 에러(`NO`)가 발생하지 않는다. 그러니깐 스택 대용으로 만든 배열이 다 비었는지 확인해줘야 하는데.. 아오 ㅠㅠ 멍청한게...
이걸 안해놨다. ㅠㅠ


