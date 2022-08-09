---
title : "Math Processing Error: Extra close brace or missing open brace 해결방법"
categories :
    - GitBlog
tag :
    - [GithubePage, GitBlog, Gitpage error]
toc : true
toc_sticky: true 
comments: true
sidebar_main: true
use_math: true
---

# Math Processing Error: Extra close brace or missing open brace
## 오류가 뜨는 원인
<br>
<br>

순조롭게 블로그 포스팅중에 git push 까지하고 글 확인을 하니 갑자기 이런 오류가 발생하였습니다.

<p align="center"><img src="/MYPICS/GitBlog/matherror/error.png" width = "400" ></p>

처음에 뭐지 무슨 오류지 싶어서 구글링을 했는데도 썩 잘 나오지 않아서, 아예 포스팅을 해보려합니다.

**brace가 없거나 추가됐다는 말이라서 오류가 났던 수식이 어디였는지부터 파악하였습니다.**

<p align="center"><img src="/MYPICS/GitBlog/matherror/1.png" width = "600" ></p>

<p align="center"><img src="/MYPICS/GitBlog/matherror/2.png" width = "600" ></p>

이제 어디가 문제인지 살펴보겠습니다.

<p align="center"><img src="/MYPICS/GitBlog/matherror/3.jpg" width = "600" ></p>

처음에는 수식 사이에 엔터를 쳐서 문제인가 싶어서 위쪽 식만 붙여서 다시 git push를 해보았으나 오류가 두 부분 똑같이 다시 발생하는 것을 발견하였습니다.

엔터는 문제가 아닙니다.

## 해결방법

**그래서 제가 썼던 수식을 자세히 들여다보니 저렇게 제가 표시한 네 부분에 {} 가 하나씩 더 들어간 것을 볼 수 있었습니다.**

그리고 오류가 나던 당시의 화면을 보면, 오류창이 총 4번 뜨는 것을 보실 수가 있습니다.

<video width="100%" height="100%" controls="controls">
  <source src="/MYPICS/GitBlog/matherror/error.mp4" type="video/mp4">
</video>

이걸 보고 확신했습니다 아 저게 문제구나. 그렇게 {} 를 지워주고 git push 했더니 오류가 사라졌습니다.

<p align="center"><img src="/MYPICS/GitBlog/matherror/4.png" width = "600" ></p>

수식을 많이 사용하시는 분들에게 도움이 되었으면 좋겠습니다~