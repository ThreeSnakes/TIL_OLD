# JavaScript heap out of memory 에러 해결 방법

블로그에 글을 쓰고 배포를 진행하는데 다음과 같은 에러가 발생하면서 배포에 실패하고 있었다. 일단 로그를 보자.

``` bash
8:40:07 PM: <--- Last few GCs --->
8:40:07 PM: [1435:0x34284f0]   559846 ms: Mark-sweep 1372.7 (1470.1) -> 1372.5 (1473.6) MB, 3618.2 / 0.0 ms  allocation failure GC in old space requested
8:40:07 PM: [1435:0x34284f0]   563438 ms: Mark-sweep 1372.5 (1473.6) -> 1372.5 (1442.6) MB, 3591.0 / 0.0 ms  last resort GC in old space requested
8:40:07 PM: [1435:0x34284f0]   566942 ms: Mark-sweep 1372.5 (1442.6) -> 1372.5 (1442.6) MB, 3504.5 / 0.0 ms  last resort GC in old space requested
8:40:07 PM: <--- JS stacktrace --->
8:40:07 PM: ==== JS stack trace =========================================
8:40:07 PM: Security context: 0x19dc550a5891 <JSObject>
8:40:07 PM:     1: SourceNode_walk [/opt/build/repo/node_modules/source-map/lib/source-node.js:~221] [pc=0x1eb867f2d8b7](this=0x2bd3cf92e3d1 <SourceNode map = 0x1eddef4f9629>,aFn=0xa260ec309b9 <JSFunction (sfi = 0x3af9083ac611)>)
8:40:07 PM:     2: SourceNode_walk [/opt/build/repo/node_modules/source-map/lib/source-node.js:~221] [pc=0x1eb867f2c2e5](this=0x3ea54b54ebf1 <SourceNode map = 0x1eddef4f9629>,aFn=0xa260ec309b9...
8:40:07 PM: FATAL ERROR: CALL_AND_RETRY_LAST Allocation failed - JavaScript heap out of memory
8:40:07 PM:  1:
8:40:07 PM: node::Abort() [node]
8:40:07 PM:  2:
8:40:07 PM: 0x8cd49c [node]
8:40:07 PM:  3:
8:40:07 PM: v8::Utils::ReportOOMFailure(char const*, bool) [node]
8:40:07 PM:  4:
8:40:07 PM: v8::internal::V8::FatalProcessOutOfMemory(char const*, bool) [node]
8:40:07 PM:  5:
8:40:07 PM: v8::internal::Factory::NewUninitializedFixedArray(int) [node]
8:40:07 PM:  6:
8:40:07 PM: 0xd84573 [node]
8:40:07 PM:  7:
8:40:07 PM: v8::internal::Runtime_GrowArrayElements(int, v8::internal::Object**, v8::internal::Isolate*) [node]
8:40:07 PM:  8: 0x1eb8675042fd
8:40:15 PM: Aborted (core dumped)
```

키워드로 **CALL_AND_RETRY_LAST Allocation failed - JavaScript heap out of** 를 검색해보니 해당 에러는 V8dml 힙 메모리 할당 한계 사이즈를 넘어서는 메모리 할당이 일어나서 발생한 버그라고 한다. 이럴때는 메모리 할당 한계 사이즈를 늘려 주면 된다고 한다.

``` bash
# 다음 명령어로 설정을 할 수 있다.
node --max_old_space_size=8192
```

그런데 이 에러가 netlify에 배포를 하다가 발생한 에러이다. 그래서 netlify를 키워드에 포함해서 다시 검색을 해보니 netlify 셋팅에 마찬가지로 같은 옵션을 줄 수 있다.

``` bash
# netlify.toml 파일에서 [build.environment]하위에 다음 내용을 추가해준다.
[build.environment]
  NODE_OPTIONS = "--max_old_space_size=4096"
```

### 출처
- [Bloodguy](https://bloodguy.tistory.com/entry/nodejs-FATAL-ERROR-CALLANDRETRYLAST-Allocation-failed-process-out-of-memory-에러-원인-해결방법 )
- [Gatsby@2.11.0 Build failure (JavaScript heap out of memory)](https://github.com/gatsbyjs/gatsby/issues/15190)