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
	
	while(!feof(fp)){	//n = �޸� �� �� ���� 
		fgets(line, 256, fp);
		n++;	
	}
	rewind(fp);	//�޸��� �� ó������ �̵� 
	
	student_info *stu = malloc(sizeof(student_info)*n);	//���� �޸� �Ҵ�
		
	while(!feof(fp)){
		fgets(line, 256, fp);	// �� �پ� �о����  
		if(l != 0){	//�� ù��° ���� ���� �����ϱ� ���� ���ǹ�	 
			token = strtok(line, delim);		//�����͸� �� �پ� �о� delim�� ���ǿ� ���� �����Ͽ� token�� ����  
			strcpy(stu[i].student_id, token);	//token�� �����͸� stu.student_id�� ����	 
			a = 1;
			while((token = strtok(NULL, delim)) != NULL){	//�����͸� ������ ����ü�� ����	 
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
		printf("c = �÷�, r = ���ڵ�, a = ��� ������, quit = ����\ninput: ");	//�������̽� 
		gets(input);	//����ڰ� ���ϴ� ���� �Է� 
		//strcpy(input_a, input);
		
		token = strtok(input, delim);	//�Է¹��� input�� delim�� ���ǿ� ���� �����Ͽ� token�� ����  
		one = *token;	//token�� �����͸� one�� ����	 
		
		while((token = strtok(NULL, delim)) != NULL){	 //input�� �ι�° ���ڿ��� token�� ����  
			two = *token;	//token�� �����͸� two�� ����  
			t = (int)two - 48;	//two�� char���̹Ƿ� int������ ��������ȯ 
			//printf("%d", t); 
		}
		if(one == 'c'){	//�÷��� ������ ���	 
			switch (two){	 
				case '1': for(n=0;n<i;n++)	printf("%s\n", stu[n].student_id);	break;
				case '2': for(n=0;n<i;n++)	printf("%s\n", stu[n].department_name);	break;
				case '3': for(n=0;n<i;n++)	printf("%c\n", stu[n].grade);	break;
				case '4': for(n=0;n<i;n++)	printf("%s\n", stu[n].name);	break;
				case '5': for(n=0;n<i;n++)	printf("%s\n", stu[n].birthday);	break;					
			}
		}
		if(one == 'r')	//���ڵ带 ������ ���	 
			printf("%s\t%c\t%s\t%c\t%s\t%s\n", stu[t-1].student_id, stu[t-1].department_id, stu[t-1].department_name, stu[t-1].grade, stu[t-1].name, stu[t-1].birthday);
			
		if(strcmp(input, "a")==0)	//��� ������ ����� ������ ���	 
			for(i=0;i<n;i++)
				printf("%s\t%c\t%s\t%c\t%s\t%s\n", stu[i].student_id, stu[i].department_id, stu[i].department_name, stu[i].grade, stu[i].name, stu[i].birthday);
				
		if(strcmp(input, "quit")==0)	break;	//���Ḧ ������ ���	
	}
	free(stu);	//�����޸� �Ҵ�� ���ʿ��ϰ� ������ �޸� ����	 
	fclose(fp);
}
