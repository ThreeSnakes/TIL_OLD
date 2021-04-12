# Singleton

Singleton은 인스턴스를 하나만 생성해서 이를 공통으로 사용하려는 것이다. 이를 이용하면 불필요한 인스턴스 생성을 막으면서 메모리 낭비를 줄일 수 있다.

``` js
class Singleton {
  static instance;

  constructor() {
    if (Singleton.instance) {
      return Singleton.instance;
    }
    this.a = 30;
    Singleton.instance = this;
  }

  add() {
    this.a += 20;
  }

  getA() {
    return this.a;
  }
}

module.exports = Singleton;
```

싱글톤이 어떤식으로 동작하는지는 이미 알고 있으니 별다른 설명은 할게 없다. 다만 JS에서 static을 어떻게 이용하는지 한번 알아보고 넘어갈 필요는 있다.

정적 함수(static function)에서 다른 정적 함수, 변수에 접근 할 경우에는 `this`를 이용해서 접근 할 수 있다. 
하지만 클래스 생성자나 다른 메소드에서 접근 하는 경우에는 `this`로 접근을 할 수 없다.

`CLASSNAME.STATIC_METHOD_NAME()` 를 이용하거나 `constructor(this.constructor.STATIC_METHOD_NAME())`를 사용해서 접근 해야 한다.

``` js
class Test {
	static static_property = 10;
	static static_func1() {
		// 정적함수에서 다른 정적 변수나 함수로는 this를 이용해 접근 할 수 있다.
		console.log(this.static_property);
	}
	static static_func2() {
		this.static_func1();
	}
	
	common_func1() {
		// 해당 코드가 실행되면 에러가 발생한다.
		// 인스턴스에서는 정적 함수나 변수에 접근할때는 this로 접근할 수 없다.
		this.static_func1();
	}
	
	common_func2() {
		// Class 명을 이용해서 접근 하는 방법
		Test.static_func1();
	}
	
	common_func3() {
		// this.constructor를 이용해서 접근 하는 방법.
		this.constructor.static_func1();
	}
}

const test = new Test();
test.common_func1();
test.common_func2();
test.common_func3();
```