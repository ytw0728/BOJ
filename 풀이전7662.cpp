// map 을 이용하여 풀면 언제나 정렬이 되어있기 때문에 파라메트릭보다 빠름.
// multi_set 을 쓰면 더 간단.
// 우선순위 큐를 2개 써서 할 경우 ( 최대 정렬, 최소정렬) -> check 배열을 만들어 어떤 값을 뺐고 어떤 값을 빼지 않았는지를 확인하여 pop해준다.

// index tree 나 segment tree 를 이용해 풀 수도 있다. min tree 와 max tree를 두개 만들어서 각 트리의 max를 찾아 두 트리에서 모두 뺀다.