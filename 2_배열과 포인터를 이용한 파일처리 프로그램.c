/*
Author:	Cho jin young
Id:		201721380
Date:	2018/03/15
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct student_info {
	unsigned char student_id[20];
	unsigned char department_id;
	unsigned char department_name[40];
	unsigned char grade;
	unsigned char name[80];
	unsigned char birthday[20];
} student_info;


int main(){
	char line[256], input[30];
	char *token;
	char delim[] = " \t\n";
	char one, two;
	int i = 0, a = 1, n = 0, l = 0, t = 0;
	
	FILE *fp = fopen("students_10.txt", "r");
	
	while(!feof(fp)){	//n = 메모리 줄 수 세기 
		fgets(line, 256, fp);
		n++;	
	}
	rewind(fp);	//메모리의 맨 처음으로 이동 
	
	student_info *stu = malloc(sizeof(student_info)*n);	//동적 메모리 할당
		
	while(!feof(fp)){
		fgets(line, 256, fp);	// 한 줄씩 읽어오기  
		if(l != 0){	//맨 첫번째 줄을 빼고 저장하기 위한 조건문	 
			token = strtok(line, delim);		//데이터를 한 줄씩 읽어 delim의 조건에 따라 구분하여 token에 저장  
			strcpy(stu[i].student_id, token);	//token의 데이터를 stu.student_id에 저장	 
			a = 1;
			while((token = strtok(NULL, delim)) != NULL){	//데이터를 각각의 구조체에 저장	 
				if(a==1)	stu[i].department_id = *token;
				if(a==2)	strcpy(stu[i].department_name, token);
				if(a==3)	stu[i].grade = *token;
				if(a==4)	strcpy(stu[i].name, token);
				if(a==5)	strcpy(stu[i].birthday, token);
				a++;
			}	
			i++;
		}
		l++;
	}
	while(1){
		char one=NULL, two=NULL;
		printf("c = 컬럼, r = 레코드, a = 모든 데이터, quit = 종료\ninput: ");	//인터페이스 
		gets(input);	//사용자가 원하는 실행 입력 
		//strcpy(input_a, input);
		
		token = strtok(input, delim);	//입력받은 input을 delim의 조건에 따라 구분하여 token에 저장  
		one = *token;	//token의 데이터를 one에 저장	 
		
		while((token = strtok(NULL, delim)) != NULL){	 //input의 두번째 문자열을 token에 저장  
			two = *token;	//token의 데이터를 two에 저장  
			t = (int)two - 48;	//two가 char형이므로 int형으로 강제형변환 
			//printf("%d", t); 
		}
		if(one == 'c'){	//컬럼을 선택한 경우	 
			switch (two){	 
				case '1': for(n=0;n<i;n++)	printf("%s\n", stu[n].student_id);	break;
				case '2': for(n=0;n<i;n++)	printf("%s\n", stu[n].department_name);	break;
				case '3': for(n=0;n<i;n++)	printf("%c\n", stu[n].grade);	break;
				case '4': for(n=0;n<i;n++)	printf("%s\n", stu[n].name);	break;
				case '5': for(n=0;n<i;n++)	printf("%s\n", stu[n].birthday);	break;					
			}
		}
		if(one == 'r')	//레코드를 선택한 경우	 
			printf("%s\t%c\t%s\t%c\t%s\t%s\n", stu[t-1].student_id, stu[t-1].department_id, stu[t-1].department_name, stu[t-1].grade, stu[t-1].name, stu[t-1].birthday);
			
		if(strcmp(input, "a")==0)	//모든 데이터 출력을 선택한 경우	 
			for(i=0;i<n;i++)
				printf("%s\t%c\t%s\t%c\t%s\t%s\n", stu[i].student_id, stu[i].department_id, stu[i].department_name, stu[i].grade, stu[i].name, stu[i].birthday);
				
		if(strcmp(input, "quit")==0)	break;	//종료를 선택한 경우	
	}
	free(stu);	//동적메모리 할당시 불필요하게 생성된 메모리 정리	 
	fclose(fp);
}
