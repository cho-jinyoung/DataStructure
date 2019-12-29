#include <stdio.h>
#include <string.h>
#include <malloc.h> 
#include "student_info.h"

void deleteNode(struct Node *cur, Node **head, Node **tail){ //head�� tail�� �ּҰ��� �޾ƿ����Ƿ� &�� ��� ��  
	if(cur==*head){			//������ ��尡 ù��° ����� ��� 
		cur = cur->next;
		cur->prev = NULL;
		*head = cur;			 
	}
	else if (cur==*tail){	//������ ��尡 ������ ����� ���	 
		cur = cur->prev;
		cur->next = NULL;
		*tail = cur;
	}
	else{					//������ ��尡 �߰� ����� ���  
		cur->prev->next = cur->next;	//�������� prev �� �� ����� next�� ���� ��� ����
		cur->next->prev = cur->prev;	//�������� next �� ���� ����� prev�� ���� ��� ���� 
	} 
}

int main(){
	int input, n = 0, k = 0, m = 0;
	char line[256], one, two[20];  
	
	FILE *fp = fopen("students_10.txt", "rt");
	while(!feof(fp)){	//�޸� �� �� ����	  
		fgets(line, 256, fp);
		n++;
	}

	rewind(fp);	//������ ó������ �̵� 

	Node *head = NULL;	//ù��° ��� ��ġ 
	Node *cur = NULL;	//���� ��� ��ġ 
	Node *tail = NULL;	//������ ��� ��ġ  
	 
	Node *new_node;	//�߰��� ���   
	Node *node;

	while (!feof(fp)) {
		node = (Node *)malloc(sizeof(Node));
		if (k == 0) {	//ù��° ���� �����ϰ� �����ϱ� ����  
			fgets(line, 256, fp);
			k++;
		}
		else {

			if (head == NULL) {
				fscanf(fp, "%s %c %s %c %s %s\n", node->student_id, &node->department_id, node->department_name, &node->grade, node->name, node->birthday);
				head = node;		//ù��° ���	 
				cur = node;			//���� ���	 
				head->prev = NULL;	//ù��° ��� �տ��� NULL 
			}
			else {
				fscanf(fp, "%s %c %s %c %s %s\n", node->student_id, &node->department_id, node->department_name, &node->grade, node->name, node->birthday);
				cur->next = node;	//���� ��� ����	
				node->prev = cur; 	//node�� ���� ��� �̹Ƿ� ��������� prev�� ���� ��� ����	  
				cur = node;			//���� ���	
				cur->next = tail;	//���� ����� ���� ��忡 tail 
			} 
		}
	}
	tail = cur;		//���� ������ ��带 tail�� ����  
	
	while(1){
		printf("���ϴ� ����� �Է��Ͻÿ�[1-�˻�, 2-�߰�, 3-����, 4-���, 5-����] \n=> ");
		scanf("%d", &input); 
		
		if(input == 1){		//�˻�	 
			printf("�˻��� �ʵ��[1-�й�, 2-�а�, 3-�г�, 4-����, 5-�������]�� �˻�� �Է��ϼ���\n=> ");
			scanf("%d", &one);	
 			scanf("%s", two);
 			
			switch(one){
				case 1:{	//�й� 
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two, cur->student_id)==0)	
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 2:	{	//�а��̸� 
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->department_name)==0)
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 3:{	//�г� 
					for(cur = head;cur!=NULL;cur=cur->next){	 
						if(two[0]==cur->grade)
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 4:{	//�̸� 
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->name)==0)
							printf(">>> \n%s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 5:{	//����
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->birthday)==0)
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
			}
		}
		
		else if (input == 2) {	//�߰�	 
			new_node = (Node *)malloc(sizeof(Node));
			printf("�߰��� �л� ������ �Է��Ͻÿ�[201721380 1 security 2 Cho 1997-07-22]\n=> ");
			scanf("%s %c %s %c %s %s", new_node->student_id, &new_node->department_id, new_node->department_name, &new_node->grade, new_node->name, new_node->birthday);
		
			//���� ��������� �ڿ� ���ο� ��� �߰�  
			new_node -> prev = tail;
  			new_node -> next = tail -> next;	//���� tail->next�� null 
  			tail -> next = new_node;
  			
  			tail = new_node; // ���� ���� ������ ���� new_node�� ��  
  			tail -> next = NULL;
		}
		
		else if (input == 3) {	//����	 			
			printf("������ �ʵ��[1-�й�, 2-�а�, 3-�г�, 4-����, 5-�������]�� �˻�� �Է��Ͻÿ�\n=> ");
			scanf("%d", &one);
			scanf("%s", two);
			
			switch(one){
				case 1:{	//�й� Ȯ��  
					for(cur = head; cur != NULL; cur = cur->next)
						if(strcmp(two, cur->student_id)==0)	// cur=������ ���  
							deleteNode(cur, &head, &tail); //head�� tail�� ���� ���� �����Ǿ�� �ϹǷ� �ּҰ��� ����  
					break;
				}
				case 2:	{	//�а� Ȯ��	 
					for(cur = head; cur != NULL; cur = cur->next)
						if(strcmp(two,cur->department_name)==0)
							deleteNode(cur, &head, &tail); 
					break;
				}
				case 3:{	//�г� Ȯ��  
					for(cur = head; cur != NULL; cur = cur->next)
						if(two[0]==cur->grade)
							deleteNode(cur, &head, &tail); 
					break;
				}
				case 4:{	//���� Ȯ��  
					for(cur = head; cur != NULL; cur = cur->next)
						if(strcmp(two,cur->name)==0)
							deleteNode(cur, &head, &tail); 
					break;
				}
				case 5:{	// ���� Ȯ��  
					for(cur = head; cur != NULL; cur = cur->next)
						if(strcmp(two,cur->birthday)==0)
							deleteNode(cur, &head, &tail); 
					break;
				}
			}
		}		
		else if(input == 4){	//��ü ������ ���	 
			for (cur = head; cur != NULL; cur = cur->next)
				printf("%s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
		}
		else if(input == 5)	break;	//����	 
		else	printf("ERROR\n");
	}
}
