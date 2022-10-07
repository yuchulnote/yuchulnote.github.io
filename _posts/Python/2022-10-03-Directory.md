---
title : "[Python] 파일과 디렉토리 다루기 : pathlib, os, path, glob"
categories :
    - Python
tag :
    - [Numpy, Python, pathlib, path, os, glob]
toc : true
toc_sticky: true
comments: true
sidebar_main: true
use_math: true
published: true
---

> 딥러닝 스터디를 하면서 MNIST 나 VGG 등 모델들을 다뤄보면서 맨처음 학습 데이터들을 디렉토리 지정하는 코드에서 상당히 멘붕을 겪었었습니다. 그래서 그런김에 공부하면서 정리해보려합니다.

<br>

## 디렉토리의 구성을 알아보자 - os.path

>os.path는 경로명과 파일명에 대한 유용한 함수를 제공하는 모듈입니다.

os.path 모듈들을 소개하면 다음과 같습니다.

<p align="center"><img src="/MYPICS/Language/Python/os/1.png" width = "700" ></p>

예제를 통해 사용법을 익혀봅시다!

[문제]:https://wikidocs.net/110260

[문제] : 특정 폴더(디렉토리)에 어떤 파이썬 파일이 있는지 알고자 할 때, 매개변수에 지정한 디렉토리의 파이썬 파일을 모두 출력하는 `search(dirname)` 함수를 작성하시오. (단, 하위 디렉토리의 파이썬 파일도 모두 출력해야 한다.)

풀이는 다음과 같습니다.

```py
import os

def search(dirname):
    filenames = os.listdir(dirname)
    for filename in filenames:
        filepath = os.path.join(dirname, filename)
        if os.path.isdir(filepath):
            search(filepath)
        elif os.path.isfile(filepath):
            name, ext = os.path.splitext(filepath)
            if ext == '.ipynb':
                print(filepath)
```
입력으로 받은 디렉토리의 모든 파일을 os.listdir()로 얻고 확장자가 .py이면 파일명을 출력합니다.

os.listdir()로 얻은 경로가 파일이 아닌 디렉토리라면 다시 그 경로를 입력으로 하여 search() 함수를 재귀호출합니다.

[os.path 더 자세한 내용]

[os.path 더 자세한 내용]:https://docs.python.org/ko/3/library/os.path.html
<br>

## 파일을 찾기 - glob.glob

glob는 패턴(유닉스 셀이 사용하는 규칙)을 이용하여 파일을 검색할 때 사용하는 모듈입니다.

흔히 사용하는 glob.glob에 대해서 살펴보겠습니다.

가장 기본으로 별표 1개 `*`로 input을 지정하여 현재 폴더 내 모든 파일, 하위 폴더의 목록을 전부 가져올 수 있습니다.

먼저 `!ls` 로 현재 디렉토리에 대해서 알아보겠습니다.
필자는 주피터 노트북 환경에서 실행하였습니다.

```py
!ls
```

<p align="center"><img src="/MYPICS/Language/Python/os/2.png" width = "700" ></p>

이제 glob.glob로 다음과 같이 나오는지 확인해보겠습니다.
```py
import glob
glob.glob('./*')
```
**`./*` 로 현재 디렉토리 내 전체파일, 하위폴더 모으기**

<p align="center"><img src="/MYPICS/Language/Python/os/3.png" width = "300" ></p>

**`*` 로 현재 디렉토리 내 전체파일, 하위폴더 모으기**

```py
glob.glob('*')
```

<p align="center"><img src="/MYPICS/Language/Python/os/4.png" width = "300" ></p>
<br>

**`*`을 이용하여 특정이름이나 확장자를 가진 파일을 찾는 법**

```py
# 특정 확장자 예시
glob.glob('*.png') # '~.png' 꼴
glob.glob('*.txt') # '~.txt' 꼴

# 특정 이름 예시
glob.glob('2*') # '2~.png' 꼴 *앞에 붙으면 시작글씨를, 뒤에 붙으면 마지막 글씨를 의미
glob.glob('*a*') # '~a~.txt' 꼴 **사이에 들어간 문자는 중간에 낀 문자가 a일 때를 의미
```
<br>

**하위 디렉토리 내 파일/폴더 목록 반환하는 법**
h
<br>

**현재 + 하위 디렉토리의 모든 확장자 파일을 찾는 법**
 `**/*, recursive=True`
<p align="center"><img src="/MYPICS/Language/Python/os/5.png" width = "700" ></p>


[glob 더 자세한 내용]

[glob 더 자세한 내용]:https://docs.python.org/ko/3/library/glob.html#module-glob

## 파일 경로를 객체로 다루기 - pathlib

pathlib은 파일 시스템 경로를 문자열이 아닌 객체로 만들어 여러가지 일을 할 수 있도록 하는 모듈입니다.

파일명 혹은 부모 디렉토리를 알아내거나, 경로 목록을 알아내거나, 파일을 작성하고 삭제하는 등 파일관련된 다양한 처리가 가능해집니다.

기존의 os.path 방식보다 사용하기 편합니다.

to be continue ...