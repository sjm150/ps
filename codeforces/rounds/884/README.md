### RECALL
#### B
가장 작은 소수가 primality가 되므로\
전체에서 가장 작은 두 소수인 2, 3 만 양끝에 가면 나머지 소수는 아예 무관하다.
#### C
홀수 인덱스와 짝수 인덱스의 요소들은 서로에게 어떠한 영향도 미치지 못한다.\
pf (\
case1: 가장 왼쪽 삭제시, 홀수 -> 짝수, 짝수 -> 홀수로 set이 변함 (서로 섞이지 않는다)\
case2: 가장 오른쪽 삭제시, 그대로 유지\
case3: 양 끝이 아닌 임의 인덱스 요소 삭제시 바로 양옆은 충돌\
-> 이 3개 기준으로 왼쪽인 요소들은 그대로 유지,\
오른쪽인 요소들은 인덱스가 2씩 줄어드는 영향을 받으므로 마찬가지로 홀짝 여부는 유지\
)\
따라서 홀수 or 짝수 인덱스 요소 집합 중 음수인 것들을 전부 제거하고 그 반대 집합의 요소를 전부 제거하면\
최종 남는 하나는 해당 집합의 음이 아닌 정수의 합이다.
#### E
4번째 case의 답이 NO인 이유는 (주석처리한 예제) 해당 case를 직접그려보면 알 수 있듯\
1번째 2x2 cell grid의 첫번째 row가 결정되면 다른 모든 row들은\
반드시 그것과 같거나 정반대인 패턴만 가능하게 되기 때문이다.\
따라서 모든 subgrid row를 만족하는 패턴이 존재하는지를 구하는 방향으로 풀이 필요.
