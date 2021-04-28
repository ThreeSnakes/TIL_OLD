# Express

## Response

### res.location
```js
res.location(url);
res.statusCode = 201;
res.json({
	message: 'OK'
});
```
- 응답의 헤더만 설정한다.
- 메세지를 같이 보낼 수 있다.
- 이때 location을 보낼때는 꼭 statusCode가 201 아니면 3XX(리다이렉션)일때 의미가 있다. 다른 값의 코드를 보내면 이동되지 않는다.
### res.redirect
```js
res.redirect(statusCode, url);
```
- 응답을 리다이렉트 시킨다.
- statusCode를 변경해서 보낼수 있다. 201이나 기타 등등의 코드로
- url로 보낸 주소페이지로 이동시키는 기능인데, 이때 message등을 전송 할 수 없다. 말 그대로 이동만 시킨다.