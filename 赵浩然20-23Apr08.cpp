#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef struct{
	char name[10];//姓名
	char account[30];//账号
	char bank[40];//开户银行
	float money;//存款余额
	float rate;//利率
	char password[100];//密码
}customer,*pcus;
customer mrr;
pcus mr=&mrr;
void create(pcus a[]){             //创建
	int i=0;
	while(a[i]!=mr){
		i++;
	}
	a[i]=(pcus)malloc(sizeof(customer));
	printf("Please input name\n");
	gets(a[i]->name);
	printf("Please input account\n");
	gets(a[i]->account);
	while(1){
		int j=0;
		while(a[j]!=mr){
			if((!strcmp(a[i]->account,a[j]->account))&&j!=i){
				break;
			}
			j++;
		}
		if(a[j]!=mr){
			printf("The account already exists,please input again\n");    //检查账号是否重复
			gets(a[i]->account);
		}
		else{
			break;
		}
	}
	printf("Please input bank\n");
	gets(a[i]->bank);
	printf("Please input password\n");
	gets(a[i]->password);
	a[i]->money=0;      //余额一开始为0
	a[i]->rate=0.15;    //利率固定
	printf("Create ends\n");
}
void login(pcus a[],int *p){
	char ac[30],ba[40],pa[100];
	int i=0;
	printf("Please input the account\n");
	gets(ac);
	printf("Please input the password\n");
	gets(pa);
	while(a[i]!=mr){
		if((!strcmp(ac,a[i]->account))&&(!strcmp(pa,a[i]->password))){
			break;
		}
		i++;
	}
	if(a[i]==mr){
		printf("Worng account or worng bank or wrong password\n");
		*p=-1;
	}
	else{
		*p=i;
	}
}
void search(pcus a[],int p){
	printf("The name is %s\n",a[p]->name);
	printf("The account is %s\n",a[p]->account);
	printf("The bank is %s\n",a[p]->bank);
	//printf("The money is %f\n",a[p]->money);
	cout<<"The remaining money is "<<a[p]->money<<"\n";   //去掉小数点后无意义零，以下cout皆是
	//printf("The rate is %f\n",a[p]->rate);
	cout<<"The rate is "<<a[p]->rate<<"\n";
	printf("Search ends\n");
}
void withraw(pcus a){
	char pa[100];
	double mo;
	int i=0;
	printf("Please input the password\n");
	gets(pa);
	if(!strcmp(pa,a->password)){
		printf("Please input how much you want to withraw\n");
		scanf("%lf",&mo);
		getchar();        //scanf一定要加getchar()
		if(a->money>mo||a->money==mo){
		//printf("Withraw succeeds,your money remains %f\n",a->money-mo);
		cout<<"Withraw succeeds,your money remains "<<a->money-mo<<"\n";
		a->money-=mo;
		}
		else{
			printf("Withraw fails,no enough money remained\n");
		}
	}
	else {
		printf("Wrong password\n");
	}
}
void transfer(pcus a[],pcus b){
	int i=0;
	char bac[30];
	double mo;
	printf("Please input the account you want to transfer to\n");
	gets(bac);
	while (a[i]!=mr) {
		if(!strcmp(bac,a[i]->account)){
			break;
		}
		i++;
	}
	if(a[i]==mr){
		printf("No this account\n");
	}
	else{
		printf("Please input how much you want to transfer\n");
		scanf("%lf",&mo);
		getchar();
		if((b->money>mo)||(b->money==mo)){
			//printf("Transfer succeeds,your money remains %f\n",b->money-mo);
			cout<<"Transfer succeeds,your money remains "<<b->money-mo<<"\n";
			b->money-=mo;
			(a[i]->money)+=mo;
		}
		else{
			printf("Transfer fails,no enough money remained\n");
		}
	}
}
void deposit(pcus a){
	long mo;                                //存款只能存整数,long防止溢出
	printf("Please input how much you want to deposit\n");
	scanf("%ld",&mo);
	getchar();
	if(!(mo%100)){                            //存款只能为100的整数倍
		//printf("Deposit succeeds,now your money remains %f\n",a->money+mo);
		cout<<"Deposit succeeds,now your money remains "<<a->money+mo<<"\n";
		a->money+=mo;
	}
	else{
		printf("Deposit fails,deposit amount should be multiple of 100\n");
	}
}
int main(int argc, char *argv[]) {
	pcus a[200];
	int i,flag=0,p;
	char c[10];
	for(i=0;i<200;i++){
		a[i]=mr;
	}
	if(a[0]==mr){
		printf("There is no customer,you need to create one first,or you can quit\n");
		gets(c);
		if(!strcmp(c,"quit")){
			printf("You quit the program\n");
			return 0;
		}
		else if(!strcmp(c,"create")){
			create(a);
			flag=1;
		}
		else {
			printf("You input wrong command,quit\n");
		}
	}
	if(flag){
		printf("You can login,create or quit\n");
		while(1){
			gets(c);
			if(!strcmp(c,"create")){
				printf("Create starts\n");
				create(a);
				printf("You can login or create\n");
			}	
			else if(!strcmp(c,"login")){
				while(1){                      // 可以多次输密码
					int i=0;
					login(a,&p);              //p保存当前登陆账户的数组下标
					if(p!=-1){
						printf("Welcome to login\n");
						break;
					}
					else{
						i++;
						printf("You input the wrong account or password\n");
						printf("Now you %d chances to try\n",3-i);
					}
					if(i==3){
						printf("You have inputed 3 wrong password,exit\n");      //输错三次退出
						return 0;
					}
				}
				printf("You can search,withraw,transfer,deposit or quit\n");
				while(1){
					//getchar();
					gets(c);
					if(!strcmp(c,"search")){
						search(a,p);
					}
					else if(!strcmp(c,"withraw")){
						withraw(a[p]);
					}
					else if(!strcmp(c,"transfer")){
						transfer(a,a[p]);
					}
					else if(!strcmp(c,"deposit")){
						deposit(a[p]);
					}
					else if(!strcmp(c,"quit")){
						printf("You quit this program\n");
						return 0;
					}
					else {
						printf("You input wrong command\n");
					}
				}
			}
			else if(!strcmp(c,"quit")){
				printf("You quit this program\n");
				return 0;
			}
			else{
				printf("You input wrong command\n");
			}	
		}
	}
	else{
		printf("Fail to create the first one,exit\n");
	}
	return 0;
}