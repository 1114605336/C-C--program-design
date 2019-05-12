#include <iostream>
#include "nodeitem.h"
using namespace std;
bool input_name(name *a){
	printf("Please input the device's name\n");
	gets(a);
	if(a[0]=='\0'){
		printf("Name's inputing falses\n");
		return false;
	}
	else{
		printf("Name's inputing succeeds\n");
		return true;
	}
}
bool input_serialNum(serialNum *a){
	printf("Please input the device's serialNum\n");
	scanf("%d",a);
	getchar();
	//printf("SerialNum's inputing ends\n");
	if(*a==-1){
		printf("SerialNum's inputing falses\n");
		return false;
	}
	else{
		printf("SerialNum's inputing succeeds\n");
		return true;
	}
}
bool input_position(position *a){
	printf("Please input the device's position\n");
	gets(a);
	//printf("Position's inputing ends\n");
	if(a[0]=='\0'){
		printf("Position's inputing falses\n");
		return false;
	}
	else{
		printf("Position's inputing succeeds\n");
		return true;
	}
}
bool input_user(user *a){
	printf("Please input the device's user\n");
	gets(a);
	//printf("User's inputing ends\n");
	if(a[0]=='\0'){
		printf("User's inputing falses\n");
		return false;
	}
	else{
		printf("User's inputing succeeds\n");
		return true;
	}
}
bool input_price(price *a){
	printf("Please input the device's price\n");
	scanf("%lf",a);
	getchar();
	//printf("Price's inputing ends\n");
	if(*a==-1){
		printf("Price's inputing falses\n");
		return false;
	}
	else{
		printf("Price's inputing succeeds\n");
		return true;
	}
}
bool input_class(classes *a){
	printf("Please input the device's class\n");
	gets(a);
	//printf("Class's inputing ends\n");
	if(a[0]=='\0'){
		printf("Class's inputing falses\n");
		return false;
	}
	else{
		printf("Class's inputing succeeds\n");
		return true;
	}
}
bool input_date(date *a){
	printf("Please input the device's date\n");
	gets(a);
	//printf("Date's inputing ends\n");
	if(a[0]=='\0'){
		printf("Date's inputing falses\n");
		return false;
	}
	else{
		printf("Date's inputing succeeds\n");
		return true;
	}
}
bool modify_name(name *a){
	printf("Please modify the device's name\n");
	gets(a);
	//printf("Name's modifying ends\n");
	if(a[0]=='\0'){
		printf("Name's modifying falses\n");
		return false;
	}
	else{
		printf("Name's modifying succeeds\n");
		return true;
	}
}
bool modify_position(position *a){
	printf("Please modify the device's position\n");
	gets(a);
	//printf("Name's modifying ends\n");
	if(a[0]=='\0'){
		printf("Position's modifying falses\n");
		return false;
	}
	else{
		printf("Date's modifying succeeds\n");
		return true;
	}
}
bool modify_user(user *a){
	printf("Please modify the device's user\n");
	gets(a);
	//printf("Name's modifying ends\n");
	if(a[0]=='\0'){
		printf("User's modifying falses\n");
		return false;
	}
	else{
		printf("User's modifying succeeds\n");
		return true;
	}
}
bool modify_price(price *a){
	printf("Please modify the device's price\n");
	scanf("%lf",a);
	//printf("Name's modifying ends\n");
	if(a==0){
		printf("Price's modifying falses\n");
		return false;
	}
	else{
		printf("Price's modifying succeeds\n");
		return true;
	}
}
bool modify_class(classes *a){
	printf("Please modify the device's class\n");
	gets(a);
	//printf("Name's modifying ends\n");
	if(a[0]=='\0'){
		printf("Class's modifying falses\n");
		return false;
	}
	else{
		printf("Class's modifying succeeds\n");
		return true;
	}
}
bool modify_date(date *a){
	printf("Please modify the device's date\n");
	gets(a);
	//printf("Name's modifying ends\n");
	if(a[0]=='\0'){
		printf("Date's modifying falses\n");
		return false;
	}
	else{
		printf("Date's modifying succeeds\n");
		return true;
	}
}










