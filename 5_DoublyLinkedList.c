#include <stdio.h>
#include <string.h>
#include <malloc.h> 
#include "student_info.h"

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

int main(){
	int input, n = 0, k = 0, m = 0;
	char line[256], one, two[20];  
	
	FILE *fp = fopen("students_10.txt", "rt");
	while(!feof(fp)){	//메모리 줄 수 세기	  
		fgets(line, 256, fp);
		n++;
	}

	rewind(fp);	//파일의 처음으로 이동 

	Node *head = NULL;	//첫번째 노드 위치 
	Node *cur = NULL;	//현재 노드 위치 
	Node *tail = NULL;	//마지막 노드 위치  
	 
	Node *new_node;	//추가할 노드   
	Node *node;

	while (!feof(fp)) {
		node = (Node *)malloc(sizeof(Node));
		if (k == 0) {	//첫번째 줄을 제외하고 저장하기 위함  
			fgets(line, 256, fp);
			k++;
		}
		else {

			if (head == NULL) {
				fscanf(fp, "%s %c %s %c %s %s\n", node->student_id, &node->department_id, node->department_name, &node->grade, node->name, node->birthday);
				head = node;		//첫번째 노드	 
				cur = node;			//현재 노드	 
				head->prev = NULL;	//첫번째 노드 앞에는 NULL 
			}
			else {
				fscanf(fp, "%s %c %s %c %s %s\n", node->student_id, &node->department_id, node->department_name, &node->grade, node->name, node->birthday);
				cur->next = node;	//다음 노드 연결	
				node->prev = cur; 	//node가 다음 노드 이므로 다음노드의 prev에 현재 노드 연결	  
				cur = node;			//현재 노드	
				cur->next = tail;	//현재 노드의 다음 노드에 tail 
			} 
		}
	}
	tail = cur;		//가장 마지막 노드를 tail에 저장  
	
	while(1){
		printf("원하는 기능을 입력하시오[1-검색, 2-추가, 3-삭제, 4-출력, 5-종료] \n=> ");
		scanf("%d", &input); 
		
		if(input == 1){		//검색	 
			printf("검색할 필드명[1-학번, 2-학과, 3-학년, 4-성명, 5-생년월일]과 검색어를 입력하세요\n=> ");
			scanf("%d", &one);	
 			scanf("%s", two);
 			
			switch(one){
				case 1:{	//학번 
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two, cur->student_id)==0)	
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 2:	{	//학과이름 
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->department_name)==0)
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 3:{	//학년 
					for(cur = head;cur!=NULL;cur=cur->next){	 
						if(two[0]==cur->grade)
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 4:{	//이름 
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->name)==0)
							printf(">>> \n%s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
				case 5:{	//생일
					for(cur = head;cur!=NULL;cur=cur->next){
						if(strcmp(two,cur->birthday)==0)
							printf(">>> %s %c %s %c %s %s\n", cur->student_id, cur->department_id, cur->department_name, cur->grade, cur->name, cur->birthday);
					}
					break;
				}
			}
		}
		
		else if (input == 2) {	//추가	 
			new_node = (Node *)malloc(sizeof(Node));
			printf("추가할 학생 정보를 입력하시오[201721380 1 security 2 Cho 1997-07-22]\n=> ");
			scanf("%s %c %s %c %s %s", new_node->student_id, &new_node->department_id, new_node->department_name, &new_node->grade, new_node->name, new_node->birthday);
		
			//가장 마지막노드 뒤에 새로운 노드 추가  
			new_node -> prev = tail;
  			new_node -> next = tail -> next;	//현재 tail->next는 null 
  			tail -> next = new_node;
  			
  			tail = new_node; // 이제 가장 마지막 노드는 new_node가 됨  
  			tail -> next = NULL;
		}
		
		else if (input == 3) {	//삭제	 			
			printf("삭제할 필드명[1-학번, 2-학과, 3-학년, 4-성명, 5-생년월일]과 검색어를 입력하시오\n=> ");
			scanf("%d", &one);
			scanf("%s", two);
			
			switch(one){
				case 1:{	//학번 확인  
					for(cur = head; cur != NULL; cur = cur->next)
						if(strcmp(two, cur->student_id)==0)	// cur=삭제할 노드  
							deleteNode(cur, &head, &tail); //head와 tail은 변한 값이 유지되어야 하므로 주소값을 보냄  
					break;
				}
				case 2:	{	//학과 확인	 
					for(cur = head; cur != NULL; cur = cur->next)
						if(strcmp(two,cur->department_name)==0)
							deleteNode(cur, &head, &tail); 
					break;
				}
				case 3:{	//학년 확인  
					for(cur = head; cur != NULL; cur = cur->next)
						if(two[0]==cur->grade)
							deleteNode(cur, &head, &tail); 
					break;
				}
				case 4:{	//성명 확인  
					for(cur = head; cur != NULL; cur = cur->next)
						if(strcmp(two,cur->name)==0)
							deleteNode(cur, &head, &tail); 
					break;
				}
				case 5:{	// 생일 확인  
					for(cur = head; cur != NULL; cur = cur->next)
						if(strcmp(two,cur->birthday)==0)
							deleteNode(cur, &head, &tail); 
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
