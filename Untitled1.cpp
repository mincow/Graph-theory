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
//
//#include <stdio.h>
//#include <conio.h>
//#define MAX 20
//#define inputfile "./Text3_05.txt"
//
//typedef struct GRAPH {
//	int n;
//	int a[MAX][MAX];
//}DOTHI;
//
//struct STACK {
//	int array[100];
//	int size;
//};
//
//int DocMaTranKe(char TenFile[100], DOTHI &g) {
//	FILE *f;
//	f = fopen(TenFile,"rt");
//	if (f == NULL) {
//		printf("ERROR !!!\n");
//		return 0;
//	}
//	fscanf(f,"%d",&g.n);
//	for (int i = 0; i < g.n; i++) {
//		for (int j = 0; j < g.n; j++) {
//			fscanf(f,"%d",&g.a[i][j]);
//		}
//	}
//	fclose(f);
//	return 1;
//}
//
//void XuatMaTranKe(DOTHI g) {
//	printf("So dinh cua do thi la: %d",g.n);
//	printf("\nMa tran cua do thi la: \n");
//	for (int i = 0; i < g.n; i++) {
//		for (int j = 0; j< g.n; j++) {
//			printf("%5d",g.a[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int dembac(DOTHI g, int n) {
//	int d = 0;
//	for (int i = 0; i < g.n; i++) {
//		if (g.a[n][i]) {
//			d++;
//		}
//	}
//	return d;
//}
//
//void init(STACK &stack) {
//	stack.size = 0;
//}
//
//void getValueStack(STACK &stack, int value) {
//	if (stack.size + 1 >= 100)
//		return;
//	stack.array[stack.size] = value;
//	stack.size++;
//}
//int checkEdge(DOTHI g) {
//	for (int i = 0; i < g.n; i++) {
//		for (int j = 0; j < g.n; j++) {
//			if (g.a[i][j])
//				return 0;
//		}
//	}
//	return 1;
//}
//
//void findPath(int i, DOTHI &g, STACK &stack) {
//	for (int j = 0; j < g.n; j++) {
//		if (g.a[i][j] != 0)	{
////			printf("%d - %d ",i,j); //test thuat toan
//			g.a[i][j] = g.a[j][i] = 0;
//			findPath(j,g,stack);
//		}
//	}
////	printf("III: %d  ",i); //test thuat toan
//	getValueStack(stack,i);
//}
//
//void eulerCircuit(DOTHI g) {
//	int x;
//	for (int i = 0; i < g.n; i++) {
//		if (dembac(g,i) > 0)
//			x = i;
//			break;
//	}	
//	DOTHI temp = g;
//	STACK stack;
//	init(stack);
//	findPath(x,temp,stack);
//	if (checkEdge(temp)) {
//		if (stack.array[0] == stack.array[stack.size - 1]) {
//			printf("\nChu trinh Euler la: ");
//			for (int i = stack.size - 1; i >= 0; i--) {
//				printf("%5d",stack.array[i]);
//			}
//		}
//	}
//	else {
//		printf("\nKhong co chu trinh Euler !!!\n");
//	}
//}
//
//void eulerPath(DOTHI g) {
//	int x;
//	for (int i = 0; i < g.n; i++) {
//		if (dembac(g,i)%2 != 0) {
//			x = i;
//			break;	
//		}
//	}
//	DOTHI temp = g;
//	STACK stack;
//	init(stack);
//	findPath(x,temp,stack);
//	if (checkEdge(temp)) {
//		if (stack.array[0] != stack.array[stack.size - 1]) {
//			printf("\nDuong di Euler la: ");
//			for (int i = stack.size - 1; i >= 0; i--) {
//				printf("%5d",stack.array[i]);
//			}
//		}
//	}
//	else {
//		printf("\nKhong co duong di Euler !!!\n");
//	}
//}
//
//int typeGraph(DOTHI g)  {
//	int countOddDeg = 0;
//	for (int i = 0; i < g.n; i++) {
//		if (dembac(g,i)%2 != 0) {
//			countOddDeg++;
//		}
//	}
//	if (countOddDeg == 2)
//		return -1; // dung 2 dinh bac le
//	if (countOddDeg == 0)
//		return 1; // chi toan bac chan
//	return 0;
//}
//
//int main() {
//	DOTHI g;
//	if (DocMaTranKe(inputfile,g) == 1) {
//		printf("Doc ma tran thanh cong !!!\n");
//		XuatMaTranKe(g);
//		printf("\nNhan phim Enter de kiem tra chu trinh Euler !!!\n");
//		getch();
//		if (typeGraph(g) == -1) {
//			printf("Nua do thi Euler, co duong di Euler la: ");
//			eulerPath(g);
//		}
//		else {
//			if (typeGraph(g) == 1) {
//				printf("Do thi Euler, chu trinh Euler la: ");
//				eulerCircuit(g);
//			}
//			else
//				printf("Day khong phai la do thi Euler !!!!\n");	
//		}
//	}
//	return 0;
//}
//
//
////code tham khao--------------------------!
////#include<iostream>
////#include<vector>
////#include<cmath>
////#define NODE 8
////
////using namespace std;
////int graph[NODE][NODE] = {
////   {0,1,1,0,0,0,0,0},
////   {1,0,0,1,0,0,0,0},
////   {1,0,0,1,0,0,0,0},
////   {0,1,1,0,1,1,0,0},
////   {0,0,0,1,0,0,1,0},
////   {0,0,0,1,0,0,0,1},
////   {0,0,0,0,1,0,0,1},
////   {0,0,0,0,1,1,0,0}
////};
////int tempGraph[NODE][NODE];
////int findStartVert() {
////   for(int i = 0; i<NODE; i++) {
////      int deg = 0;
////      for(int j = 0; j<NODE; j++) {
////         if(tempGraph[i][j])
////            deg++; //increase degree, when connected edge found
////      }
////      if(deg % 2 != 0) //when degree of vertices are odd
////      return i; //i is node with odd degree
////   }
////   return 0; //when all vertices have even degree, start from 0
////}
////int dfs(int prev, int start, bool visited[]){
////   int count = 1;
////   visited[start] = true;
////   for(int u = 0; u<NODE; u++){
////      if(prev != u){
////         if(!visited[u]){
////            if(tempGraph[start][u]){
////               count += dfs(start, u, visited);
////            }
////         }
////      }
////   }
////   return count;
////}
////bool isBridge(int u, int v) {
////   int deg = 0;
////   for(int i = 0; i<NODE; i++)
////      if(tempGraph[v][i])
////   deg++;
////   if(deg>1) {
////      return false; //the edge is not forming bridge
////   }
////   return true; //edge forming a bridge
////}
////int edgeCount() {
////   int count = 0;
////   for(int i = 0; i<NODE; i++)
////      for(int j = i; j<NODE; j++)
////         if(tempGraph[i][j])
////   count++;
////   return count;
////}
////void fleuryAlgorithm(int start) {
////   static int edge = edgeCount();
////   static int v_count = NODE;
////   for(int v = 0; v<NODE; v++) {
////      if(tempGraph[start][v]) {
////         bool visited[NODE] = {false};
////         if(isBridge(start, v)){
////            v_count--;
////         }
////         int cnt = dfs(start, v, visited);
////         if(abs(v_count-cnt) <= 2){
////            cout << start << "--" << v << " ";
////            if(isBridge(v, start)){
////               v_count--;
////            }
////            tempGraph[start][v] = tempGraph[v][start] = 0; //remove edge from graph
////            edge--;
////            fleuryAlgorithm(v);
////         }
////      }
////   }
////}
////int main() {
////   for(int i = 0; i<NODE; i++) //copy main graph to tempGraph
////   for(int j = 0; j<NODE; j++)
////      tempGraph[i][j] = graph[i][j];
////   cout << "Euler Path Or Circuit: ";
////   fleuryAlgorithm(findStartVert());
////}


//#include <stdio.h>
//#include <conio.h>
//#define MAX 20
//#define inputfile "./Text3_01.txt"
//
//
//struct GRAPH {
//	int n;
//	int a[MAX][MAX];
//};
//
//int chuaXet[MAX];
//int luuVet[MAX];
//
//
////-----------------------------------DFS (Depth First Search)
//int readMatrix(char TenFile[100], GRAPH &g) {
//	FILE *f;
//	f = fopen(TenFile,"rt");
//	if (f == NULL) {
//		printf("ERROR !!!\n");
//		return 0;
//	}
//	fscanf(f,"%d",&g.n);
//	for (int i = 0; i < g.n; i++) {
//		for (int j = 0; j < g.n; j++) {
//			fscanf(f,"%d",&g.a[i][j]);
//		}
//	}
//	fclose(f);
//	return 1;
//}
//
//void writeMatrix(GRAPH g) {
//	printf("So dinh cua do thi la: %d",g.n);
//	printf("\nMa tran cua do thi la: \n");
//	for (int i = 0; i < g.n; i++) {
//		for (int j = 0; j< g.n; j++) {
//			printf("%5d",g.a[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void DFS(int v, GRAPH g) {
//	printf("%5d",v);
//	chuaXet[v] = 1;
//	for (int i = 0; i < g.n; i++) {
//		if (g.a[v][i] != 0 && chuaXet[i] == 0) {
//			luuVet[i] = v;
//			DFS(i,g);
//		}
//	}
//}
//
//void duyetDFS(int s, int f, GRAPH g) {
//	printf("Thu tu duyet la: ");
//	int i;
//	for (i = 0; i < g.n; i++) {
//		luuVet[i] = -1;
//		chuaXet[i] = 0;
//	}
//	DFS(s,g);
//	if (chuaXet[f] == 1) {
//		printf("\nDuong di tu dinh %d den dinh %d la: \n\t",s,f);
//		i = f;
//		printf("%d",f);
//		while (luuVet[i] != -1) {
//			printf(" <-");
//			printf("%5d",luuVet[i]);
//			i = luuVet[i];
//		}
//	}
//	else {
//		printf("\nKhong co duong di tu dinh %d den dinh %d !!!\n",s,f);
//	}
//}
//
////-----------------------------BFS (Breath First Search)	
//struct QUEUE {
//	int size;
//	int array[MAX];
//};
//
//void init(QUEUE &q) {
//	q.size = 0;
//}
//
//int isEmpty(QUEUE q) {
//	if (q.size <= 0) {
//		return 1;
//	}
//	return 0;
//}
//
//int push(QUEUE &q, int value) {
//	if (q.size + 1 >= 100) {
//		printf("FULL !!!\n");
//		return 0;
//	}
//	q.array[q.size] = value;
//	q.size++;
//	return 1;
//}
//
//int pop(QUEUE &q,int &value) {
//	if (q.size <= 0) {
//		printf("EMPTY !!!\n");
//		return 0;
//	}
//	value = q.array[0];
//	for (int i = 0; i < q.size -1; i++) {
//		q.array[i] = q.array[i+1];
//	}
//	q.size--;
//	return 1;
//}
//
//void BFS(int v, GRAPH g) {
//	QUEUE q;
//	QUEUE temp;
//	init(q);
//	init(temp);
//	push(q,v);
//	while(!isEmpty(q)) {
//		pop(q,v);
////kiemtralai
//		push(temp,v);
//		chuaXet[v] = 1;
//		for (int i = 0; i < g.n; i++) {
//			if(g.a[v][i] != 0 && chuaXet[i] == 0) {
//				push(q,i);
//				if (luuVet[i] == -1) {
//					luuVet[i] = v;
//				}
//			}
//		}
//	}
//	printf("Thu tu duyet la: ");
//	for (int k = 0; k < temp.size - 1; k++) {
//		printf("%5d",temp.array[k]);
//	}
//}
//
//void duyetBFS(int s, int f, GRAPH g) {
//	int i;
//	for (i = 0; i < g.n; i++) {
//		luuVet[i] = -1;
//		chuaXet[i] = 0;
//	}
//	BFS(s,g);
////	for (int k  = 0; k < g.n; k++) {
////		printf("%5d",luuVet[k]);
////	}
//	if (chuaXet[f] == 1) {
//		printf("\nDuong di tu dinh %d den dinh %d la: ",s,f);
//		i = f;
//		printf("%5d",f);
//		while (luuVet[i] != -1) {
//			printf(" <-");
//			printf("%5d",luuVet[i]);
//			i = luuVet[i];
//		}
//	}
//	else {
//		printf("\nKhong co duong di tu %d den %d !!!\n",s,f);
//	}
//}
//
//int main() {
//	GRAPH g;
//	int s,f;
//	if (readMatrix(inputfile,g) == 1) {
//		printf("Doc ma tran thanh cong !!!\n");
//		writeMatrix(g);
//		printf("\nNhan phim Enter de duyet theo DFS !!!\n");
//		getch();
//		printf("Nhap dinh bat dau: "); scanf("%d",&s);
//		printf("\nNhap dinh ket thuc: "); scanf("%d",&f);
//		duyetBFS(s,f,g);
//	}
//	return 0;
//}
//
//#include <stdio.h>
//#include <conio.h>
//#define MAX 50
//#define inputfile "./Text4_02.txt"
//
//struct GRAPH {
//	int n;
//	int a[MAX][MAX];
//};
//
//struct EDGE {
//	int u;
//	int v;
//	int value;
//};
//
//EDGE T[MAX];
//int chuaXet[MAX];
//
//int DocMaTranKe(char TenFile[100], GRAPH &g) {
//	FILE* f;
//	f = fopen(TenFile,"rt");
//	if (f == NULL) {
//		printf("ERROR !!!\n");
//		return 0;
//	}
//	fscanf(f,"%d",&g.n);
//	for (int i = 0; i < g.n; i++) {
//		for (int j = 0; j < g.n; j++) {
//			fscanf(f,"%d",&g.a[i][j]);
//		}
//	}
//	fclose(f);
//	return 1;	
//}
//
//void XuatMaTranKe(GRAPH g) {
//	printf("So dinh cua do thi: %d\n",g.n);
//	printf("Ma tran ke cua do thi la:\n");
//	for (int i = 0; i < g.n; i++) {
//		for (int j = 0; j < g.n; j++) {
//			printf("%5d",g.a[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int kthople(GRAPH g) {
//	for (int i = 0; i < g.n; i++) {
//		if (g.a[i][i] != 0) {
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int ktdtvh(GRAPH g) {
//	for (int i = 0; i < g.n; i++) {
//		for (int j = 0; j < g.n; j++) {
//			if (g.a[i][j] != g.a[j][i])
//				return 0;
//		}
//	}
//	return 1;
//}
//
//int dembac(GRAPH g, int n) {
//	int d = 0;
//	for (int i = 0; i < g.n; i++) {
//		if (g.a[n][i] == 1) {
//			d++;
//		}
//	}
//		return d;
//}
//
//void dembaccuadinh(GRAPH g) {
//	for (int i = 0; i < g.n; i++) {
//		printf("Bac cua dinh %d la: %d",i,dembac(g,i));
//		printf("\n");
//		}	
//}
//
//void Timcacdinhlienthong(GRAPH g, int nhan[MAX], int i) {
//	for (int j = 0; j < g.n; j++) {
//		if (g.a[i][j] != 0 && nhan[j] != nhan[i]) {
//			nhan[j] = nhan[i];
//			Timcacdinhlienthong(g,nhan,j);
//		}
//	}
//}
//
//int xetlienthong(GRAPH g) {
//	int nhan[MAX];
//	for (int i = 0; i < g.n; i++) {
//		nhan[i] = 0;	
//	}
//	int sotplt = 0;
//	for (int i = 0; i < g.n; i++) {
//		if (nhan[i] == 0) {	
//			sotplt++;
//			nhan[i] = sotplt;
//			Timcacdinhlienthong(g,nhan,i);
//		}
//	}
//	return sotplt;
//}
//
//void prim(GRAPH g) {
//	if (xetlienthong(g) != 1) {
//		 printf("Do thi khong lien thong nen khong thuc hien duoc thuat toan Prim !!!\n");
//		 return;
//	}
//	int nT = 0;
//	for (int i = 0; i < g.n; i++) {
//		chuaXet[i] = 0;
//	}
//	chuaXet[0] = 1;
//	while (nT < g.n - 1) {
//		EDGE minEdge;
//		int minValue = 100;
//		for (int i = 0; i < g.n; i++) {
//			if (chuaXet[i] == 1) {
//				for (int j = 0; j < g.n; j++) {
//					if (chuaXet[j] == 0 && g.a[i][j] != 0 && minValue > g.a[i][j]) {
//						minEdge.u = i;
//						minEdge.v = j;
//						minEdge.value = g.a[i][j];
//						minValue = g.a[i][j];
//					}
//				}
//			}
//		}
//		T[nT] = minEdge;
//		nT++;
//		chuaXet[minEdge.v] = 1;	
//	}
//	int sum = 0;
//	printf("Cay khung nho nhat cua do thi la:\n");
//	for (int i = 0; i < nT - 1; i++) {
//		printf("(%d,%d).\n",T[i].u, T[i].v);
//		sum += T[i].value;
//	}
//	printf("(%d,%d).\n",T[nT - 1].u, T[nT - 1].v);
//	sum += T[nT - 1].value;
//	printf("Tong trong so cua cay khung la: %d \n",sum);
//}
//
//void sortA(EDGE E[100], int sumEdge) {
//	EDGE tempEdge;
//	for (int i = 0; i < sumEdge - 1; i++) {
//		{
//			for (int j = i+1; j < sumEdge; j++) {
//				if (E[i].value > E[j].value) {
//					tempEdge = E[i];
//					E[i] = E[j];
//					E[j] = tempEdge;
//				}
//			}
//		}
//	}
//}
//
//void kruskal(GRAPH g) {
//	EDGE listEdge[MAX];
//	int sumEdge = 0;
//	for(int i = 0; i < g.n; i++) {
//		for (int j = i+1; j < g.n; j++) {
//			if(g.a[i][j] > 0) {
//				listEdge[sumEdge].u = i;
//				listEdge[sumEdge].v = j;
//				listEdge[sumEdge].value = g.a[i][j];
//				sumEdge++;
//			}
//		}
//	}
//	sortA(listEdge,sumEdge);
//	int nT = 0;
//	EDGE T[MAX];
//	int nhan[MAX];
//	for (int i = 0; i < g.n; i++) {
//		nhan[i] = i;
//	}
//	int currentEdge = 0;
//	while (nT < g.n && currentEdge < sumEdge) {
//		if (nhan[listEdge[currentEdge].u] != nhan[listEdge[currentEdge].v]) {
//			T[nT] = listEdge[currentEdge];
//			nT++;
//			int value = nhan[listEdge[currentEdge].v];
//			for (int j = 0; j < g.n; j++) {
//				if (nhan[j] == value) {
//					nhan[j] = nhan[listEdge[currentEdge].u];
//				}
//			}
//		}
//		currentEdge++;
//	}
//	if (nT != g.n -1) {
//		printf("\nDo thi khong lien thong\n");
//	}
//	else {
//		int sum = 0;
//		printf("\nDo thi lien thong\n");
//		printf("Cay khung nho nhat cua do thi la:\n");
//		for (int i = 0; i < nT; i++) {
//			printf("(%d,%d)\n",T[i].u,T[i].v);
//			sum += T[i].value;
//		}
//		printf("\nTong gia tri cua cay khung la: %d\n",sum);
//	}
//}
//
//int main() {
//	GRAPH g;
//	if (DocMaTranKe(inputfile,g) == 1) {
//		printf("\nDa doc file thanh cong\n");	
//		XuatMaTranKe(g);
//		printf("Nhan Enter de tiep tuc !!!!");
//		getch();
//		kruskal(g);
//	}	
//
//	return 0;
//}
//
//#include <stdio.h>
//#include <conio.h>
//#define VOCUC 1000
//#define MAX 30
//#define inputfile "./Text5_01.txt"
//
//
//int luuVet[MAX];
//int chuaXet[MAX];
//int doDaiDuongDi[MAX];
//
//struct GRAPH {
//	int n;
//	int a[MAX][MAX];
//};
//
//int DocMaTranKe(char TenFile[100], GRAPH &g) {
//	FILE* f;
//	f = fopen(TenFile,"rt");
//	if (f == NULL) {
//		printf("ERROR !!!\n");
//		return 0;
//	}
//	fscanf(f,"%d",&g.n);
//	for (int i = 0; i < g.n; i++) {
//		for (int j = 0; j < g.n; j++) {
//			fscanf(f,"%d",&g.a[i][j]);
//		}
//	}
//	fclose(f);
//	return 1;	
//}
//
//void XuatMaTranKe(GRAPH g) {
//	printf("So dinh cua do thi: %d\n",g.n);
//	printf("Ma tran ke cua do thi la:\n");
//	for (int i = 0; i < g.n; i++) {
//		for (int j = 0; j < g.n; j++) {
//			printf("%5d",g.a[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int timDuongNganNhat(GRAPH g) {
//	int li = -1;
//	float p = VOCUC;
//	for (int i = 0; i < g.n; i++) {
//		if (chuaXet[i] == 0 && doDaiDuongDi[i] < p) {
//			p = doDaiDuongDi[i];
//			li = i;
//		}
//	}
//	return li;
//}
//
//void capNhatDuongDi(int u, GRAPH g) {
//	chuaXet[u] = 1;
//	for (int v = 0; v < g.n; v++) {
//		if (chuaXet[v] == 0 && g.a[u][v] > 0 && g.a[u][v] < VOCUC) {
//			if (doDaiDuongDi[v] > doDaiDuongDi[u] + g.a[u][v]) {
//				doDaiDuongDi[v] = doDaiDuongDi[u] + g.a[u][v];
//				luuVet[v] = u;
//			}
//		}
//	}
//}
//
//void dijkstra(int s, int f, GRAPH g) {
//	int i;
//	for (i = 0; i < g.n; i++) {
//		chuaXet[i] = 0;
//		doDaiDuongDi[i] = VOCUC;
//		luuVet[i] = -1;
//	}
//	doDaiDuongDi[s] = 0;
//	while (chuaXet[f] == 0) {
//		int u = timDuongNganNhat(g);
//		if (u == -1)
//			break;
//		capNhatDuongDi(u,g);
//		
//	}
//	if (chuaXet[f] == 1) {
//		printf("Duong di ngan nhat tu dinh %d den dinh %d la: \n\t",s,f);
//		i = f;
//		printf("%d",f);
//		while (luuVet[i] != s) {
//			printf("<- %d",luuVet[i]);
//			i = luuVet[i];
//		}
//		printf("<-%d\n",luuVet[i]);
//		printf("\tVoi do dai la %d \n",doDaiDuongDi[f]);
//	}
//	else {
//		printf("Khong co duong di tu dinh %d den dinh %d !!!!\n",s,f);
//	}
//}
//
////THUAT TOAN FLOYD
//
//int sau_nut[MAX][MAX];
//int L[MAX][MAX];
//
//void floyd(GRAPH g) {
//	int i,j;
//	for (i = 0; i < g.n; i++) {
//		for (j = 0; j < g.n; j++) {
//			if (g.a[i][j] > 0) {
//				sau_nut[i][j] = j;
//				L[i][j] = g.a[i][j];
//			}
//			else {
//				sau_nut[i][j] = -1;
//				L[i][j] = VOCUC;
//			}
//		}
//	}
//	
//	for (int k = 0; k < g.n; k++) {
//		for (i = 0; i < g.n; i++) {
//			for (j = 0; j <g.n; j++) {
//				if (L[i][j] > L[i][k] + L[k][j]) {
//					L[i][j] = L[i][k] + L[k][j];
//					sau_nut[i][j] = sau_nut[i][k];
//				}				
//			}
//		}
//	}
//	int s,f;
//	printf("Nhap dinh bat dau: "); scanf("%d",&s);
//	printf("\nNhap dinh ket thuc: "); scanf("%d",&f);
//	if (sau_nut[s][f] == -1) {
//		printf("Khong co duong di tu dinh %d den dinh %d !!!!\n",s,f);
//	}
//	else {
//		printf("Duong di ngan nhat tu dinh %d den dinh %d la: \n\t",s,f);
//		printf("\t%d",s);
//		int u = s;
//		while (sau_nut[u][f] != f) {
//			u = sau_nut[u][f];
//			printf("--> %d",u);
//		}
//		printf("--> %d",f);
//		printf("\n\tVoi do dai la %d \n",L[s][f]);
//	}
//}
//  
//
//int main() {
//	GRAPH g;
////	int s,f;
////	if (DocMaTranKe(inputfile,g) == 1) {
////		printf("\nDa doc file thanh cong\n");	
////		XuatMaTranKe(g);
////		printf("Nhan Enter de tiep tuc !!!!");
////		getch();
////		printf("\nNhap dinh bat dau: "); scanf("%d",&s);
////		printf("\nNhap dinh ket thuc: "); scanf("%d",&f);
////		dijkstra(s,f,g);
////	}
//	floyd(g);
//	return 0;
//}
