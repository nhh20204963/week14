#include <stdio.h>

struct student{
	char name[30];
	float grade;
	char classment[3];
};
void tencot(){
	printf("%30s | %20s | %20s\n", "Name", "Grade", "Classment");
}
void nhap(struct student* sv){
	printf("\nNhap ten: ");scanf("%s", &sv->name);
	printf("Nhap diem: ");scanf("%f", &sv->grade);
	printf("Nhap diem chu: ");scanf("%s", &sv->classment);
}
void hienthi(struct student sv){
	printf("%30s | %20.2f | %20s\n", sv.name, sv.grade, sv.classment);
}
void hienthiDS(struct student ds[], int slsv){
	int i;
	for(i = 0; i < slsv; i++){
		nhap(&ds[i]);
	}
	tencot();
	printf("\nDanh sach ban dau: \n");
	for(i = 0; i < slsv; i++){
		hienthi(ds[i]);
	}
}
void sapxep(struct student* ds, int slsv){
	int i, j;
	for(i = 0; i < slsv - 1; i++){
		for(j = i + 1; j < slsv; j++){
			if(ds[i].grade < ds[j].grade){
				struct student temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
	for(i = 0; i < slsv; i++){
		hienthi(ds[i]);
	}
}
int main(){
	struct student ds[100];
	int slsv;
	printf("Nhap slsv = ");scanf("%d", &slsv);
	hienthiDS(ds, slsv);
	printf("\nDanh sach sau khi sap xep: \n");
	sapxep(ds, slsv);
	return 0;
}
