## GitHub HomePage

[Github로 이동](https://github.com/moovweb/gvm)

## 설치 방법.

### 맥에서 사용 하려면 아래 작업 먼저 필요.

``` bash
xcode-select --install
brew update
brew install mercurial
```

### gvm 설치

``` bash
## 아래 명령어로 설치를 진행한다.
➜  ~ bash < <(curl -s -S -L https://raw.githubusercontent.com/moovweb/gvm/master/binscripts/gvm-installer)

Cloning from https://github.com/moovweb/gvm.git to /Users/changhyunlim/.gvm
No existing Go versions detected
Installed GVM v1.0.22

Please restart your terminal session or to get started right away run
 `source /Users/changhyunlim/.gvm/scripts/gvm`
 
## 이후 나온 것 처럼 위 명령어를 실행해 주자
➜  ~ source /Users/changhyunlim/.gvm/scripts/gvm

## 설치 확인
➜  ~ gvm
Usage: gvm [command]

Description:
  GVM is the Go Version Manager

Commands:
  version    - print the gvm version number
  get        - gets the latest code (for debugging)
  use        - select a go version to use (--default to set permanently)
  diff       - view changes to Go root
  help       - display this usage text
  implode    - completely remove gvm
  install    - install go versions
  uninstall  - uninstall go versions
  cross      - install go cross compilers
  linkthis   - link this directory into GOPATH
  list       - list installed go versions
  listall    - list available versions
  alias      - manage go version aliases
  pkgset     - manage go packages sets
  pkgenv     - edit the environment for a package set
  
```

### termainal에서 사용하기 위해서 bash, zsh에 추가해놓자.

``` bash
vi ~/.zshrc
## 이후 열린 파일에서 마지막에 아래 내용 추가.

# gvm setting
[[ -s "$HOME/.gvm/scripts/gvm" ]] && source "$HOME/.gvm/scripts/gvm"
```

### 2019.04.11 기준 stable 버전 설치 과정.

``` bash
# 1.5 이상 버전 설치시 1.4 버전을 먼저 설치 후 설치가 가능하다.
# 아래 순서대로 진행한다.
gvm install go1.4 --binary
gvm use go1.4 
export GOROOT_BOOTSTRAP=$GOROOT 
gvm install 1.12.3 -B
## 원래는 gvm install 1.12.3 으로 진행해야 하는데... 해당 명령어로 진행할경우 설치가 안됨. 그래서 Bynary로 설치. 

# 설치 확인
➜  ~ gvm list

gvm gos (installed)

=> go1.12.3
   go1.4

# 해당 버전 디폴트로 설정
➜  ~ gvm use go1.12.3 --default
Now using version go1.12.3

# go 설치 확인
➜  ~ go version
go version go1.12.3 darwin/amd64
```

## 명령어

### go 설치 가능한 목록 보기

``` bash
gvm listall

#### 아래처럼 목록 나옴 ####
go1.12.1
go1.12.2
go1.12.3
release.r56
release.r57
release.r58
.. 생략..
release.r60.3
```

### go 설치

``` bash
gvm install go1.12.3
```

### go 설치 삭제

``` bash
➜  ~ gvm uninstall go1.4
Uninstalled version go1.4
```

### 설치한 Go Version 확인

``` bash
➜  ~ gvm list

gvm gos (installed)

=> go1.12.3
   go1.4
```