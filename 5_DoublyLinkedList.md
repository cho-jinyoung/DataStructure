# 이중 연결 리스트(Doubly Linked List)

- 하나의 노드가 다음 노드를 가리키는 하나의 포인터 변수를 가지는 단일 연결 리스트와 달리 이전 노드를 가리키는 포인터 변수를 추가로 가짐
```c
//이중 연결 리스트 초기화 함수
void init() {
  head = (struct Node *)malloc(sizeof(struct Node));  //첫번째 노드
  tail = (struct Node *)malloc(sizeof(struct Node));  //마지막 노드
  
  head -> next = tail;
  head -> prev = NULL;
  
  tail -> next = NULL;
  tail -> prev = head;
}
```
```c
//새로운 노드 삽입 함수
//prev_node = 새로운 노드 삽입 위치 이전 노드, new_node = 삽입할 새로운 노드 
void insertNode(struct Node *prev_node, struct Node *new_node) {  
  new_node -> prev = prev_node;
  new_node -> next = prev_node -> next;
  prev_node -> next = new_node;
  prev_node -> next -> prev = new_node;
}
```
```c
//노드 삭제 함수
//cur = 삭제할 노드
void deleteNode(struct Node *cur, Node **head, Node **tail){ //head와 tail은 주소값을 받아왔으므로 &를 써야 함  
	if(cur==*head){			//삭제할 노드가 첫번째 노드인 경우 
		cur = cur->next;
		cur->prev = NULL;
		*head = cur;			 
	}
	else if (cur==*tail){	//삭제할 노드가 마지막 노드인 경우	 
		cur = cur->prev;
		cur->next = NULL;
		*tail = cur;
	}
	else{					//삭제할 노드가 중간 노드인 경우  
		cur->prev->next = cur->next;	//현재노드의 prev 즉 전 노드의 next에 다음 노드 연결
		cur->next->prev = cur->prev;	//현재노드의 next 즉 다음 노드의 prev에 이전 노드 연결 
	} 
}
```
## 이중 연결 리스트 기반 성적처리 프로그램

