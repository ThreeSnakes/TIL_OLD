# DynamoDB Backup && Test

`본 문서는 stg환경을 구성하기 위해서 dynamoDB backup 방법 및 테스트를 진행한 내역을 기록해 놓은 문서이다.`

## DynamoDB 백업 방법
- [AWS 자습서](https://aws.amazon.com/ko/blogs/korea/how-to-import-export-amazon-dynamodb-using-data-pipeline-and-opensource-tools/)를 보고 백업을 진행 하려 했더니 `Seoul region`에 `data pipeline`이 없다. ㅡㅡ;; 또한 자습서에 보면 `DynamoDB` 에서 테이블 선택후 `action 버튼` 밑에 `backup 버튼`도 있는것으로 나오는데 `Seoul region`에서는 `테이블 삭제` 버튼만 존재한다. 결국 자습서에서 data pipeline을 이용하는 방법 말고 다른 방법으롤 시도해야 한다. 
- 자습서 마지막 부분에 `dynamodb-import-export-too`을 이용해서 하는 방법이 있는데 이를 이용해서 작업을 진행 했다. 아래부터는 자습서를 이용해서 테스트해 보았다.

### dynamodb-import-export-too 설치.
- `maven` 설치 할라 했더니 wget이 없네 -_-;; wget 설치.
    ``` bash
    brew install wget
    ```

- `maven` 설치.
    ``` bash
    Limchanghyeon@imchanghyeon-ui-iMac  ~  wget http://ftp.kddilabs.jp/infosystems/apache/maven/maven-3/3.3.9/binaries/apache-maven-3.3.9-bin.tar.--2018-02-07 18:39:26--  http://ftp.kddilabs.jp/infosystems/apache/maven/maven-3/3.3.9/binaries/apache-maven-3.3.9-bin.tar.gz
    Resolving ftp.kddilabs.jp (ftp.kddilabs.jp)... 192.26.91.193, 2001:200:601:10:206:5bff:fef0:466c
    Connecting to ftp.kddilabs.jp (ftp.kddilabs.jp)|192.26.91.193|:80... connected.
    HTTP request sent, awaiting response... 200 OK
    Length: 8491533 (8.1M) [application/x-gzip]
    Saving to: ‘apache-maven-3.3.9-bin.tar.gz’

    apache-maven-3.3.9-bin.tar.gz     100%[==========================================================>]   8.10M  74.6KB/s    in 1m 57s

    2018-02-07 18:41:26 (70.7 KB/s) - ‘apache-maven-3.3.9-bin.tar.gz’ saved [8491533/8491533]
    ### 다운로드 받는데 3분정도 소요됨.
    ```

- `maven` 압축 해제
    ``` bash
    Limchanghyeon@imchanghyeon-ui-iMac  ~  tar -zxvf ./apache-maven-3.3.9-bin.tar.gz
    x apache-maven-3.3.9/boot/plexus-classworlds-2.5.2.jar
            .... 생략 ....
    x apache-maven-3.3.9/lib/ext/
    x apache-maven-3.3.9/lib/ext/README.txt
    ```

- `java JDK` 설치 필요. 이전에 깔아놔서 그냥 스킵.
- [dynamodb-import-export-tool github](https://github.com/awslabs/dynamodb-import-export-tool)로 가서 툴 코드를 다운로드 받거나 pull한다.
- `maven`으로 해당 코드 빌드 한다.
    ``` bash
    Limchanghyeon@imchanghyeon-ui-iMac  ~/Desktop/dynamodb-import-export-tool-master  /Users/Limchanghyeon/apache-maven-3.3.9/bin/mvn install
    [INFO] Scanning for projects...
            .... 생략 ....
    Downloaded: https://repo.maven.apache.org/maven2/org/codehaus/plexus/plexus-digest/1.0/plexus-digest-1.0.jar (12 KB at 38.9 KB/sec)
    Downloaded: https://repo.maven.apache.org/maven2/org/codehaus/plexus/plexus-utils/3.0.5/plexus-utils-3.0.5.jar (226 KB at 745.2 KB/sec)
    [INFO] Installing /Users/Limchanghyeon/Desktop/dynamodb-import-export-tool-master/target/dynamodb-import-export-tool-1.0.1.jar to /Users/Limchanghyeon/.m2/repository/com/amazonaws/dynamodb-import-export-tool/1.0.1/dynamodb-import-export-tool-1.0.1.jar
    [INFO] Installing /Users/Limchanghyeon/Desktop/dynamodb-import-export-tool-master/pom.xml to /Users/Limchanghyeon/.m2/repository/com/amazonaws/dynamodb-import-export-tool/1.0.1/dynamodb-import-export-tool-1.0.1.pom
    [INFO] ------------------------------------------------------------------------
    [INFO] BUILD SUCCESS
    [INFO] ------------------------------------------------------------------------
    [INFO] Total time: 01:43 min
    [INFO] Finished at: 2018-02-07T18:49:07+09:00
    [INFO] Final Memory: 22M/187M
    [INFO] ------------------------------------------------------------------------
    ```

- 여기 까지 하면 `dynamodb-import-export-tool` 설치가 끝남. 

### dynamodb-import-export-too 로 테이블 복사하기.
- `dynamodb-import-export-tool` 명령어 옵션.
    ``` bash
    java -jar dynamodb-import-export-tool.jar

        --destinationEndpoint <destination_endpoint> // 타겟 EndPoint : dynamodb.ap-northeast-2.amazonaws.com 입력.
        
        --destinationTable <destination_table> // 타겟 테이블 : Dev-FingerIndicator-backup 입력.
        
        --sourceEndpoint <source_endpoint> // 원본 EndPoint : dynamodb.ap-northeast-2.amazonaws.com 입력.
        
        --sourceTable <source_table>// 원본 테이블 : Dev-FingerIndicator 입력.
        
        --readThroughputRatio <ratio_in_decimal> // 원본에서 읽을때 throughput 비율.
        
        --writeThroughputRatio <ratio_in_decimal> // 타겟에 쓸때 throughput 비율.
        
        --maxWriteThreads // (Optional, default=128 * Available_Processors) Maximum number of write threads to create.
        
        --totalSections // (Optional, default=1) Total number of sections to split the bootstrap into. Each application will only scan and write one section.
        
        --section // (Optional, default=0) section to read and write. Only will scan this one section of all sections, [0...totalSections-1].
        
        --consistentScan // (Optional, default=false) indicates whether consistent scan should be used when reading from the source table.
    ```

- `dynamodb-import-export-tool`로 `DB` 복사하기.
    ``` bash
        java -jar dynamodb-import-export-tool.jar --sourceEndpoint dynamodb.ap-northeast-2.amazonaws.com --sourceTable [원본 테이블명] --destinationEndpoint dynamodb.ap-northeast-2.amazonaws.com --destinationTable [복사될 타겟 테이블명] --readThroughputRatio 0.1 --writeThroughputRatio 0.1
        2018-02-07 19:18:32,724 INFO  com.amazonaws.dynamodb.bootstrap.CommandLineInterface - Starting transfer...
        2018-02-07 19:48:07,673 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
        2018-02-07 19:48:17,676 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
        2018-02-07 19:48:27,679 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
        2018-02-07 19:48:37,683 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
        ### 30분만에 복사는 끝났지만 해당 작업이 terminate가 되지 않았다. 다시 테스트 필요.
    ```

## Dynamo DB 백업 테스트
번의 테스트를 거쳐서 실제 운영 DynamoDB를 백업을 진행 하려고 한다. 백업 하려는 테이블은 총 6개이며 1개의 테이블만 유독 데이터가 많으며(약 26GB) 나머지는 KB단위이며 데이터도 많지 않다.

### Test1
``` bash
## 테이블명은 임의로 변경
## 리드 비율 0.5, 쓰기 비율 1로 주었다.
java -jar dynamodb-import-export-tool-1.0.1.jar --sourceEndpoint dynamodb.ap-northeast-2.amazonaws.com --sourceTable aaa --destinationEndpoint dynamodb.ap-northeast-2.amazonaws.com --destinationTable bbb --readThroughputRatio 0.5 --writeThroughputRatio 1
2018-02-08 12:03:36,022 INFO  com.amazonaws.dynamodb.bootstrap.CommandLineInterface - Starting transfer...
2018-02-08 12:09:39,022 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:09:49,026 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:09:59,031 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:10:09,035 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:10:19,037 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:10:29,039 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:10:39,044 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:10:49,044 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:10:59,045 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:11:09,047 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:11:19,048 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:11:29,053 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:11:39,058 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:11:49,060 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:11:59,060 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:12:09,063 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:12:19,069 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:12:29,070 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:12:39,074 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:12:49,075 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:12:59,079 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:13:09,082 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:13:19,084 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:13:29,086 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:13:39,089 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:13:49,094 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:13:59,097 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:14:09,103 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:14:19,108 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 12:14:20,208 INFO  com.amazonaws.dynamodb.bootstrap.CommandLineInterface - Finished Copying Table.
```
- `readThroughputRatio` =  0.5 `writeThroughputRatio`  = 1 로 줬더니 약 6분만에 모든 작업이 끝났다. 확실히 늘리면 빨라진다.
- 다만 복사되는 테이블에 `autoScailing`을 주지 않았더니 `write`에 쓰로틀링 발생. 데이터가 40개 정도가 저장되지 않았다.
- 복사되는 테이블에 프로비저닝된 읽기/쓰기 를 5씩 줬었다. `autoScailing`도 똑같이 5씩 주었었다.
![TEST1](https://user-images.githubusercontent.com/36795031/38771353-c0befc70-405c-11e8-9028-f40ee74827f9.png)

### Test2
``` bash
# 실제 운영 테이블로 테스트를 진행 하였다.

✘ Limchanghyeon@imchanghyeon-ui-iMac  ~/Desktop/dynamodb-import-export-tool-master/target  java -jar dynamodb-import-export-tool-1.0.1.jar --sourceEndpoint dynamodb.ap-northeast-2.amazonaws.com --sourceTable aaa --destinationEndpoint dynamodb.ap-northeast-2.amazonaws.com --destinationTable bbb --readThroughputRatio 0.3 --writeThroughputRatio 0.7
2018-02-08 16:09:08,104 INFO  com.amazonaws.dynamodb.bootstrap.CommandLineInterface - Starting transfer...
2018-02-08 16:36:00,722 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
.... 생략 ....
2018-02-08 17:49:52,045 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-08 17:49:55,699 INFO  com.amazonaws.dynamodb.bootstrap.CommandLineInterface - Finished Copying Table.
```
- 실제 운영 Table을 대상으로 백업 작업을 진행 하였다.
- `readThroughputRatio` =  0.3 `writeThroughputRatio` = 0.7 로 줬더니 약 33분만에 23,357항목 읽기가 끝났지만, 쓰기가 끝나기 까지는  1시간 10분이 소요되었다.

- 읽기
    ![TEST2-1](https://user-images.githubusercontent.com/36795031/38771373-1ad61950-405d-11e8-8535-e78cd8548d4c.png)
    - 기존 운영 테이블에서 읽기 용량 그래프이다.
    - 읽기 용량에 대한 그래프인데  `readThroughputRatio`를 0.3을 줘서 그런지 평균적으로 약 9개를 사용하는 것으로 보인다.

- 쓰기
    ![TEST2-2](https://user-images.githubusercontent.com/36795031/38771374-1afba788-405d-11e8-94dd-1e8192abb69a.png)
    - 새로 만들어진 백업 테이블의 쓰기 용량 그래프이다.
    - 운영 테이블의 읽기 보다 소요시간이 훨씬 많이 걸렸다. 약 3배 정도 더 걸린듯으로 보인다.
    - 쓰기 용량도 마찬가지로 `writeThroughputRatio` 을 0.7을 줘서 그런지 평균적으로 약 21개를 사용하는 것으로 보인다.

- 종합
 - [자습서](https://docs.aws.amazon.com/ko_kr/amazondynamodb/latest/developerguide/ProvisionedThroughput.html)에 보면 읽기는 1 unit 당 4KB, 쓰기는 1 unint당 1KB를 1초당 1회씩 쓴다고 한다. 약 4배 가까이 차이가 나는데 위에서 읽기/쓰기의 시간차이가 나는 이유도 unit 당 데이터 처리량의 차이때문이라고 생각 되어진다. 
 - 결국 백업을 진행 할 때, 읽기 보다 쓰기를 할때 프로비전닝된 쓰기를 3배정도 높게 준다면 비슷한 시간이 걸리지 않을까 예측된다. 
 - 원본 테이블에서 프로비저닝된 읽기가 30 정도라 가정할 때, 여기서 30% 정도만 사용한다면 초당 약 9 unint을 사용하게 되는 것이고,  9 * 4 = 36KB 이트가 된다. 이 데이터를 백업쪽에 기록 할때 평균 36 unit을 사용하게 한다면 비슷한 시간에 끝낼수 있을것이라 예상하는 것이다.

### TEST 3
``` bash
Limchanghyeon@imchanghyeon-ui-iMac  ~/Desktop/dynamodb-import-export-tool-master/target  java -jar dynamodb-import-export-tool-1.0.1.jar --sourceEndpoint dynamodb.ap-northeast-2.amazonaws.com --sourceTable aaa --destinationEndpoint dynamodb.ap-northeast-2.amazonaws.com --destinationTable bbb --readThroughputRatio 0.3 --writeThroughputRatio 0.8
2018-02-09 11:00:40,006 INFO  com.amazonaws.dynamodb.bootstrap.CommandLineInterface - Starting transfer...
2018-02-09 11:27:36,062 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-09 11:27:46,063 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
... 생략 ...
2018-02-09 12:08:01,320 WARN  com.amazonaws.dynamodb.bootstrap.AbstractLogConsumer - Waiting for the threadpool to terminate...
2018-02-09 12:08:02,792 INFO  com.amazonaws.dynamodb.bootstrap.CommandLineInterface - Finished Copying Table
```
- 마찬가지로 운영 테이블로 테스트를 진행 하였다.

- 테스트 진행전 예상.
    - 운영쪽 프리비저닝 리드는 따로 건들이지 않고 30% 정도만 쓴다고 가정하면 약 9개의 유닛을 사용. 그렇다면 약 1초에 36kb를 읽는다.
    - stg로 만드는 테이블에서는 초당 36kb를 쓰기 위해서는 36유닛이 필요하다. 그래서 프리비저닝된 쓰기 유닛을 40개를 맞춰놓았다.
    - 이럴 경우 끝나는 시간이 비슷할거라 예상 하였다.

- 테스트 종료 후.
    - 원본 테이블 읽기 작업.
        ![Test3-1](https://user-images.githubusercontent.com/36795031/38771413-07428bfc-405e-11e8-8661-7fd55404e467.png)
    - 복사되는 테이블 쓰기 작업. 
        ![Test3-2](https://user-images.githubusercontent.com/36795031/38771414-07676dc8-405e-11e8-89a1-9fef2d747005.png)
    - 읽기 작업은 약 27분만에 종료 됬지만, 쓰기 작업은 거의 70분이 소요 됬다.
    - 읽기 작업은 진행할때 평균 9unit을 사용되지만, 쓰기 작업은 평균 32unit 정도 소요 되었다. `writeThroughputRatio`를 0.8로 맞춰서 맞게 나온것으로 보이지만 흠.. 시간이 더 확줄어야 될것으로 보이는데 그렇지 않았다.
    - [백서](https://docs.aws.amazon.com/ko_kr/amazondynamodb/latest/developerguide/HowItWorks.ProvisionedThroughput.html)에서 할당된 처리량 항목을 보면 쓰기를 진행할때 가장 가까운 정수로 올림을 한다고 한다.
    - Release-Finger-Indicator는 118.50MB KB로 계산 하면 121344KB를 가진다.
    - 읽기를 계산하면 121344KB / (9개의 Unit * 4KB * 2(Eventually Consistent Read)) = 약 28.088888889분.
    - 쓰기를 계산하면 121344KB / (32개의 Unit * 1KB) = 약 63.2분.
    - 계산 하면 얼추 비슷하게 나오는것 같다. 그렇다면 비슷하게 끝내려면 읽기 Unit 개수 * 4 * 2(`Eventually Consistent Read`) 까지 하면 되지 않을까 싶다. 아니면 Strongly Consistent Read 옵션을 주서 read를 write랑 비슷하게 맞춰버리든가...

