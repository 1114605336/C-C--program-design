//#include <iostream>
#include <cstdlib>
#include "nodeitem.h"
using namespace std;
typedef struct a{
	char name[30];//设备名称
	int serialNum;//设备编号（不重复）
	char position[30];//设备所在实验室名称
	char user[20];//使用者姓名
	double price;//设备价格
	char classes[20];// 设备种类(如：微机、打印机、扫描仪等等)
	char date[20];//设备购买日期，如20090101等
	struct a *next;
}device,*pdevice;
void create_node(pdevice *a);
bool search_nodename(name *a,pdevice b);
bool search_nodeSerialNum(serialNum a,pdevice b);
bool search_nodeuser(user *a,pdevice b);
void delete_node(pdevice b);
void display_node(pdevice a);