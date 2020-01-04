#include "calculator.h"

LinkedStack *calculator;	//연결리스트 전역변수로 선언

void init_stack(void) {		//스택 생성 함수 
	calculator = (LinkedStack *)malloc(sizeof(LinkedStack));
	calculator->top = NULL;
}
int is_empty(void) {	//스택이 비었는지 확인하는 함수	 
	if (calculator->top == NULL)
		return 1;
	else return 0;
}
int push(StackNode *new_node) {		//스택을 쌓는 함수  
	new_node->link = calculator->top;
	calculator->top = new_node;
}
StackNode *pop(void) {	//스택을 제거하는 함수  
	StackNode *node1;

	if (calculator->top == NULL)
		return NULL;
	else {
		node1 = calculator->top;
		calculator->top = calculator->top->link;
		return node1;
	}
}
int main() {
	char input[100];	//계산할 내용 입력  
	int i = 0, number[100], j = 0, len, pre = 0, k = 0, co = 0, ii, result, op_num = 0;
	int n1, n2;	//pop한 숫자 저장 
	char op;	//pop한 연산기호 저장

	StackNode *num_node;	//숫자 저장 노드  
	StackNode *op_node;	//연산기호 저장 노드	

	init_stack();	//스택 생성 함수

	printf("	<<계산기>>\n");
	printf("input: ");
	gets(input);

	len = strlen(input);	//문자열 길이 
	
	for (i = 0; i < len; i++) {
		if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*') {	// + , - , * , / 연산
			op_node = (StackNode *)malloc(sizeof(StackNode));	//동적할당

			op_node->item.operator = input[i];	//노드스택에 넣기
			push(op_node);	//스택에 쌓기

			if (input[i] == '/' || input[i] == '*')	// * ,/ 연산일 경우 먼저 계산해야 함
				pre++;	//먼저 계산할 연산이 존재함  
			else op_num++;	//나중에 연산할 횟수
		}
		else	//숫자  
		{
			num_node = (StackNode *)malloc(sizeof(StackNode));
			num_node->item.operand = atoi(&input[i]);

			k = num_node->item.operand;

			co = 0;
			while (k) {		//숫자가 두자리수 이상일 경우
				k = k / 10;
				co++;	//숫자의 자릿수
			}
			i = i + co - 1;
			push(num_node);

			if (pre == 1) {	//먼저 계산할 연산(*,/)이 존재함  
				n1 = pop()->item.operand;	//맨 위에 쌓인 스택 제거, 즉 숫자
				op = pop()->item.operator;	//두번째 스택 제거, 즉 연산자
				n2 = pop()->item.operand;	//세번째 스택 제거, 즉 숫자

				if (op == '*')
					result = n2 * n1;
				else if (op == '/')
					result = n2 / n1;

				num_node = (StackNode *)malloc(sizeof(StackNode));
				num_node->item.operand = result;
				push(num_node);
				pre = 0;
			}
		}
	}
	for (i = 0; i < op_num; i++) {
		n1 = pop()->item.operand;
		op = pop()->item.operator;
		n2 = pop()->item.operand;

		if (op == '+')
			result = n2 + n1;
		else if (op == '-')
			result = n2 - n1;

		num_node = (StackNode *)malloc(sizeof(StackNode));
		num_node->item.operand = result;
		push(num_node);
	}
	printf("<<result = %d>>", result);
	getch();
}
