# typedi

**typedi**는 JavaScript, TypeScript에서 의존성 주입을 관리해주는 라이브러리이다.

일단 **의존성**이 무엇인지 알아보자. 의존성이란 함수가 자신의 기능을 수행하는데, **자신이 가지고 있는 상태(데이터)만으로는 해결이 불가능하고 다른 함수 또는 클래스가 필요할 경우 이를 의존성이 갖는다 말할 수 있다.**

```js
// 법인 세율이 저장되어 있는 Class
class BizTaxRate {
  #vatRate;

  constructor() {
    this.#vatRate = 0.1;
  }
  
  vatRate() {
    return this.#vatRate;
  }
}

// 세금을 계산하는 Class
class Tax {
  #income;
  #taxRate;

  constructor(income) {
    this.#income = income;
    this.#taxRate = new BizTaxRate();
  }

  calcTax() {
    const vatTaxRate = this.#taxRate.vatRate();
    return this.#income * vatTaxRate;    
  }
}
const tax = new Tax(10000);
console.log(tax.calcTax()); // 1000
```

역시서 `Tax Class`의 경우 `BizTaxRate Class`에 의존하고 있다. 왜냐하면, `calcTax()` 함수의 경우 TaxRate 인스턴스의 값이 없으면 계산이 되지 않기 때문이다. 이런 경우를 의존성을 갖는다 라고 말할 수 있는 것이다. 

그런데 여기서 `BizTaxRate`를 다른 객체로 변경하고 싶으면 Tax Class를 수정해야 한다. 생성자 함수 안에서 의존성을 갖는 객체를 생성하고 있기 때문에 Tax Class는 내부에 있는 코드를 수정하기 전까지는 다른 Class의 인스턴스를 받을 수 있는 방법이 없는 것이다. 즉 의존성을 갖는 객체를 코드 안에서 생성하고 있기 때문에 유연성이 떨어지는 것이다. 이를 해결 하기 가장 좋은 방법은 해당 의존성을 외부에서 받는 것이다.

```js
class Tax {
  #income;
  #taxRate;

  constructor(income, taxRate) {
    this.#income = income;
    this.#taxRate = taxRate;
  }

  calcTax() {
    const vatTaxRate = this.#taxRate.vatRate();
    return this.#income * vatTaxRate;    
  }
}
const tax = new Tax(10000, new BizTaxRate());
console.log(tax.calcTax()); // 1000
```

이런식으로 바꿔주면 설사 법인 세율이 아닌 개인 세율로 변경되더라도 생성자를 호출할때 넘겨주기만 하면 된다. (+ setter 함수를 이용하는 방법도 있긴 하다.) 이를 **의존성 주입**이라 한다. 

의존하는 객체를 내부가 아닌 외부에서 주입받는 것을 뜻하는데 **typedi**는 이런 의존성 주입을 관리해주는 라이브러리라고 생각 하면된다.

