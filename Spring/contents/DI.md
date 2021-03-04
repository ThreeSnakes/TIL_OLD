# Spring DI(Dependency Injection)

`DI`는 클래스 사이의 의존관계를 빈 설정 정보를 바탕으로 컨테이너가 자동적으로 연결해주는것을 말한다. 오브젝트 레퍼런스를 외부(컨테이너)에서 주입 받아서, 실행 시에 동적으로 의존관계가 생성되도록 한다. 결국 컨테이너가 흐름의 주체가 되어서 애플리케이션 코드에 의존관계를 주입하는 것이다. 

## 정리
- 스프링 Ioc 컨테이너 핵심 개념
- 객체 간의 의존 관계를 외부 컨테이너가 관리
- 불필요한 의존 관계를 없애거나 줄일 수 있다.
- 각 객체를 빈(bean)으로 관리.

## Inject 방법
- Field Injection
    ``` java
    class Test {
        @Autowired
        private TestRepository testRepository;
    }
    ```
    - Spring에서만 사용된다. POJO(Plain Old java Object, 프레임워크에 종속된 객체를 사용하게 된다. )
    - 테스트시 Mock객체를 끼워넣기 어렵다. ( 생성자, Setter가 없기 때문에.)
- Constructor Injection
    ``` java
    class Test {
        private TestRepository testRepository;
        
        @Autowired
        public Test(TestRepository testRepository) {
            this.testRepository = testRepository;
        }
    }
    ```
    - 생성자를 이용하는 방법. 
    - 객체 생성시 주입객체를 받기 때문에 생성 이후에는 객체 수정 불가능, 
    - 생성자가 명시적으로 존재하기때문에 Mock 객체 주입 편리.
- Setter Injectin
    ``` java
    class Test {
        private TestRepository testRepository;
        
        @Autowired
        public void setTestRepository(TestRepository testRepository) {
            this.testRepository = testRepository;
        }
    }
    ```
    - Setter를 이용하는 방법.
    - 객체가 생성된 이후에도 주입된 객체 변경 가능. 다만 코드에 의해서 변경될 수 있으므로 사용시 주의 필요.

## 사용시 주의
- Spring에서 public static, non-final 필드는 에는 injection을 허용하지 않는다. 
    - non-final은 수정이 가능하다는 것을 의미, 결국 의존성 주입은 초기화시 한번만 진행하게 하기 위한것이다. 