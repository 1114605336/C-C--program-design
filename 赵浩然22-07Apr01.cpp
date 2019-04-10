#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct contacter{
char name[50];//名字
char mphone[30];//移动电话
char sphone[30];//固定电话
char email[50];//电子邮件
char group[20];//群组
}Contacter,*pcon;
Contacter MR;
pcon const mr=&MR;  //声明一个外部变量“默认”用来初始化，常量指针防止被修改
void turn (pcon a[]){
	int i=0;
	for(;i<200;i++){
		a[i]=mr;              //先把所有元素指向默认地址，用全局变量的地址就可以，都能看见而且不重
	}
}
void insert (pcon p[]){   
	int j=0;
	while(p[j]!=mr){
		j++;
	}
	p[j]=(pcon)malloc(sizeof(Contacter));
	getchar();
	printf("Inserting\n");
	printf("Please input name\n");
	gets(p[j]->name);
	printf("Please input mobile phone number\n");
	gets(p[j]->mphone);
	printf("Please input steady phone number\n");
	gets(p[j]->sphone);
	printf("Please input email\n");
	gets(p[j]->email);
	printf("Please input group\n");
	gets(p[j]->group);
	printf("Insert ends\n");
	//getchar();
}
void delet(pcon a[]){       //删掉的往前移    同名的默认删靠前的那个
	printf("Please input the name which you want to delete\n");
	char name[50];
	getchar();
	gets(name);
	int j=0,i=0,sum=0;
	while(a[sum]!=mr){
		sum++;          //统计个数
	}
	while(a[j]!=mr){
		if(!strcmp(name,a[j]->name)){
			printf("This contacter is deleted,you can store new contacter later\n");
			for(i=j;i<sum-1;i++){
				a[i]=a[i+1];
			}
			a[sum-1]=mr;
			break;
		}
		j++;
	}
	if(a[j]==mr){
		printf("Fail to delete this contacter\n");
	}
	//getchar();
}
void search(pcon a[]){      //按姓名输入输出手机号，否则输出姓名
	getchar();
	char n[50];
	printf("Please input mobile number or name\n");
	gets(n);
	int i=0;
	if(n[0]>=48&&n[0]<=58){                  //我Haoran Zhao就不信有人名字第一个字母是数字
		printf("You input the mobile number\n");
		while(a[i]!=mr){
			if(!strcmp(n,a[i]->mphone)){
				printf("The name is %s\n",a[i]->name);
				break;
			}
			i++;
		}
		if(a[i]==mr){
			printf("Fail to find %s\n",n);
		}

	}
	else{
		printf("You input the name\n");
		while(a[i]!=mr){
			if(!strcmp(n,a[i]->name)){
				printf("The mobile number is %s\n",a[i]->mphone);
				break;
			}
			i++;
		}
		if(a[i]==mr){
			printf("Fail to find %s\n",n);
		}
	}
}
void list(pcon a[]){
	int i=0,flag=0;
	char g[20];
	getchar();
	printf("Please input the group you want to list\n");
	gets(g);
	while(a[i]!=mr){
		if(!strcmp(g,a[i]->group)){
			printf("The name is ");
			puts(a[i]->name);
			printf("The mobile phone number is ");
			puts(a[i]->mphone);
			printf("The steady phone number is ");
			puts(a[i]->sphone);
			printf("The email is ");
			puts(a[i]->email);
			printf("The group is ");
			puts(a[i]->group);
			puts("--------------------------");
			flag++;
		}
		i++;
	}
	if(!flag){
		printf("Fail to find %s group\n",g);
		puts("--------------------------");
	}
	//igetchar();
}
void change(pcon a[]){      //先输入名字，再对应修改
	getchar();
	char name[50],m[30];
	int i=0;
	printf("Please input the name which belong to the contactor you want to change\n");
	gets(name);
	while(a[i]!=mr){
		if(!strcmp(a[i]->name,name)){
			break;            //确定位置
		}
		i++;
	}
	if(a[i]==mr){
		printf("No contacter is named %s\n",name);
	}
	else{
		printf("Please input what you want to change\n");
		printf("You can change name,mobile phone number,steady phone number,email or group\n");
		gets(m);
		if(!strcmp(m,"name")){
			printf("You will change the name\n");
			gets(a[i]->name);
			printf("You have changed the name\n");
		}
		else if(!strcmp(m,"mobile phone number")){
			printf("You will change the mobile phone number\n");
			gets(a[i]->mphone);
			printf("You have changed the mobile phone number\n");
		}
		else if(!strcmp(m,"steady phone number")){
				printf("You will change the steady phone number\n");
				gets(a[i]->sphone);
				printf("You have changed the steady phone number\n");
			}
		else if(!strcmp(m,"email")){
				printf("You will change the email\n");
				gets(a[i]->email);
				printf("You have changed the email\n");
			}
		else if(!strcmp(m,"group")){
				printf("You will change the group\n");
				gets(a[i]->group);
				printf("You have changed the group\n");
			}
		else{
			printf("Fail to change\n");
		}
	}
}
void quit(){
	printf("You exit this program\n");
	exit(EXIT_SUCCESS);
}
int main(int argc, char *argv[]) {
	//先在数组里增删改查，全部结束后再存到文件，再退出
	FILE *fp;
	int i=0;
	char c;
	pcon a[200];       //用指针数组，每个元素指向一个结构体
	turn(a);           //初始化，所有元素先指向同一个const过的默认结构体，以此来判断是否操作过    
	c=getchar();
	if((fp=fopen("cont.txt","w+"))==NULL){
		printf("Cannot open file");
		exit(EXIT_FAILURE);
	}	
	else{
		while(1){
			if(c=='I'||c=='i'){
				insert(a);
			}
			else if(c=='D'||c=='d'){
				delet(a);
			}
			else if(c=='S'||c=='s'){
				search(a);
			}
			else if(c=='L'||c=='l'){
				list(a);
			}
			else if(c=='M'||c=='m'){
				change(a);
			}
			else{
				while(a[i]!=mr){
					fprintf(fp,"The name is %s\n",a[i]->name);
					fprintf(fp,"The mobile phone number is %s\n",a[i]->mphone);
					fprintf(fp,"The steady phone number is %s\n",a[i]->sphone);
					fprintf(fp,"The email is %s\n",a[i]->email);
					fprintf(fp,"The group is %s\n",a[i]->group);
					fputs("--------------------------", fp);
					fprintf(fp,"\n");
					i++;
				}
				quit();             //quit退出
			}
			c=getchar();
		}
	}
	fclose(fp);
	return 0;
}
//终于写完了,getchar()让我自闭