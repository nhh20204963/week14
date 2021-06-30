#include <stdio.h>
 
typedef struct
{
	int tuso;
	int mauso; 
}PS;

void nhap(PS *ps, const char name);
PS calPS(PS psA, PS psB, const char op);
void xuat(PS ps, const char name);

int main(){
	PS psA, psB, psC;
	int key;
	nhap(&psA, 'A');
	xuat(psA, 'A');
	nhap(&psB, 'B');
	xuat(psB, 'B');
	do{
		printf("\n\n1. Cong 2 phan so: C = A+B");
		printf("\n2. Tru 2 phan so: C = A-B");
		printf("\n3. Nhan 2 phan so: C = A*B");
		printf("\n4. Chia 2 phan so: C = A/B");
		printf("\n5.Thoat");
		printf("\nBan chon: ");
		scanf("%d", &key);
		switch(key){
			case 1:
				psC = calPS(psA, psB, '+');
				xuat(psC,'C');
				break;
			case 2:
				psC = calPS(psA, psB, '-');
				xuat(psC, 'C');
				break;
			case 3:
				psC = calPS(psA, psB, '*');
				xuat(psC, 'C');
				break;
			case 4:
				psC = calPS(psA, psB, '/');
				xuat(psC, 'C');
				break;
			case 5:
				break;
		}
	}while(key);
}
void nhap(PS *ps, const char name){
	printf("\nTu so: ");
	scanf("%d", &ps->tuso);
	printf("\nMau so: ");
	scanf("%d", &ps->mauso);
}
PS calPS(PS psA, PS psB, const char op){
	PS psC;
	switch(op){
		case '+': // A+B
			psC.tuso = psA.tuso * psB.mauso + psA.mauso * psB.tuso;
			psC.mauso = psA.mauso * psB.mauso;
			break;
		case '-': // A-B
			psC.tuso = psA.tuso * psB.mauso - psA.mauso * psB.tuso;
			psC.mauso = psA.mauso * psB.mauso;
			break;
		case '*': // A*B
			psC.tuso = psA.tuso * psB.tuso;
			psC.mauso = psA.mauso * psB.mauso;
			break;
		case '/': // A/B
			psC.tuso = psA.tuso * psB.mauso;
			psC.mauso = psA.mauso * psB.tuso;
		default:
			printf("\nToan tu khong hop le");
	}
	return psC;
}
 
void xuat(PS ps, const char name){
	if(ps.mauso != 0){
		printf("\nPhan so %c = %d / %d", name, ps.tuso, ps.mauso);
	}
}
