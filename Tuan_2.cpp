#include <stdio.h>
#include <conio.h>
#define MAX 20
#define inputfile "./Text3_05.txt"

typedef struct GRAPH {
	int n;
	int a[MAX][MAX];
}DOTHI;

struct STACK {
	int array[100];
	int size;
};

int DocMaTranKe(char TenFile[100], DOTHI &g) {
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

void XuatMaTranKe(DOTHI g) {
	printf("So dinh cua do thi la: %d",g.n);
	printf("\nMa tran cua do thi la: \n");
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j< g.n; j++) {
			printf("%5d",g.a[i][j]);
		}
		printf("\n");
	}
}

int dembac(DOTHI g, int n) {
	int d = 0;
	for (int i = 0; i < g.n; i++) {
		if (g.a[n][i]) {
			d++;
		}
	}
	return d;
}

void init(STACK &stack) {
	stack.size = 0;
}

void getValueStack(STACK &stack, int value) {
	if (stack.size + 1 >= 100)
		return;
	stack.array[stack.size] = value;
	stack.size++;
}
int checkEdge(DOTHI g) {
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (g.a[i][j])
				return 0;
		}
	}
	return 1;
}

void findPath(int i, DOTHI &g, STACK &stack) {
	for (int j = 0; j < g.n; j++) {
		if (g.a[i][j] != 0)	{
//			printf("%d - %d ",i,j); //test thuat toan
			g.a[i][j] = g.a[j][i] = 0;
			findPath(j,g,stack);
		}
	}
//	printf("III: %d  ",i); //test thuat toan
	getValueStack(stack,i);
}

void eulerCircuit(DOTHI g) {
	int x;
	for (int i = 0; i < g.n; i++) {
		if (dembac(g,i) > 0)
			x = i;
			break;
	}	
	DOTHI temp = g;
	STACK stack;
	init(stack);
	findPath(x,temp,stack);
	if (checkEdge(temp)) {
		if (stack.array[0] == stack.array[stack.size - 1]) {
			printf("\nChu trinh Euler la: ");
			for (int i = stack.size - 1; i >= 0; i--) {
				printf("%5d",stack.array[i]);
			}
		}
	}
	else {
		printf("\nKhong co chu trinh Euler !!!\n");
	}
}

void eulerPath(DOTHI g) {
	int x;
	for (int i = 0; i < g.n; i++) {
		if (dembac(g,i)%2 != 0) {
			x = i;
			break;	
		}
	}
	DOTHI temp = g;
	STACK stack;
	init(stack);
	findPath(x,temp,stack);
	if (checkEdge(temp)) {
		if (stack.array[0] != stack.array[stack.size - 1]) {
			printf("\nDuong di Euler la: ");
			for (int i = stack.size - 1; i >= 0; i--) {
				printf("%5d",stack.array[i]);
			}
		}
	}
	else {
		printf("\nKhong co duong di Euler !!!\n");
	}
}

int typeGraph(DOTHI g)  {
	int countOddDeg = 0;
	for (int i = 0; i < g.n; i++) {
		if (dembac(g,i)%2 != 0) {
			countOddDeg++;
		}
	}
	if (countOddDeg == 2)
		return -1; // dung 2 dinh bac le
	if (countOddDeg == 0)
		return 1; // chi toan bac chan
	return 0;
}

int main() {
	DOTHI g;
	if (DocMaTranKe(inputfile,g) == 1) {
		printf("Doc ma tran thanh cong !!!\n");
		XuatMaTranKe(g);
		printf("\nNhan phim Enter de kiem tra chu trinh Euler !!!\n");
		getch();
		if (typeGraph(g) == -1) {
			printf("Nua do thi Euler, co duong di Euler la: ");
			eulerPath(g);
		}
		else {
			if (typeGraph(g) == 1) {
				printf("Do thi Euler, chu trinh Euler la: ");
				eulerCircuit(g);
			}
			else
				printf("Day khong phai la do thi Euler !!!!\n");	
		}
	}
	return 0;
}


//code tham khao--------------------------!
//#include<iostream>
//#include<vector>
//#include<cmath>
//#define NODE 8
//
//using namespace std;
//int graph[NODE][NODE] = {
//   {0,1,1,0,0,0,0,0},
//   {1,0,0,1,0,0,0,0},
//   {1,0,0,1,0,0,0,0},
//   {0,1,1,0,1,1,0,0},
//   {0,0,0,1,0,0,1,0},
//   {0,0,0,1,0,0,0,1},
//   {0,0,0,0,1,0,0,1},
//   {0,0,0,0,1,1,0,0}
//};
//int tempGraph[NODE][NODE];
//int findStartVert() {
//   for(int i = 0; i<NODE; i++) {
//      int deg = 0;
//      for(int j = 0; j<NODE; j++) {
//         if(tempGraph[i][j])
//            deg++; //increase degree, when connected edge found
//      }
//      if(deg % 2 != 0) //when degree of vertices are odd
//      return i; //i is node with odd degree
//   }
//   return 0; //when all vertices have even degree, start from 0
//}
//int dfs(int prev, int start, bool visited[]){
//   int count = 1;
//   visited[start] = true;
//   for(int u = 0; u<NODE; u++){
//      if(prev != u){
//         if(!visited[u]){
//            if(tempGraph[start][u]){
//               count += dfs(start, u, visited);
//            }
//         }
//      }
//   }
//   return count;
//}
//bool isBridge(int u, int v) {
//   int deg = 0;
//   for(int i = 0; i<NODE; i++)
//      if(tempGraph[v][i])
//   deg++;
//   if(deg>1) {
//      return false; //the edge is not forming bridge
//   }
//   return true; //edge forming a bridge
//}
//int edgeCount() {
//   int count = 0;
//   for(int i = 0; i<NODE; i++)
//      for(int j = i; j<NODE; j++)
//         if(tempGraph[i][j])
//   count++;
//   return count;
//}
//void fleuryAlgorithm(int start) {
//   static int edge = edgeCount();
//   static int v_count = NODE;
//   for(int v = 0; v<NODE; v++) {
//      if(tempGraph[start][v]) {
//         bool visited[NODE] = {false};
//         if(isBridge(start, v)){
//            v_count--;
//         }
//         int cnt = dfs(start, v, visited);
//         if(abs(v_count-cnt) <= 2){
//            cout << start << "--" << v << " ";
//            if(isBridge(v, start)){
//               v_count--;
//            }
//            tempGraph[start][v] = tempGraph[v][start] = 0; //remove edge from graph
//            edge--;
//            fleuryAlgorithm(v);
//         }
//      }
//   }
//}
//int main() {
//   for(int i = 0; i<NODE; i++) //copy main graph to tempGraph
//   for(int j = 0; j<NODE; j++)
//      tempGraph[i][j] = graph[i][j];
//   cout << "Euler Path Or Circuit: ";
//   fleuryAlgorithm(findStartVert());
//}
