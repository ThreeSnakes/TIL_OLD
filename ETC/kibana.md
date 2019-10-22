# Kibana

## 목차

- [Kibana란?](#kibana란)
- [주요기능](#주요기능)
- [주의해야할 점](#주의해야할-점)
- [참조](#참조)

### Kibana란

- 지속적으로 누적되는 데이터를 실시간으로 분석할 때 **ELK stack**을 사용하는데 여기서 **ELK**는 **Elastic Search**, **Logstash**, **Kibana** 이 3개를 가리킨다
- 강력하고 화려한 그래픽을 통해 데이터 작업을 할 수 있는 오픈 소스 데이터 시각화 플랫폼
- 히스토그램부터 Geo맵까지 다양한 시각화 도구를 지원
- **Elastick Search**를 저장소로 사용하면서 **Kibana**를 사용하지 않는다면 통계 페이지, 데이터 처리를 위해서 별도의 서버를 띄우고 이를 보여주는 UI코드등을 작성해야 한다. 하지만 **Kibana**를 사용하면 단 몇분만에 데이터 시각화를 할 수 있다

### 주요기능

- **Discover**
  - Discover 메뉴는 Elastic Search에 저장된 데이터를 한눈에 확인 할 수 있는 메인 페이지
  - Discover 메뉴에서 데이터를 확인 하려면 Settings에서 index 혹은 index-pattern을 추가 해야 한다. 추가 하면 Discover 메뉴에서 chart와 data table로 이를 확인 할 수 있다.
- **Visualize**
  - Visualize 메뉴는 Elastic Search에서 수집된 결과를 시각화하여 보여준다
  - 여러 종류의 차트 지원
    - Area Chart(영역차트)
    - Data Table(데이터 테이블)
    - Line Chart(선형 차트)
    - Markdown Widget(마크다운 위젯)
    - Metric(메트릭)
    - Pie Chart(원형 차트)
    - Tile Map(타일 맵)
    - Vertical Bar Chart(세로 막대 차트)
- **Dashboard**
  - Visualize를 통해 시각화한 객체를 모아서 하나의 대시보드에 배치하여 한눈에 확인할 수 있도록 하는 기능
- **Setting**
  - 여러가지 설정을 할 수 있음...
  - Kibana 설정 파일은 yml로 작성됨

### 주의해야할 점

- Elastic Search 버전에 따라서 Kibana에 안정적인 버전이 따로 있다. 처음 설치/사용시 주의하자
- Elastic Search 검색은 하나의 쓰레드로 동작함. Auto-refresh 주기가 짧아지면 많은 search request가 생성되어 부하가 발생할 수 있음. 이 경우 비정상적인 결과를 발생 시킬수 있음

### 참조

- [티몬의 개발이야기](https://m.blog.naver.com/PostView.nhn?blogId=tmondev&logNo=220846929773&proxyReferer=https%3A%2F%2Fwww.google.com%2F)