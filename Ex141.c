#include <stdio.h>

struct Date{
	int ngay;
	int thang;
	int nam;
};
void nhapdate(struct Date* date, char ten){
	printf("Nhap ngay sinh nguoi %c", ten);
	printf("\nNhap ngay: ");scanf("%d", &date->ngay);
	while(date->ngay < 1 || date->ngay > 31){
		printf("Nhap lai ngay: ");
		scanf("%d", &date->ngay);
	}
	printf("Nhap thang: ");scanf("%d", &date->thang);
	while(date->thang < 1 || date->thang > 12){
		printf("Nhap lai thang: ");
		scanf("%d", &date->thang);
	}
	printf("Nhap nam: ");scanf("%d", &date->nam);
}
void datecmp(struct Date* date1, struct Date* date2){
	if(date1->nam < date2->nam){
		printf("%d/%d/%d before %d/%d/%d", date1->ngay, date1->thang, date1->nam, date2->ngay, date2->thang, date2->nam);
	}else if(date1->nam > date2->nam){
		printf("%d/%d/%d after %d/%d/%d", date1->ngay, date1->thang, date1->nam, date2->ngay, date2->thang, date2->nam);
	}else{
		if(date1->thang < date2->thang){
			printf("%d/%d/%d before %d/%d/%d", date1->ngay, date1->thang, date1->nam, date2->ngay, date2->thang, date2->nam);
		}else if(date1->thang > date2->thang){
			printf("%d/%d/%d after %d/%d/%d", date1->ngay, date1->thang, date1->nam, date2->ngay, date2->thang, date2->nam);;
		}else{
			if(date1->ngay < date2->ngay){
				printf("%d/%d/%d before %d/%d/%d", date1->ngay, date1->thang, date1->nam, date2->ngay, date2->thang, date2->nam);
			}else if(date1->ngay > date2->ngay){
				printf("%d/%d/%d after %d/%d/%d", date1->ngay, date1->thang, date1->nam, date2->ngay, date2->thang, date2->nam);;
			}else{
				printf("%d/%d/%d is identical %d/%d/%d", date1->ngay, date1->thang, date1->nam, date2->ngay, date2->thang, date2->nam);
			}
		}
	}
}
int main(){
	struct Date date1;
	nhapdate(&date1, 'A');
	struct Date date2;
	nhapdate(&date2, 'B');
	datecmp(&date1, &date2);
}
