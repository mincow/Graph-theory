#include <stdio.h>
#include <conio.h>
#define MAX 50
#define inputfile "./Text4_02.txt"

struct GRAPH {
	int n;
	int a[MAX][MAX];
};

struct EDGE {
	int u;
	int v;
	int value;
};

EDGE T[MAX];
int chuaXet[MAX];

int DocMaTranKe(char TenFile[100], GRAPH &g) {
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

void XuatMaTranKe(GRAPH g) {
	printf("So dinh cua do thi: %d\n",g.n);
	printf("Ma tran ke cua do thi la:\n");
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			printf("%5d",g.a[i][j]);
		}
		printf("\n");
	}
}

int kthople(GRAPH g) {
	for (int i = 0; i < g.n; i++) {
		if (g.a[i][i] != 0) {
			return 0;
		}
	}
	return 1;
}

int ktdtvh(GRAPH g) {
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (g.a[i][j] != g.a[j][i])
				return 0;
		}
	}
	return 1;
}

int dembac(GRAPH g, int n) {
	int d = 0;
	for (int i = 0; i < g.n; i++) {
		if (g.a[n][i] == 1) {
			d++;
		}
	}
		return d;
}

void dembaccuadinh(GRAPH g) {
	for (int i = 0; i < g.n; i++) {
		printf("Bac cua dinh %d la: %d",i,dembac(g,i));
		printf("\n");
		}	
}

void Timcacdinhlienthong(GRAPH g, int nhan[MAX], int i) {
	for (int j = 0; j < g.n; j++) {
		if (g.a[i][j] != 0 && nhan[j] != nhan[i]) {
			nhan[j] = nhan[i];
			Timcacdinhlienthong(g,nhan,j);
		}
	}
}

int xetlienthong(GRAPH g) {
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
	return sotplt;
}

void prim(GRAPH g) {
	if (xetlienthong(g) != 1) {
		 printf("Do thi khong lien thong nen khong thuc hien duoc thuat toan Prim !!!\n");
		 return;
	}
	int nT = 0;
	for (int i = 0; i < g.n; i++) {
		chuaXet[i] = 0;
	}
	chuaXet[0] = 1;
	while (nT < g.n - 1) {
		EDGE minEdge;
		int minValue = 100;
		for (int i = 0; i < g.n; i++) {
			if (chuaXet[i] == 1) {
				for (int j = 0; j < g.n; j++) {
					if (chuaXet[j] == 0 && g.a[i][j] != 0 && minValue > g.a[i][j]) {
						minEdge.u = i;
						minEdge.v = j;
						minEdge.value = g.a[i][j];
						minValue = g.a[i][j];
					}
				}
			}
		}
		T[nT] = minEdge;
		nT++;
		chuaXet[minEdge.v] = 1;	
	}
	int sum = 0;
	printf("Cay khung nho nhat cua do thi la:\n");
	for (int i = 0; i < nT - 1; i++) {
		printf("(%d,%d).\n",T[i].u, T[i].v);
		sum += T[i].value;
	}
	printf("(%d,%d).\n",T[nT - 1].u, T[nT - 1].v);
	sum += T[nT - 1].value;
	printf("Tong trong so cua cay khung la: %d \n",sum);
}

void sortA(EDGE E[100], int sumEdge) {
	EDGE tempEdge;
	for (int i = 0; i < sumEdge - 1; i++) {
		{
			for (int j = i+1; j < sumEdge; j++) {
				if (E[i].value > E[j].value) {
					tempEdge = E[i];
					E[i] = E[j];
					E[j] = tempEdge;
				}
			}
		}
	}
}

void kruskal(GRAPH g) {
	EDGE listEdge[MAX];
	int sumEdge = 0;
	for(int i = 0; i < g.n; i++) {
		for (int j = i+1; j < g.n; j++) {
			if(g.a[i][j] > 0) {
				listEdge[sumEdge].u = i;
				listEdge[sumEdge].v = j;
				listEdge[sumEdge].value = g.a[i][j];
				sumEdge++;
			}
		}
	}
	sortA(listEdge,sumEdge);
	int nT = 0;
	EDGE T[MAX];
	int nhan[MAX];
	for (int i = 0; i < g.n; i++) {
		nhan[i] = i;
	}
	int currentEdge = 0;
	while (nT < g.n && currentEdge < sumEdge) {
		if (nhan[listEdge[currentEdge].u] != nhan[listEdge[currentEdge].v]) {
			T[nT] = listEdge[currentEdge];
			nT++;
			int value = nhan[listEdge[currentEdge].v];
			for (int j = 0; j < g.n; j++) {
				if (nhan[j] == value) {
					nhan[j] = nhan[listEdge[currentEdge].u];
				}
			}
		}
		currentEdge++;
	}
	if (nT != g.n -1) {
		printf("\nDo thi khong lien thong\n");
	}
	else {
		int sum = 0;
		printf("\nDo thi lien thong\n");
		printf("Cay khung nho nhat cua do thi la:\n");
		for (int i = 0; i < nT; i++) {
			printf("(%d,%d)\n",T[i].u,T[i].v);
			sum += T[i].value;
		}
		printf("\nTong gia tri cua cay khung la: %d\n",sum);
	}
}

int main() {
	GRAPH g;
	if (DocMaTranKe(inputfile,g) == 1) {
		printf("\nDa doc file thanh cong\n");	
		XuatMaTranKe(g);
		printf("Nhan Enter de tiep tuc !!!!");
		getch();
		kruskal(g);
	}	

	return 0;
}
