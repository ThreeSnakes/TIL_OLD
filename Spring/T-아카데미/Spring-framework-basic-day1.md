# T - 아카데미 day1.
-
2016.05.17 Spring Framework Basic day_1.

<Strong>1. jdk 설치.</Strong>
  - 실습 PC에 [jdk](http://www.oracle.com/) 설치한다. 그냥 기본 경로에 설치 한다. 
  - 환경 변수 설정. 변수 이름 : `JAVA_HOME` 경로 : `jdk 설치 경로.` 변수 이름 : `Path` 경로 : 맨뒤에 `;%JAVA_HOME%\bin 입력`

<Strong>2. Spring STS 설치.</Strong>
  - [Spring](https://spring.io) 설치한다. windows 64bit 4.5.2 version 설치.
  - C:\dev-ecommerce 폴더 생성후. 이곳에 압축 해제.
  - workspace 폴더 생성후 작업 폴더로 지정.
  - `General -> workspace -> textfile encording` 을 `utf-8`로 설정. 한글로 인하여 깨질 수 있기 때문에 설정. 
  - `grep-console` 설치.. maket place 에서 grep 검색.

<Strong>3. 수업 시작.</Strong>
  - 6p. Spring Boot로 시작 하려면 `new -> New Spring Starter Project` 로 눌러서 실행한다.
  - 7p. `Packaging`은 배포할 때 `.jar` 로 할것이냐 `.war`로 할 것이냐를 결정한다.
  - 7p. `Group`은 일반적으로 도메인을 거꾸로 작성하는 것이 관례이다. 
  - 8p. 설정 하고 next 클릭하면 Spring Boot가 프로젝트를 생성해 준다. 
  - 10p. `Project 오른쪽 버튼 클릭 -> Run as 에서 Spring Boot App 클릭 후 localhost:8080으로 접속`해 보자. 
  - 10p. `@Controller` => Controller 역활을 한다는 어노테이션.
  - 10p. `@RequestMapping` => 실제 URL 주소를 맵핑하는 어노테이션.
  - 10p. `@ResponseBody` => Body에 뿌린다는 어노테이션.
  - 10p. `@RestController` => `@Controller` + `@ResponseBody` 역활을 한다고 생각 하면된다. 이경우 `@ResponseBody`, `@Controller`를 쓸 필요가 없다.
  - 11p. `Run As -> Maven Install` 클릭 한다. 이게 가끔 Error를 내 뱉는데 계속 돌리다 보면 인식한다..?
  - 20p. `@Order` => 실행 순서를 부여하는 어노테이션.
  - 20p. Spring Boot를 시작할 때 `Command Line arguments`를 주거나, 어떤 코드를 실행하려면 `CommandLineRunner 인터페이스의 run(String...args)`를 구현하면 된다. `(String...args)`는 가변인자이다.
  - 21p. STS에서 실제 인자를 줄수 있다. `Run Configuration -> argruments 탭 클립 -> Program arguments` 에 인자 넣어 주면 된다. 
  - 21p. 설정 파일 같은 경우에는 `src/main/resources/` 에 넣는다. 
  - 21p. `@PropertySource("파일명")` => Property를 읽을 올 수 있다. 
  - 22p. [mvnRepository.com](http://www.mvnrepository.com/) => @named 와 같은 경우 기본 어노테이션이 아니다. 이럴 경우 위 홈페이지에서 접속해서 named를 검색 해본 후 pom.xml에 검색 내용을 dependency에 붙여 넣어주면 동작 시킬 수 있다. 
  - 24p. `Spring IoC(Inversion of Control)` => *한 객체가 협업해야 하는 다른 객체의 참조를 취득하는 방법에 대한 제어의 역행이라는 의미*를 갖는다.
  - 24p. 일반적으로 `IoC`는 `의존성 주입(DI)`, `의존성 룩업(DL)`로 나뉜다. 일반적으로 `DI`를 이야기 할때는 `IOC`를 가리키지만 `IOC`를 이야기 할 떄는 `DI`만을 가리키는 것이 아니다. 
  - 24p. `DI`에는 `세터 주입`,`생성자 주입`, `메소드 주입` 이 있다. `DL`에는 `의존성풀`과 `컨텐스트화된 의존성 룩업` 이 있다.
  - `DL(Dependency Lookup)`
    - 모든 `IOC 컨테이너`는 각 컨테이너에서 관리해야 하는 객체들을 관리하기 위한 별도의 저장소를 가진다.
    - `의존성 풀(Dependency Pull)`
      - Ioc 타입중 가장 익숙한 타입으로 필요할 때 마다 레지스트리에서 의존성을 가지고 온다.
    - `컨텍스트화된 의존성 룩업(Contextualized Dependency Lookup)`
      - 컨테이너는 내부 `WAS(톰캣, JBOSS 등)`나 스프링 프레임워크에서 제공한다.
  - `DI(Dependency Injection)`
    -각 계층 사이, 각 class 사이에 필요로 하는 의존관계가 있다면 이를 스프링 컨테이너가 자동적으로 연결시켜 주는 것으로 각 class 사이의 의존관계를 `Bean(java의 객체를 뜻함)` 설정 정보 또는 어노테이션을 바탕으로 컨테이너가 자동적으로 연결해주는 것이다.
      - `Setter Injection`
        - class 사이의 의존관계를 연결시키기 위해 `setter 메소드`를 이용하는 방법.
      - `Constructor Injection`
        - class 사이의 의존관계를 연결 시키기 위해 `생성자`를 이용하는 방법.
      - `Method Injection`
        - 위 두가지 Injection의 한계점을 극복하기 위하여 지원하고 있는 `DI`의 한 종류이다.
        - 어떤 메소드의 실행을 다른 메소드로 대체
        - 메소드의 리턴형을 추상클래스로 지정한 후 필요에 따라 추상클래스를 상속받은 임의의 객체를 리턴 하도록 구성할 수 있다.
  - 26p. `BeanFactory`
    - 스프링의 의존성 주입의 핵심 인터페이스.
    - Bean의 생성과 소멸 담당(의존성과 생명주기 및 관리 담당), 객체를 관리하는 고급 설정 기법 제공한다.
    - `BeanFactory`를 프로그래밍적으로 설정할 수 있지만 대부분 설정 파일을 통해 외부에서 설정 하는 방식을 사용한다.
    - `PropertiesBeanDefinitionReader`는 프로퍼티 파일에서 `Bean`정의를 읽고 `XmlBeanDefinition Reader`는 `XML파일`에서 `Bean`정의를 읽는다. 
  - 27p. `ApplicationContext`
    - `BeanFactory`의 모든 기능 제공(`BeanFactory` 인터페이스를 상속받는다.)
    - `ApplicationContext`설정 시 자바 어노테이션을 지원.
  - 28p. `Lazy-Loading`, `Pre-Loading`
    - 스프링에서 자바 빈을 로딩하는 방법은 `BeanFactory를 이용하는 방법`과 `ApplicationContext를 이용하는 방법`이 있다.
      - `Lazy-Loading`
        - 메소드나 클래스가 요청을 받는 시점에 자바빈의 인스턴스를 만들고 로딩하는 방법이다.
      - `Pre-Loading`
        - 모든 빈들이 `ApplicationContext 컨테이너`에 의해 설정파일이 로드 될 때 인스턴스로 만들어지고 로드 된다.
        - 스프링 설정파일에 여러개의 자바빈이 정의 되어있다고 모두 자주 사용 되는 것은 아닐것이다. 이러한 경우라면 요청이 있을때 자바빈을 인스턴스로 만드는 것이 좋을 것이다. 물론 모두 자주 사용된다면 한번에 로드 하는 것도 좋은 방법이다. 
  - 32p. `Project에서 마우스 우측버튼 -> new -> other -> Spring -> Spring Bean Configuration File`을 클릭하면 xml 파일을 쉽게 만들수 있다.
  - 38p. `Setter 주입.` -> `maker`라는 객체(`property`)에 `hyundailMaker`를 참조(`ref`)해서 넣는다는 것이다.
  - 39p. `@Component` -> DTO와 같은 컴포넌트 클래스임을 의미. `@Named`와 동일
  - 41p. `@Service` -> `@Named`와 동일. 서비스 계층의 클래스임을 의미한다.
  - 42p. `@Autowired` -> Type이 어노테이션 밑에 선언 된거 같은 것을 찾아 자동 주입, 여러 개인 경우 `@Qualifier`로 지정해서 넣어준다.
  - 43p. `<context:annotation-config/>` 는 4가지 타입의 `BeanPostProcessors`를 등록하여 어노테이션이 사용가능 하도록 한다.
    - `CommonAnnotationBeanPostProcessor`      : `@PostConstruct`, `@PreDestroy`, `@Resource`
    - `AutowiredAnnotationBeanPostProcessor`   : `@Autowired`, `@Value`, `@Injec`, `@Qualifier`, etc...
    - `RequiredAnoontationBeanPostProcessor`   : `@Required`
    - `PersistenceAnnotationBeanPostProcessor` : `@PersistenceUnit`, `@PersistenceContext`
  - 43p. `<context:component-scan/>` 은 `<context:annotation-config/>`를 상속 받았다고 보면 된다.
    - 즉 `<context:component-scan/>` = `<context:annotation-config/> + Bean Registration`이다.
  - 43p. `ioc4.xml`을 만들때 `bean`과 `context`를 포함해서 만든다. 교재에는 `context`가 빠져 있다.
  - 45p. `DI`와 관련된 어노테이션
    - 스프링 컨테이너는 base-package의 클래스를 검색해서 자동으로 자바 빈으로 등록하는데 이에 해당하는 것이 `@Component`, `@Repository`, `@Service`, `@Controller`, `@RestController`이다.
    - 자동스캔을 위해서는 `<context:componenet-scan base-package='onj.edu.spring'/>` 과 같이 base-package를 기술하며, 패키지가 여럿인 경우 콤마로 구분하여 기술한다.
      - `@Component`
        - 일반적인 용도의 컴포넌트들을 표시하는 기본 스테레오 타입, `멤버변수`와 `getter`, `setter`만 가지고 있는 DTO 같은 컴포넌트를 일컫는다.
      - `@Repository`
        - 퍼시스턴스 레이어(영속성 계층)의 DAO 컴포넌트
      - `@Service`
        - 서비스 레이어의 서비스 컴포넌트
      - `@Controller`
        -프리젠테이션 레이어의 컨트롤러 컴포넌트
  - 45p. `Context Configuration Annotations`
    - `@Scope`
      - 일반적으로 `@Component`, `@Service`, `@Repository` 등으로 자동 스캐닝한 자바빈은 싱글톤 형태로 하나만 생성하는데 이를 변경 하려면 `@Scope` 어노테이션을 사용하면 된다. 즉 빈의 범위를 설정한다.
        - `singleton` : IoC 컨테이너당 하나의 빈을 리턴
        - `prototype` : 요구가 있을 때 마다 새로운 빈을 만들어 리턴
        - `request` : HTTP request 객체당 하나의 빈을 리턴
        - `session` : HTTP session당 하나의 빈을 리턴
        - `globalSession` : 전체 모든 세션에 대해 하나의 빈을 리턴
        ```
        @Component
        @Scope("prototype")
        class Ojc {
        .......
      }

        <bean id="ojc" class = "oraclejava.edu.Ojc" scope="prototype"/>
        ```
    - `@Autowired`
      - Spring Framework에 종속적.
      - 빈의 id, name 으로 아무거나 맞으면 적용(Type Driven Injection)
      - 여러개의 빈이 검색 될 경우 `@Qualifier(name = "XXX")` 어노테이션으로 구분한다.
      - 기본적으로 `@Autowired`된 속성은 모두 빈이 주입되어야 한다(없으면 에러 발생). 하지만 `(required=false)`로 하면 에러 발생 안한다.
    - `@Resource`
      - Spring Framework에 비종속적으로 권장하는 방식( 일반적으로 비종속적인 방식을 추천한다.)
      - 빈의 name으로 주입될 빈을 찾는다. 멤버변수, setter 메소드에 적용 가능하다.
      - 사용하기 위해서는 `jsr250-api.jar`가 클래스패스에 추가되어야 한다.
    - `@Inject`
      - 특정 Framework에 종속되지 않은 어플리케이션을 구성하기 위해서는 @Inject를 사용하는 것을 권장.
      - JSR.330 라이브러리인 javax.inject-x.x.x.jar 파일이 추가되어야 한다.
      - 멤버변수, setter 메소드, 생성자, 일반 메소드에 적용 가능.
    - `@Required`
      - Setter 메소드위에 기술하여 필수 프로퍼티를 설정하는 용도로 사용된다. 
    - `@Named`
      - JSR.330의 어노테이션이며 Spring의 `@Component`, `@Qualifier`와 동일하다. 
    - `@Order`
      - Spring4에서 새로 소개된 `@Order` 어노테이션은 같은 타입의 빈이 컬렉션(List등) Autowired 될 때 그 순서를 지정한다. 
      - 낮은 순서가 우선순위가 높다.
      - *주의* Spring version을 꼭 4 이상으로 해야만 한다. 
