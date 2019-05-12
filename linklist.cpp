#include <iostream>
#include "linklist.h"
using namespace std;
void create_linklist(pdevice *a){
	create_node(a);
}
/*void delete_linklist(plinklist a){
	a->head=NULL;
}
void search_linklist_name(plinklist a,pdevice b[],name c){
	pdevice p=a->head;
	int i=0;
	while(p){
		if(!strcmp(p->name,c)){
			b[i]=p;
			i++;
		}
		p=p->next;
	}
}
*/
