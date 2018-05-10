### Hibernate 에서 @Query에서 한글 사용시 못찾는 경우
controller에서 QueryString을 한글로 받아서 이를 MySQL에서 찾아야 하는데 이상하게 숫자나 영문 검색시 잘 검색이 되지만 한글만 입력되면 제대로 값이 parsing이 안되는지 검색을 못하고 있다. ㅠㅠ 한참을 찾아도 못찾다가 방법을 찾았다.

application.yml 에서 datasource 부분에 url을 입력하는데 utf와 unicode를 쓴다고 명시적으로 설정해줘야 한다. 
``` yml
spring:
  profiles: dev
  datasource:
    url: jdbc:mysql://aa.com/Release?useUnicode=yes&characterEncoding=UTF-8
    username: aa
    password: aa
    driver-class-name: com.mysql.jdbc.Driver
```
위에 코드에서 url 부분 끝에 `?useUnicode=yes&characterEncoding=UTF-8` 부분을 추가해줘야 한다. 해당 코드를 추가해주면 한글도 잘 넘어간다. 

**참조**
- [JPA utf-8 characters not persisted](https://stackoverflow.com/questions/18163328/jpa-utf-8-characters-not-persisted)

