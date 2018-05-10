### SpringBoot JPA 테이블 대소문자 구분.

`SpringBoot`에서 `MySQL`에 연결하고 사용하고 있는데 테이블명이 대소문자 둘다 사용하고 있는데, `Hibernate`에서 대문자로 입력된 테이블명을 소문자로 자동으로 바꾸고 있다. 그러다 보니 테이블을 못찾아 에러가 발생하고 있다. 아래처럼 DB에 저장되어 있는 테이블명은 `Videos`인데 `videos`로 검색을해서 아래처럼 에러가 발생한다. 
``` bash
018-05-10 15:35:41.807  WARN 22360 --- [nio-8080-exec-1] o.h.engine.jdbc.spi.SqlExceptionHelper   : SQL Error: 1146, SQLState: 42S02
2018-05-10 15:35:41.807 ERROR 22360 --- [nio-8080-exec-1] o.h.engine.jdbc.spi.SqlExceptionHelper   : Table 'xxxx.videos' doesn't exist
2018-05-10 15:35:41.870 ERROR 22360 --- [nio-8080-exec-1] o.a.c.c.C.[.[.[/].[dispatcherServlet]    : Servlet.service() for servlet [dispatcherServlet] in context with path [] threw exception [Request processing failed; nested exception is org.springframework.dao.InvalidDataAccessResourceUsageException: could not extract ResultSet; SQL [n/a]; nested exception is org.hibernate.exception.SQLGrammarException: could not extract ResultSet] with root cause

com.mysql.jdbc.exceptions.jdbc4.MySQLSyntaxErrorException: Table 'xxxx.videos' doesn't exist
	at sun.reflect.NativeConstructorAccessorImpl.newInstance0(Native Method) ~[na:1.8.0_171]
	at sun.reflect.NativeConstructorAccessorImpl.newInstance(NativeConstructorAccessorImpl.java:62) ~[na:1.8.0_171]
	at sun.reflect.DelegatingConstructorAccessorImpl.newInstance(DelegatingConstructorAccessorImpl.java:45) ~[na:1.8.0_171]
	at java.lang.reflect.Constructor.newInstance(Constructor.java:423) ~[na:1.8.0_171]
	at com.mysql.jdbc.Util.handleNewInstance(Util.java:425) ~[mysql-connector-java-5.1.44.jar:5.1.44]
	... 생략
```
이를 수정 하기 위해서 `application.yml`에 대소문자를 구분하도록 설정을 추가해줘야 한다. 
``` yml
spring:
  jpa:
    hibernate:
      naming:
        physical-strategy: org.hibernate.boot.model.naming.PhysicalNamingStrategyStandardImpl
```
이러면 테이블명에 대소문자를 구분할 수 있게 된다. 

**참조**
- [Spring boot JPA insert in TABLE with uppercase name with Hibernate](https://stackoverflow.com/questions/28571848/spring-boot-jpa-insert-in-table-with-uppercase-name-with-hibernate)

