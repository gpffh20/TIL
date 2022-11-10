## Linked List(연결리스트)란?
* 동적할당으로 데이터를 저장하는 방법
* 다음에 올 값의 주소를 가지고 있음
* 임의의 값을 삽입, 수정, 삭제하기에 좋음

<br>

>### 정석구현(구조체 사용)
```cpp
// STL list는 doubly linked list이기 때문에 그냥 가져다 활용하면 된다.

#include <bits/stdc++.h>

struct node
{
    node* next; // 다음 주소를 가르킴
    node* last; // 마지막 주소를 가르킴
    int data;
}

node* init(node* tmp)
{
	tmp = new node();
	tmp->next = NULL;
	tmp->last = NULL;
	tmp->data = 0;
	return tmp;
}

node* insert(node* head, int data)
{
	if (head == NULL)
    { // 첫 삽입인 경우
		head = init(head);
		head->data = data;
		head->last = head;
		return head;
	}
	node* cur_node = head->last;

	node* new_node = NULL;
	new_node = init(new_node);
	cur_node->next = new_node;
	new_node->data = data;
	head->last = new_node;
	return head;
}

int getData(node* head, int index)
{
	node* cur_node = head;
	for (int i = 0; i < index && cur_node != NULL; i++)
		cur_node = cur_node->next;
	if (cur_node == NULL)
		return -1; // 범위를 넘어감

	return cur_node->data;
}
int count(node* head, int data)
{ // 연결 리스트에서 data의 값이 몇개 있는지 
	int _cnt = 0;
	node* cur_node = head;
	while (cur_node->next != NULL)
    { // 마지막 노드를 찾음
		if (cur_node->data == data)
			_cnt += 1;
		cur_node = cur_node->next;
	}
	return _cnt;
}

node* remove(node* head, int index)
{ // index 번째 위치한 노드 삭제
	node* cur_node = head;
	node* pre_node = NULL; // 삭제하려는 노드의 앞에 위치한 노드
	for(int i = 0 ; i <index && cur_node != NULL ; i ++)
    {
		pre_node = cur_node;
		cur_node = cur_node->next;
	}
	if (cur_node == NULL) // 인덱스가 연결리스트 사이즈보다 큰경우
		return head;

	if (pre_node == NULL)
    {  // 루트 노드를 삭제하려고 하면
		head->next->last = head->last;
		head = head->next;
		return head;
	}
	if (cur_node->next == NULL) //마지막 노드를 삭제하려고 하면
		head->last = pre_node; // 마지막 노드를 앞의 노드로 재 설정

	pre_node->next = cur_node->next;
	return head;
}

void print(node* cur_node)
{
	while (cur_node != NULL)
    {
		cout << cur_node->data << " ";
		cur_node = cur_node->next;
	}
	cout << "\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	node* list = NULL;
	list = insert(list, 1);
	list = insert(list, 2);
	list = insert(list, 3);
	list = insert(list, 4);
	list = insert(list, 3);
	list = insert(list, 2);
	list = insert(list, 1);
	print(list);


	cout << "3의 개수 : " << count(list, 3) << "개\n";

	list = remove(list, 0);
	print(list);

	list = remove(list, 3);
	print(list);

	cout << "3의 개수 : " << count(list, 3) << "개\n";

	list = remove(list, 4); // 마지막 노드 삭제
	print(list);

	list = insert(list, 5);
	print(list);
}
```

>### 배열 사용 구현
* 메모리 누수 문제때문에 실무에서는 사용 불가능하지만 코테에서는 사용 가능
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1; // 새로운 원소가 들어갈 수 있는 인덱스, 원소가 추가될 때 마다 1씩 증가

// 연결 리스트의 0번지는 시작원소로 고정. 실제 값이 있는 것이 아닌 예외처리를 하지 않기 위한 더미노드
void insert(int addr, int num)
{   // addr은 배열 상에서 몇 번지에 있는지를 의미
  dat[unused] = num;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];
  if(nxt[addr] != -1)   // 맨 마지막 원소 뒤에 새 원소 추가할 때 -1에 접근하지 않게 하기 위함
    pre[nxt[addr]] = unused;
  nxt[addr] = unused;
  unused++;
}

void erase(int addr)
{
  nxt[pre[addr]] = nxt[addr];
  if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse()
{
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test()
{
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void)
{
  fill(pre, pre+MX, -1);    // 해당 원소의 이전 원소가 존재하지 않음을 판별
  fill(nxt, nxt+MX, -1);    // 해당 원소의 다음 원소가 존재하지 않음을 판별
  insert_test();
  erase_test();
}
```

>### 손코딩 문제
* Q1. 원형 연결 리스트 내의 임의의 노드 하나가 주어졌을 때 해당 List의 길이를 효율적으로 구하는 방법?
* Q2. 중간에 만나는 두 연결 리스트의 시작점들이 주어졌을 때 만나는 지점을 구하는 방법?
* Q3. 주어진 연결리스트 안에 사이클이 있는지 판단하라

<br>

>### 정답
* A1. 동일한 노드가 나올 때 까지 계속 다음 노드로 가면 됨, 공간복잡도 O(1), 시간복잡도 O(N)
* A2. 일단 두 시작점 각각에 대해 끝까지 진ㄴ행시켜서 각각의 길이를 구함. 그 후 다시 두 시작점으로 돌아와서 더 긴 쪽을 둘의 차이만큼 앞으로 먼저 이동시켜놓고 두 시작점이 만날 때 까지 두 시작점을 동시에 한 칸씩 전진시키면 됨. 공간복잡도 O(1), 시간복잡도 O(A+B).
* A3. Floyd's cycle-finding algorithm 이용해서 해결 가능. 공간복잡도 O(1), 시간복잡도 O(N)