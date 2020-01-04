#include "calculator.h"

LinkedStack *calculator;	//���Ḯ��Ʈ ���������� ����

void init_stack(void) {		//���� ���� �Լ� 
	calculator = (LinkedStack *)malloc(sizeof(LinkedStack));
	calculator->top = NULL;
}
int is_empty(void) {	//������ ������� Ȯ���ϴ� �Լ�	 
	if (calculator->top == NULL)
		return 1;
	else return 0;
}
int push(StackNode *new_node) {		//������ �״� �Լ�  
	new_node->link = calculator->top;
	calculator->top = new_node;
}
StackNode *pop(void) {	//������ �����ϴ� �Լ�  
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
	char input[100];	//����� ���� �Է�  
	int i = 0, number[100], j = 0, len, pre = 0, k = 0, co = 0, ii, result, op_num = 0;
	int n1, n2;	//pop�� ���� ���� 
	char op;	//pop�� �����ȣ ����

	StackNode *num_node;	//���� ���� ���  
	StackNode *op_node;	//�����ȣ ���� ���	

	init_stack();	//���� ���� �Լ�

	printf("	<<����>>\n");
	printf("input: ");
	gets(input);

	len = strlen(input);	//���ڿ� ���� 
	
	for (i = 0; i < len; i++) {
		if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*') {	// + , - , * , / ����
			op_node = (StackNode *)malloc(sizeof(StackNode));	//�����Ҵ�

			op_node->item.operator = input[i];	//��彺�ÿ� �ֱ�
			push(op_node);	//���ÿ� �ױ�

			if (input[i] == '/' || input[i] == '*')	// * ,/ ������ ��� ���� ����ؾ� ��
				pre++;	//���� ����� ������ ������  
			else op_num++;	//���߿� ������ Ƚ��
		}
		else	//����  
		{
			num_node = (StackNode *)malloc(sizeof(StackNode));
			num_node->item.operand = atoi(&input[i]);

			k = num_node->item.operand;

			co = 0;
			while (k) {		//���ڰ� ���ڸ��� �̻��� ���
				k = k / 10;
				co++;	//������ �ڸ���
			}
			i = i + co - 1;
			push(num_node);

			if (pre == 1) {	//���� ����� ����(*,/)�� ������  
				n1 = pop()->item.operand;	//�� ���� ���� ���� ����, �� ����
				op = pop()->item.operator;	//�ι�° ���� ����, �� ������
				n2 = pop()->item.operand;	//����° ���� ����, �� ����

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
