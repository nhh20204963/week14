#include <stdio.h>

struct weather{
    float totalrain;
    float hightemp;
    float lowtemp;
    float avetemp;
};
void tencot(){
    printf("%20s | %20s | %20s | %20s|\n","Toralrain", "Hightemp", "Lowtemp", "Avetemp");
}
void nhap(struct weather* tt){
    printf("\nNhap tong mua: ");scanf("%f", &tt->totalrain);
    printf("Nhap nhiet cao: ");scanf("%f", &tt->hightemp);
    while(tt->hightemp > 50 || tt->hightemp < -40){
        printf("Nhap lai nhiet cao: ");scanf("%f", &tt->hightemp);
    }
    printf("Nhap nhiet thap: ");scanf("%f", &tt->lowtemp);
    while(tt->lowtemp > 50 || tt->lowtemp < -40){
        printf("Nhap lai nhiet thap: ");scanf("%f", &tt->lowtemp);
    }
    printf("Nhap nhiet TB: ");scanf("%f", &tt->avetemp);
    while(tt->avetemp > 50 || tt->avetemp < -40){
        printf("Nhap lai nhiet TB: ");scanf("%f", &tt->avetemp);
    }
}
void hienthi(struct weather tt){
    printf("%20.2f | %20.2f | %20.2f | %20.2f|\n",tt.totalrain, tt.hightemp, tt.lowtemp, tt.avetemp);
}
void hienthiDS(struct weather ds[]){
    int i;
    for(i = 0; i < 12; i++){
    	nhap(&ds[i]);
	}
	tencot();
    for(i = 0; i < 12; i++){
        hienthi(ds[i]);
    }
}
int main(){
    struct weather ds[15];
    hienthiDS(ds);
    float sumrain;
    int i;
    for(i = 0; i < 12; i++){
    	sumrain += ds[i].totalrain;
	}
	printf("\n\tTong luong mua trong nam = %.2f", sumrain);
	printf("\n\tLuong mua trung binh 1 thang = %.2f", sumrain / 3);
	float maxtemp, mintemp;
	maxtemp = ds[0].hightemp;
	for(i = 0; i < 12; i++){
		if(ds[i+1].hightemp > maxtemp){
			maxtemp = ds[i+1].hightemp;
		}
	}
	printf("\n\tNhiet do cao nhat trong nam = %.2f", maxtemp);
	mintemp = ds[0].lowtemp;
	for(i = 0; i < 12; i++){
		if(ds[i+1].lowtemp < mintemp){
			mintemp = ds[i+1].lowtemp;
		}
	}
	printf("\n\tNhiet do thap nhat trong nam = %.2f", mintemp);
}


