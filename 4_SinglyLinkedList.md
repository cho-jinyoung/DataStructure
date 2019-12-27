# 단일 연결 리스트(Singly Linked List)

배경지식
* 리스트: 배열과 유사하게 동일한 유형의 자료를 나열하기 위한 추상 데이터 구조(ADT)
* Node: 리스트에서 사용될 데이터 타입, node에는 다음 데이터를 가리키기 위한 포인터가 구성됨
* 시작노드 이전엔 head pointer가 시작노드를 가리키고 있고, 마지막노드는 null을 가리킴
* 추가시 동적으로 메모리를 할당(malloc사용)받아 노드 생성
```c
// 새로운 노드 생성
Node *s1;
s1=(Node *)malloc(sizeof(Node));
```
## 단일 연결 리스트 기반 성적처리 프로그램

```c
// sudent_id를 포함한 Node구조체
typedef struct Node{
  unsigned int student_id;
  unsigned int kor;
  unsigned int eng;
  unsigned int math;
  struct Node *next;    // 다음 노드를 가리키는 포인터, 구조체와 같은 type으로 선언
} Node;
```
 student_id 기준 오름차순으로 새로운 노드 추가를 위한 insert_node함수, 
 리스트의 시작위치와 삽입할 노드를 인자로 전달
```c
// #1
void insert_node(Node **head, Node *new_node) { 
  Node *p = NULL;
  Node *prev = NULL;    // p이전 노드
  if (*head == NULL) {  // 빈 리스트인 경우, head의 next가 new_node가리킴
    new_node -> next = NULL;
    *head = new_node;
    return;
  } else {  //리스트 존재, head가 가리키는 노드 존재
    for(p=*head, prev=p; p!=null; p=p->next) {
      if(p==*head && new_node->student_id < p->student_id) {
        *head = new_node;
        new_node->next = p;
        return;
      }
      else if(p!=head && new_node->student_id < p->student_id) {
        prev->next = new_node;
        new_node->next = p;
      }
      else if(new_node->student_id > p->student_id && p->next==null) {
        p->next = new_node;
        new_node->next = NULL;
      }
    }
  }  
}
```
```c
// #2
void insert_node(Node **head, Node *new_node) {
  Node *p = NULL;
  Node *prev = NULL;    // p이전 노드
  if (*head == NULL) {  // 빈 리스트인 경우, head의 next가 new_node가리킴
    new_node -> next = NULL;
    *head = new_node;
    return;
  }
  //리스트 존재, head가 가리키는 노드 존재
  p = *head;
  while(p != NULL){
      if(p->next < new_node->student_id){ //들어갈 위치 찾기
        prev = p;
        p = p->next;
      }
      else{
        //첫번째 노드 자리
        if(prev==NULL)
          *head = new_node;
        //중간 노드 자리
        else
          prev->next = new_node;
        new_node->next = p;
        return;
      }
  }
  //마지막 노드 자리
  p->next = new_node;
  new_node->next = NULL;
}
```
