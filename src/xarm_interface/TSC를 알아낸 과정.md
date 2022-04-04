## 상황 

와 Joint Space Control (관절 공간 제어)는 배웠으니까 알겠었는데 Task Sapce Control(작업 공간 제어)는 어떻게 하는 건지 모르겠었다.

전에 했던 test_turtle_mani를 보면서 해봤는데 아니 왜 안 움직이는 건지 이해할 수 없었다.

오류를 검색해봐도 이렇다할 해결방법이 없었다.

- 소숫점 6자리까지 입력하기
- ABORTED: No motion plan found. No execution attempted. 뭐 이런 에러였다.
- gui를 통해서 갈 수 있고 좌표을 얻어서 그 좌표로 했는데 코드로는 안 움직인다는 오류였는데 읽어보니까 알고보니 갈 수 없었다고... 뭐 이런...



그래서 찾아봤다... 징글징글하게 영어도 읽었다.

그래서 찾다가...

https://answers.ros.org/question/341130/moveit-problem-fail-aborted-no-motion-plan-found-no-execution-attempted/



이거 따라했다.



## 차이점 생각 

그 전과 다른 점은 move()로 이동하지 않는다.

- 이유는 모르겠다.

setPoseTarget()을 사용한다. 그 전에는 setPositionTarget()을 사용해서 xyz값만 넣어줬는데 이제는 xyzxyzw를 넣어준다...

그리고 setPoseTarget()을 사용하면서 end_effector_link를 넣어줘야 했는데... 뭘 넣어야 하나 이것저것 해보다가 xarm_ros/xarm_description/urdf/xarm5.urdf.xarco 파일을 보다가 link_eef가 있어서 이거 나는 endeffector쪽의 좌표니까 link_eef eef는 endeffector겠지? 그래서 그 걸 넣어줬다.. 그러니까 작동...





## 주의

부동소수점 생각하고 값을 넣어야 한다.