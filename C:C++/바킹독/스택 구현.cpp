// 원소를 담은 큰 배열 한 개와 인덱스를 저장할 변수 하나만 필요

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0; // 다음 원소 삽입 위치 가르킴 -> 스택의 길이와 동일

void push(int x)  // 스택에 x를 추가하는 함수
{
    dat[pos] = x;   // dat[pos++] = x; 와 동일한 값
    pos++;
}

void pop()  // 스택의 꼭대기에 위치한 값을 제거
{
    pos--;
}

int top()  // 스택의 꼭대기에 있는 값을 반환
{
    return dat[pos - 1];
}