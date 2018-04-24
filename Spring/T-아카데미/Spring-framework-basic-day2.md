# T - 아카데미 day2.
-
2016.05.17 Spring Framework Basic day_2.

1. 수업시작
  - 68p. ref 태그를 이용한 Value Injection ( `ref local`, `ref bean`, `id`, `name`의 차이)
    - 하나의 빈을 다른 빈에 주입하기 위해 두 개의 빈 설정이 필요한데 하나의 빈은 주입될 빈이고, 다른 빈은 타겟이 되는 빈에 대한 설정이다. 주입될 빈과 타겟에서 `setter`로 정의 한 빈은 서로 호환이 되기만 하면 된다.
    - 빈 정의는 같은 XML 파일 내에 있어야 하는데 만약 다른 이름의 빈을 주입하거나 다른 설정 파일에서 빈을 찾으려면 `<ref> 태그의 bean 속성을 사용해야 한다.
    - `ref`태그를 사용하여 주입하며, ref태그에는 항상 `property`나 `constructor-arg` 다음에 나와야 한다. 
    ```
    <bean id = "sample" name = "sampleName" class = "onj.ref.injection.RefInjectionExam">
      <property name = "onj">
        <ref bean = "onj"/>
      </property>
    </bean>
    ```
    
  - 70p. `bean` VS `local`
    - `<ref bean = "onjBean"/>`
      - 가장 일반적인 형태. 동일한/상위 `BeanFactory` or `ApplicationContext`내에서 자바 빈을 검색, 물론 동일한 XML 설정 파일 내부가 아니더라도 관계 없다.
      - 찾고자 하는 `onjBean`은 `id`, `name` 어느것이나 정의 되어 있으면 된다.
    - `<ref local = "onjBean"/>`
      - Spring4에서 `local`은 더이상 사용하지 않는다. Spring4 이상이라면 `<ref bean=""/>`을 사용하자.
      
  - 71p. 빈 정의시 `id`와 `name`의 차이.
    - `id` or `bean`은 하나의 XML 파일에서는 하나만 정의 가능(유일하다)
    - `id`는 오로지 하나, `name`은 여러 개 정의 가능하다. 
    - 다른 설정파일에 `name`이 같은 빈을 정의할 수 있다. 단 `id`는 불가능.
    - XML 설정 파일이 여러개라면 다음과 같이 쓴다.
    
      ```
        FileSystemXmlApplicationContext context = new FileSystemXmlApplicationContext(new String[] { "beans2.xml", "bean1.xml"});
        Foo f = (Foo) context.getBean("king");
      ```
      - 위와 같은 경우라면 `bean1.xml`의 king이 로드 된다. 나중에 로드 되므로...
      
  - 74p. `AOP` 개요
    - 전체 애플리케이션에 걸쳐 사용되어야 하는 공통적인 기능(횡단관심사)이 필요 할 수도 있다. 
    - `DI`의 목적이 Application간 결합도를 떨어뜨리는 것이 목표라면 `AOP`의 목적은 횡단관심사(Cross-Cutting Concerns, 로깅, 인증, 보안 같은 기능..)와 이에 영향을 받는 객체간에 결합도를 떨어 뜨리는 것이다. 
    - 즉 `AOP`는 횡단관심사를 모듈화하는 프로그래밍 기법으로 공통적인 기능을 `Aspect`라 불리는 한곳에서 정의 한다. 
    
  - 75p. '횡단 관심사(Cross-Cutting Concern)`
    - 여러 개의 모듈에 걸치는 시스템 전체적인 요구사항을 다룬다.
    - 예를 들자면 인증, 로깅, 트랜잭션 무결성, 오류 검사, 정책 시행등과 같은 기능을 말한다.
    
  - 75p. '핵심 관심사(Core Concern)`
    - 각 모듈에서 수행해야 하는 기본적이고 대표적인 업무 기능을 말한다. 
    
  - 75p. Spring의 AOP지원
    - 프로그래밍을 통한 AOP 구현 : `ProxyFactory 기반 AOP`
    - 선언전 AOP 설정 메커니즘
      - `ProxyFactoryBean` = 스프링 `ApplicationContext`를 XML에 선언하여 빈 정의를 기반으로 `AOP 프록시`를 생성한다.
      - `Spring aop 네임스페이스 ` = `aop 네임스페이스`를 이용하여 `Aspect` 및 `DI 요구사항`을 간단히 정의. AOP 네임스페이스도 내부적으로 `ProxyFactoryBean`을 사용한다.
      - `@Aspect Annotation` = `@AspectJ`방식의 어노테이션을 사용하여 클래스에서 AOP 설정이 가능하다. 이 방식은 `AspectJ`를 기반으로 하고 있어 `AspectJ 라이브러리`가 필요하다. 
  
  - 76p. Spring 용어
  
     | 용어 이름 | 설명 |
      | ------------------ | ---- |
      | 결합점 ( Join Point ) | `무수히 많은 Advice를 적용할 수 있는 지점.` 타겟 클래스가 구현한 인터페이스의 모든 메소드가 조인 포인트가 된다. |
      | 교차점 ( pointcut ) | `충고를 받을 메소드를 정의한 것.` 충고를 적용할 조인 포인트를 선별하는 작업 또는 그 기능을 정의한 모듈이다. 이를 정의 하지 않을시 모든 메소드에 정의가 적용된다. |
      | 충고 ( advice ) | `타겟 클래스에 제공할 횡단 관심사 기능을 구현한 것.` EX) Login.. Logging 같은 기능. |
      | 애스팩트 ( Aspect ) | `Aspect는 AOP의 기본 모듈. 충고(advice) + (교차점)pointcut` |
      | 대상 ( target ) | `충고를 받는 클래스` |
      | 위빙 ( Weaving ) | '새로운 프록시 객체를 생성하는 과정` |
      | 프록시 ( Proxy ) | `advice를 target 객체에 적용하는 생기는 객체. 대상(target) + 애스팩트(Aspect)[ = 충고(advice) + (교차점)pointcut]` |
 
  - 77p. Spring에서 `Proxy` 객체를 생성하는 2가지 방법.
    - `Target class`가 인터페이스 기반이라면 `java.lang.reflect.Proxy class`를 이용하여 생성한다.
    - `Target class`가 어떤 인터페이스를 구현하고 있지 않다면 `CGLIB`이라는 라이브러를 사용하여 대상클래스의 서브 클래스를 생성 시킨다.

  - 79p. AOP 충고(Adive)
  
      | 이름 ( Name ) | 패키지 ( Package ) | 설명 ( Description ) |
      | ------------- | ------------------ | -------------------- |
      | 주변 충고 ( around advice ) | org.aopallince.intercept.MethodInterceptor | 메소드 호출 전/후 실행 된다. |
      | 사전 충고 ( before advice ) | org.springframework.aop.MethodBeforeAdvice | 메소드 실행전에 전치리 기능을 한다. |
      | 사후 충고 ( after returning advice ) | org.springframework.aop.AfterReturningAdvice | 대상 메소드가 리턴한 후에 호출된다. (정상 종료 됬을 경우 ) |
      | 예외 충고 ( throws advice ) | org.springframework.aop.ThrowsAdvice |  대상 메소드가 예외를 던질 때 호출 된다. |
      | 사후 충고 ( finally after advice ) | org.aopallince.intercept.AfterAdvice |  메소드의 실행 결과와 관계없이 실행 즉 오류 나서 예외를 던지더라도 실행 된다. | 

  - 85p. `포인트컷(Pointcut)`
    - `Pointcut`은 모든 `Join Point`중 `Advice`가 `Weaving`되어야 할 `Join Point`의 집합을 정리한 것이다.
    - `Pointcut`은 특정한 클래스의 특정한 메소드가 특정한 기준과 일치하는지를 판단하고 맞다면 `advice`가 적용된다.
    - Spring은 충고를 받으려고 하는 클래스와 메소드의 관점에서 `pointcut`을 정의하며 `advice`는 클래스의 이름과 메소드의 시그니처(Method 이름, 매개변수, 타입 등)와 같은 특징에 기초하여 대상클래스와 메소드에 엮인다.
  
  - 86p. `ProxyFactoryBean`을 이용한 선언적 AOP구현
    - `ProxyFactoryBean`클래스는 빈의 타겟을 지정할 수 있게 해주는 `FactoryBean`의 구현체로 AOP 프록시에 적용할 빈의 `어드바이스`와 `어드바이저(=Aspect)`를 제공한다.
    - `traget` 과 `interceptorNames(advice or advisor)`를 넣어 준다. 
    - 대상 클래스가 인터페이스 기반이고 `proxyTargetClass` 속성이 `true`라면 `GCLIB`기반의 프록시가 생성되고 `false`라면 `JDK Proxy` 기반으로 프록시가 생성된다.

  - 99p. `@AspectJ Annotation`을 이용한 AOP
    - Spring AOP와 JDK 1.5 이상인 경우 어노테이션을 이용하여 `advice`를 선언할수 있다.
    - `target method`에 `advice`를 적용할 때는 `AspectJ`의 weaving 메커니즘이 아닌 자체 프록시 메터니즘을 이용한다.
    - `@AspectJ`를 사용하기 위해서 XML설정 파일에 `<aop:aspectj-autoproxy/>` 태그를 설정에 추가해야 하며 클래스에 `@Aspect` 어노테이션을 추가하여 `Aspect`를 생성해야 한다. 
   
  - 100p. `Aspect`선언
      1. 자바 설정을 이용하여 `AspectJ`를 사용하는 방법
  
    ```
    @Configuration
    @EnableAspectJAutoProxy
    public class AppConfig{}
    ```
  
      2. XML 설정을 이용하여 `AspectJ`를 사용하는 방법

    ```
    <aop:aspectj-autoproxy>
    ```

  - 101p. `Advice 선언`
    1. `사전 충고(@Before)`
      - `@Before` 어노테이션을 사용하며 `pointcut` 메소드가 실행되기 전에 `advice`가 적용된다.
        ```
        @Aspect
        public class BeforeExample {
          
          @Before("x.y.MyClass.dataAccessOperation()")
          public void doAccessCheck1() {
          ...
          }
          
          @Before("execution(* x.y.MyClass.*(..))")
          public void doAccessCheck2() {
          ...
          }
        ```

    1.  `사후 충고(@AfterReturning)`
      - `@AfterReturnning` 어노테이션을 사용하며 `pointcut` 메소드가 리턴(정상종료)된 후 `advice`가 적용된다.
        ```
        @Aspect
        public class AfterReturningExample {
        
          @AfterReturning("x.y.MyClass.dataAccessOperation()")
          public void doAccessCheck1() {
          ...
          }
        
          @AfterReturning(
            pointcut = "x.y.MyClass.dataAccessOperation()",
            returning = "retVal")
          public void doAccessCheck2(Object retVal) {
          ...
          }
        }
        ```

    1. `예외 충고(@AfterThrowing)`
      - `@AfterThrowing` 어노테이션을 사용하며 `pointcut` 메소드에서 예외가 발생할 때 `advice`가 적용된다.
        ```
        @Aspect
        public class AfterThrowingExample {
        
          @AfterThrowing("x.y.MyClass.dataAccessOperation()")
          public void doRecoveryActions1() {
          ...
          }
          
          @AfterThrowing(
            pointcut = "x.y.MyClass.dataAccessOperation()",
            throwing = "ex")
          public void doRecoveryActoins2(DataAccessException ex) {
          ...
          }
        }
        ```

    1. `사후 충고(@After)`
      - `@After` 어노테이션을 사용하며 `pointcut` 메소드가 실행 된 후 (정상 종료 여부와 상관없이 ) `advice`가 적용된다.
      
        ```
        @Aspect
        public class AfterExample {
          @After("x.y.MyClass.dataAccessOperation()")
          public void doReleaseLock() {
          ...
          }
        }
        ```
  
    1. `주변충고`
      - `@Around` 어노테이션을 사용하며 `pointcut` 메소드가 실행 되기 전, 리턴 된 후에 `advice`가 적용된다.
      - `advice` 메소드의 첫번째 파라미터는 `ProceedingJoinPoint`가 되어야 한다. `proceed()` 메소드를 통해 `target` 클래스의 원래 메소드를 호출하고, `proceed()` 메소드를 호출하면서 `Object[]` 형태로 파라미터를 전달할 수도 있다. `proceed()` 메소드는 기술 안할수도 있고, 한번, 여러 번 호출 할 수도 있으므로 원래 메소드에 대한 여러 형태의 제어가 가능하다. 

        ```
        @Aspect
        public class AroundExample {
          @Around("x.y.MyClass.businessService()")
          public Object doBasicProfiling(ProceeingJoinPoint pjp) throws Throwable {
          object retVal = pjp.proceed();
          return retVal;
          }
        }
        ```
  
  - 106p. `@Pointcut` 선언
    - `@Pointcut` 어노테이션을 사용한다.
  
      ```
      @Pointcut("execution(* onj.aop.*.*(..))")
      private void mypointcut() {}
      ```

  - 113p. 스프링 선언적 AOP에 대한 고려사항(@AspectJ vs XML)
    - 스프링 애플리케이션이 XML 기반이라면 aop 네임스페이스를 이용하는 것이 적절하다.  이렇게 하면 `DI`, `AOP` 설정 방식을 일관되게 유지할 수 있기 때문이다.
    - 애플리케이션이 어노테이션 기반이라면 `@AspectJ` 어노테이션을 사용한다. `@AspectJ` 어노테이션을 사용 하는 경우 모듈 안에 `Aspect` 관련 정보를 캡슐화 할 수 있기 때문에 유지보수가 용이하다. 

  - 114p. `aop 네임스페이스`와 `@AspectJ` 어노테이션의 차이
    - `pointcut` 구문이 조금 다르다.
    - `aop 네임스페이스`에서는 `싱글톤` 방식의 Aspect instance화 모델만 지원.
    - `@Aspect` 어노테이션 방식에서는 두 개의 `pointcut` 정의를 `사전충고`에서 조합할 수 있지만 `aop 네임스페이스` 에서는 조건을 조합한 `pointcut`을 새로 생성해야 한다.
  
  - 114p. 기존 JAVA JDBC 와 Spring JDBC의 비교
    - Spring의 DAO 프레임워크에서는 Connection 객체를 DataSource를 통해서 취득하며 Connection객체를 프로그래머가 직접 다루지 않는다.
    - Spring은 데이터 접근 프로세스에 있어서 고정된 부분(템플릿)과 가변적 부분을 명확히 구분한다.
    - 프로그래머는 콜백 부분(가변적 부분)만 구현하면 된다. => 로직에만 신경써라.
  
  - 114p. Spring JDBC
    - [MariaDB](https://downloads.mariadb.org/) 접속. 
    - 10.1.14 Stable Version, mariadb-10.1.14-winx64.msi 다운로드 받음.
    - 설치를 하다보면 root 비밀번호 셋팅하는 화면 밑에 `UTF8` 을 기본으로 셋팅하는 라디오 버튼이 있다.
    - [HeidiSQL](http://www.heidisql.com/download.php?download=installer) 접속.
    - HeidiSQL 9.3 설치. 계속 Next만 눌러주자. DB관리해주는 툴이다.
    - 포트랑 userId 확인하고 MaiaDB 설치때 입력한 비밀번호 입력하고 접속.
    - 다 설치 후에 HeidiSQL 실행후 DBTable 과 데이터 입력해주자. 
      ```
      create table emp (
      empno int(4) not null auto_increment,
      ename varchar(50),
      sal int(4),
      primary key(empno)
      )ENGINE=INNODB;

      insert into emp(ename,sal) values ('1길동',1000);
      insert into emp(ename,sal) values ('2길동',2000);
      insert into emp(ename,sal) values ('3길동',3000);
      ```
    - JDBC 를 이용한 project 생성시 `pom.xml`에 다음 `dependency`를 입력해 준다.
    
      ```
      <dependency>
			<groupId>org.springframework</groupId>
			<artifactId>spring-jdbc</artifactId>
			<version>${spring-framework.version}</version>
		  </dependency>
		  <dependency>
			<groupId>mysql</groupId>
			<artifactId>mysql-connector-java</artifactId>
			<version>5.1.38</version>
			<scope>runtime</scope>
		  </dependency>
		  <dependency>
			<groupId>commons-dbcp</groupId>
			<artifactId>commons-dbcp</artifactId>
			<version>1.4</version>
		  </dependency>
		```

