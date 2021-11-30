# NestJS

## Configuration
- 처음에는 dotenv를 쓰려고 작업을 진행하였다. nestjs 문서에도 dotenv를 쓰는것을 추천하고, 이를 이용해 작업하는 코드도 있다.
- 한데 현재 회사의 config 구조상 dotenv를 사용하는 것은 무리가 있다.
	- depth가 존재한다.
		- dotenv는 depth를 지원하지 않는다.
	- config가 JSON으로 되어 있다.
		- 만약 config를 dotenv로 변경하려면 기존 json파일을 dotenv 형태로 변경해서 이를 S3에 업로드 해주거나, json을 dotenv로 바꿔주는 transfiler가 필요하다. 이를 작업하기에는 일정 및 쓸데없는 시간낭비라 생각 된다.
		- 또한 production, staging, development 환경마다 config가 완벽하게 따로 존재하는게 아니라 이를 merge하는 형태로 되어 있다. 결국 ENV는 하나의 파일로 만들어져야 한다는 것인데, 이것 또한 영 꺼림직한 작업이다.