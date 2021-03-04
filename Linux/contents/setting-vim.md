# Vim setting
---
Vim setting 하는거 총 정리한 것이다. 할때마다 찾지 말고 이걸로 한방에 해결 하자.

```
1. vim 설치
  sudo apt-get install vim
  보통 vim은 ubuntu에 설치 되어있는데 혹시 설치 안되있는 것도 있을수 있으니 작성.
  
2. vim 기본 setting
  sudo vi /etc/vim/vimrc
  열린 파일 맨 마지막에 다음 내용을 추가 시켜 준다.
  
  set cindent
  set number
  set autoindent
  set smartindent
  set ruler
  set tabstop =4
  # tabstop 입력할때 = 바로뒤에 숫자가 나와야 한다. 뛰어쓰기 금지!
  set hlsearch
  set ignorecase
  set showmatch
  
3. git 설치.
  sudo apt-get install git
  
4. vundle 코드 git으로 받아 오기.
  git clone https://github.com/gmarik/Vundle.vim.git ~/.vim/bundle/vundle

5. vim 에 Vundle setting.
  sudo vi /etc/vim/vimrc
  열린 파일 맨 마지막에 다음 내용을 추가 시켜 준다.
  
  "Vundle setting"
  set nocompatible
  filetype off
  
  set rtp+=~/.vim/bundle/vundle/
  
  call vundle#rc()
    Bundle 'gmarik/vundle'
    Bundle 'git://git.wincent.com/command-t.git'
    
  filetype plugin indent on
  
6. vundle 사용법
  sudo vi /etc/vim/vimrc 로 vimrc 를 연 상태에서
  :BundleSearch 를 입력 하면 vim 창이 두개로 갈라 진다.
  왼쪽 편은 설치 할 수 있는 vundle 창이다. 여기서 /[Plugin 이름] 을 누른다음 N을 누르면 이름이 포함된 Plugin을 차례대로 검색 할 수 있다.
  plugin 이름을 복사 한 다음에 이를 오른쪽 vimrc 에 Bundle 'plugin 이름' 형식으로 넣어 준다.
  
7. bundle 설치
  6번 과정으로 vimrc에 bundle을 추가 시켰다면 실제로 bundle을 설치해줘야 한다.
  vim +PluginInstall +qall
  명령어를 입력하면 vimrc에 추가한 bundle을 설치 한다.
  
8. NERDTree 설치
  NERDTree는 vim에서 파일들을 파일탐색기 형태로 계층적인 모습으로 볼수 있게 해주는 Plugin이다.
  
  6 ~ 7과정으로 NERDTree를 설치해보자.
  /NERD 검색후 'The-NERD-tree' 검색후 설치.
  vim을 킨 상태에서 :NERDTree 입려하면 왼쪽에 NERDTree 창 생성됨.
  
  #단축키 지정.
  sudo vi /etc/vim/vimrc 로 vimrc 를 연 상태에서
  nmap <F9> :NERDTree<CR>
  입력하면 F9를 누르면 NERDTree 실행 된다. 노트북에서는 VMWare 때문에 F9만 누르면 안먹히고 Fn키 누르고 F9 눌러줘야 된다.
  
9. TagList 설치.
  TagList는 소스코드 파일에서 함수, 전역변수 리스트를 검색할수 있는 강력한 사이드바이다. 다만 ctags를 사용하기 때문에 이를 설치 해줘야 한다.
  
  ctag 설치.
  sudo apt-get install ctags
  
  6 ~ 7 과정으로 Taglsit를 설치해보자.
  /taglist 검색후 'taglist-plus' 검색후 설치.
  
  #단축키 지정.
  sudo vi /etc/vim/vimrc 로 vimrc 를 연 상태에서
  nmap<F10> :TlistToggle<CR>
  let Tlist_Ctags_Cmd = "/usr/bin/ctags"
  let Tlist_Inc_Winwidth = 0
  let Tlist_Exit_OnlyWindow = 0
  let Tlist_Auto_Open = 0
  let Tlist_use_Right_Window = 1
  입력한다. F10을 누르면 Taglist 실행. Taglist는 오른쪽에 실행된다.
  
10. AutoComplePop 설치.
  AutoComplePop은 vim에서 자동완성 기능을 지원하게 해주는 Plugin이다.
  
  6 ~ 7 과정으로 AutoComplePop을 설치해보자.
  /AutoComplePop 검색후 'AutoComplePop' 검색 후 설치.
  
11. SrcExpl 설치.
  SrcExlp은 소스코드에서 변수가 선언된 부분을 볼수 있다. 한마디로 소스 인사이트 같은 기능?
  
  Vundle에서 찾을수가 없다.. 그래서 조금 귀찮더라도 git에서 받아야 한다.
  git clone https://github.com/wesleyche/SrcExpl ~/.vim/bundle/SrcExpl 로 다운로드 한다.
  
  그다음 vi 들어간 다음에 vimrc에 다음 입력해주고 :BundleInstall 입력후 설치한다.
  
  #단추키 지정.
  Plugin 'SrcExpl'
  nmap <F8> :SrcExplToggle<CR>
  nmap <c-h> <c-w>h
  nmap <c-j> <c-w>j
  nmap <c-k> <c-w>k
  nmap <c-l> <c-w>l
  
  let g:SrcExpl_winHeight = 8
  let g:SrcExpl_refreshTime = 100
  let g:SrcExpl_jumpKey = "<enter>"
  let g:srcExpl_gobackKey = "<space>"
  let g:SrcExpl_isUpdateTags = 0
```
