//#include <iostream>
#include "linklist.h"
#include <algorithm>
//#include "node.h"
//#include "nodeitem.h"
using namespace std;
//int i=0;
/*
要求:
用链表实现;
能够完成对设备信息的录入、修改和删除(设备编号不允许修改,录入时按设备号排序);
对设备进行分类统计;   用数组记录
根据设备名称、编号、使用者等对设备进行查询;
*/
int main(int argc, char *argv[]) {
	char op[20],op1[20];          //op用来确定对节点的操作，op1用来确定对哪个数据操作
	pdevice classes[20],t,f1,f2;    //t指向最新的，f1,f2用来寻找以及排序,默认指向head
	linklist ll;
	int ts;                       //serialNUm
	int flag=0,sers[1000000];
	for(int i=0;i<1000000;i++){
		sers[i]=-1;               //初始化
	}
	//gets(op);
	while(1){
		if(flag){
			printf("Please input what do you want to do:input,modify,delete,search,classify or quit\n");
			gets(op);
		}
		if(!flag){
			printf("There is no data,you need to create first\n");
			create_linklist(&(ll.head));
			t=ll.head;
			f1=t;
			f2=t;
			input_name(t->name);
			input_serialNum(&(t->serialNum));
			input_position(t->position);
			input_user(t->user);
			input_price(&(t->price));
			input_class(t->classes);
			input_date(t->date);
			if(t){
				printf("Create succeeds\n");
				flag=1;
			}
			else{
				printf("Create fails\n");
				exit(EXIT_FAILURE);
			}
		}
		else if(!strcmp("input",op)){
			f1=f2=ll.head;
			pdevice p;
			int i=0;
			printf("Input starts\n");
			create_node(&p);
			input_name(p->name);
			input_serialNum(&(p->serialNum));
			input_position(p->position);
			input_user(p->user);
			input_price(&(p->price));
			input_class(p->classes);
			input_date(p->date);
			while(f1!=NULL){
				if(f1->serialNum==p->serialNum){
					break;
				}
				f1=f1->next;
			}
			if(f1){
				printf("This device is existing\n");
				break;
			}
			f1=ll.head;
			if(p->serialNum>t->serialNum){
				t->next=p;
			}
			else if(p->serialNum<(ll.head)->serialNum){
				p->next=ll.head;
				ll.head=p->next;
			}
			else{
				while(f1){
					if((f1->serialNum<p->serialNum)&&((f1->next)->serialNum>p->serialNum)){
						p->next=f1->next;
						f1->next=p;
						break;
					}
				}
			}
			t=p;
			f1=ll.head;
			printf("Input succeeds\n");
		}
			else if(!strcmp("modify",op)){
			int s;
			printf("Modify starts\nPlease input the serialNum belongs to the device you want to modify\n");
			scanf("%d",&s);
			getchar();
			printf("Please input what do you want to modify:name,serialNum,position,user,price,class or date\n");
			gets(op1);
			while(f1){
				if(f1->serialNum==s){
					break;
				}
				f1=f1->next;
			}
			if(!f1){
				printf("This device is not existed\n");
				continue;
			}
			if(!strcmp("name",op1)){
				modify_name(f1->name);
			}
			else if(!strcmp("serialNum",op1)){
				printf("You can not modify the serialNum\n");
			}
			else if(!strcmp("position",op1)){
				modify_position(f1->position);
			}
			else if(!strcmp("user",op1)){
				modify_user(f1->user);
			}
			else if(!strcmp("price",op1)){
				modify_price(&(f1->price));
			}
			else if(!strcmp("class",op1)){
				modify_class(f1->classes);
			}
			else if(!strcmp("date",op1)){
				modify_date(f1->date);
			}
			else{
				printf("You input wrong command\n");
			}
			//printf("Modify succeeds\n");
			f1=ll.head;
			
		}
		else if(!strcmp("delete",op)){
			if(t==ll.head){
				printf("You can not delete the only equirement\n");
				continue;
			}
			printf("Delete starts\nPlease input the serialNum belongs to the device you want to delete\n");
			scanf("%d",&ts);
			getchar();
			while(f1){
				if(search_nodeSerialNum(ts,f1)){
					f2->next=f1->next;
					delete_node(f1);
					break;
				}
				f2=f1;
				f1=f1->next;
			}
			if(!f1){
				printf("The device do not exist\n");
			}
			//f2=ll.head;
			//f1=ll.head;
			else{
				printf("Delete succeeds\n");
			}
			f2=ll.head;
			f1=ll.head;
		}
		else if(!strcmp("search",op)){
			printf("Search starts\nPlease input what you want to search:name,serialNum or user\n");
			gets(op1);
			if(!strcmp("name",op1)){
				name n [20];
				printf("Please input the name\n");
				gets(n);
				while(f1){
					if(search_nodename(n,f1)){
						break;
					}
					f1=f1->next;
				}
				if(!f1){
					printf("The device do not exist\n");
				}
				else{
					display_node(f1);	
					printf("Search succeeds\n");
				}
				f1=ll.head;
			}
			else if(!strcmp("serialNum",op1)){
				serialNum n;
				printf("Please input the serialNum\n");
				scanf("%d",&n);
				getchar();
				while(f1!=NULL){
					if(search_nodeSerialNum(n,f1)){
						break;
					}
					f1=f1->next;
				}
				if(!f1){
					printf("The device do not exist\n");
				}
				else{
					display_node(f1);	
					printf("Search succeeds\n");
				}
				f1=ll.head;
			}
			else if(!strcmp("user",op1)){
				user n [20];
				printf("Please input the user\n");
				gets(n);
				while(f1){
					if(search_nodeuser(n,f1)){
						break;
					}
					f1=f1->next;
				}
				if(!f1){
					printf("The device do not exist\n");
				}
				else{
					display_node(f1);	
					printf("Search succeeds\n");
				}
				f1=ll.head;
			}
			else{
				printf("You input wrong command\n");
			}
		}
		else if(!strcmp("classify",op)){
			printf("PC:\n");
			f1=ll.head;
			while(f1!=NULL){
				if(!strcmp("pc",f1->classes)){
					display_node(f1);
				}
				f1=f1->next;
			}
			f1=ll.head;
			printf("PRINTER:\n");
			while(f1!=NULL){
				if(!strcmp("printer",f1->classes)){
					display_node(f1);
				}
				f1=f1->next;
			}
			f1=ll.head;
			printf("SCANNER:\n");
			while(f1!=NULL){
				if(!strcmp("scanner",f1->classes)){
					display_node(f1);
				}
				f1=f1->next;
			}
			f1=ll.head;
			printf("OTHER:\n");
			while(f1){
				if((!strcmp("PC",f1->classes))&&(!strcmp("printer",f1->classes))&&(!strcmp("scanner",f1->classes))){
					display_node(f1);
				}
				f1=f1->next;
			}
			f1=ll.head;
		}
		else if(!strcmp("quit",op)){
			printf("You exit this program\n");
			exit(EXIT_SUCCESS);
		}
		else{
			printf("You input wrong command\n");
		}
	}
	return 0;
}






