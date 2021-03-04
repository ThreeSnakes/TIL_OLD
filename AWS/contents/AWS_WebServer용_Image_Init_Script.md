# AWS WebServer용 Image Init Script
---

이 스크립트는 웹서버를 띄울때 여러가지 설치 및 셋팅 해야 하는 항목을 한번에 하기위해 작성한 배쉬 스크립트 파일이다. 

``` bash
#!/bin/bash -ex
echo "##########################################"
echo "### WELCOME!! init EC2 Server Instance ###"
echo "##########################################"
echo "this shell program is init Shell script."
echo "1. Set Date Time. "
echo "2. Install NVM Module. "
echo "3. Install GIT. "
echo "4. Set ~/.bash_profile. "
echo "5. make WebApp/tmp Directory. "
echo "6. node install. "
echo "7. install Global Node Module. "
echo "8. install python pip. "
echo "9. install pm2-logrotate. "
whoami
echo "##########################################"
echo "step1. set Date Time KST"
echo "##########################################"
cd /etc
sudo rm localtime
cd /etc
sudo ln -s /usr/share/zoneinfo/Asia/Seoul localtime
echo "=================RESULT==================="
date
echo "=========================================="
echo "##########################################"
echo "step2. install NVM"
echo "##########################################"
curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.33.6/install.sh | bash
. ~/.nvm/nvm.sh
nvm
echo "##########################################"
echo "ste3. install git"
echo "##########################################"
yes | sudo yum install git
echo "##########################################"
echo "step4. Set ~/.bash_profile. "
echo "##########################################"
echo "# AWS Setting" >> ~/.bashrc
echo "export AWS_REGION=ap-northeast-2" >> ~/.bashrc
echo "export NODE_EVN=production" >> ~/.bashrc
echo "=================RESULT==================="
cat ~/.bashrc
echo "=========================================="
echo "##########################################"
echo "step5. make WebApp/Tmp Directory."
echo "##########################################"
cd
pwd
mkdir -p WebApp/tmp
cd WebApp/tmp
echo "=================RESULT==================="
pwd
echo "=========================================="
echo "##########################################"
echo "step6. Node Install and check. "
echo "##########################################"
cd
nvm install 6.10.0
nvm ls
nvm alias default 6.10.0
node -v
npm -v
echo "##########################################"
echo "step7. install Global Node Module. "
echo "##########################################"
npm install pm2 -g
npm install bunyan -g
echo "##########################################"
echo "step8. install python pip. "
echo "##########################################"
python -V
wget https://bootstrap.pypa.io/get-pip.py
python get-pip.py
rm get-pip.py
pip -v
echo "##########################################"
echo "step9. install pm2-logrotate. "
echo "##########################################"
pm2 install pm2-logrotate
pm2 set pm2-logrotate:max_size 100M
pm2 set pm2-logrotate:compress true

```

localTime 셋팅, NVM 설치 및 셋팅, Git 설치, 환경변수 설정, python 설치, pm2-logrotate를 설치 및 셋팅을 진행 한다.