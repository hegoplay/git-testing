#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct daiLy{
	char tenDL[100];
	double doanhThu;
	char SDT[12];
	daiLy* Tiep;
};

struct thanhPho{
	char tenTP[100];
	daiLy* Down;
	thanhPho* Next;
};
//node p = vi tri trong head
thanhPho* head = NULL;
//Tao 1 dai ly
daiLy* createDaiLy(char tenDL[], double doanhThu,char SDT[12]){
	daiLy* temp = (daiLy*)malloc(sizeof(daiLy));
	temp->doanhThu = doanhThu;
	strcpy(temp->tenDL,tenDL);
	strcpy(temp->SDT,SDT);
	temp->Tiep = NULL;
	return temp;
}

thanhPho* createThanhPho(char s[]){
	thanhPho* temp = (thanhPho*)malloc(sizeof(thanhPho));
	temp->Down = NULL;
	temp->Next = NULL;
	strcpy(temp->tenTP,s);
	return temp;
}

void addThanhPho(){
	printf ("Nhap thanh pho muon them: ");
	fflush(stdin);
	char name[100];
	gets(name);
	thanhPho* p = head;//tao bien tam
	thanhPho* temp = createThanhPho(name); //tao bien temp de dua du lieu vao
	if (p==NULL) {//truong hop head = NULL
		head = temp;
		return;
	}
	//truong hop head chi co 1 phan tu
	if (strcmp(p->tenTP,name)>0){
		temp->Next = head;
		head = temp;
		return;
	}
	//truong hop con lai
	while (p->Next!=NULL&&strcmp(p->Next->tenTP,name)<0){
		p = p->Next;
	}
	p->Next= temp;
}

thanhPho* timThanhPho(char tenTP[]){
	//tim vi tri thanh pho muon them DaiLy
	thanhPho* p = head;
	while (p!=NULL){
		if (strcmp(p->tenTP,tenTP)==0) return p;
		p = p->Next;
	}
	//tra ve NULL khi khong tim thay
	return NULL;
}
//xuat danh sach cac thanh pho de nhap ten thanhpho tim dai ly
void display1DaiLy(daiLy* &dl1){
	if (dl1 == NULL) printf("Dai ly 1 khong co du lieu ");
	printf ("%-20s%-15.2f%-20s",dl1->tenDL,dl1->doanhThu,dl1->SDT);
}

void addDaiLy(){
	printf ("Nhap thanh pho muon them Dai Ly: ");
	fflush(stdin);
	char str[100];
	gets(str);
	thanhPho* p = timThanhPho(str);
	if (p==NULL){
		//truong hop khong tim thay thanh pho
		printf ("Thanh pho khong ton tai");
		return;
	}
	else{
		char tenDL[100],SDT[12]; double doanhThu;
		printf ("Nhap ten dai ly muon them: ");
		fflush(stdin);
		gets(tenDL);
		printf ("Nhap doanh thu cua dai ly: ");
		scanf ("%lf",&doanhThu);
		printf ("Nhap so dien thoai cua dai ly: ");
		fflush(stdin);
		gets(SDT);
		daiLy *p1 =p->Down;
		if (p1==NULL){
			printf ("how\n");
			p1 = createDaiLy(tenDL,doanhThu,SDT);
			
			display1DaiLy(p1);
			return;
		}
		while (p1->Tiep!=NULL&&p1->doanhThu<doanhThu){
			//tim vi tri cua dai ly trong thanhpho ma muon chen them
			p1 = p1->Tiep;
		}
		daiLy* temp = createDaiLy(tenDL,doanhThu,SDT);
		temp->Tiep = p1->Tiep;
		p1->Tiep = temp;
//		p1 = temp;
		display1DaiLy(p1->Tiep);
	}
}

void displayTP(){
	thanhPho* p = head;
	while (p!=NULL){
		printf ("%-30s",p->tenTP);
		p = p->Next;
	}
}
//xuat tat ca daiLy trong node thanhPho x
void displayDaiLy(thanhPho* x){
	daiLy* p1 = x->Down;
	if (p1==NULL) printf ("NOT GOOD");
	while (p1!=NULL){
		printf ("GOOD\n");
		display1DaiLy(p1);
		p1 = p1->Tiep;
	}
}

int main(){
	char tp[100];
	bool choice;
	do{
		addThanhPho();
//		temp = createThanhPho(tp);
//		bool choice1;
//		printf ("Co muon them dai ly o thanh pho nay khong ?"); //1: co 0:khong
//		scanf ("%d",&choice1);
//		if (choice1 == true){
//			do{
//				
//				
//				//tiep tuc khoi tao dai ly neu nhu nhap 1
//				printf("co muon tiep tuc them dai ly khong ?\nNguoi nhap: ");
//				scanf ("%d",choice1);
//			}
//			while (choice1 == 1);
//		}
		printf ("Tiep tuc ? (1: co/ 0: khong)\nNguoi nhap: ");
		scanf ("%d",&choice);
	}
	while (choice == 1);
	bool choice1 = 0;
	displayTP();
	printf ("\nCo muon them dai ly khong ?\nNguoi Nhap: "); //1: co 0:khong
	scanf ("%d",&choice1);
	
	while (choice1 == 1){
		addDaiLy();
		printf ("Tiep tuc ? (1: co/ 0: khong)\nNguoi nhap: ");
		scanf ("%d",&choice1);
	}
	//test kiem tra danh sach dai ly quy nhon
	char x[100];
	fflush(stdin);
	gets(x);
	thanhPho* vt = timThanhPho(x);
	if (vt == NULL) printf ("WTF ?"); 
	displayDaiLy(vt);
	return 0;
}