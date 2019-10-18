# Github에 100MB 이상 파일 업로드 하는 방법

Github에 100MB 이상의 파일을 commit하고 push 하려는데 Error가 발생하면서 업로드가 되질 않았다. 찾아보니 Gihub에는 100MB 이상의 파일을 업로드 하려면 별도의 처리를 해줘야 한다. 그 방법을 정리한 내용이다.

## 해결방법

1. 일단 `Git large File Storage(LFS)`를 설치해준다.

    ```bash
    git lfs install


    ## 그런데 나는 별도의 설치가 필요 없었다. 이미 설최어 있었음. (MAC 환경)
    ```

2. 설치가 끝나면 해당 레파지토리에 가서 lfs 명령을 이용하여 이를 추가하여 준다.

    ```bash
    git lfs track "*.txt"

    ## NODE_STREAM_TEST 레파지토리에서 100MB이상은 TXT 파일만 있어서 이를 추가해주었다.
    ```

3. 그러면 `.gitattributes` 파일이 추가된것을 볼수 있다. 이를 stage에 올리고 commit 하고 push하면 올라가는 것을 볼수 있다.

    ```bash
    ➜  node_stream_tester git:(master) ✗ git add .
    ➜  node_stream_tester git:(master) ✗ git status
    On branch master
    Your branch is up to date with 'origin/master'.

    Changes to be committed:
      (use "git reset HEAD <file>..." to unstage)

            new file:   .gitattributes
            new file:   files/cn.txt
            new file:   files/en.txt
            new file:   files/hindi.txt
            new file:   files/jp.txt
            new file:   files/ko.txt
    ➜  node_stream_tester git:(master) ✗ git commit -m "feat: upload txt files for test"  
    [master 8d466db] feat: upload txt files for test
    6 files changed, 16 insertions(+)
    create mode 100644 .gitattributes
    create mode 100755 files/cn.txt
    create mode 100755 files/en.txt
    create mode 100755 files/hindi.txt
    create mode 100755 files/jp.txt
    create mode 100755 files/ko.txt
    ➜  node_stream_tester git:(master) git push origin master
    Uploading LFS objects: 100% (5/5), 1.1 GB | 15 MB/s, done
    Enumerating objects: 10, done.
    Counting objects: 100% (10/10), done.
    Delta compression using up to 8 threads.
    Compressing objects: 100% (8/8), done.
    Writing objects: 100% (9/9), 1.17 KiB | 1.17 MiB/s, done.
    Total 9 (delta 0), reused 0 (delta 0)
    To https://github.com/ThreeSnakes/node_stream_tester.git
      df9d5a7..8d466db  master -> master
    ```

## 참조

- [git-lfs](https://git-lfs.github.com/)
- [Lim JongHyuck - Github에 100MB 이상의 파일을 올리는 방법](https://medium.com/@stargt/github%EC%97%90-100mb-%EC%9D%B4%EC%83%81%EC%9D%98-%ED%8C%8C%EC%9D%BC%EC%9D%84-%EC%98%AC%EB%A6%AC%EB%8A%94-%EB%B0%A9%EB%B2%95-9d9e6e3b94ef)