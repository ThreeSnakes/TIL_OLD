# [Bootstrap] CheckBox

`Bootstrap`에서 `checkbox` 사용팁을 기록해 놓는다.

``` html
<div class="text-left checkbox">
  <label>
    <input type="checkbox"> Requirement
  </label>
</div>
```

위에 있는 코드처럼 **div태그** 안에 **label태그**를 만들고 그 안에 **checkbox**를 넣을 경우 **label**을 클릭하면 체크박스도 자동으로 체크가 된다. 위 형태가 아닐 경우에는 라벨에 별도의 이벤트, CSS를 다시 넣어줘야 되는데 이게 꽤 귀찮다. 그냥 위에 코드처럼 만들어서 넣어주자.
