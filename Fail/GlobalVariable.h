#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include<math.h>
#include<string.h>

#ifndef GLOBAL
#define GLOBAL 1
#include "email.h"
#include "banking.h"
#include "media.h"
#endif
// variabel Global
clock_t tim;

// Method Tampilan Web
void website();

// Method Logout
void logout();

// Method Lainnya
void clearscreenAbort();
void clrscr();
void endprogram();

void website(){
	time_t t;
	time(&t);
	system("@cls||clear");
	printf("=============================================================\n");
	printf("=                          WEBSITE                          =\n");
	printf("=============================================================\n");
	printf("%s\n",ctime(&t));
	printf("-----------------------------------------------------------\n");
	printf("[1] Tokomedia.com\n");
	printf("[2] Gmail.com\n");
	printf("[3] Banking\n");
	printf("[0] Exit\n");
	printf("-----------------------------------------------------------\n");
	printf(">>>");
	
	while(1){
		
		if(kbhit()){
			char c = getch();
			if(c == 49){
				printf("1\n");
				start1();
			}
			else if(c == 50){
				printf("2\n");
				gmailstart();
			}
			else if(c == 51){
				printf("3\n");
				MBankingstart();
			}
			else if(c == 48){
				printf("0");
				endprogram();
			}
		}	
	}
	
}

void logout(){
	indexloginskrg = -1;
	pagenow = 1;
	cartnow = 1;
	printf("Logging Out\n");
	clrscr();
	start1();	
}

void clearscreenAbort(){
	printf("Aborting Operation\n");
	printf("Press Enter to Continue\n");
	getchar();
	getchar();	
}

void endprogram(){
	printf("\n--------------------------------------\n");
	tim = clock() - tim;
	double time_taken = ((double)tim)/CLOCKS_PER_SEC;
	printf("Program digunakan selama %.4lf detik", time_taken);
	exit(0);
}

void clrscr(){
	printf("Press Enter to Continue\n");
	getchar();
	getchar();	
}
