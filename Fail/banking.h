#ifndef BANKER
#define BANKER 1
#include "email.h"
#include "media.h"
#include "GlobalVariable.h"
#endif
// MBanking Account Structure
typedef struct bannnk{
	char username[100];
	char email[100];
	char pass[100];
};


// Variabel Global MBanking
int indexloginbank = -1;
int jlhbank = 0;

// struct Global Bank
bannnk Mbank[100];

// Method Tampilan MBanking
void MBankingstart();
void MBankinglogin();
void MBankingRegister();
void Mbankingmenu();
void Topup();

// Method Top-up
void tambahsaldo(int saldo);

// Method File MBanking
void scanfilebank();
void editfilebank();

void MBankingstart(){
	time_t t;
	time(&t);
	
	system("@cls||clear");
	printf("=========================================================================================\n");
	printf("=                                    MBANKING                                           =\n");
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
				MBankinglogin();
			}
			else if(c == 50){
				printf("2\n");
				MBankingRegister();
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

void MBankinglogin(){
	
	char username[100], pass[100];
	printf("-----------------------------------------------------------\n");
	int index;
	while(1){
		printf("Username : ");
		scanf("%s", &username);
		if(strcmp(username,"0") == 0){
			clearscreenAbort();
			MBankingstart();
		}
		int flag = 0;
		for(int i = 0; i < jlhbank; i++){
			if(strcasecmp(username,Mbank[i].username) == 0){
				index = i;
				flag = 1;
				break;
			}
		}
		if(flag){
			break;
		}
		printf("Username Tidak Ada!!\n");
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
		if(strcmp(pass,Mbank[index].pass) == 0){
			break;
		}
		printf("\nPassword Salah!\n");
	}
	
	indexloginbank = index;
	printf("\nLogin Berhasil\n");
	clrscr();
	Mbankingmenu();
}

void MBankingRegister(){
	
	char username[100],email[100], pass[100];
	printf("-----------------------------------------------------------\n");
	while(1){	
		printf("Username\t: ");
		scanf("%[^\n]", &username);
		
		if(strcmp(username, "0") == 0){
			clearscreenAbort();
			MBankingstart();
		}
		int flag = 0;
		for(int i = 0; i < jlhbank; i++){
			if(strcasecmp(username,Mbank[i].username) == 0){
				flag = 1;
				break;
			}
		}
		
		if(flag){
			printf("Username Sudah Ada\n");
			continue;
		}
		break;
	}
	while(1){
		printf("Bind Email\t\t: ");
		scanf("%s", &email);
		if(strcmp(email,"0") == 0){
			clearscreenAbort();
			MBankingstart();
		}
		int flag = 0;
		for(int i = 0; i < jlhgmail; i++){
			if(strcasecmp(email,gmail[i].email) == 0){
				flag = 1;
			}
		}
		if(flag == 0){
			printf("Email Tidak Terdaftar!\n");
			continue;
		}
		
		for(int i = 0; i < jlhbank; i++){
			if(strcasecmp(email,Mbank[i].email) == 0){
				flag = 0;	
			}
		}
		if(flag){
			break;
		}
		printf("Email Sudah Digunakan!!\n");
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
	strcpy(Mbank[jlhbank].username,username);
	strcpy(Mbank[jlhbank].email,email);
	strcpy(Mbank[jlhbank].pass,pass);
	jlhbank++;
	editfilebank();
	clrscr();
	MBankingstart();
}

void Mbankingmenu(){
	time_t t;
	time(&t);
	char name[100];
	for(int i = 0; i < jlhgmail; i++){
		if(strcasecmp(Mbank[indexloginbank].email, gmail[i].email) == 0){
			strcpy(name, gmail[i].name);
		}
	}
	
	system("@cls||clear");
	printf("=========================================================================================\n");
	printf("=                                    MBANKING                                           =\n");
	printf("=========================================================================================\n");
	printf("%s\n",ctime(&t));
	printf("Selamat Datang %s\n", name);
	printf("-----------------------------------------------------------\n");
	printf("[1] Top-up Saldo Tokomedia\n");
	printf("[0] Logout\n");
	printf("-----------------------------------------------------------\n");
	printf(">>>");
	
	while(1){
		
		if(kbhit()){
			char c = getch();
			if(c == 49){
				printf("1\n");
				Topup();
			}
			else if(c == 48){
				printf("0\n");
				printf("Logging Out\n");
				clrscr();
				MBankingstart();
			}
		}	
	}
	
	
}

void Topup(){
	printf("-----------------------------------------------------------\n");
	printf("Pilihan Top up :\n");
	printf("[1] Rp.1.000.000\n");
	printf("[2] Rp.10.000.000\n");
	printf("[3] Custom\n");
	printf("-----------------------------------------------------------\n");
	printf(">>>");
	while(1){
		
		if(kbhit()){
			char c = getch();
			if(c == 49){
				printf("1\n");
				tambahsaldo(1000000);
			}
			else if(c == 50){
				printf("2\n");
				tambahsaldo(10000000);
			}
			else if(c == 51){
				printf("3\n");
				printf("-----------------------------------------------------------\n");
				printf("Total Top-Up : Rp.");
				int num;
				scanf("%d", &num);
				tambahsaldo(num);
			}
			else if(c == 48){
				printf("0\n");
				clearscreenAbort();
				Mbankingmenu();
			}
		}	
	}
}

void tambahsaldo(int saldo){
	if(saldo <= 0){
		printf("Tidak Valid\n");
		clearscreenAbort();
		Mbankingmenu();
	}	
	
	int index;
	
	for(int i = 0; i < jlhuser; i++){
		if(strcmp(Mbank[indexloginbank].email, pengguna[i].email) == 0){
			index = i;
			break;
		}
	}
	
	pengguna[index].saldo += saldo;
	printf("Berhasil Melakukan Top-up\n");
	
	for(int i = 0; i < jlhgmail; i++){
		if(strcmp(Mbank[indexloginbank].email, gmail[i].email) == 0){
			index = i;
			break;
		}	
	}
	
	time_t t;
	time(&t);
	
	strcpy(gmail[index].inbox[gmail[index].inboxcount].pengirim, "MBanking");
	strcpy(gmail[index].inbox[gmail[index].inboxcount].keterangan, "Top-Up Saldo Berhasil");
	strcpy(gmail[index].inbox[gmail[index].inboxcount].waktu, ctime(&t));
	gmail[index].inboxcount++;
	editfilegmail();
	editfileuser();
	
	clrscr();
	Mbankingmenu();
}

void scanfilebank(){
	FILE *fp = fopen("Bank.txt", "r");
	
	while(fscanf(fp,"%[^\n]%*c", &Mbank[jlhbank].username) != EOF){
		fscanf(fp,"%s%*c", &Mbank[jlhbank].email);
		fscanf(fp, "%[^\n]%*c", &Mbank[jlhbank].pass);
		jlhbank++;
	}
	
	fclose(fp);		
}

void editfilebank(){
	FILE *fp = fopen("Bank.txt", "w");	
	
	for(int i = 0; i < jlhbank; i++){
		fprintf(fp,"%s\n", Mbank[i].username);
		fprintf(fp,"%s\n",Mbank[i].email);
		fprintf(fp,"%s",Mbank[i].pass);
		if(i != jlhbank - 1){
			fprintf(fp,"\n");
		}
	}
	
	fclose(fp);	
}
