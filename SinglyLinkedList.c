#include <stdio.h>
#include <malloc.h> 
#include <string.h>
#include "student_info.h"

int main(){
	
	int input, n = 0, i = 0, k = 0, m=0;
	char search[100], add[100], del[100], line[256];
	char one, two[20];
	
	FILE *fp = fopen("students_10.txt", "rt");
	
	while(!feof(fp)){	//�޸� �� �� ����	 
		fgets(line, 256, fp);
		n++;
	}
	rewind(fp);	//������ ó������ �̵� 

	Node *head = NULL;
	Node *cur = NULL;
	Node *pre = NULL;	
	
	Node *new_node = (Node *)malloc(sizeof(Node));
	Node *node;	
	
	while(!feof(fp)){
		node = (Node *)malloc(sizeof(Node));	
		
		if(k==0){	//ù��° ���� �����ϰ� �����ϱ� ����  
			fgets(line, 256, fp);	
			k++;
		}
		else {
			if(head == NULL){
				fscanf(fp,"%s %c %s %c %s %s\n", node->student_id, &node->department_id, node->department_name, &node->grade, node->name, node->birthday);
				head = node;	//ù��° ���	 
				cur = node;		//���� ���	 
			}
			else {
				fscanf(fp,"%s %c %s %c %s %s\n", node->student_id, &node->department_id, node->department_name, &node->grade, node->name, node->birthday);
				cur->next = node; //���� ���� ����	 
				cur = node;	//���� ���	 
			}
		}
	}
	for (cur = head; cur != NULL; cur = cur->next)
		printf("%s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
	
	while(1){
		//Node *list = head;
		printf("���ϴ� ����� �Է��Ͻÿ�[1-�˻�, 2-�߰�, 3-����, 4-���, 5-����] \n=> ");
		scanf("%d", &input); 
		
		if(input == 1){	//�˻�	 
			printf("�˻��� �ʵ�� �Է��ϼ���\n=> ");
			scanf("%d", &one);	
 			scanf("%s", two);
 			
			switch(one){
				case 1:{
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two, cur->student_id)==0)		//�й� Ȯ��  
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 2:	{
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->department_name)==0)	//�а��̸� Ȯ��	 
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 3:{
					for(cur = head;cur!=NULL;cur=cur->next){	 
						if(two[0]==cur->grade)	//�г� Ȯ��	 
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 4:{
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->name)==0)	//�̸� Ȯ��	 
							printf(">>> \n%s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 5:{
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->birthday)==0)	//���� Ȯ��	 
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
			}
		}
		
		else if (input == 2) {	//�߰�	 
			Node *p;
			Node *phead;
			printf("�߰��� �л� ������ �Է��Ͻÿ�[201721380 1 security 2 Cho 1997-07-22]\n=> ");

			for(cur = head; cur != NULL; cur = cur->next){	 
				node->next = new_node;	//������ ���ڿ� ���ο� ��� ����	 
				new_node->next = NULL;	
			}
			scanf("%s %c %s %c %s %s", new_node->student_id, &new_node->department_id, new_node->department_name, &new_node->grade, new_node->name, new_node->birthday);
		}
		
		else if (input == 3) {	//����	 
			
			printf("������ �ʵ��[1-�й�, 2-�а�, 3-�г�, 4-����, 5-�������]�� �˻�� �Է��Ͻÿ�\n=> ");
			scanf("%d", &one);
			scanf("%s", two);
			
			switch(one){
				case 1:{
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two, cur->student_id)==0)
						{
							printf("%s \n",cur->student_id);
							if(cur==head)
							{
								head=cur->next;
								cur=cur->next;
							}
							else
							{
								printf("%s \n",pre->student_id);
								pre->next = cur->next;
							}
						}
						pre=cur;
					}
					break;
				}
				case 2:	{
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->department_name)==0)
							{
							//printf("%s \n",cur->department_name);
							if(cur==head)
							{
								head=cur->next;
								cur=cur->next;
							}
							else
							{
								//printf("%s \n",pre->department_name);
								pre->next = cur->next;
							}
						}
						pre=cur;
					}
					break;
				}
				case 3:{
					for(cur = head;cur!=NULL;cur=cur->next){
						if(two[0]==cur->grade)
						{
							if(cur==head)
							{
								head=cur->next;
								cur=cur->next;
							}
							else
							{
								pre->next = cur->next;
							}
						}
						pre=cur;
					}
					break;
				}
				case 4:{
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->name)==0)
						{
							if(cur==head)
							{
								head=cur->next;
								cur=cur->next;
							}
							else
							{
								pre->next = cur->next;
							}
						}
						pre=cur;
					}
					break;
				}
				case 5:{
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->birthday)==0)
						{
							if(cur==head)
							{
								head=cur->next;
								cur=cur->next;
							}
							else
							{
								pre->next = cur->next;
							}
						}
						pre=cur;
					}
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
