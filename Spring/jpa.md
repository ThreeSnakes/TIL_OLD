### JPA (Java Persistence API)
#### 컨셉
- Database에 존재하는 모델을 자바의 한 객체로 Mapping 하는것이 목적
- 코드상에 존재하는 객체는 마찬가지로 DB에도 존재해야 한다.

#### 테이블 설정
- 테이블의 이름과 동일한 모델 클래스를 생성
    - `@Entity(name = "")` 어노테이션 사용, 해당 어노테이션을 설정 해줘야 스프링에서 해당 클래스를 참조 한다.
    - `@Table(name = "")` 어노테이션은 테이블 명과 클래스 명이 다를 경우 사용한다.
- 테이블의 모든 컬럼에 대응하는 필드를 만들 필요는 없다. 필요한 컬럼만 만들면 된다.
    - DB의 컬럼 이름이 새로 만든 클래스의 변수명과 다를 경우 `@Colmun(name = "")` 어노테이션을 만들어야 한다. 
    - 크기가 큰 컬럼(EX- `CLOB`, `BLOB`)과 같은 탑입의 컬럼은 해당 타입 여부에 따라서 `@Clob/@Blob` 어노테이션 설정이 필요하다.
- `Serialize/Deserialize` 할 수 있어야 하기 때문에 `Getter/Setter` 를 만들어 줘야 한다. 
    - `lombok` 라이브러리를 사용하면 `@Getter/@Setter` 어노테이션 사용

#### CRUD
- 실제 동작은 `Repository`를 통해서 이루어진다. `Interface`를 생성해서 `Repository`를 상속한다.
    ``` java
    public interface VideoRepository extends Repository<Video, Long> {
    Video getVideosById(Long id);
    }
    ```
- `CrudRepository`, `Repository` 등 여러가지 레파지토리가 있는데, 여기서 필요 한 것을 사용 하면된다. 
- `CrudRepository`를 사용하면 기본 `CRUD`는 사용 할 수 있다. `Repository`는 `CrudRepository`의 손자뻘로써, 필요할때 사용한다.