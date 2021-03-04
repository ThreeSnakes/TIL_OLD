# T - 아카데미 day3.
-
2016.05.19 Spring Framework Basic day_3.

1. Lombok 설치.
  - [Lombok](https://projectlombok.org/download.html) 접속.
  - lombok.jar 1.16.8. 다운로드 한다.
  - 다운로드 한 파일을 더블클릭한후 STS의 경로를 잡아줘야 한다. STS 실행파일로 경로를 잡아 준다.
  - 그다음 lombok을 사용할 때 `pom.xml`에 다음 `dependency`를 추가해준다.

      ```
      <dependency>
       <groupId>org.projectlombok</groupId>
       <artifactId>lombok</artifactId>
       <version>1.16.6</version>
      </dependency>
		 ```

  - `@Getter`, `@Setter`, `@ToString`, `@EqualsAndHashCode`, `@Log`, `@Data`,`@AllArgsConstructor`를 사용할 수 있게 된다. 
  - [lombok 설명 블로그](https://blogs.idincu.com/dev/?p=17) 가보자.
  
2. `Spring WEB MVC`
	- `Spring Model-View-Controller Framework`는 디스패처 서블릿이 `Front Controller`로서 요청을 받고 이 요청을 controller에 mapping 하여 필요한 메소드를 실행시키고, view 이름을 해석하고 파일을 업로드 하는 등의 일을 처리한다.
	- 기본적인 핸들러는 `@Controller`, `@RequestMapping` 어노테이션이며 `@RequestMapping`을 통해 유연한 요청처리가 가능하도록 하며, `@Controller` 메커님즘은 `RESTful Web Site`를 구축 가능하도록 해준다.
	- Spring에서 미리 만들어 놓은 controller를 사용해도 되지만 기본적으로 아무 Object라도 Controller로 Mapping 하는 것이 가장 좋다.
		1. `DispacherServlet`
			- `HttpServlet`을 상속받은 서블릿이며 웹 응용프로그램의 `web.xml`에서 정의한다.
			- 사용장의 요청을 맨 앞단에서 받아 `Handler Mapping` 빈에게 `URL`과 요청정보를 넘겨 어떤 사용자 Controller가 요청을 처리할 지 받고 해당 사용자 Controller로 요청을 위임한다.
			- 사용자 Controller로부터 Model과 View를 리턴받아 `ViewResolver`를 통해 view 이름을 해석하여 사용자의 요청을 처리할 view로 요청을 `forward`한다. 이때 Model data를 view에게 넘겨주게 되어 view가 최종적인 응답을 만들어 클라이언트 브라우저에게 보내게 된다. 
			- 세개의 파라미터를 가진다.
				1. `contextClass`
				2. `contextConfigLocation`
				3. `namespace`
		2. `ContextLoaderListener`
			- `DispacherServlet` 설정 파일에는 Spring MVC 컴포넌트와 관련된 `<bean>`정의를 포함한다.
			- 서비스 계층과 영속성 계층에 속하는 빈 역시 `DispatcherServlet`의 설정파일에 포함될 수 있지만 별도의 설정파일을 두는 것이 좋다.
			- 설정 파일들이 모두 로드 되도록 하기 위해 `ContextLoader`를 설정하며 `Contextloader`는 `DispacherServlet`이 로드하는 것 이외의 `Context`설정 파일을 로드한다.

		3. `@Controller`, `@RequestMapping`을 이용한 컨트롤러 mapping.
			1. `@Controller`를 이용한 Controller 설정.
				- `@Controller` 어노테이션은 Spring Controller가 될 수 있는 클래스를 지칭하낟.
				- `DispacherServlet`은 사용자의 요청에 대해 `@Controller` 어노테이션이 있는 controller를 스캔하며 controller 클래스의 `@RequestMapping`어노테이션에 있는 요청을 Controller의 메소드와 mapping한다.
				- `@Controller`를 기술한 클래스가 `DispacherServlet`에 의해 자동 인식되게 하기 위해서는 설정 파일에 `component scanning`을 추가 해야 한다. 
				````
				<context:componenet-scan base-package="x.y.z.controller"/>
				````

			2. `RequestMapping`을 이용한 컨트롤러 메소드 mapping.
				- `@RequestMapping` 어노테이션은 사용자가 지정한 URL로 요청을 보내는 경우 실행될 메소드를 정의할 때 사용한다.
				- 클래스 레벨 `@RequestMapping`은 해당 하는 요청에 대응할 controller라는 것을 의미하고 메소드 레벨에 정의되는 경우에는 더 범위를 줄여 기술한 `HTTP 메소드(GET or POST)`에 대해 처리할 메소드를 기술한다든지 또는 특별한 파라미터 조건에 의해 실행될 메소드를 정의 할 떄 사용한다.
				- `@RequestMapping("/hello")` 라고 한다면 /hello/*, /hello.html, /hello.do 등이 포함된다. 

		4. Spring Web MVC 기본 흐름.  
			1. WEB Browser(클라이언트)의 요청이 Front Controller인 `DispatcherServlet`에 전달된다.
			2. `DispatcherServlet`은 `handlerMapping`빈 에게 의뢰하여 사용자 controller가 어느것이닞 확인한다.
			3. `DispatcherServelt`은 `HandlerAdapter`를 통해 선택된 controller를 호출한다. `@RequestMapping`, `Controller`로 정의된 어노테이션기반 컨트롤러는 `RequestMappingHandlerAdapter`를 통해 호출한다.
			4. 사용자 컨트롤러의 비즈니스 로직 메소드를 실행하고 메서드는 처리 결과 정보를 담은 `ModelAndView`객체를 `DispacherServlet`에 리턴한다. 기본적으로 `InternalResourceViewResolver`가 등록되어 접두어, 접미어로 뷰이름을 해석한다.
			5. `DispacherServlet`은 전달받은 뷰(주로JSP) 이름에 해당되는 프로그램을 찾아서 실행시키면서 데이터를 담은 Model 객체를 전달해 준다.
			6. 뷰의 응답(HTML)을 `DispacherSerlvet`에 전달하고, 이를 클라이언트로 전송한다.
		
		5. 
