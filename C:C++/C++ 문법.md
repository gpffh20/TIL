## C++ 문법
---
>### vector
* 배열과 거의 동일한 기능 수행
* '=' 사용시 deep copy 발생
* C++에서 배열을 선언하려면 크기를 정해줘야하지만 vector는 늘렸다 줄였다 할 수 있다.
* 함수의 인자로 사용할 시 복사본을 이용하는 개념이기 때문에 원본에 영향 주지 않는다.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  vector<int> v1(3, 5); // {5,5,5};
  cout << v1.size() << '\n'; // 3
  v1.push_back(7); // {5,5,5,7};

  vector<int> v2(2); // {0,0};
  v2.insert(v2.begin()+1, 3); // {0,3,0};

  vector<int> v3 = {1,2,3,4}; // {1,2,3,4}
  v3.erase(v3.begin()+2); // {1,2,4};

  vector<int> v4; // {}
  v4 = v3; // {1,2,4}
  cout << v4[0] << v4[1] << v4[2] << '\n';
  v4.pop_back(); // {1,2}
  v4.clear(); // {}
}
```
* vector에 있는 모든 원소 순회
```cpp
vector<int> v1 = {1, 2, 3, 4, 5, 6};

// 1. range-based for loop
for(int e : v1) // e에 v1원소 하나씩 들어가는 for문
  cout << e << ' ';
for(int &e : v1) // 원본 수정 시에는 이렇게 써야함

// 2. for
for(int i = 0; i < v1.size(); i++)
  cout << v1[i] << ' ';
```
>### -auto
* '타입추론', '초기화 값에 따라 알아서 데이터 타입을 정해주는 키워드' 라고도 불린다.
* auto 키워드는 선언한 변수나 람다식의 타입을 컴파일러에게 추론하도록 맡깁니다.
```cpp
//변수 선언
auto a1 = 10;   // int 타입
auto a2 = 10.0f;  // float 타입
auto a3 = "c";  // char 타입
auto a4 = "BlockDMask"; // string 타입
auto a5 = {10, 20, 30};  //int 배열 타입
```

* for는 m의 각 원소에 대해 첫번째부터 마지막 원소까지 복사본을 v에 저장한뒤에 출력 한다는 의미이다.
* 복사본을 따로 저장하고 싶지 않으면 &로 참조만 하면 됨
```cpp

for (auto v : m ) printf("%d\n", v->first);
// for(a : b)는 자료형 관계 없이 같은 기능을 함.
for (auto& v : arr
 ```
>### -string
[관련 블로그](https://rebro.kr/53)

>### -iterator(반복자)
* 포인터와 거의 비슷하게 동작
* .begin() : 순차열의 시작
* .end() : 순차열의 끝

>### 공백이 포함 된 문자열 출력
* getline 함수 이용
    * c++ string 형태의 자료에만 사용가능
    ```cpp
    string s;
    getline(cin, s);
    cout << s;
    ```
>### 네임스페이스
* C++에서는 변수, 함수, 구조체, 클래스 등을 서로 구분하기 위해서 이름으로 사용되는 다양한 내부 식별자(identifier)를 가지고 있다. 하지만 프로그램이 커지면 내부 식별자 간에 충돌할 수 있다. 이러한 이름 충돌 문제를 C++에서는 네임스페이스(namespace)를 통해 해결하고 있다.

>### bool
* boolean을 의미
* 값으로 true와 false만 가짐
* flag와 유사하다고 생각하면 편할 듯
```cpp
bool tr = true; // 1
bool fa = false;  // 0
```
>### 구조체
* 하나 이상의 변수를 그룹 지어서 새로운 자료형을 정의
* 더미 노드란, 데이터 저장을 위한 노드가 아니라 노드의 추가/삭제 구현의 간편성을 위해 사용하는 노드이다. 실제 데이터를 저장하는 다른 노드를 가리키는 포인터의 역할만을 수행한다
```cpp
struct Employee   // Employee라는 구조체 형성
{
  short id;
  int age;
  double wage;

  Emloyee joe{1, 32, 6000.0};   // 초기화

  Employee joe;   //변수 joe는 Employee타입.
  joe.id = 14;
  joe.age = 32;
  joe.wage = 24.15;
}
```
>### STL List
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  list<int> L = {1,2}; // 1 2
  list<int>::iterator t = L.begin(); // t는 1을 가리키는 중, iterator가 번지 역할을 함, iterator t 대신 auto t 사용 가능
  L.push_front(10); // 10 1 2
  cout << *t << '\n'; // t가 가리키는 값 = 1을 출력
  L.push_back(5); // 10 1 2 5
  L.insert(t, 6); // t가 가리키는 곳 앞에 6을 삽입, 10 6 1 2 5
  t++; // t를 1칸 앞으로 전진, 현재 t가 가리키는 값은 2
  t = L.erase(t); // t가 가리키는 값을 제거, 그 다음 원소인 5의 위치를 반환
                  // 10 6 1 5, t가 가리키는 값은 5
  cout << *t << '\n'; // 5
  for(auto i : L) cout << i << ' ';
  cout << '\n';
}
```
>### 삼항연산자
```cpp
res = (A < B) ? A : B;

if(A < B)
  res = A;
else
  res = B;

// 두 식의 결과는 같다
```
>### size_t형
* unsigned int와 같다
* typedef unsigned int size_t;가 풀네임이다
* size_t는 32비트 운영체제에서 "부호 없는 32비트 정수", 64비트 운영체제에서 "부호없는 64비트 정수"다
* unsigned int는 64비트 운영체제에서 여전히 32비트 일 수 있다
* 메모리나 문자열 등의 길이를 구할 때에는 size_t형으로 반환된다

>### 스택
* 한 쪽 끝에서만 원소를 넣고 뺄 수 있는 자료구조.
* 프링글스 통 같음(LIFO)
* 제일 상단이 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능
* 원소의 추가/제거, 제일 상단 원소 확인만 가능
* STL stack
  ```cpp
  #include <bits/stdc++.h>
  using namespace std;

  int main(void) {
  stack<int> S;
  S.push(10); // 10
  S.push(20); // 10 20
  S.push(30); // 10 20 30
  cout << S.size() << '\n'; // 3
  if(S.empty()) cout << "S is empty\n";
  else cout << "S is not empty\n"; // S is not empty
  S.pop(); // 10 20
  cout << S.top() << '\n'; // 20
  S.pop(); // 10
  cout << S.top() << '\n'; // 10
  S.pop(); // empty
  if(S.empty()) cout << "S is empty\n"; // S is empty
  cout << S.top() << '\n'; // runtime error 발생
  // 스택이 비어있는데 top, pop 호출하면 runtime error 발생
  }
  ```
  >### pair
  * 한 번에 두개의 자료형을 갖는 클래스
  * 헤더파일 #include <utility>
  * .first, .second 로 구분
  ```cpp
  // pair 사용했던 문제 예시
  #include <bits/stdc++.h>
  using namespace std;

  int main()
  {
      ios::sync_with_stdio(0);
      cin.tie(0);

      int n, height;
      stack <pair<int, int>> top;
      string ans;
      cin >> n;
      top.push({0, 100000001});    // 0출력 할 때 예외처리를 미리해줌
    
      for(int i = 1; i <= n; i++)
      {
          cin >> height;
          while(top.top().second < height)
              top.pop();
          cout << top.top().first << " ";
          top.push({i, height});
      }
  }
  ```

  >### 큐
  * 한 쪽 끝에서 자료를 넣고, 반대쪽 끝에서 자료를 뺄 수 있는 구조(FIFO)
  * 원소가 추가되는 곳: rear
  * 원소가 제거되는 곳: front
  * 인덱스로 내부 원소에 접근 불가
  ```cpp
  // SQL queue 이용
  #include <bits/stdc++.h>
  using namespace std;

  int main(void) {
    queue<int> Q;
    Q.push(10); // 10
    Q.push(20); // 10 20
    Q.push(30); // 10 20 30
    cout << Q.size() << '\n'; // 3
    if(Q.empty()) cout << "Q is empty\n";
    else cout << "Q is not empty\n"; // Q is not empty
    Q.pop(); // 20 30
    cout << Q.front() << '\n'; // 20
    cout << Q.back() << '\n'; // 30
    Q.push(40); // 20 30 40
    Q.pop(); // 30 40
    cout << Q.front() << '\n'; // 30
  }
  // 큐가 비어있는데 front, back, pop을 호출하면 런타임 에러남
  ```

>### 덱
* 양쪽 끝에서 삽입과 삭제가 전부 가능
* STL deque에서는 인덱스로 원소에 접근 가능
```cpp
// 배열을 이용한 구현
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];  // 양쪽으로 확장해야하기 때문에 초기값이 중간이어야함
int head = MX, tail = MX;

void push_front(int x)
  dat[--head] = x;

void push_back(int x)
  dat[tail++] = x;

void pop_front()
  head++;

void pop_back()
  tail++;

int front()
  return dat[head];

int back()
  return dat[tail - 1];
```
<br/>

```cpp
// STL deque 이용, vector와 비슷한 면이 있지만 메모리상 구조가 다름
#include <bits/stdc++.h>
using namespace std;

int main(void){
  deque<int> DQ;
  DQ.push_front(10); // 10
  DQ.push_back(50); // 10 50
  DQ.push_front(24); // 24 10 50
  for(auto x : DQ)cout<<x;
  cout << DQ.size() << '\n'; // 3
  if(DQ.empty()) cout << "DQ is empty\n";
  else cout << "DQ is not empty\n"; // DQ is not empty
  DQ.pop_front(); // 10 50
  DQ.pop_back(); // 10
  cout << DQ.back() << '\n'; // 10
  DQ.push_back(72); // 10 72
  cout << DQ.front() << '\n'; // 10
  DQ.push_back(12); // 10 72 12
  DQ[2] = 17; // 10 72 17
  DQ.insert(DQ.begin()+1, 33); // 10 33 72 17
  DQ.insert(DQ.begin()+4, 60); // 10 33 72 17 60
  for(auto x : DQ) cout << x << ' ';
  cout << '\n';
  DQ.erase(DQ.begin()+3); // 10 33 72 60
  cout << DQ[3] << '\n'; // 60
  DQ.clear(); // DQ의 모든 원소 제거
  DQ.at(2) // 인덱스가 2인 원소
}
```

<br/><br>

>## 함수
### -memset
* 메모리의 내용을 원하는 크기만큼 특정 값으로 세팅할 수 있는 함수
* 헤더: memory.h 또는 string.h
* 오류날 가능성이 많아 추천은 안함
```cpp
memset(void* ptr, int value, size_t num);
// void* ptr은 메모리의 시작 주소
// value는 세팅하고자 하는 값, 문자 넣어도 상관없음.
// 길이, sizeof(객체)로 많이 씀.
int a[21];
memset(a, 0, sizeof a);
```
### -fill
* 메모리의 내용을 원하는 크기만큼 특정 값으로 세팅할 수 있는 함수
* 헤더: algorithm
```cpp
void fill(ForwardIterator first, ForwardIterator last, contT&val);
// first는 채우고자 하는 자료구조 시작위치 iterator
// last는 채우고자 하는 자료구조 끝 위치, last는 불포함
// val은 first부터 last전까지 채우고자 하는 값
int a[21];
int b[21][21];  // 2차원 배열
fill(a, a+21, 0);
for(int i = 0; i < 21; i++)
  fill(b[i], b[i]+21, 0);
```

### -cin/cout
* 사용 방법
    ```cpp
    #include <iostream>
    cout << "Hello";
    cin >> num;
    ```
* 주의할 점
  * 시간초과 막아야함
    * C stream과 C++ stream은 동기화 되어있다. 따라서 scanf/printf와 cin/cout을 같이 쓴다면 동기화가 되어야하지만 하나만 쓴다면 굳이 동기화를 시켜 시간을 오래걸리게 할 필요가 없다.
    ```cpp
    ios::sync_with_stdio(0);
    cout << ..
    cin >> ..
    ```
  * 버퍼로 인한 출력 순서 꼬임
    * 버퍼는 입력이나 출력을 할 때 컴퓨터가 이용하는 임시 공간이라고 할 수 있는데 버퍼에 어느정도 모여야 출력시키기 때문에 순서가 꼬일 수 있다. 이걸 방지하기 위해 cin 명령 전에 cout 버퍼를 비워준다.
    * 하지만 채점할 때는 출력값만 맞으면 돼서 굳이 버퍼를 비우지 않게 해준다.
    ```cpp
    cin.tie(0);
    ```
### -min/max
```cpp
// a, b중 작은거 출력
min(a, b);
min({a, b, c, d});
// a, b중 큰거 출력
max(a, b);
max({a, b, c, d});
```
### -sort
```cpp
#include <algorithm>
// 오름차순 정렬
int arr[5] = {5, 2, 1, 9, 3};
sort(arr, arr + 5);

//내림차순 정렬
bool compare(int a, int b)
{
  return a > b;
}
 int main()
 {
  int arr[5] = {5, 2, 1, 9, 3};
  sort(arr, arr + 5, compare);
 }
 ```

 ### -swap
 ```cpp
 swap(a, b);  // a와 b의 값 swap
 swap(arr[a], arr[a+10]); // arr배열의 a변째 인덱스 부터 a+10 인덱스 까지 swap
 ```
### -abs
* 절댓값
```cpp
abs(-100);
100
```

### scanf/prinf
```cpp
#include <stdio.h>
int num1, num2;
scanf("%d", "%d", &num1, &num2);
printf("%d, "%d", num1, num2);
```

### find
* find(객체 시작, 객체 끝, 찾을 데이터);
* 입력한 데이터와 일치하는 원소의 반복자를 내놓음
```cpp
list<int> L;
find(L.begin(), L.end(), 3);
// 리스트 안에서 3의 반복자를 출력
```

### atoi
* 문자열을 정수로 변환
```cpp
string num = "2019"
num = atoi(num); // "2019"가 2019로 변환 됨
```