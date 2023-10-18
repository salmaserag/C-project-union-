#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8


struct user{
	char fullname[50] ;
	char username[50];
	char email[50];
	char phone[50];
	char password[50];
	char confirmpass[50];
	char active[50];
};

union active{
	struct str{
		char True[50];
		char False[50];
	};
};

void takeinput(char ch[50]){
	fgets(ch,50,stdin);
	ch[strlen(ch)-1]=0;
}

char generateUsername(char email[50] , char username[50]){
	for(int i = 0 ; i<strlen(email) ; i++){
		if(email[i] == '@') break;
		else username[i] = email[i];
	}
}


void takePassword(char pwd[50]){
	int i;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			pwd[i] = '\0';
			break;
		}else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
			pwd[i++] = ch ;
			printf("* \b");
		}
		
	}
}


int main() {
	
	FILE *fp;
	int opt , opt_union , usrfound=0;
	struct user user;
	union active active;
	struct str str;
	
	char username[50] , pword[50];
	struct user usr;
	
	
	printf("\n\t\t\t\t--------------------Welcome to outhentication system--------");
	printf("\nPlease choose your option");
	printf("\n1.SignUp");
	printf("\n2.Login");
	printf("\n3.Exit");
	
	printf("\n\nYour choise :\t");
	scanf("%d",&opt);
	fgetc(stdin);
	
	
	switch(opt){
		case 1:
			
			system("cls");
    		printf("\n1-Active");
			printf("\n2-Not Active\n");
			printf("\nEnter your option : ");

			scanf("%d",&opt_union);
         	fgetc(stdin);
         	
         	switch(opt_union){
				case 1:
					strcpy(str.True,"True");
			        strcpy(user.active,str.True);
			        break;
			        
			    case 2:
					strcpy(str.False,"False");
			        strcpy(user.active,str.False);
			        break;
			
         	}
         	
         	system("cls");
		    printf("\nEnter Your Full name : \t");
		    takeinput(user.fullname);
		    
		    printf("Enter Your email : \t");
		    takeinput(user.email);
		    
		    printf("Enter Your phoneNumber : \t");
		    takeinput(user.phone);
		    
		    printf("Enter Your Password : \t");
		    takePassword(user.password);
		    
		    printf("\n Confirm Your Password : \t");
		    takePassword(user.confirmpass);
		    
		    if(!strcmp(user.password , user.confirmpass)){
		    	printf("\nYour password matched");
		    	generateUsername(user.email , user.username);
		    	fp = fopen("User.dat","a+");
		    	fwrite(&user,sizeof(struct user),1,fp);
		    	if(fwrite != 0){
		    		printf("\nUser regestration success , Your user name is %s" , user.username);
				}else{
					printf("\nSorry! something wrong :(");
				}
		    	
			}else{
				printf("\nPassword donot matched");
				Beep(800,300);   //window h
			}
			
		break;
		
		case 2:
			
			system("cls");
			printf("\nEnter Your Username : \t");
		    takeinput(username);
		    
		    printf("Enter Your Password : \t");
		    takePassword(pword);
		    
		    fp = fopen("User.dat" , "r");
		    while(fread(&usr ,sizeof(struct user),1,fp)){
		    	if(!strcmp(usr.username , username)){
		    		if(!strcmp(usr.password , pword)){
		    			
		    				strcpy(str.False,"False");
			    			if(!strcmp(usr.active,str.False)){
			    				printf("\n Sorry Account Not Active !");
							    Beep(800 , 300);
							    return 0 ;
							}
						
		    			printf("\n\n\t\t--Welcome %s" , usr.fullname);
		    			
		    			printf("\n\n |FullName : \t%s" , usr.fullname);
		    			printf("\n |Email : \t%s" , usr.email);
		    			printf("\n |UserName : \t%s" , usr.username);
		    			printf("\n |Phone : \t%s" , usr.phone);
		    			printf("\n |Active : \t%s" , usr.active);
		    			
					}
					else{
						printf("\n Invalid Password !");
						Beep(800 , 300);
					}
					usrfound = 1 ;
				}
			}
			
			if(!usrfound){
				printf("\n\n User not registerd ");
				Beep(800 , 300);
			}
			
	    break;
	    
	    
	    case 3:
	    	
		   printf("\n Bye Bye :) ");
		   return 0;
	
			
		    
		    
	}
	
	
	
	
	return 0;
}

