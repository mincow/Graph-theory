#include <stdio.h>
#include <conio.h>
#define MAX 10
#define inputfile "./Text2_01.txt"

typedef struct GRAPH {
	int n;
	int a[MAX][MAX];
}DOTHI;

int DocMaTranKe(char TenFile[100], DOTHI &g) {
	FILE* f;
	f = fopen(TenFile,"rt");
	if (f == NULL) {
		printf("ERROR !!!\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	return 1;	
}

void XuatMaTranKe(DOTHI g) {
	printf("So dinh cua do thi: %d\n",g.n);
	printf("Ma tran ke cua do thi la:\n");
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			printf("%5d",g.a[i][j]);
		}
		printf("\n");
	}
}

int kthople(DOTHI g) {
	for (int i = 0; i < g.n; i++) {
		if (g.a[i][i] != 0) {
			return 0;
		}
	}
	return 1;
}

int ktdtvh(DOTHI g) {
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (g.a[i][j] != g.a[j][i])
				return 0;
		}
	}
	return 1;
}

int dembac(DOTHI g, int n) {
	int d = 0;
	for (int i = 0; i < g.n; i++) {
		if (g.a[n][i] == 1) {
			d++;
		}
	}
		return d;
}

void dembaccuadinh(DOTHI g) {
	for (int i = 0; i < g.n; i++) {
		printf("Bac cua dinh %d la: %d",i,dembac(g,i));
		printf("\n");
		}	
}

void Timcacdinhlienthong(DOTHI g, int nhan[MAX], int i) {
	for (int j = 0; j < g.n; j++) {
		if (g.a[i][j] != 0 && nhan[j] != nhan[i]) {
			nhan[j] = nhan[i];
			Timcacdinhlienthong(g,nhan,j);
		}
	}
}

void xetlienthong(DOTHI g) {
	int nhan[MAX];
	for (int i = 0; i < g.n; i++) {
		nhan[i] = 0;	
	}
	int sotplt = 0;
	for (int i = 0; i < g.n; i++) {
		if (nhan[i] == 0) {	
			sotplt++;
			nhan[i] = sotplt;
			Timcacdinhlienthong(g,nhan,i);
		}
	}
	printf("\nSo thanh phan lien thong la: %d\n",sotplt);
	for (int i = 1; i <= sotplt; i++) {
		printf("Thanh phan lien thong thu %d gom cac dinh: ",i);
		for (int j = 0; j < g.n; j++) {
			if (nhan[j]==i)
				printf("%5d",j);
		}		
		printf("\n");
	}
}

int main() {
//	DOTHI g;
//	if (DocMaTranKe(inputfile,g) == 1) {
//		printf("\nDa doc file thanh cong\n");	
//		XuatMaTranKe(g);
//	}
//	printf("Nhan Enter de kiem tra hop le !!!!");
//	getch();
//	if (kthople(g) == 1) {
//		printf("\nHop le !!!\n");
//	}
//	else
//		printf("\nKhong Hop Le !!!\n");
//
//	if (ktdtvh(g) == 1) {
//		printf("Do thi vo huong !!!\n");
//	}
//	else
//		printf("Do thi co huong !!!\n");
//	printf("\n");
//	dembaccuadinh(g);
//	printf("\n\n");
	DOTHI g;
	if (DocMaTranKe(inputfile,g) == 1) {
		printf("\nDa doc file thanh cong\n");	
		XuatMaTranKe(g);
		printf("Nhan Enter de tiep tuc !!!!");
		getch();
		xetlienthong(g);
	}	

	return 0;
}
