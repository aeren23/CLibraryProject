#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
	int Id;
	char Name[100];
	char Author[100];
	int paperCount;
	int IsRented;
}Books;

typedef struct{
	int Id;
	char Name[100];
	char Surname[100];
	char Depertmant[100];
	char BirthDate[100];
}Users;

typedef struct{
	int Id;
	int BookId;
	int UserId;
	char StartDate[100];
	char FinishDate[100];
}Rents;

//Functions
int getLengthBook();
int getLengthUsers();
int getLengthRents();
Books* GetBooks();
Users* GetUsers();
Rents* getRents();
void ListUsers();
void ListBooks();
void ListRents();
void AddBook();
void AddUser();
void UpdateBooks(int upId);
void UpdateUsers(int upId);
void UpdateRents(int GUserId,int RentId);
void DeleteBook(int DelId);
void DeleteUser(int DelId);
void RentBook(int RUserId,int RentBookId);

void SearchBook(char *tempC);
void SearchUser(char *tempC);

void DesignMenu();
void DesignMenu2();

void clearScreen() {
    system("cls");
}

void main(){
	char *tempC= (char *)malloc(50);
	int transactionNo;
line15:
	printf(" Lutfen Yapmak Istediginiz Islemi Turunu Secmek Icin Yanindaki Sayiyi Giriniz:\n");
	DesignMenu();
	printf(" Kitap Islemleri(1)\n Kullanici Islemleri(2)\n Odunc Islemleri(3)\n");
	DesignMenu();
line1:	
	printf("Islem Numarasini Giriniz:");
	scanf("%d",&transactionNo);
	if(transactionNo<1 || transactionNo>3){
		printf("Lutfen belirtilen araliklarda deger giriniz!\n");
		goto line1;
	}
	clearScreen();
	if(transactionNo==1){
		clearScreen();
		printf("Kitap Islemleri:\n");
		DesignMenu();
		printf(" Kitap Listeleme(1) \n Kitap Ekleme(2) \n Kitap Guncelleme(3) \n Kitap Silme(4) \n Kitap Arama(5) \n\n");
		DesignMenu2();
	 line2:
		printf(" Lutfen Yapmak Istediginiz Islemi Secmek Icin Yanindaki Sayiyi Giriniz:\n");
		scanf("%d",&transactionNo);
		if(transactionNo<1 || transactionNo>5){
		printf("Lutfen belirtilen araliklarda deger giriniz!\n");
			goto line1;
		}
		switch(transactionNo){
			case 1:
				clearScreen();
				DesignMenu2();
				ListBooks();
				printf("Menu'ye Donmek Icin(0):");
				scanf("%d",&transactionNo);
				if(transactionNo==0){
					clearScreen();
					goto line15;
				}
				break;
			case 2:
				clearScreen();
				DesignMenu2();
				AddBook();
				printf("Kitap Ekleme Islemi Basarili\n");
				printf("Menu'ye Donmek Icin(0):");
				scanf("%d",&transactionNo);
				if(transactionNo==0){
					clearScreen();
					goto line15;
				}
			    break;
			case 3:
				clearScreen();
				ListBooks();
				DesignMenu();
				int UpdateId;
				printf("Lütfen guncellemek istediginiz kitabýn Id'sini giriniz:");
				scanf("%d",&UpdateId);
				UpdateBooks(UpdateId);
				clearScreen();
				printf("Yeni Degerler:\n");
				DesignMenu();
				ListBooks();
				printf("Menu'ye Donmek Icin(0):");
				scanf("%d",&transactionNo);
				if(transactionNo==0){
					clearScreen();
					goto line15;
				}
				break;
			case 4:
				clearScreen();
				ListBooks();
				DesignMenu();
				int DeleteId;
			line29:
				printf("Lutfen Silmek  Istediginiz Kitabin Id'sini giriniz:");
				scanf("%d",&DeleteId);
				Rents *rents=getRents();
				int rentLength=getLengthRents();
				for(int i=0;i<rentLength;i++){
					if(rents[i].BookId==DeleteId){
						printf("Sectiginiz kitap kiralanmis oldugu icin silinemez. Baska kitap seciniz\n\n");
						goto line29;
					}
				}
				DeleteBook(DeleteId);
				clearScreen();
				printf("Yeni Degerler:\n");
				DesignMenu();
				ListBooks();
				printf("Menu'ye Donmek Icin(0):");
				scanf("%d",&transactionNo);
				if(transactionNo==0){
					clearScreen();
					goto line15;
				}
				break;
			case 5:	
				clearScreen();
				printf("Kitap Ara:");
				scanf("%s",tempC);
				DesignMenu();
				SearchBook(tempC);
				DesignMenu();
				printf("Menu'ye Donmek Icin(0):");
				scanf("%d",&transactionNo);
				if(transactionNo==0){
					clearScreen();
					goto line15;
				}
				break;
			default:
			break;
		}
	}
	else if(transactionNo==2){
		clearScreen();
		printf("Kullanýcý Islemleri:\n");
		DesignMenu();
		printf(" Kullanici Listeleme(1) \n Kullanici Ekleme(2) \n Kullanici Guncelleme(3) \n Kullanici Silme(4) \n Kullanici Arama(5) \n\n");
		DesignMenu2();
	 line3:
		printf(" Lutfen Yapmak Istediginiz Islemi Secmek Icin Yanindaki Sayiyi Giriniz:\n");
		scanf("%d",&transactionNo);
		if(transactionNo<1 || transactionNo>5){
		printf("Lutfen belirtilen araliklarda deger giriniz!\n");
			goto line1;
		}
		switch(transactionNo){
			case 1:
				clearScreen();
				DesignMenu2();
				ListUsers();
				printf("Menu'ye Donmek Icin(0):");
				scanf("%d",&transactionNo);
				if(transactionNo==0){
					clearScreen();
					goto line15;
				}
			    break;
			case 2:
				clearScreen();
				DesignMenu2();
				AddUser();
				printf("Kullanici Ekleme Islemi Basarili\n");
				printf("Menu'ye Donmek Icin(0):");
				scanf("%d",&transactionNo); 
				if(transactionNo==0){
					clearScreen();
					goto line15;
				}
			    break;
			case 3:
				clearScreen();
				ListUsers();
				DesignMenu();
				int UpdateId;
				printf("Lutfen guncellemek istediginiz kullanicinin Id'sini giriniz:");
				scanf("%d",&UpdateId);
				UpdateUsers(UpdateId);
				clearScreen();
				printf("Yeni Degerler:\n");
				DesignMenu();
				ListUsers();
				printf("Menu'ye Donmek Icin(0):");
				scanf("%d",&transactionNo);
				if(transactionNo==0){
					clearScreen();
					goto line15;
				}
				break;
			case 4:
				clearScreen();
				ListUsers();
				DesignMenu();
				int DeleteId;
			line30:
				printf("Lutfen Silmek  Istediginiz Kullanicinin Id'sini giriniz:");
				scanf("%d",&DeleteId);
				Rents *rents=getRents();
				int rentLength=getLengthRents();
				for(int i=0;i<rentLength;i++){
					if(rents[i].UserId==DeleteId){
						printf("Sectiginiz kullanici kitap kiralamis oldugu icin silinemez. Baska kullanici seciniz.\n\n");
						goto line30;
					}
				}
				DeleteUser(DeleteId);
				clearScreen();
				printf("Yeni Degerler:\n");
				DesignMenu();
				ListUsers();
				printf("Menu'ye Donmek Icin(0):");
				scanf("%d",&transactionNo);
				if(transactionNo==0){
					clearScreen();
					goto line15;
				}
				break;
			case 5:
				clearScreen();
				printf("Kullanici Ara:");
				scanf("%s",tempC);
				DesignMenu();
				SearchUser(tempC);
				DesignMenu();
				printf("Menu'ye Donmek Icin(0):");
				scanf("%d",&transactionNo);
				if(transactionNo==0){
					clearScreen();
					goto line15;
				}
				break;
			default:
			break;
		}
	}
	else{
		clearScreen();
		printf("Odunc Islemleri:\n");
		DesignMenu();
		printf(" Odunc Alma(1) \n Kitabi Geri Ver(2) \n Odunc Listeleme(3) \n\n");
		DesignMenu2();
	 line4:
		printf(" Lutfen Yapmak Istediginiz Islemi Secmek Icin Yanindaki Sayiyi Giriniz:\n");
		scanf("%d",&transactionNo);
		if(transactionNo<1 || transactionNo>3){
		printf("Lutfen belirtilen araliklarda deger giriniz!\n");
			goto line1;
		}
		switch(transactionNo){
			case 1:
				clearScreen();
				printf("Odunc Alma:\n\n");
				DesignMenu();
				ListUsers();
				DesignMenu();
				Books *books=GetBooks();
				int RUserId;
				Rents *rents=getRents();
				int rentsLength=getLengthRents();
			line10:
				printf("Lutfen Kiralama Islemi Yapmak Istediginiz Kullanici Id'sini Giriniz:");
				scanf("%d",&RUserId);
				for(int i=0;i<rentsLength;i++){
					if(rents[i].UserId==RUserId){
						printf("Sectiginiz kullanici zaten kiralama islemi yapmýs. Lutfen baska kullanici secin.\n");
						goto line10;
					}
				}
				clearScreen();
				ListBooks();
				DesignMenu();
				int RentBookId;
			line11:
				printf("Kiralamak istediginiz kitabin Id'sini giriniz:");
				scanf("%d",&RentBookId);
				if(books[RentBookId].IsRented==1){
					printf("Sectiginiz kitap zaten kiralanmýs. Lutfen baska kitap secin.\n");
					for(int j=0;j<rentsLength;j++){
						if(rents[j].BookId==RentBookId){
							printf("Sectiginiz kitabýn geri gelis tarihi: %s\n",rents[j].FinishDate);
						}
					}
					goto line11;
				}
			RentBook(RUserId,RentBookId);
			printf("Odunc Alma Islemi Basarili\n\n");
			printf("Menu'ye Donmek Icin(0):");
				scanf("%d",&transactionNo);
				if(transactionNo==0){
					clearScreen();
					goto line15;
				}
			break;
				
				
			case 2:
				clearScreen();
				printf("Kitabi Geri Ver:\n\n");
				DesignMenu();
				ListUsers();
				DesignMenu();
				int GUserId;
				Rents *rentss=getRents();
				int RentId;
				int findResult=0;
			line13:
				printf("Lutfen Kitap Geri Verme Islemi Yapmak Istediginiz Kullanici Id'sini Giriniz:");
				scanf("%d",&GUserId);
				for(int i=0;i<getLengthRents();i++){
					if(rentss[i].UserId==GUserId){
						findResult=1;
						RentId=rentss[i].Id;
					}
				}
				if(findResult!=1){
					printf("Id'sini girmis oldugunuz kullaniciya ait bir kayýt bulunamadý. Lutfen baska kullanici giriniz.\n");
					goto line13;
				}
				UpdateRents(GUserId,RentId);
				printf("Odunc Geri Verme Islemi Basarili\n\n");
				printf("Menu'ye Donmek Icin(0):");
				scanf("%d",&transactionNo);
				if(transactionNo==0){
					clearScreen();
					goto line15;
				}
			case 3:
				clearScreen();
				DesignMenu();
				ListRents();
				printf("Menu'ye Donmek Icin(0):");
				scanf("%d",&transactionNo);
				if(transactionNo==0){
					clearScreen();
					goto line15;
				}
				break;
			default:
			break;
		}
	}
}

// Eleman sayýsýna sayýsýna eriþmek için
int getLengthBook(){
	FILE *BookPtr;
	char rowTemp[100];
    int rowCount=0;
	if((BookPtr=fopen("Books.txt","r"))==NULL){
		printf("File could not be opened!");
	}
	else{
		while(fscanf(BookPtr, "%[^\n]%*c", rowTemp) == 1){
        	rowCount++;
    	}
	}
	fclose(BookPtr);
	return rowCount/5;
}

int getLengthUsers(){
	FILE *UserPtr;
	char rowTemp[100];
	int rowCount=0;
	if((UserPtr=fopen("Users.txt","r"))==NULL){
		printf("File could not be opened!");
	}
	else{
		while(fscanf(UserPtr, "%[^\n]%*c", rowTemp) == 1){
        	rowCount++;
    	}
	}
	fclose(UserPtr);
	return rowCount/5;
}

int getLengthRents(){
	FILE *RentPtr;
	char rowTemp[100];
	int rowCount=0;
	if((RentPtr=fopen("Rents.txt","r"))==NULL){
		printf("File could not be opened!");
	}
	else{
		while(fscanf(RentPtr, "%[^\n]%*c", rowTemp) == 1){
        	rowCount++;
    	}
	}
	fclose(RentPtr);
	return rowCount/5;
}

//Design Methods
void DesignMenu(){
	for(int i=0;i<120;i++){
		printf("-");		
	}
	printf("\n");
}
void DesignMenu2(){
	for(int i=0;i<120;i++){
		printf(".");		
	}
	printf("\n");
}




//Get Methods
Books* GetBooks(){
	int *BookLength = (int*)malloc(sizeof(int) * (getLengthBook()));
    Books *books = (Books*)malloc(sizeof(Books) * (*BookLength));
	int lengthOfBook=getLengthBook();
	FILE *BookPtr;
	if((BookPtr=fopen("Books.txt","r"))==NULL){
		printf("File could not be opened!");
	}
	else{
		for(int i=0;i<lengthOfBook;i++ ){
			fscanf(BookPtr,"%d\n",&books[i].Id);
        	fscanf(BookPtr,"%[^\n]%*c",books[i].Name);
        	fscanf(BookPtr,"%[^\n]%*c",books[i].Author);
        	fscanf(BookPtr,"%d",&books[i].paperCount);
        	fscanf(BookPtr,"%d",&books[i].IsRented);
    	}
	}
	fclose(BookPtr);
	return books;
}

Users* GetUsers(){
	int *UserLength = (int*)malloc(sizeof(int) * (getLengthUsers()));
    Users *users = (Users*)malloc(sizeof(Users) * (*UserLength));
	int lengthOfUsers=getLengthUsers();
	FILE *UserPtr;
	if((UserPtr=fopen("Users.txt","r"))==NULL){
		printf("File could not be opened!");
	}
	else{
		for(int i=0;i<lengthOfUsers;i++){
			fscanf(UserPtr,"%d\n",&users[i].Id);
			fscanf(UserPtr,"%[^\n]%*c",users[i].Name);
			fscanf(UserPtr,"%[^\n]%*c",users[i].Surname);
			fscanf(UserPtr,"%[^\n]%*c",users[i].Depertmant);
			fscanf(UserPtr,"%[^\n]%*c",users[i].BirthDate);
		}
	}
	fclose(UserPtr);
	return users;
}

Rents* getRents(){
	int *RentsLength=(int*)malloc(sizeof(int)*(getLengthRents()));
	Rents *rents= (Rents*)malloc(sizeof(Rents)* (*RentsLength));
	int lengthRents=getLengthRents();
	FILE *RentPtr;
	if((RentPtr=fopen("Rents.txt","r"))==NULL){
		printf("File could not be opened!");
	}
	else{
		for(int i=0;i<lengthRents;i++){
			fscanf(RentPtr,"%d",&rents[i].Id);
			fscanf(RentPtr,"%d",&rents[i].BookId);
			fscanf(RentPtr,"%d\n",&rents[i].UserId);
			fscanf(RentPtr,"%[^\n]%*c",rents[i].StartDate);
			fscanf(RentPtr,"%[^\n]%*c",rents[i].FinishDate);
		}
	}
	fclose(RentPtr);
	return rents;
}


//List Methods
void ListBooks(){
	int lengthBooks=getLengthBook();
	Books *books=GetBooks();
	DesignMenu();
	for (int i = 0; i < lengthBooks; i++) {
    	printf("Id: %d, Name: %s, Author: %s, Paper Count: %d, Is Rented: %d\n\n",
           	books[i].Id, books[i].Name, books[i].Author, books[i].paperCount, books[i].IsRented);
       	DesignMenu2();    	
	}
}

void ListUsers(){
	int lengthUsers=getLengthUsers();
	Users *users=GetUsers();
	printf("Kullanicilar Listesi:\n");
	DesignMenu();
	for (int i = 0; i < lengthUsers; i++) {
    	printf("Id: %d, Name: %s, Surname: %s, Depertmant: %s, BirthDate: %s\n\n",
           	users[i].Id, users[i].Name, users[i].Surname, users[i].Depertmant, users[i].BirthDate);
       	DesignMenu2();
	}	
}

//Add Methods
void AddBook(){
	Books book;
	int NewBookId=getLengthBook()+1;
	book.Id=NewBookId;
	getchar();
	printf("Yeni kitabin ismini giriniz:");
    fgets(book.Name, sizeof(book.Name), stdin);
    book.Name[strcspn(book.Name, "\n")] = '\0'; 
    
    printf("Yeni kitabin yazarinin ismini giriniz:");
    fgets(book.Author, sizeof(book.Author), stdin);
    book.Author[strcspn(book.Author, "\n")] = '\0'; 
    
    printf("Yeni kitabin sayfa sayisini giriniz:");
    char paperCountStr[100];
    fgets(paperCountStr, sizeof(paperCountStr), stdin);
    sscanf(paperCountStr, "%d", &book.paperCount);
	//yeni eklenen kitap kiralýk olamaz
	book.IsRented=0;
	
	FILE *BookPtr;
	if(getLengthBook()==0){
		if((BookPtr=fopen("Books.txt","w"))==NULL){
			printf("File could not be opened!");
		}
		else{
			fprintf(BookPtr,"%d\n",book.Id);
			fprintf(BookPtr,"%s\n",book.Name);
			fprintf(BookPtr,"%s\n",book.Author);
			fprintf(BookPtr,"%d\n",book.paperCount);
			fprintf(BookPtr,"%d\n",book.IsRented);
		}	
	}
	else{
		if((BookPtr=fopen("Books.txt","a"))==NULL){
			printf("File could not be opened!");
		}
		else{
			fprintf(BookPtr,"%d\n",book.Id);
			fprintf(BookPtr,"%s\n",book.Name);
			fprintf(BookPtr,"%s\n",book.Author);
			fprintf(BookPtr,"%d\n",book.paperCount);
			fprintf(BookPtr,"%d\n",book.IsRented);
		}
	}
	fclose(BookPtr);
	
}
void AddUser(){
	Users user;
	int NewUserId=getLengthUsers()+1;
	user.Id=NewUserId;
	getchar();
	printf("Yeni kullanicinin ismini giriniz:");
    fgets(user.Name, sizeof(user.Name), stdin);
    user.Name[strcspn(user.Name, "\n")] = '\0'; 
    
    printf("Yeni kullanicinin soy ismini giriniz:");
    fgets(user.Surname, sizeof(user.Surname), stdin);
    user.Surname[strcspn(user.Surname, "\n")] = '\0'; 
    
    printf("Yeni kullanicinin bolumunu giriniz:");
    fgets(user.Depertmant, sizeof(user.Depertmant), stdin);
    user.Depertmant[strcspn(user.Depertmant, "\n")] = '\0'; 
    
    printf("Yeni kullanicinin dogum tarihini giriniz:");
    fgets(user.BirthDate, sizeof(user.BirthDate), stdin);
    user.BirthDate[strcspn(user.BirthDate, "\n")] = '\0'; 
    
    
    FILE *UserPtr;
    if(getLengthUsers()==0){
    	if((UserPtr=fopen("Users.txt","w"))==NULL){
			printf("File could not be opened!");
		}
		else{
			fprintf(UserPtr,"%d\n",user.Id);
			fprintf(UserPtr,"%s\n",user.Name);
			fprintf(UserPtr,"%s\n",user.Surname);
			fprintf(UserPtr,"%s\n",user.Depertmant);
			fprintf(UserPtr,"%s\n",user.BirthDate);
		}	
	}
	else{
		if((UserPtr=fopen("Users.txt","a"))==NULL){
			printf("File could not be opened!");
		}
		else{
			fprintf(UserPtr,"%d\n",user.Id);
			fprintf(UserPtr,"%s\n",user.Name);
			fprintf(UserPtr,"%s\n",user.Surname);
			fprintf(UserPtr,"%s\n",user.Depertmant);
			fprintf(UserPtr,"%s\n",user.BirthDate);
		}
	}

	fclose(UserPtr);
}


//Güncelleme
void UpdateBooks(int upId){
	Books *books=GetBooks();
	int BookLength=getLengthBook();
	printf("%d. Kitap=>Kitabin Ýsmi:%s\tKitabin Yazari:%s\tKitabin Sayfa Sayisi:%d\tOdunc Alindi Mi?:%d\n",upId,books[upId-1].Name,books[upId-1].Author,books[upId-1].paperCount,books[upId-1].IsRented);
	DesignMenu2();
	
	getchar();
	printf("%d. Kitabin Ismini Guncelle:",upId);
    fgets(books[upId-1].Name, sizeof(books[upId-1].Name), stdin);
    books[upId-1].Name[strcspn(books[upId-1].Name, "\n")] = '\0'; 
    
    printf("%d. Kitabin Yazarinin Ismini Guncelle:",upId);
    fgets(books[upId-1].Author, sizeof(books[upId-1].Author), stdin);
    books[upId-1].Author[strcspn(books[upId-1].Author, "\n")] = '\0'; 
    
    printf("%d. Kitabin Sayfa Sayisini Guncelle:",upId);
    char paperCountStr[100];
    fgets(paperCountStr, sizeof(paperCountStr), stdin);
    sscanf(paperCountStr, "%d", &books[upId-1].paperCount);
    
    FILE *BookPtr;
	if((BookPtr=fopen("Books.txt","w"))==NULL){
		printf("File could not be opened!");
	}
	else{
		for(int i=0;i<BookLength;i++){
			fprintf(BookPtr,"%d\n",books[i].Id);
			fprintf(BookPtr,"%s\n",books[i].Name);
			fprintf(BookPtr,"%s\n",books[i].Author);
			fprintf(BookPtr,"%d\n",books[i].paperCount);
			fprintf(BookPtr,"%d\n",books[i].IsRented);
		}
	}
	fclose(BookPtr);
}

void UpdateUsers(int upId){
	Users *users=GetUsers();
	int UsersLength=getLengthUsers();
	
	printf("%d. Kullanici=>Kullanici Ýsmi:%s\tKullanici Soyismi:%s\tKullanici Bolumu:%s\tKullanici Dogum Tarihi:%s\n",upId,users[upId-1].Name,users[upId-1].Surname,users[upId-1].Depertmant,users[upId-1].BirthDate);
	DesignMenu2();
	
	getchar();
	printf("%d. Kullanicinin ismini guncelle:",upId);
    fgets(users[upId-1].Name, sizeof(users[upId-1].Name), stdin);
    users[upId-1].Name[strcspn(users[upId-1].Name, "\n")] = '\0'; 
    
    printf("%d. Kullanicinin soy ismini guncelle:",upId);
    fgets(users[upId-1].Surname, sizeof(users[upId-1].Surname), stdin);
    users[upId-1].Surname[strcspn(users[upId-1].Surname, "\n")] = '\0'; 
    
    printf("%d. Kullanicinin bolumunu guncelle:",upId);
    fgets(users[upId-1].Depertmant, sizeof(users[upId-1].Depertmant), stdin);
    users[upId-1].Depertmant[strcspn(users[upId-1].Depertmant, "\n")] = '\0'; 
    
    printf("%d. Kullanicinin dogum tarihini guncelle:",upId);
    fgets(users[upId-1].BirthDate, sizeof(users[upId-1].BirthDate), stdin);
    users[upId-1].BirthDate[strcspn(users[upId-1].BirthDate, "\n")] = '\0'; 
    
    
    FILE *UserPtr;
	if((UserPtr=fopen("Users.txt","w"))==NULL){
		printf("File could not be opened!");
	}
	else{
		for(int i=0;i<UsersLength;i++){
			fprintf(UserPtr,"%d\n",users[i].Id);
			fprintf(UserPtr,"%s\n",users[i].Name);
			fprintf(UserPtr,"%s\n",users[i].Surname);
			fprintf(UserPtr,"%s\n",users[i].Depertmant);
			fprintf(UserPtr,"%s\n",users[i].BirthDate);
		}
	}
	fclose(UserPtr);
}

void UpdateRents(int GUserId,int RentId){
	Rents *OldRents=getRents();
	Books *books=GetBooks();
	int lengthBook=getLengthBook();
	int *RentsLength=(int*)malloc(sizeof(int)*(getLengthRents()-1));
	Rents *NewRents= (Rents*)malloc(sizeof(Rents)* (*RentsLength));
	
	int lengthRents=getLengthRents();
	
	int RentBookId;
	for(int i=0;i<lengthRents;i++){
		if(OldRents[i].UserId==GUserId){
			RentBookId=OldRents[i].BookId;
		}
	}
	books[RentBookId-1].IsRented=0;
	int j=0;
	for(;j<lengthRents;j++){
		if(OldRents[j].Id==RentId){
			j++;
			break;
		}
		NewRents[j].Id=OldRents[j].Id;
		NewRents[j].BookId=OldRents[j].BookId;
		NewRents[j].UserId=OldRents[j].UserId;
	}
	for(;j<lengthRents;j++){
		NewRents[j-1].Id=OldRents[j].Id-1;
		NewRents[j-1].BookId=OldRents[j].BookId;
		NewRents[j-1].UserId=OldRents[j].UserId;	
	}
	
	FILE *BookPtr;
	if((BookPtr=fopen("Books.txt","w"))==NULL){
		printf("File could not be opened!");
	}
	else{
		for(int i=0;i<lengthBook;i++){
			fprintf(BookPtr,"%d\n",books[i].Id);
			fprintf(BookPtr,"%s\n",books[i].Name);
			fprintf(BookPtr,"%s\n",books[i].Author);
			fprintf(BookPtr,"%d\n",books[i].paperCount);
			fprintf(BookPtr,"%d\n",books[i].IsRented);
		}
	}
	fclose(BookPtr);
	
	FILE *RentPtr;
	if((RentPtr=fopen("Rents.txt","w"))==NULL){
		printf("File could not be opened!");
	}
	else{
		for(int i=0;i<lengthRents-1;i++){
			fprintf(RentPtr,"%d\n",NewRents[i].Id);
			fprintf(RentPtr,"%d\n",NewRents[i].BookId);
			fprintf(RentPtr,"%d\n",NewRents[i].UserId);
		}
	}
	fclose(RentPtr);
}


//Silme Ýþlemleri

void DeleteBook(int DelId){
	Books *OldBooks=GetBooks();
	int bookLength=getLengthBook();
	int *BookLength = (int*)malloc(sizeof(int) * (bookLength-1));
    Books *NewBooks = (Books*)malloc(sizeof(Books) * (*BookLength));
	int i;
	for(i=0;i<bookLength;i++){
		if(OldBooks[i].Id==DelId){
			i++;
			break;
		}
		NewBooks[i].Id=OldBooks[i].Id;
		strcpy(NewBooks[i].Name, OldBooks[i].Name);
        strcpy(NewBooks[i].Author, OldBooks[i].Author);
		NewBooks[i].paperCount=OldBooks[i].paperCount;
		NewBooks[i].IsRented=OldBooks[i].IsRented;

	}
	for(;i<bookLength;i++){
		NewBooks[i-1].Id=OldBooks[i].Id-1;
		strcpy(NewBooks[i-1].Name, OldBooks[i].Name);
        strcpy(NewBooks[i-1].Author, OldBooks[i].Author);
		NewBooks[i-1].paperCount=OldBooks[i].paperCount;
		NewBooks[i-1].IsRented=OldBooks[i].IsRented;
	}
	
	
	FILE *BookPtr;
	if((BookPtr=fopen("Books.txt","w"))==NULL){
		printf("File could not be opened!");
	}
	else{
		for(int j=0;j<bookLength-1;j++){
			fprintf(BookPtr,"%d\n",NewBooks[j].Id);
			fprintf(BookPtr,"%s\n",NewBooks[j].Name);
			fprintf(BookPtr,"%s\n",NewBooks[j].Author);
			fprintf(BookPtr,"%d\n",NewBooks[j].paperCount);
			fprintf(BookPtr,"%d\n",NewBooks[j].IsRented);
		}
	}
	fclose(BookPtr);
}

void DeleteUser(int DelId){
	Users *OldUsers=GetUsers();
	int userLength=getLengthUsers();
	int *UserLength = (int*)malloc(sizeof(int) * (userLength-1));
    Users *NewUsers = (Users*)malloc(sizeof(Users) * (*UserLength));
	int i;
	for(i=0;i<userLength;i++){
		if(OldUsers[i].Id==DelId){
			i++;
			break;
		}
		NewUsers[i].Id=OldUsers[i].Id;
		strcpy(NewUsers[i].Name, OldUsers[i].Name);
		strcpy(NewUsers[i].Surname, OldUsers[i].Surname);
		strcpy(NewUsers[i].Depertmant, OldUsers[i].Depertmant);
		strcpy(NewUsers[i].BirthDate, OldUsers[i].BirthDate);
		

	}
	for(;i<userLength;i++){
		NewUsers[i-1].Id=OldUsers[i].Id-1;
		strcpy(NewUsers[i-1].Name, OldUsers[i].Name);
		strcpy(NewUsers[i-1].Surname, OldUsers[i].Surname);
		strcpy(NewUsers[i-1].Depertmant, OldUsers[i].Depertmant);
		strcpy(NewUsers[i-1].BirthDate, OldUsers[i].BirthDate);
	}
	
	FILE *UserPtr;
	if((UserPtr=fopen("Users.txt","w"))==NULL){
		printf("File could not be opened!");
	}
	else{
		for(int i=0;i<userLength;i++){
			fprintf(UserPtr,"%d\n",NewUsers[i].Id);
			fprintf(UserPtr,"%s\n",NewUsers[i].Name);
			fprintf(UserPtr,"%s\n",NewUsers[i].Surname);
			fprintf(UserPtr,"%s\n",NewUsers[i].Depertmant);
			fprintf(UserPtr,"%s\n",NewUsers[i].BirthDate);
		}
	}
	fclose(UserPtr);
}
//Kitap Kiralama
void RentBook(int RUserId,int RentBookId){
	int NewRentId=getLengthRents()+1;
	Books *books=GetBooks();
	int booksLength=getLengthBook();
	Rents rent;
	rent.Id=NewRentId;
	rent.BookId=RentBookId;
	rent.UserId=RUserId;
	printf("Lutfen kitabi aldiginiz tarihi giriniz:");
	scanf("%s",rent.StartDate);
	printf("Lutfen kitabi getireceginiz tarihi giriniz:");
	scanf("%s",rent.FinishDate);
	for(int j=0;j<booksLength;j++){
		if(books[j].Id==RentBookId){
			books[j].IsRented=1;
		}
	}
	FILE *BookPtr;
	if((BookPtr=fopen("Books.txt","w"))==NULL){
		printf("File could not be opened!");
	}
	else{
		for(int i=0;i<booksLength;i++){
			fprintf(BookPtr,"%d\n",books[i].Id);
			fprintf(BookPtr,"%s\n",books[i].Name);
			fprintf(BookPtr,"%s\n",books[i].Author);
			fprintf(BookPtr,"%d\n",books[i].paperCount);
			fprintf(BookPtr,"%d\n",books[i].IsRented);
		}
	}
	fclose(BookPtr);
	
	FILE *RentPtr;
	if(getLengthRents()==0){
		if((RentPtr=fopen("Rents.txt","w"))==NULL){
		printf("File could not be opened!");
		}
		else{
			fprintf(RentPtr,"%d\n",rent.Id);
			fprintf(RentPtr,"%d\n",rent.BookId);
			fprintf(RentPtr,"%d\n",rent.UserId);
			fprintf(RentPtr,"%s\n",rent.StartDate);
			fprintf(RentPtr,"%s\n",rent.FinishDate);
		}
	}
	else{
		if((RentPtr=fopen("Rents.txt","a"))==NULL){
			printf("File could not be opened!");
		}
		else{
			fprintf(RentPtr,"%d\n",rent.Id);
			fprintf(RentPtr,"%d\n",rent.BookId);
			fprintf(RentPtr,"%d\n",rent.UserId);
			fprintf(RentPtr,"%s\n",rent.StartDate);
			fprintf(RentPtr,"%s\n",rent.FinishDate);
		}
	}
	fclose(RentPtr);
}
//Kiralama Listele
void ListRents(){
	Rents *rents=getRents();
	Books *books=GetBooks();
	Users *users=GetUsers();
	int lengthUsers=getLengthUsers();
	int lengthRents=getLengthRents();
	printf("Odunc Listesi:\n\n");
	DesignMenu();
	for(int i=0;i<lengthRents;i++){
		int UserId=rents[i].UserId;
		int BookId=rents[i].BookId;
		printf("Kullanici Ismi: %s, Soyismi: %s,Kiraladigi Kitap Ismi: %s\n Baslangic Tarihi: %s, Bitis Tarihi: %s\n\n",
			users[UserId-1].Name,users[UserId-1].Surname,books[BookId-1].Name,rents[i].StartDate,rents[i].FinishDate);
	}
	DesignMenu2();
}
void SearchBook(char *tempC){
	char *result;
	Books *books=GetBooks();
	int lengthBook=getLengthBook();
	for(int i=0;i<lengthBook;i++){
		result=strstr(books[i].Name,tempC);
		if(result!=NULL){
			printf("Id: %d, Name: %s, Author: %s, Paper Count: %d, Is Rented: %d\n\n",
           		books[i].Id, books[i].Name, books[i].Author, books[i].paperCount, books[i].IsRented);  
		}
	}
}
void SearchUser(char *tempC){
	char *result;
	Users *users=GetUsers();
	int lengthUsers=getLengthUsers();
	for(int i=0;i<lengthUsers;i++){
		result=strstr(users[i].Name,tempC);
		if(result!=NULL){
			printf("Id: %d, Name: %s, Surname: %s, Depertmant: %s, BirthDate: %s\n\n",
           		users[i].Id, users[i].Name, users[i].Surname, users[i].Depertmant, users[i].BirthDate);
       		DesignMenu2();
		}
	}
}









