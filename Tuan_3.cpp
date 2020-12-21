#include <stdio.h>
#include <conio.h>
#define MAX 20
#define inputfile "./Text3_01.txt"


struct GRAPH {
	int n;
	int a[MAX][MAX];
};

int chuaXet[MAX];
int luuVet[MAX];


//-----------------------------------DFS (Depth First Search)
int readMatrix(char TenFile[100], GRAPH &g) {
	FILE *f;
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

void writeMatrix(GRAPH g) {
	printf("So dinh cua do thi la: %d",g.n);
	printf("\nMa tran cua do thi la: \n");
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j< g.n; j++) {
			printf("%5d",g.a[i][j]);
		}
		printf("\n");
	}
}

void DFS(int v, GRAPH g) {
	printf("%5d",v);
	chuaXet[v] = 1;
	for (int i = 0; i < g.n; i++) {
		if (g.a[v][i] != 0 && chuaXet[i] == 0) {
			luuVet[i] = v;
			DFS(i,g);
		}
	}
}

void duyetDFS(int s, int f, GRAPH g) {
	printf("Thu tu duyet la: ");
	int i;
	for (i = 0; i < g.n; i++) {
		luuVet[i] = -1;
		chuaXet[i] = 0;
	}
	DFS(s,g);
	if (chuaXet[f] == 1) {
		printf("\nDuong di tu dinh %d den dinh %d la: \n\t",s,f);
		i = f;
		printf("%d",f);
		while (luuVet[i] != -1) {
			printf(" <-");
			printf("%5d",luuVet[i]);
			i = luuVet[i];
		}
	}
	else {
		printf("\nKhong co duong di tu dinh %d den dinh %d !!!\n",s,f);
	}
}

//-----------------------------BFS (Breath First Search)	
struct QUEUE {
	int size;
	int array[MAX];
};

void init(QUEUE &q) {
	q.size = 0;
}

int isEmpty(QUEUE q) {
	if (q.size <= 0) {
		return 1;
	}
	return 0;
}

int push(QUEUE &q, int value) {
	if (q.size + 1 >= 100) {
		printf("FULL !!!\n");
		return 0;
	}
	q.array[q.size] = value;
	q.size++;
	return 1;
}

int pop(QUEUE &q,int &value) {
	if (q.size <= 0) {
		printf("EMPTY !!!\n");
		return 0;
	}
	value = q.array[0];
	for (int i = 0; i < q.size -1; i++) {
		q.array[i] = q.array[i+1];
	}
	q.size--;
	return 1;
}

void BFS(int v, GRAPH g) {
	QUEUE q;
	QUEUE temp;
	init(q);
	init(temp);
	push(q,v);
	while(!isEmpty(q)) {
		pop(q,v);
//kiemtralai
		push(temp,v);
		chuaXet[v] = 1;
		for (int i = 0; i < g.n; i++) {
			if(g.a[v][i] != 0 && chuaXet[i] == 0) {
				push(q,i);
				if (luuVet[i] == -1) {
					luuVet[i] = v;
				}
			}
		}
	}
	printf("Thu tu duyet la: ");
	for (int k = 0; k < temp.size - 1; k++) {
		printf("%5d",temp.array[k]);
	}
}

void duyetBFS(int s, int f, GRAPH g) {
	int i;
	for (i = 0; i < g.n; i++) {
		luuVet[i] = -1;
		chuaXet[i] = 0;
	}
	BFS(s,g);
//	for (int k  = 0; k < g.n; k++) {
//		printf("%5d",luuVet[k]);
//	}
	if (chuaXet[f] == 1) {
		printf("\nDuong di tu dinh %d den dinh %d la: ",s,f);
		i = f;
		printf("%5d",f);
		while (luuVet[i] != -1) {
			printf(" <-");
			printf("%5d",luuVet[i]);
			i = luuVet[i];
		}
	}
	else {
		printf("\nKhong co duong di tu %d den %d !!!\n",s,f);
	}
}

int main() {
	GRAPH g;
	int s,f;
	if (readMatrix(inputfile,g) == 1) {
		printf("Doc ma tran thanh cong !!!\n");
		writeMatrix(g);
		printf("\nNhan phim Enter de duyet theo DFS !!!\n");
		getch();
		printf("Nhap dinh bat dau: "); scanf("%d",&s);
		printf("\nNhap dinh ket thuc: "); scanf("%d",&f);
		duyetBFS(s,f,g);
	}
	return 0;
}
