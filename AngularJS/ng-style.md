# ng-style 사용법

## 목차

- [함수로 사용하는 경우](#함수로-사용하는-경우)
- [템플릿으로 사용하는 경우](#템플릿으로-사용하는-경우)

### 함수로 사용하는 경우

``` html
<div class="modal-body">
  <div style="text-align:center;width: 100%;overflow:scroll;">
		<!--  이 부분이다. 아래 ng-style을 확인하자. -->
    <img ng-src="{{imgUrl}}"
      style="display:block;margin-left:auto;margin-right:auto;width:50%;"
      ng-style="imgStyle"
    />
  </div>
  <div class="row" style="margin-top:10px;text-align: center">
    <div class="btn-group" role="group">
      <button type="button" class="btn btn-info" ng-click="imgRotate('-90')">{{ "ad::좌 90도 회전" | i18next }}</button>
      <button type="button" class="btn btn-success" ng-click="imgRotate('origin')">{{ "ad::원본" | i18next }}</button>
      <button type="button" class="btn btn-info" ng-click="imgRotate('+90')">{{ "ad::우 90도 회전" | i18next }}</button>
    </div>
    <div class="btn-group" role="group">
      <button type="button" class="btn btn-info" ng-click="imgBlowUp('+0.2')">{{ "ad::확대" | i18next }}</button>
      <button type="button" class="btn btn-success" ng-click="imgBlowUp('origin')">{{ "ad::원본" | i18next }}</button>
      <button type="button" class="btn btn-info" ng-click="imgBlowUp('-0.2')">{{ "ad::축소" | i18next }}</button>
    </div>
  </div>
</div>
```

``` coffee
$scope.imgStyle = getImageStyle()

getImageStyle = () ->
      rotate = $scope.imgRotateDegree
      ratio = $scope.imgBlowUpRatio
      return {
        "-webkit-transform": "rotate(#{rotate}deg) scale(#{ratio})",
        "-moz-transform": "rotate(#{rotate}deg) scale(#{ratio})",
        "-o-transform": "rotate(#{rotate}deg) scale(#{ratio})",
        "-ms-transform": "rotate(#{rotate}deg) scale(#{ratio})",
        "transform": "rotate(#{rotate}deg) scale(#{ratio})",
        "transform-origin": "center"
      }
```

### 템플릿으로 사용하는 경우

``` html
<input type="button" value="set color" ng-click="myStyle={color:'red'}">
<input type="button" value="set background" ng-click="myStyle={'background-color':'blue'}">
<input type="button" value="clear" ng-click="myStyle={}">
<br/>
<span ng-style="myStyle">Sample Text</span>
<pre>myStyle={{myStyle}}</pre>
```
