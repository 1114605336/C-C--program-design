#include <iostream>
#include <string.h>
#include "node.h"
using namespace std;
void create_node(pdevice *p){
	*p=(pdevice)malloc(sizeof(device));
	(*p)->next=NULL;
}
bool search_nodename(name *a,pdevice b){
	if(strcmp(a,b->name)){
		return false;
	}
	else{
		return true;
	}
}
bool search_nodeSerialNum(serialNum a,pdevice b){
	if(a==(b->serialNum)){
		return true;
	}
	else{
		return false;
	}
}
bool search_nodeuser(user *a,pdevice b){
	if(strcmp(a,b->user)){
			return false;
	}
	else{
		return true;
	}
}
void delete_node(pdevice b){
	free (b);
}
void display_node(pdevice a){
	printf("The name is %s\n",a->name);
	printf("The serialNum is %d\n",a->serialNum);
	printf("The position is %s\n",a->position);
	printf("The user is %s\n",a->user);
	printf("The price is %lf\n",a->price);
	printf("The class is %s\n",a->classes);
	printf("The date is %s\n",a->date);
}