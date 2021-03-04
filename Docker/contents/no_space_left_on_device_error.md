# no space left on device Error 해결 방법

## 목차

- [내용](no_space_left_on_device_error.md#%EB%82%B4%EC%9A%A9)
- [정리](no_space_left_on_device_error.md#%EC%A0%95%EB%A6%AC)
- [참조](no_space_left_on_device_error.md#%EC%B0%B8%EC%A1%B0)

### 내용

사내에서 사용하는 대시보드류가 docker로 실행해되는데 그중 특정 대시보드를 run하면 다음과 같은 에러를 뱉으면서 실행이 되질 않았다.

``` bash
npm WARN tar ENOSPC: no space left on device, open '/app/node_modules/.staging/node-notifier-28c86365/vendor/notifu/notifu.exe'
npm WARN tar ENOSPC: no space left on device, open '/app/node_modules/.staging/lodash-5c8f0c91/object.js'
npm WARN tar ENOSPC: no space left on device, open '/app/node_modules/.staging/async-ba5de1c7/selectSeries.js'
...
npm ERR! path /app/node_modules/.staging/watch-344a320f
npm ERR! code ENOSPC
npm ERR! errno -28
npm ERR! syscall mkdir
npm ERR! nospc ENOSPC: no space left on device, mkdir '/app/node_modules/.staging/watch-344a320f'
npm ERR! nospc There appears to be insufficient space on your system to finish.
npm ERR! nospc Clear up some disk space and try again.

npm ERR! A complete log of this run can be found in:
npm ERR!     /home/.npm/_logs/2020-01-20T06_56_09_109Z-debug.log
```

### 정리

**df -h**로 디스크 용량이 꽉 찼나 확인해 봐도 용량을 널널한데.. docker에서 런을 하면 용량이 없다 나온다.

찾아보니 macOS에서는 Docker 자체에 할당된 용량 이상으로 이미지가 남아있어 빌드시 용량이 없다고 나오는 것이라 한다.

docker에서 사용하고 있는 용량을 확인해보자.

``` bash
➜  com.docker.driver.amd64-linux cd ~/Library/Containers/com.docker.docker/Data/com.docker.driver.amd64-linux
➜  com.docker.driver.amd64-linux ll
total 118151096
srwxr-xr-x  1 abra staff     0B  1 20 10:37 00000002.000005f4
srwxr-xr-x  1 abra staff     0B  1 20 10:37 00000002.00001000
srwxr-xr-x  1 abra staff     0B  1 20 10:37 00000002.00001001
srwxr-xr-x  1 abra staff     0B  1 20 10:37 00000002.00001002
srwxr-xr-x  1 abra staff     0B  1 20 10:37 00000002.0000f3a4
srwxr-xr-x  1 abra staff     0B  8  1 09:13 00000002.0000f3a5
srwxr-xr-x  1 abra staff     0B  1 20 10:37 00000003.000005f5
srwxr-xr-x  1 abra staff     0B  1 20 10:37 00000003.00000948
-rw-r--r--@ 1 abra staff    56G  1 20 16:05 Docker.qcow2
-rw-r--r--  1 abra staff    86K  1 20 10:37 config.iso
srwxr-xr-x  1 abra staff     0B  1 20 10:37 connect
-rw-r--r--  1 abra staff    64K  7 26  2018 console-ring
drwxr-xr-x  2 abra staff    64B  8  1 09:14 data
lrwxr-xr-x  1 abra staff    17B  1 20 10:37 guest.000005f5 -> 00000003.000005f5
lrwxr-xr-x  1 abra staff    17B  1 20 10:37 guest.00000948 -> 00000003.00000948
-rw-r--r--  1 abra staff   2.7K  1 20 10:37 hyperkit.json
-rw-r--r--  1 abra staff     3B  1 20 10:37 hyperkit.pid
srwxr-xr-x  1 abra staff     0B  1 20 10:37 lifecycle-server.sock
drwxr-xr-x  2 abra staff    64B  7 23  2018 log
-rw-r--r--  1 abra staff    36B  7 23  2018 nic1.uuid
lrwxr-xr-x  1 abra staff    12B  1 20 10:37 tty -> /dev/ttys004
➜  com.docker.driver.amd64-linux

# 여기서 Docker.qcow2 파일이 약 56G를 사용하는 것을 볼수 있다.
# 이 파일을 그냥 지우거나 Docker 명령어로 이미지를 정리해주자.
# 파일을 지워도 상관없는게 Docker 재시동시 다시 생성된다고 한다.
# 파일을 지우는건 조금 그러니깐 그냥 Docker 명령어로 이미지를 정리하자.
# 마법의 주문을 사용하자.
docker rm $(docker ps -a -q)
docker rmi $(docker images -q)

# 이후 실행하니 잘 된다. 근데 기존 이미지를 싹 다 지우니 오래걸린다..
```

### 참조

- https://blog.outsider.ne.kr/1295
