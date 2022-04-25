# DIP(Dependency Inversion Principle)

NestJS에서 TypeORM을 사용하지 않고 node-mysql2로 Repository Pattern을 구현하기 위해서 자료를 조사하는데 `DIP(Dependency Inversion Principle, 의존성 역정 원칙)`개념이 자료마다 나와서 이를 정리한다. 

그러고보니 [도메인 주도 개발 시작하기 챕터2](../../Book/도메인%20주도%20개발%20시작하기/contents/2.%20아키텍처%20개요.md) 에서도 DIP를 설명하고 있는데, 그냥 읽고만 넘어가서 그런가 머리에 남지 않았는데, 다시 한번 확실히 이해하고 넘어가는게 좋아 보인다.

## 의존성 역전 원칙

객체 지향 프로그맹에서 의존성 역전 원칙은 소프트웨어 모듈을 분리하는 특정 형식을 의미한다. 즉, 객체(?,기능)을 분리할 때 사용하는 원칙이라고 생각할 수 있을것 같다. 보통 DIP를 조사하면 다음과 같은 설명을 읽을수 있다.

> 고수준 모듈은 저수준 모듈의 구현에 의존해서는 안된다. 저수준 모듈이 고수준 모듈에서 정의한 추상 타입에 의존해야 한다.

여기서 고수준 모듈은 무엇이고, 저수준 모듈은 무엇일까.?

## 고수준 모듈? 저수준 모듈?

[도메인 주도 개발 시작하기](../../Book/도메인%20주도%20개발%20시작하기/contents/2.%20아키텍처%20개요.md)에서는 고수준 모듈과 저수준 모듈을 다음처럼 설명 하였다.

> 고수준 모듈: 의미 있는 단일 기능을 제공하는 모듈, 여러개의 하위 기능이 필요하다.
> 
> 저수준 모듈: 하위 기능을 실제로 구현한 것

책에서 나온 설명을 현재 작업하고 있는 기능중에서 가장 유사한 기능으로 이야기 해보자면 정산 메일 조회 기능을 예로 들을 수 있을 것 같다.
정산 메일 조회기능은 고객의 정산 데이터를 조회하고 각 데이터를 고객의 국가별, 타입별로 부가세 및 세금을 계산한뒤 이를 추가하여 되돌려주는 기능이다.

- `고수준 모듈`: MailService, 정산 메일을 조회하는 Service, 
- `저수준 모듈`: TaxCalculator, 고객의 타입에 따라서 세금을 계산하는 함수가 존재하며 국가별로 나누어져 있다.

이를 간단하게 Class 다이어그램으로 표현하면 다음처럼 표시할 수 있을것 같다.

```text
// 일단 TaxCalculator가 하나만 존재한다고 생각하자.
[MailService] ----> [TaxCalculator]
```

이 경우 `MailService의 함수(기능)`는 `TaxCalculator 클래스(기능)`에 의존하고 있다. 즉, `고수준 모듈이 저수준 모듈에 의존하고 있는 형태`가 되는 것이다.

그러면 이 의존이 문제가 되는 경우는 무엇인지 생각해보자. [도메인 주도 개발 시작하기](../../Book/도메인%20주도%20개발%20시작하기/contents/2.%20아키텍처%20개요.md)에서는 다음과 같은 문제가 발생 할 수 있다고 하였다.

- **테스트가 힘들다.**
	- `MailService`의 함수만 테스트가 불가능하다. 저수준 모듈인 `TaxCalculator` 클래스의 메소드도 완벽하게 동작을 해야 해당 메소드 전체를 테스트 할 수 있게 되는 것이다.
- **`TaxCalculator`가 변경되는 경우 `MailService`도 같이 수정되어야 한다.**
	- 만약 다른 국가 또는 타입이 추가되거나, `TaxCalculator`가 수정된다고 생각해보자. 이 경우 MailService 자체를 다시 수정해야 하는 경우가 발생한다.

여기서 고수준 모듈이 같이 수정 되야 하는 경우를 생각해보면 다음과 같은 경우를 예로 들을 수 있을것 같다.

```ts
class MailService {
	constructor(taxService) {
		this.taxService = taxService;
	}
	
	getSettlementMail() {
		// ...
		const tax = taxService.caculateTax(income);
		// ...
	}
}

class TaxService {
	calculateTax(income) {
		// tax 계산 로직
		return tax;
	}
}

```

위 경우 새로운 국가(대만 = `TW`)가 추가 되어서 `TaxService`에 `caluclateTwTax()` 메소드를 추가하면 `MailService`에서는 국가에 따라서 로직을 결정하는 부분이 추가가 되는 것이다.

```ts
class MailService {
	constructor(taxService) {
		this.taxService = taxService;
	}
	
	getSettlementMail() {
		// ...
		let tax = ;
		switch(country) {
		case 'TW':
			tax = taxService.caculateTwTax(income);
			break;
		case 'KR':
			tax = taxService.caculateTax(income);
			break;
		}
		// ...
	}
}

class TaxService {
	calculateTax(income) {
		// tax 계산 로직
		return tax;
	}

	calculateTwTax(income) {
		// TW Tax 계산 로직
		return tax;
	}
}
```

만약 국가(또는 타입)가 늘어나면 늘어날수록 `TaxService는` 비대해지고, `MailService`는 `Country`에 따라서 분기하는 로직또한 비대해질것이다. (음..? 이건 개방폐쇄원칙 아닌가..?)

그렇다면 저수준 모듈이 고수준 모듈에 의존하도록 하려면 어떻게 해야 할까..?

## 인터페이스를 이용한다.

바로 `인터페이스`를 이용하면 된다. MailService 입장에서는 세금이 계산만 되면 되는 것이다.

```ts
class MailService {
	constructor(taxService) {
		this.taxService = taxService;
	}
	
	getSettlementMail() {
		// ...
		const tax = taxService.caculateTax(income);
		// ...
	}
}

interface TaxService {
	calculateTax(income) {}
}

class KrTaxService {
	calculateTax(income) {
		// KR Tax 계산 로직
		return tax;
	}
}

class TwTaxService {
	calculateTax(income) {
		// Tw Tax 계산 로직
		return tax;
	}
}
```

```text
// 일단 TaxCalculator가 하나만 존재한다고 생각하자.
[MailService] ----> [TaxService]
                           ^
	                |------|------|
	        [KrTaxService]   [TwTaxService]
```

`MailService`는 `TaxService`에 의존하는데, `TaxService`에는 기술에 대한 구현이 존재하지 않고 단순 인터페이스만 존재한다. 즉, `TaxService`는 고수준 모듈이 되는 것이고, `calculateTax` 자체는 이를 상속받은 개별 `KrTaxService`, `TwTaxService`에서 구현된다.

이제 `MailService`는 `TaxService`라는 인터페이스를 상속받는 모든 저수준 모듈를 다룰 수 있게 된다. 만약 새로운 국가가 추가 된다 하더라도 `TaxService`를 상속받은 구현 클래스만 추가하면 된다. 또한 테스트를 진행할 때도 `TaxService`를 상속받은 `MockClass`만 만들어주면 테스트를 진행할 수 있게 된다. 

또한 `저수준 모듈(구현 클래스 => KrTaxService, TwTaxService)`은 이제 고수준 모듈인 `TaxService`에 의존하게 된다. 즉, 의존성 방향이 바뀌어 버리게 된 것이다. 이를 의존성 역전의 법칙이라 말한다.

## 정리

의존성 역전의 법칙은 결국 코드의 확장성 및 재사용성을 높이는 방법이다. 경직된 객체를 사용하는 것보다 인터페이스를 사용하는 것이 유연한 구조를 만들게 해준다. 객체를 생성할 때 구현해야 하는 것과 인터페이스로 구현해야 하는 것을 잘 생각한뒤 작업을 진행하자.

## 참조
- https://blog.itcode.dev/posts/2021/08/17/dependency-inversion-principle
- https://steady-coding.tistory.com/388