# 스택
* Stack: 가장 나중에 입력된 자료가 가장 나중에 출력되는 선입후출(LIFO:Last Input First Output) 형태의 자료구조
  * Push: 스택에 데이터를 입력하는 연산
  * Pop: 스택의 데이터를 출력하는 연산
  * SP(stack pointer): 스택에 가장 최근에 입력된 데이터를 가리키는 포인터
* 스택의 추상 자료구조
  * sp: 스택 포인터(top)
  * size(): 스택에 포함된 원소의 개수 반환
  * stack(): 원소가 없는 새로운 스택 생성
  * push(S, item): 새로운 원소 item을 스택에 추가
```
if isFull(S)
  then error "stack overflow"
  else top = top + 1
    stack[top] = item
```
 * pop(): 스택포인터가 가리키는 원소를 스택에서 제거
```
if isEmpty(S)
  then error "stack underflow"
  else item = stack[top]
    top = top - 1
    return item
```
 * isEmpty(S): 스택이 비어있는지 여부를 반환
```
//isEmpty
if top == -1
  then return TRUE
  else return FALSE
//isFull
if top == (MAX_STACK_SIZE - 1)
  then return TRUE
  then return FALSE
```
## 연결리스트 기반 스택
* 하나의 요소가 하위에 있는 다른 요소를 가리키도록 링크 구성
* 동적 메모리를 할당하여 스택의 크기를 동적으로 늘릴 수 있기 때문에 크기제한 없이 사용할 수 있지만,
동적 메모리 할당/해제 처리를 위해 연산 처리시간이 늘어날 수 있음 
```
typedef struct StackNode {
  union item{
    int operand;
    char operator;
  }item;
  
  struct StackNode *link;
} StackNode; //스택을 통해 처리하고자 하는 데이터타입

typedef struct {
  StackNode *top;
} LinkedStack; //스택 자체에 대한 데이터 타입
```
* union:공용체, 여러 멤버를 공유하는 하나의 값
 ** 공용체 멤버에 접근시 .사용
 ** malloc함수를 사용하여 공용체 포인터에 메모리 할당 후 멤버에 접근시 -> 사용
 ** struct는 각 멤버들의 메모리 시작 주소가 다르지만 union은 시작주소가 모두 동일
