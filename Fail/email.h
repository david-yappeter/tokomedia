#ifndef EMAILL 
#define EMAILL 1
#include "media.h"
#include "banking.h"
#include "GlobalVariable.h"
#endif

// EmailBox Structure
typedef struct mailbox{
	char pengirim[100];
	char keterangan[100];
	char waktu[100];
};

// Email Structure
typedef struct structemail{
	char name[100];
	char email[100];
	char pass[100];
	mailbox inbox[100];
	int inboxcount = 0;
};


// Method Tampilan Gmail
void gmailstart();
void gmaillogin();
void gmailregister();
void gmaildashboard();
void gmailmessage();

// Method Gmail
void deletemail();

// Method File Gmail
void scanfilegmail();
void editfilegmail();

// Variabel Global Gmail
int indexlogingmail = -1;
int jlhgmail = 0;
int gmailpagenow = 1;
	
// struct Global Email
structemail gmail[100];

void gmailstart(){
	time_t t;
	time(&t);
	
	system("@cls||clear");
	printf("=========================================================================================\n");
	printf("=                                      GMAIL                                            =\n");
	printf("=========================================================================================\n");
	printf("%s\n",ctime(&t));
	printf("-----------------------------------------------------------\n");
	printf("[1] Login\n");
	printf("[2] Register\n");
	printf("[3] Return\n");
	printf("[0] Exit\n");
	printf("-----------------------------------------------------------\n");
	printf(">>>");
	
	while(1){
		
		if(kbhit()){
			char c = getch();
			if(c == 49){
				printf("1\n");
				gmaillogin();
			}
			else if(c == 50){
				printf("2\n");
				gmailregister();
			}
			else if(c == 51){
				printf("3\n");
				website();
			}
			else if(c == 48){
				printf("0");
				endprogram();
			}
		}	
	}
	
}

void gmaillogin(){
	char email[100], pass[100];
	printf("-----------------------------------------------------------\n");
	int index;
	while(1){
		printf("Email : ");
		scanf("%s", &email);
		if(strcmp(email,"0") == 0){
			clearscreenAbort();
			gmailstart();
		}
		int flag = 0;
		for(int i = 0; i < jlhgmail; i++){
			if(strcasecmp(email,gmail[i].email) == 0){
				index = i;
				flag = 1;
				break;
			}
		}
		if(flag){
			break;
		}
		printf("Email Tidak Ada!!\n");
	}
	
	while(1){
		printf("Password : ");
		int p=0; 
		do{ 
		    pass[p]=getch();
		    if(pass[p] == 13){
		    	if(p == 0){
        		continue;
				}
		    	break;
			}
			if(pass[p] == 32){
				printf("*");
				p++;
				continue;
			}
			if(pass[p] == 8){
				if(p == 0){
        		continue;
				}
				printf("\b \b");
				p--;
				continue;
			}
			if(((pass[p] >= 'A' && pass[p] <= 'Z') || (pass[p] >= 'a' && pass[p] <= 'z') || (pass[p] >= '0' && pass[p] <= '9')) == 0){
				continue;
			} 
		        printf("*"); 
		    p++; 
		}while(1); 
		pass[p]='\0';
		if(strcmp(pass,gmail[index].pass) == 0){
			break;
		}
		printf("\nPassword Salah!\n");
	}
	
	indexlogingmail = index;
	printf("\nLogin Berhasil\n");
	clrscr();
	gmaildashboard();	
}

void gmailregister(){
	
	char name[100],email[100], pass[100];
	printf("-----------------------------------------------------------\n");
	printf("Nama Lengkap\t: ");
	scanf("%[^\n]", &name);
	while(1){
		printf("Email\t\t: ");
		scanf("%s", &email);
		if(strcmp(email,"0") == 0){
			clearscreenAbort();
			gmailstart();
		}
		int flag = 0;
		for(int i = 0; i < jlhgmail; i++){
			if(strcasecmp(email,gmail[i].email) == 0){
				flag = 1;
			}
		}
		if(flag){
			printf("Email Sudah Ada\n");
			continue;
		}
		
		break;
	}
	
	printf("Password\t: ");
	int p=0; 
    do{ 
        pass[p]=getch();
        if(pass[p] == 13){
        	if(p == 0){
        		continue;
			}
        	break;
		}
		if(pass[p] == 32){
			printf("*");
			p++;
			continue;
		}
		if(pass[p] == 8){
			if(p == 0){
				continue;
			}
			printf("\b \b");
			p--;
			continue;
		}
		if(((pass[p] >= 'A' && pass[p] <= 'Z') || (pass[p] >= 'a' && pass[p] <= 'z') || (pass[p] >= '0' && pass[p] <= '9')) == 0){
			continue;
		} 
            printf("*"); 
        p++; 
    }while(1); 
    pass[p]='\0';
	
	printf("\nAkun Berhasil Dibuat\n");
	strcpy(gmail[jlhgmail].name,name);
	strcpy(gmail[jlhgmail].email,email);
	strcpy(gmail[jlhgmail].pass,pass);
	
	jlhgmail++;
	
	editfilegmail();
	clrscr();
	gmailstart();
	
}

void gmaildashboard(){
	time_t t;
	time(&t);
	
	system("@cls||clear");
	printf("=========================================================================================\n");
	printf("=                                      GMAIL                                            =\n");
	printf("=========================================================================================\n");
	printf("%s\n",ctime(&t));
	printf("Selamat Datang %s\n", gmail[indexlogingmail].name);
	printf("-----------------------------------------------------------\n");
	printf("No.\tPengirim\t\t\tKeterangan@\t\t\t\tWaktu\n");
	gmailmessage();
	printf("=============================================================\n");	
	printf("[<--] Previous              %d-%d                  Next [-->]\n",((gmailpagenow - 1) * 20 + 1), (gmailpagenow *20));
	printf("   [D = Delete]                        \n");
	
	int a = (gmail[indexlogingmail].inboxcount % 20 == 0) ? gmail[indexlogingmail].inboxcount/20 : gmail[indexlogingmail].inboxcount/20 + 1;
	
	while(1){
		
		if(kbhit()){
			char c = getch();
			 // <--
			if(c == 75){
				if(gmailpagenow != 1){
					gmailpagenow--;
					gmaildashboard();
				}	
			}
			// -->
			else if(c == 77){
				if(gmailpagenow != a){
					gmailpagenow++;
					gmaildashboard();
				}		
			}
			else if(c == 48){
				gmailpagenow = 1;
				gmailstart();
			}	
			else if(c == 68 || c == 100){
				deletemail();
			}
		}
		
	}
	
	
}

void gmailmessage(){
	
	for(int i = ( (gmailpagenow - 1) * 20); i < (gmailpagenow * 20); i++){
		if(i >= gmail[indexlogingmail].inboxcount){
			break;
		}
		int len = strlen(gmail[indexlogingmail].inbox[i].keterangan);
		printf("%d\t%s\t", (i+1), gmail[indexlogingmail].inbox[i].pengirim);
		printf("%s", gmail[indexlogingmail].inbox[i].keterangan);
		
		if(len >= 40){
			printf("\t");
		}
		else if(len >= 32){
			printf("\t\t");
		}
		else if(len >= 24){
			printf("\t\t\t");
		}
		else if(len >= 16){
			printf("\t\t\t\t");
		}
		else if(len >= 8){
			printf("\t\t\t\t\t");
		}
		printf("%s\n", gmail[indexlogingmail].inbox[i].waktu);
	}
		
}

void deletemail(){
	int num;
	printf("=============================================================\n");	
	
	while(1){
		printf("Delete Mail Number [%d-%d] : ", 1, gmail[indexlogingmail].inboxcount);
		scanf("%d", &num);
		
		if(num == 0){
			clearscreenAbort();
			gmaildashboard();
		}
		if(num < 1 || num > gmail[indexlogingmail].inboxcount){
			printf("Out Of Bounds\n");
			continue;
		}
		else{
			break;
		}	
	}
	
	for(int i = num - 1; i < gmail[indexlogingmail].inboxcount - 1; i++){
		strcpy(gmail[indexlogingmail].inbox[i].pengirim, gmail[indexlogingmail].inbox[i + 1].pengirim);
		strcpy(gmail[indexlogingmail].inbox[i].keterangan, gmail[indexlogingmail].inbox[i + 1].keterangan);
		strcpy(gmail[indexlogingmail].inbox[i].waktu, gmail[indexlogingmail].inbox[i + 1].waktu);
	}
	
	gmail[indexlogingmail].inboxcount--;

	editfilegmail();
	
	printf("Delete Berhasil\n");
	clrscr();
	gmaildashboard();
		
}

void scanfilegmail(){
	FILE *fp = fopen("Email.txt", "r");
	
	while(fscanf(fp,"%s%*c", &gmail[jlhgmail].email) != EOF){
		fscanf(fp,"%[^\n]%*c", &gmail[jlhgmail].name);
		fscanf(fp,"%[^\n]", &gmail[jlhgmail].pass);
		fscanf(fp,"%d%*c",&gmail[jlhgmail].inboxcount);
		
		for(int i = 0; i < gmail[jlhgmail].inboxcount; i++){
			fscanf(fp,"Gmail.com %s%*c", gmail[jlhgmail].inbox[i].pengirim);
			fscanf(fp,"%[^\n]%*c", gmail[jlhgmail].inbox[i].keterangan);
			fscanf(fp,"%[^\n]%*c", gmail[jlhgmail].inbox[i].waktu);	
		}
		jlhgmail++;
	}
	
	fclose(fp);	
}

void editfilegmail(){
	
	FILE *fp = fopen("Email.txt", "w");	
	
	for(int i = 0; i < jlhgmail; i++){
		fprintf(fp, "%s\n", gmail[i].email);
		fprintf(fp, "%s\n", gmail[i].name);
		fprintf(fp, "%s\n", gmail[i].pass);
		fprintf(fp, "%d\n", gmail[i].inboxcount);
		
		for(int j = 0; j < gmail[i].inboxcount; j++){
			fprintf(fp, "Gmail.com %s\n", gmail[i].inbox[j].pengirim);
			fprintf(fp, "%s\n", gmail[i].inbox[j].keterangan);
			fprintf(fp, "%s\n", gmail[i].inbox[j].waktu);
		}
	}
	
	fclose(fp);
}
