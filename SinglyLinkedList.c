#include <stdio.h>
#include <malloc.h> 
#include <string.h>
#include "student_info.h"

int main(){
	
	int input, n = 0, i = 0, k = 0, m=0;
	char search[100], add[100], del[100], line[256];
	char one, two[20];
	
	FILE *fp = fopen("students_10.txt", "rt");
	
	while(!feof(fp)){	//메모리 줄 수 세기	 
		fgets(line, 256, fp);
		n++;
	}
	rewind(fp);	//파일의 처음으로 이동 

	Node *head = NULL;
	Node *cur = NULL;
	Node *pre = NULL;	
	
	Node *new_node = (Node *)malloc(sizeof(Node));
	Node *node;	
	
	while(!feof(fp)){
		node = (Node *)malloc(sizeof(Node));	
		
		if(k==0){	//첫번째 줄을 제외하고 저장하기 위함  
			fgets(line, 256, fp);	
			k++;
		}
		else {
			if(head == NULL){
				fscanf(fp,"%s %c %s %c %s %s\n", node->student_id, &node->department_id, node->department_name, &node->grade, node->name, node->birthday);
				head = node;	//첫번째 노드	 
				cur = node;		//현재 노드	 
			}
			else {
				fscanf(fp,"%s %c %s %c %s %s\n", node->student_id, &node->department_id, node->department_name, &node->grade, node->name, node->birthday);
				cur->next = node; //다음 노드와 연결	 
				cur = node;	//현재 노드	 
			}
		}
	}
	for (cur = head; cur != NULL; cur = cur->next)
		printf("%s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
	
	while(1){
		//Node *list = head;
		printf("원하는 기능을 입력하시오[1-검색, 2-추가, 3-삭제, 4-출력, 5-종료] \n=> ");
		scanf("%d", &input); 
		
		if(input == 1){	//검색	 
			printf("검색할 필드명를 입력하세요\n=> ");
			scanf("%d", &one);	
 			scanf("%s", two);
 			
			switch(one){
				case 1:{
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two, cur->student_id)==0)		//학번 확인  
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 2:	{
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->department_name)==0)	//학과이름 확인	 
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 3:{
					for(cur = head;cur!=NULL;cur=cur->next){	 
						if(two[0]==cur->grade)	//학년 확인	 
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 4:{
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->name)==0)	//이름 확인	 
							printf(">>> \n%s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 5:{
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->birthday)==0)	//생일 확인	 
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
			}
		}
		
		else if (input == 2) {	//추가	 
			Node *p;
			Node *phead;
			printf("추가할 학생 정보를 입력하시오[201721380 1 security 2 Cho 1997-07-22]\n=> ");

			for(cur = head; cur != NULL; cur = cur->next){	 
				node->next = new_node;	//마지막 노드뒤에 새로운 노드 연결	 
				new_node->next = NULL;	
			}
			scanf("%s %c %s %c %s %s", new_node->student_id, &new_node->department_id, new_node->department_name, &new_node->grade, new_node->name, new_node->birthday);
		}
		
		else if (input == 3) {	//삭제	 
			
			printf("삭제할 필드명[1-학번, 2-학과, 3-학년, 4-성명, 5-생년월일]과 검색어를 입력하시오\n=> ");
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
		
		else if(input == 4){	//전체 데이터 출력	 
			for (cur = head; cur != NULL; cur = cur->next)
				printf("%s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
		}
		else if(input == 5)	break;	//종료	 
		else	printf("ERROR\n");
	}

}
