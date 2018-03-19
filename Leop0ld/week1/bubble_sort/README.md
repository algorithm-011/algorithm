# 버블 정렬(Bubble Sort)

버블 정렬은 맨 처음에 위치한 데이터부터 시작하여 해당 값과 바로 뒤에 있는 값을 비교하여 큰 값을 뒤로 보낸다.

이렇게 한번 처음부터 끝까지 돌면 맨 마지막 인덱스의 값이 가장 큰 값이 되므로 픽스한다.

똑같이 돌면서 스왑하되, 맨 마지막 인덱스를 하나씩 줄여가면서 실행하면 된다.

## 시간 복잡도
- O(n<sup>2</sup>)