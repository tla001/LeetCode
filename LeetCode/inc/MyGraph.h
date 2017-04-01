/*
 * MyGraph.h
 *
 *  Created on: 2017��3��23��
 *      Author: tla001
 */

#ifndef INC_MYGRAPH_H_
#define INC_MYGRAPH_H_

#include "Include.h"

typedef char VertexType;	//������������
typedef int EdgeType;		//��Ȩ����������

#define MAXVEX 20			//��󶥵���
#define INF		65535		//����������

#define debug

class MyMGraph {
public:
	typedef struct {
		VertexType vexs[MAXVEX];
		EdgeType arc[MAXVEX][MAXVEX];
		int numVer, numEdg;
	} MGraph;
	//��λ
	int LocateMGraph(MGraph *g, VertexType v) {
		int i = 0;
		int res = 0;
		for (i = 0; i < g->numVer; i++) {
			if (g->vexs[i] == v) {
				res = 1;
				break;
			}
		}
		if (res > 0)
			return i;
		else
			return -1;
	}
	//����һ��������ͼ���ڽӾ����ʾ
	void CreateMGraph(MGraph *g) {
		int i, j, k;
		cout << "please input the nums of vertexs and edges: \n";
		cin >> g->numVer >> g->numEdg;
#ifdef debug
		cout << "you have input vertexs num= " << g->numVer << "\tedges num= "
				<< g->numEdg << endl;
#endif
		cout << "input vertexs:\n";
		for (i = 0; i < g->numVer; i++) {
			cin >> g->vexs[i];
		}
		cout << "input done\n";
#ifdef debug
		for (i = 0; i < g->numVer; i++) {
			cout << g->vexs[i] << "\t";
		}
		cout << endl;
#endif
		for (i = 0; i < g->numVer; i++) {
			for (j = 0; j < g->numVer; j++) {
				if (i == j)
					g->arc[i][j] = 0;
				else
					g->arc[i][j] = INF; //��ʼ��
			}
		}
		for (k = 0; k < g->numEdg; k++) {
			VertexType p, q;
			EdgeType w;
			cout << "input (vi,vj) as 'vi vj' " << endl;
			cin >> p >> q;
			cout << "input edge pounds:" << endl;
			cin >> w;
			int m = -1;
			int n = -1;
			m = LocateMGraph(g, p);
			n = LocateMGraph(g, q);
			if (m == -1 || n == -1) {
				cout << "err" << endl;
				exit(-1);
			}
			g->arc[m][n] = w;
			g->arc[n][m] = g->arc[m][n];
#ifdef debug
			cout << w << endl;
			cout << "m= " << m << "\tn= " << n << endl;
			cout << g->arc[m][n] << endl;
#endif
		}
	}
	static void CreateMGraph(MGraph *g, vector<VertexType> vers,
			vector<vector<EdgeType>> edges, int edge_size) {
		g->numEdg = edge_size;
		g->numVer = vers.size();
		int i, j;
		for (i = 0; i < g->numVer; i++) {
			g->vexs[i] = vers[i];
		}
		for (i = 0; i < g->numVer; i++) {
			for (j = 0; j < g->numVer; j++) {
				if (i == j)
					g->arc[i][j] = 0;
				else
					g->arc[i][j] = INF; //��ʼ��
			}
		}
		for (i = 0; i < edges.size(); i++) {
			for (j = i; j < edges[i].size(); j++) {
				g->arc[i][j] = edges[i][j];
				g->arc[j][i] = edges[i][j];
			}
		}
	}
//��ӡͼ
	static void PrintMGraph(MGraph g) {
		int i, j;
		for (i = 0; i < g.numVer; i++) {
			for (j = 0; j < g.numVer; j++) {
				cout << g.arc[i][j] << "\t";
			}
			cout << "\n";
		}
	}
	static void MGraphVisit(VertexType v) {
		cout << v << " ";
	}
	static int visited[MAXVEX];
//�ڽӾ����������ȵݹ��㷨
	static void MGraphDFS(MGraph g, int i) {
		int j;
		visited[i] = 1;
		MGraphVisit(g.vexs[i]);
		for (j = 0; j < g.numVer; j++) {
			if (g.arc[i][j] > 0 && g.arc[i][j] < 65535 && !visited[j]) {
				MGraphDFS(g, j);
			}
		}
	}
//�ڽӾ������ȱ���
	static void MGraphDFSTraverse(MGraph g) {
		int i;
		for (i = 0; i < g.numVer; i++) {
			visited[i] = 0;
		}
		for (i = 0; i < g.numVer; i++) {
			if (!visited[i]) {
				MGraphDFS(g, i);
			}
		}
	}
	static void MGraphTest() {
		MGraph g;
		vector<VertexType> vers = { 'a', 'b', 'c', 'd', 'e' };
		int edgesSize = 3;
		//ʹ�������ǽ��г�ʼ��
		vector<vector<EdgeType>> edges = {
			{	0,1,INF,INF,INF},
			{	1,0,INF,2,INF},
			{	1,1,0,3,INF},
			{	1,1,1,0,INF},
			{	1,1,1,1,0}};
		CreateMGraph(&g, vers, edges, edgesSize);
		PrintMGraph(g);
		MGraphDFSTraverse(g);
	}

	void ShortPath_Dijkstra(MGraph *g, EdgeType *&dist, int *&path,
			VertexType s) {
		int k = LocateMGraph(g, s);
		dist = (EdgeType*) malloc(sizeof(EdgeType) * g->numVer);
		path = (int*) malloc(sizeof(int) * g->numVer);
		int *visited = (int*) malloc(sizeof(int) * g->numVer);
		//��ʼ������ֵ
		for (int i = 0; i < g->numVer; i++) {
			if (g->arc[k][i] != 65535) {
				dist[i] = g->arc[k][i];
				path[i] = k;
			} else {
				dist[i] = 65535;
				path[i] = -1;
			}
			visited[i] = 0;
		}
		visited[k] = 1;
		//��ѭ�����ڱ������µĶ��㣬�����¶����ս�����һȦһȦ����
		for (int i = 1; i < g->numVer; i++) {
			int minDist = 65535;
			int pos = -1;
			//���ҵ�ǰδ�����Ҿ���ֵ��С�ĵ�
			for (int j = 0; j < g->numVer; j++) {
				if (visited[j] == 0 && dist[j] < minDist) {
					minDist = dist[j];
					pos = j;
				}
			}
			if (pos < 0)
				cout << "pos err" << endl;
			//����ǰ��鲢��������ʣ�µ㣨������ǰ�㣩�ľ���ֵ
			visited[pos] = 1;
			for (int j = 0; j < g->numVer; j++) {
				if (visited[j] == 0 && g->arc[pos][j] != 65535
						&& (minDist + g->arc[pos][j]) < dist[j]) {
					dist[j] = minDist + g->arc[pos][j];
					path[j] = pos;		//��¼���ڵ�
				}
			}
		}
	}

	void PrintDShortPath(MGraph *g, EdgeType *dist, int *path, VertexType s,
			int end) {
		int k = LocateMGraph(g, s);
		std::stack<int> p;
		while (end != k) {
			p.push(end);
			end = path[end];
		}
		p.push(end);
		while (!p.empty()) {
			cout << g->vexs[p.top()] << "\t";
			p.pop();
		}
	}
	void MGraphDijkstraTest() {
		MGraph g;
		vector<VertexType> vers = { 'a', 'b', 'c', 'd', 'e' };
		int edgesSize = 3;
		//ʹ�������ǽ��г�ʼ��
		vector<vector<EdgeType>> edges = {
			{	0,1,INF,INF,INF},
			{	1,0,INF,2,INF},
			{	1,1,0,3,INF},
			{	1,1,1,0,INF},
			{	1,1,1,1,0}};
		CreateMGraph(&g, vers, edges, edgesSize);
		PrintMGraph(g);
		EdgeType *dist;
		int *path;

		VertexType s = 'a';
		//MGraphDFSTraverse(g);
		ShortPath_Dijkstra(&g, dist, path, s);
		for (int i = 0; i < g.numVer; i++) {
			if (i != LocateMGraph(&g, s)) {
				cout << "from " << s << " to " << g.vexs[i]
						<< " the short path : " << endl;
				PrintDShortPath(&g, dist, path, s, i);
				cout << " long: " << dist[i] << endl;
			}
		}
	}
	/************************Floyd **********************/
	void ShortPath_Floyd(MGraph *g, EdgeType dist[][MAXVEX],
			int path[][MAXVEX]) {
		for (int i = 0; i < g->numVer; i++) {
			for (int j = 0; j < g->numVer; j++) {
				dist[i][j] = g->arc[i][j];
				path[i][j] = -1;
			}
		}
		for (int k = 0; k < g->numVer; k++) {
			for (int i = 0; i < g->numVer; i++) {
				for (int j = 0; j < g->numVer; j++) {
					if (dist[i][j] > (dist[i][k] + dist[k][j])) {
						dist[i][j] = dist[i][k] + dist[k][j];
						path[i][j] = k;
					}
				}
			}
		}
		//	for (int i = 0; i < g->numVer; i++) {
		//		for (int j = 0; j < g->numVer; j++) {
		//			cout << dist[i][j] << "\t";
		//
		//		}
		//		cout << endl;
		//	}
		//	for (int i = 0; i < g->numVer; i++) {
		//		for (int j = 0; j < g->numVer; j++) {
		//			cout << path[i][j] << "\t";
		//
		//		}
		//		cout << endl;
		//	}
	}
	void PrintFloyd(MGraph *g, EdgeType dist[][MAXVEX], int path[][MAXVEX],
			int start, int end) {
		std::stack<int> shortpath;
		int temp = end;
		while (temp >= 0 && temp != start) {
			shortpath.push(temp);
			temp = path[start][temp];
		}
		shortpath.push(start);
		cout << "from " << g->vexs[start] << " to " << g->vexs[end]
				<< " the short path : " << endl;
		while (!shortpath.empty()) {
			cout << g->vexs[shortpath.top()] << "\t";
			shortpath.pop();
		}
		cout << "*** cost : " << dist[start][end] << endl;
	}
	void MGraphFloydTest() {
		MGraph g;
		vector<VertexType> vers = { 'a', 'b', 'c', 'd', 'e' };
		int edgesSize = 3;
		//ʹ�������ǽ��г�ʼ��
		vector<vector<EdgeType>> edges = {
			{	0,1,INF,INF,INF},
			{	1,0,INF,2,INF},
			{	1,1,0,3,INF},
			{	1,1,1,0,INF},
			{	1,1,1,1,0}};
		CreateMGraph(&g, vers, edges, edgesSize);
		PrintMGraph(g);
		EdgeType dist[MAXVEX][MAXVEX];
		int path[MAXVEX][MAXVEX];

		//MGraphDFSTraverse(g);
		ShortPath_Floyd(&g, dist, path);
		for (int i = 0; i < g.numVer; i++) {
			for (int j = 0; j < g.numVer; j++)
				if (i != j) {
					PrintFloyd(&g, dist, path, i, j);
				}
		}
	}
};

//�ڽӱ�
class LGraph {
public:
	typedef struct EdgeNode         //�߱���
	{
		int adjvex;         //�ڽӵ��򣬴洢�ö����Ӧ���±�
		EdgeType weigth;        //���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ
		struct EdgeNode *next;      //����ָ����һ���ڽӵ�
	} EdgeNode;
	typedef struct VertexNode       //�����ṹ
	{
		VertexType data;        //�����򣬴洢������Ϣ
		EdgeNode *firstedge;        //�߱�ͷָ��
	} VertexNode, AdjList[MAXVEX];
	typedef struct {
		AdjList adjList;
		int numVertexes, numEdges;  //ͼ�е�ǰ�������ͱ���
	} GraphList;
	int LocateLGraph(GraphList *g, VertexType v) {
		int i;
		int res = 0;
		for (i = 0; i < g->numVertexes; i++) {
			if (v == g->adjList[i].data) {
				res = 1;
				break;
			}
		}
		if (res > 0)
			return i;
		else
			return -1;
	}
	void CreateLGraph(GraphList *g) {
		int i;
		EdgeNode *e, *f;

		cout << "please input the nums of vertexs and edges: \n";
		cin >> g->numVertexes >> g->numEdges;
#ifdef debug
		cout << "you have input vertexs num= " << g->numVertexes
				<< "\tedges num= " << g->numEdges << endl;
#endif
		cout << "input vertexs data:\n";
		for (i = 0; i < g->numVertexes; i++) {
			cin >> g->adjList[i].data;
			g->adjList[i].firstedge = NULL;
		}
		//����
		for (i = 0; i < g->numEdges; i++) {
			VertexType p, q;
			EdgeType w;
			cout << "input (vi,vj) as 'vi vj' " << endl;
			cin >> p >> q;
			cout << "input edge pounds:" << endl;
			cin >> w;
			int m = -1, n = -1;
			m = LocateLGraph(g, p);
			n = LocateLGraph(g, q);
#ifdef debug
			cout << "m= " << m << "\tn= " << n << endl;
			cout << "p= " << p << "\tq= " << q << endl;
#endif
			if (m == -1 || n == -1) {
				return;
			}
			//�����ڴ棬���ɱ߱�ڵ�
			e = (EdgeNode *) malloc(sizeof(EdgeNode));
			if (e == NULL) {
				exit(-1);
			}
			e->adjvex = n;
			e->next = g->adjList[m].firstedge;
			e->weigth = w;
			g->adjList[m].firstedge = e;

			f = (EdgeNode *) malloc(sizeof(EdgeNode));
			if (f == NULL) {
				exit(-1);
			}
			f->adjvex = m;
			f->next = g->adjList[n].firstedge;
			f->weigth = w;
			g->adjList[n].firstedge = f;
		}
	}
	void PrintLGraph(GraphList *g) {
		int i = 0;
		while (i < g->numVertexes) {
			cout << "���� " << g->adjList[i].data << " :";
			EdgeNode *e = NULL;
			e = g->adjList[i].firstedge;
			while (e != NULL) {
				cout << g->adjList[e->adjvex].data << "( " << e->weigth
						<< " )\t";
				e = e->next;
			}
			cout << endl;
			i++;
		}
	}
	void LGraphVisit(VertexType v) {
		cout << v << " ";
	}

	static int visited[MAXVEX];
	//�ڽӱ��������ȵݹ��㷨
	void LGraphDFS(GraphList g, int i) {
		EdgeNode *p;
		visited[i] = 1;
		LGraphVisit(g.adjList[i].data);
		p = g.adjList[i].firstedge;
		while (p) {
			if (!visited[p->adjvex]) {
				LGraphDFS(g, p->adjvex);
			}
			p = p->next;
		}
	}
	//�ڽӱ����ȱ���
	void LGraphDFSTraverse(GraphList g) {
		int i;
		for (i = 0; i < g.numVertexes; i++) {
			visited[i] = 0;
		}
		for (i = 0; i < g.numVertexes; i++) {
			if (!visited[i]) {
				LGraphDFS(g, i);
			}
		}
	}
	void LGraphTest() {
		GraphList g;
		CreateLGraph(&g);
		PrintLGraph(&g);
		LGraphDFSTraverse(g);
	}
};
#endif /* INC_MYGRAPH_H_ */
