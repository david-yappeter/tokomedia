

#ifndef DATA
#include "email.h"
#include "banking.h"
#include "GlobalVariable.h"
#define DATA 1
#endif
// Item Structure
typedef struct Itemm{
	char arr[100];
	int harga;
};

// Cart Item
typedef struct CartSt{
	char arr[100];
	int harga;	
	int jumlah;
};

// user Structure
typedef struct akuntoko{
	char namaasli[100];
	char email[100];
	char password[100];
	int saldo;	
	CartSt cart[100];
	int cartcount = 0;
};


// Variabel Global Tokomedia
int jlhuser = 0;
int itemcount = 0;
int indexloginskrg = -1;
int pagenow = 1;
int cartnow = 1;
int totalbelanjaan;

// struct Global Tokomedia
akuntoko pengguna[100];
Itemm itemlist[200];


// Method Tampilan Tokomedia
void start1();
void Register();
void Login();
void mainmenu();
void ListItem();
void itempage();
void cartmenu();
void cartpage();
void checkoutform();

// Method File Tokomedia
void scanfileuser();
void editfileuser();
void scanitem();

// Method Cart
void addtoCart();
void deletecart();
void checkout();

// Method Perhitungan
void totalharga();
void totalglobal();

void start1(){
	time_t t;
	time(&t);	
	
	system("@cls||clear");
	printf("=============================================================\n");
	printf("=                         TOKOMEDIA                         =\n");
	printf("=============================================================\n");
	printf("%s\n",ctime(&t));
	printf("Penyedia Barang-Barang Elektronik Rumah Tangga, Mudah & Aman\n");
	printf("-----------------------------------------------------------\n");
	printf("[1] Login\n");
	printf("[2] Register\n");
	printf("[3] Return\n");
	printf("[0] Exit\n");
	printf("-----------------------------------------------------------\n");
	printf("OS : ");
	
	#ifdef _WIN32 // Termasuk 32 dan 64 bit
		#ifdef _WIN64
	        printf("Windows 64 bit\n");
	    #else 
	        printf("Windows 32 bit\n");
	    #endif
	#elif __linux__
  		printf("Linux\n");
 	#elif TARGET_OS_MAC
  		printf("MacOS\n");
 	#elif APPLE
  		printf("Apple OS\n");
 	#elif __ANDROID_
  		printf("Android\n");
	#endif
	printf("-----------------------------------------------------------\n");
	printf(">>>");
	
	while(1){
		
		if(kbhit()){
			char c = getch();
			if(c == 49){
				printf("1\n");
				Login();
			}
			else if(c == 50){
				printf("2\n");
				Register();
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

void Login(){
	char email[100], pass[100];
	printf("-----------------------------------------------------------\n");
	
	int index;
	while(1){
		printf("Email : ");
		scanf("%s", &email);
		if(strcmp(email,"0") == 0){
			clearscreenAbort();
			start1();
		}
		int flag = 0;
		for(int i = 0; i < jlhuser; i++){
			if(strcasecmp(email,pengguna[i].email) == 0){
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
//		scanf("%[^\n]",pass);
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
		if(strcmp(pass,pengguna[index].password) == 0){
			break;
		}
		printf("\nPassword Salah!\n");
	}
	
	indexloginskrg = index;
	printf("\nLogin Berhasil\n");
	clrscr();
	mainmenu();
}

void Register(){
	char name[100],email[100], pass[100];
	printf("-----------------------------------------------------------\n");
	printf("Nama Lengkap\t: ");
	scanf("%[^\n]", &name);
	while(1){
		printf("Email\t\t: ");
		scanf("%s", &email);
		if(strcmp(email,"0") == 0){
			clearscreenAbort();
			start1();
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
		
		for(int i = 0; i < jlhuser; i++){
			if(strcasecmp(email,pengguna[i].email) == 0){
				flag = 0;	
			}
		}
		if(flag){
			break;
		}
		printf("Email Sudah Terdaftar!!\n");
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
	strcpy(pengguna[jlhuser].namaasli,name);
	strcpy(pengguna[jlhuser].email,email);
	strcpy(pengguna[jlhuser].password,pass);
	pengguna[jlhuser].saldo = 0;
	jlhuser++;
	editfileuser();
	clrscr();
	start1();
}

void mainmenu(){
	time_t t;
	time(&t);	
	
	tim = clock();
	system("@cls||clear");
	printf("=========================================================================================\n");
	printf("=                                    TOKOMEDIA                                          =\n");
	printf("=========================================================================================\n");
	printf("%s\n",ctime(&t));
	printf("Selamat datang %s\n", pengguna[indexloginskrg].namaasli);
	printf("Saldo Anda : Rp %d\n", pengguna[indexloginskrg].saldo);
	printf("-----------------------------------------------------------\n");
	printf("[1] Lihat List Item\n");
	printf("[2] Cart\n");
	printf("[3] Check-Out\n");
	printf("[4] Return\n");
	printf("[0] Logout\n");
	printf("-----------------------------------------------------------\n");	
	printf(">>>");
	
	while(1){
		
		if(kbhit()){
			char c = getch();
			if(c == 49){
				ListItem();
			}
			else if(c == 50){
				cartmenu();	
			}
			else if(c == 51){
				checkoutform();
			}
			else if(c == 52){
				website();
			}
			else if(c == 48){
				logout();
			}
		}
		
	}
	
}

void ListItem(){
	system("@cls||clear");
	printf("=========================================================================================\n");
	printf("=                                    TOKOMEDIA                                          =\n");
	printf("=========================================================================================\n");
	printf("No.\t\tNama\t\t\t\t\tHarga\n");
	itempage();
	printf("=====================================================================\n");	
	printf("[<--] Previous       %d-%d       [B = Add To Cart]         Next [-->]\n",((pagenow - 1) * 20 + 1), (pagenow *20));
	
	int a = (itemcount % 20 == 0) ? itemcount/20 : itemcount/20 + 1;
	
	while(1){
		
		if(kbhit()){
			char c = getch();
			 // <--
			if(c == 75){
				if(pagenow != 1){
					pagenow--;
					ListItem();
				}	
			}
			// -->
			else if(c == 77){
				if(pagenow != a){
					pagenow++;
					ListItem();
				}		
			}
			else if(c == 48){
				pagenow = 1;
				mainmenu();
			}	
			else if(c == 66 || c == 98){
			 	addtoCart();		
			}
		}
		
	}
}

void itempage(){
	
	for(int i = ( (pagenow - 1) * 20); i < (pagenow * 20); i++){
		if(i >= itemcount){
			break;
		}
		int len = strlen(itemlist[i].arr);
		printf("%d\t%s", (i+1), itemlist[i].arr);
		
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
		printf("Rp.%d\n", itemlist[i].harga);
	}
		
}

void cartmenu(){
	system("@cls||clear");
	printf("=========================================================================================\n");
	printf("=                                    TOKOMEDIA                                          =\n");
	printf("=========================================================================================\n");
	printf("No.\t\tNama\t\t\t\t\tHarga@\t\tJumlah\n");
	cartpage();
	printf("=============================================================\n");	
	printf("[<--] Previous              %d-%d                  Next [-->]\n",((cartnow - 1) * 20 + 1), (cartnow *20));
	printf("   [D = Delete]                           [T = total]\n");
	
	int a = (pengguna[indexloginskrg].cartcount % 20 == 0) ? pengguna[indexloginskrg].cartcount/20 : pengguna[indexloginskrg].cartcount/20 + 1;
	
	while(1){
		
		if(kbhit()){
			char c = getch();
			 // <--
			if(c == 75){
				if(cartnow != 1){
					cartnow--;
					cartmenu();
				}	
			}
			// -->
			else if(c == 77){
				if(cartnow != a){
					cartnow++;
					cartmenu();
				}		
			}
			else if(c == 48){
				cartnow = 1;
				mainmenu();
			}	
			else if(c == 68 || c == 100){
				deletecart();	
			}
			else if(c == 84 || c == 116){
				totalharga();
			}
		}
		
	}
	
}

void cartpage(){
	
	for(int i = ( (cartnow - 1) * 20); i < (cartnow * 20); i++){
		if(i >= pengguna[indexloginskrg].cartcount){
			break;
		}
		int len = strlen(pengguna[indexloginskrg].cart[i].arr);
		printf("%d\t%s", (i+1), pengguna[indexloginskrg].cart[i].arr);
		
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
		printf("Rp.%d\t%d\n", pengguna[indexloginskrg].cart[i].harga, pengguna[indexloginskrg].cart[i].jumlah);
	}	
}

void checkoutform(){
	totalglobal();
	system("@cls||clear");
	printf("=========================================================================================\n");
	printf("=                                    TOKOMEDIA                                          =\n");
	printf("=========================================================================================\n");
	printf("No.\t\tNama\t\t\t\t\tHarga@\t\tJumlah\n");
	cartpage();
	printf("=============================================================\n");	
	printf("[<--] Previous              %d-%d                  Next [-->]\n",((cartnow - 1) * 20 + 1), (cartnow *20));
	printf("Total Harga : Rp%d\n", totalbelanjaan);
	printf("Saldo Anda : Rp. %d\n", pengguna[indexloginskrg].saldo);
	printf("=============================================================\n");	
	printf("[1] Check-out\n");
	printf("[2] Return\n");
		
	while(1){
		if(kbhit()){
			char c = getch();
			if(c == 49){
				checkout();
			}
			else if(c == 50){
				mainmenu();
			}
		}	
	}	
	
}

void checkout(){
	printf("=============================================================\n");	
	if(pengguna[indexloginskrg].saldo < totalbelanjaan){
		printf("SALDO TIDAK CUKUP!\n");
		clrscr();
		mainmenu();
	}	
	
	pengguna[indexloginskrg].saldo -= totalbelanjaan;
	printf("Berhasil\n");
	
	int index;
	for(int i = 0; i < jlhgmail; i++){
		if(strcasecmp(pengguna[indexloginskrg].email, gmail[i].email) == 0){
			index = i;
		}
	}
	
	time_t t;
	time(&t);
	
	strcpy(gmail[index].inbox[gmail[index].inboxcount].pengirim, "Tokomedia.com");
	strcpy(gmail[index].inbox[gmail[index].inboxcount].keterangan, "Transaksi Berhasil");
	strcpy(gmail[index].inbox[gmail[index].inboxcount].waktu, ctime(&t));
	
	gmail[index].inboxcount++;
	
	pengguna[indexloginskrg].cartcount = 0;
	
	editfilegmail();
	editfileuser();
	
	clrscr();
	mainmenu();
}

void scanfileuser(){
	FILE *fp = fopen("Akun.txt","r");
	
	while(fscanf(fp, "%[^\n]%*c", &pengguna[jlhuser].namaasli) != EOF){
		fscanf(fp,"%s%*c", &pengguna[jlhuser].email);
		fscanf(fp,"%[^\n]%*c", &pengguna[jlhuser].password);
		fscanf(fp,"%d%*c", &pengguna[jlhuser].saldo);
		jlhuser++;
	}	
	
	fclose(fp);
}

void editfileuser(){
	FILE *fp = fopen("Akun.txt", "w");
	
	for(int i = 0; i < jlhuser; i++){
		fprintf(fp, "%s\n", pengguna[i].namaasli);
		fprintf(fp, "%s\n", pengguna[i].email);
		fprintf(fp, "%s\n", pengguna[i].password);
		fprintf(fp, "%d", pengguna[i].saldo);
		if(i != jlhuser - 1){
			fprintf(fp,"\n");
		}	
	}
	fclose(fp);
}

void scanitem(){
	FILE *fp = fopen("list_barang.txt", "r");

	while(fscanf(fp,"%[^\n]%*c", &itemlist[itemcount].arr) != EOF){
		fscanf(fp,"Rp.%d%*c", &itemlist[itemcount].harga);
		itemcount++;
	}
	
	fclose(fp);
}





void addtoCart(){
	int num;
	printf("=============================================================\n");	
	
	while(1){
		printf("Add To Cart Item Number [%d-%d] : ", 1, itemcount);
		scanf("%d", &num);
		
		if(num == 0){
			clearscreenAbort();
			ListItem();
		}
		if(num < 1 && num > itemcount){
			printf("Out Of Bounds\n");
			continue;
		}
		else{
			break;
		}	
	}
	int jumlah;
	while(1){
		printf("Jumlah Item : ");
		scanf("%d", &jumlah);
		if(jumlah == 0){
			clearscreenAbort();
			ListItem();	
		}
		if(jumlah < 0){
			printf("Tidak Valid!\n");
			continue;
		}
		else{
			break;
		}
	}
	strcpy(pengguna[indexloginskrg].cart[pengguna[indexloginskrg].cartcount].arr, itemlist[num-1].arr);
	pengguna[indexloginskrg].cart[pengguna[indexloginskrg].cartcount].harga =  itemlist[num-1].harga;
	pengguna[indexloginskrg].cart[pengguna[indexloginskrg].cartcount].jumlah = jumlah;
	pengguna[indexloginskrg].cartcount++;
	
	printf("Barang Berhasil Ditambah\n");
	clrscr();
	ListItem();
	
}

void deletecart(){
	int num;
	printf("=============================================================\n");	
	
	while(1){
		printf("Delete Item Number [%d-%d] : ", 1, pengguna[indexloginskrg].cartcount);
		scanf("%d", &num);
		
		if(num == 0){
			clearscreenAbort();
			ListItem();
		}
		if(num < 1 && num > pengguna[indexloginskrg].cartcount){
			printf("Out Of Bounds\n");
			continue;
		}
		else{
			break;
		}	
	}
	
	strcpy(pengguna[indexloginskrg].cart[num-1].arr, pengguna[indexloginskrg].cart[pengguna[indexloginskrg].cartcount - 1].arr);
	pengguna[indexloginskrg].cart[num-1].harga =  pengguna[indexloginskrg].cart[pengguna[indexloginskrg].cartcount - 1].harga;
	pengguna[indexloginskrg].cart[num-1].jumlah = pengguna[indexloginskrg].cart[pengguna[indexloginskrg].cartcount - 1].jumlah;
	pengguna[indexloginskrg].cartcount--;
	
	printf("Delete Berhasil\n");
	clrscr();
	cartmenu();
		
}

void totalharga(){
	printf("=============================================================\n");	
	int total = 0;
	for(int i = 0; i < pengguna[indexloginskrg].cartcount; i++){
		total += (pengguna[indexloginskrg].cart[i].jumlah *pengguna[indexloginskrg].cart[i].harga);
	}
	totalbelanjaan = total;
	printf("Total Harga : Rp. %d\n", total);
	clrscr();
	cartmenu();
}

void totalglobal(){
	int total = 0;
	for(int i = 0; i < pengguna[indexloginskrg].cartcount; i++){
		total += (pengguna[indexloginskrg].cart[i].jumlah *pengguna[indexloginskrg].cart[i].harga);
	}
	totalbelanjaan = total;
}
