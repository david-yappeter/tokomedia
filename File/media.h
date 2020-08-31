// MBanking Account Structure
typedef struct bannnk{
	char username[100];
	char email[100];
	char pass[100];
};

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

// variabel Global
clock_t tim;
	// Variabel Global Tokomedia
	int jlhuser = 0;
	int itemcount = 0;
	int indexloginskrg = -1;
	int pagenow = 1;
	int cartnow = 1;
	int totalbelanjaan;
	// Variabel Global Gmail
	int indexlogingmail = -1;
	int jlhgmail = 0;
	int gmailpagenow = 1;
	// Variabel Global MBanking
	int indexloginbank = -1;
	int jlhbank = 0;

// struct Global
akuntoko pengguna[100];
Itemm itemlist[200];
structemail gmail[100];
bannnk Mbank[100];

// Method Tampilan Website
	// Method Tampilan Web
	void website();
	// Method Tampilan TokoMedia
	void start1();
	void Register();
	void Login();
	void mainmenu();
	void ListItem();
	void itempage();
	void cartmenu();
	void cartpage();
	void checkoutform();
	// Method Tampilan Gmail
	void gmailstart();
	void gmaillogin();
	void gmailregister();
	void gmaildashboard();
	void gmailmessage();
	// Method Tampilan MBanking
	void MBankingstart();
	void MBankinglogin();
	void MBankingRegister();
	void Mbankingmenu();
	void Topup();

// Method Logout
void logout();

// Method File
	// Method File TokoMedia
	void scanfileuser();
	void editfileuser();
	void scanitem();
	// Method File Gmail
	void scanfilegmail();
	void editfilegmail();
	// Method File MBanking
	void scanfilebank();
	void editfilebank();

// Method Cart
void addtoCart();
void deletecart();
void checkout();

// Method Gmail
void deletemail();

// Method Top-up
void tambahsaldo(int saldo);

// Method Perhitungan
void totalharga();
void totalglobal();

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

void start1(){
	time_t t;
	time(&t);	
	
	
	tim = clock();
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
		getchar();
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

void logout(){
	indexloginskrg = -1;
	pagenow = 1;
	cartnow = 1;
	printf("Logging Out\n");
	clrscr();
	start1();	
}

void scanfileuser(){
	FILE *fp = fopen("File/Akun.txt","r");
	
	while(fscanf(fp, "%[^\n]%*c", &pengguna[jlhuser].namaasli) != EOF){
		fscanf(fp,"%s%*c", &pengguna[jlhuser].email);
		fscanf(fp,"%[^\n]%*c", &pengguna[jlhuser].password);
		fscanf(fp,"%d%*c", &pengguna[jlhuser].saldo);
		jlhuser++;
	}	
	
	fclose(fp);
}

void editfileuser(){
	FILE *fp = fopen("File/Akun.txt", "w");
	
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
	FILE *fp = fopen("File/list_barang.txt", "r");

	while(fscanf(fp,"%[^\n]%*c", &itemlist[itemcount].arr) != EOF){
		fscanf(fp,"Rp.%d%*c", &itemlist[itemcount].harga);
		itemcount++;
	}
	
	fclose(fp);
}

void scanfilegmail(){
	FILE *fp = fopen("File/Email.txt", "r");
	
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
	
	FILE *fp = fopen("File/Email.txt", "w");	
	
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

void scanfilebank(){
	FILE *fp = fopen("File/Bank.txt", "r");
	
	while(fscanf(fp,"%[^\n]%*c", &Mbank[jlhbank].username) != EOF){
		fscanf(fp,"%s%*c", &Mbank[jlhbank].email);
		fscanf(fp, "%[^\n]%*c", &Mbank[jlhbank].pass);
		jlhbank++;
	}
	
	fclose(fp);		
}

void editfilebank(){
	FILE *fp = fopen("File/Bank.txt", "w");	
	
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
		if(num < 1 || num > itemcount){
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
