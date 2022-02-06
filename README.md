# lower_bound, upper_bound
 

우선 lower_bound와 upper_bound는 이진 탐색(Binary Search)을 기반으로 탐색하는 함수이다. 

따라서 배열이나 리스트, 벡터 등이 기본적으로 정렬이 되어있어야 하고, 시간복잡도는 O(logn)이다.

기본적으로 이진 탐색은 찾고자 하는 원소가 있는지, 있다면 어디에 위치해 있는지를 찾는다면,

lower_bound와 upper_bound는 이진 탐색을 바탕으로 원소가 어느 부분에 속할 수 있는지를 알려주는 함수이다.   

## lower_bound
* 용도 : 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
* 사용 조건 : 탐색을 진행할 배열 혹은 벡터는 오름차순 정렬되어 있어야 함

## upper_bound
* 용도 : 찾으려는 key 값을 초과하는 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
* 사용 조건 : 탐색을 진행할 배열 혹은 벡터는 오름차순 정렬되어 있어야 함<br>
#
### code example

```c
#include<iostream>
#include<vector>

int main() {

	vector<int> arr = { 1,3,5,5,7,8,8,10,10,11,13 };
	cout << "5 이상 11 이하의 갯수 : " << upper_bound(arr.begin(, arr.end(), 11) - lower_bound(arr.begin(), arr.end(), 5);

	return 0;
}
```
#
# Priority_queue

기본적으로 C++에서 자주 쓰이는 vector와 같은 container adaptor의 한 종류이며 C++에서 int와 같은 기본자료형으로 우선순위 큐를 사용한다면 큐에 있는 모든 원소 중에서 가장 큰 값이 Top을 유지하도록, 우선순위가 가장 크도록 설계되어 있다 또한 우선순위 큐는  내부적으로 Heap이라는 자료구조를 사용하고 있다. 

## basic method

* push() : 우선순위 큐에 원소를 추가한다.
* pop()  : 우선순위 큐에서 top의 원소를 제거한다.
* top()  : 우선순위 큐에서 top에 있는 원소 즉 우선순위가 높은 원소를 반환한다.
* empty() : 우선순위 큐가 비어있으면 true를 반환하고 그렇지 않으면 false를 반환한다.
* size() :  우선순위 큐에 포함되어 있는 원소의 수를 반환한다.
#
### code example

```c
struct cmp{
    bool op()(int a,int b){
        return a > b;
    }
}

priority_queue <int, vector<int>, greater<int> > pq; // min 값이 top
priority_queue <int, vector<int>, cmp > pq; //cmp 라는 비교 연산자를 사용 가능.

```
#

# sort

배열(arr), vector(v)

* sort(arr, arr + n);                                           // 배열에서 사용 (시작점 주소와 마지막 주소 + 1)
* sort(v.begine(), v. end());  [less<자료형>() 생략]    // 오름차순 정렬 (default = Ascending order)
* sort(v.begine(), v. end(), greater<자료형>());        // 내림차순 정렬 (Descending order)
* sort(v.begine(), v. end(), compare);                    // 사용자 정의 함수 compare

```c
// 내림차순 정렬 
std::sort(numbers.begin(), numbers.end(), std::greater<int>());
std::sort(numbers.rbegin(), numbers.rend());
```



