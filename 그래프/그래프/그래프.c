#include <stdio.h> 
#include <stdlib.h> 
#include <memory.h> 
#define SIZE 50 

typedef struct Graph {
	int vNum;
	int** matrix;
	int* visit;
} Graph;

typedef struct Queue {
	int items[SIZE];
	int front;
	int rear;
}Queue;

int isEmpty(Queue* queue) {
	if (queue->rear == -1)
		return 1;
	else
		return 0;
}

int isFull(Queue* queue) {
	if (queue->front == 0 && queue->rear == SIZE - 1)
		return 1;
	else
		return 0;
}

Queue* createQueue() {
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	newQueue->front = -1;
	newQueue->rear = -1;
	return newQueue;
}

void BFS(Graph* graph, int vertex) {
	Queue* queue = createQueue();
	int i = 0;

	enQueue(queue, vertex);
	printf(" %d ", vertex);

	while (!isEmpty(queue)) {
		for (i = vertex; i < graph->vNum; i++) {
			if (!graph->visit[i] && graph->matrix[vertex][i] == 1) {
				graph->visit[i] = 1;
				enQueue(queue, i);
				printf(" %d ", i);
			}
		}
		vertex = deQueue(queue);
	}
}

int enQueue(Queue* queue, int data) {
	if (isFull(queue)) {
		return;
	}
	else {
		if (queue->front == -1) {
			queue->front = 0;
		}
		queue->rear++;
		queue->items[queue->rear] = data;
	}
}

int deQueue(Queue* queue) {
	int item = 0;
	if (isEmpty(queue))
		return;
	else {
		if (queue->front >= queue->rear) {
			queue->front = -1;
			queue->rear = -1;
		}
		item = queue->items[queue->front];
		queue->front++;
	}
	return item;
}

Graph* createGraph(int vNum) {
	int i = 0;
	Graph* graph = (Graph*)malloc(sizeof(Graph) * vNum);
	graph->matrix = (int**)malloc(sizeof(int*) * vNum);
	graph->visit = (int*)malloc(sizeof(int) * vNum);

	graph->vNum = vNum;
	for (i = 0; i < vNum; i++) {
		graph->matrix[i] = (int*)malloc(sizeof(int) * vNum);
		memset(graph->matrix[i], 0, sizeof(int) * vNum);

		graph->visit[i] = 0;  // 추가 
	}

	return graph;
}

void addEdge(Graph* graph, int start, int end) {
	graph->matrix[start][end] = 1;
	graph->matrix[end][start] = 1;
}

void printGraph(Graph* graph) {
	int i, j;

	for (i = 0; i < graph->vNum; i++) {
		printf("start %d ->", i);
		for (j = 0; j < graph->vNum; j++) {
			printf("%d ", graph->matrix[i][j]);
		}

		printf("\n");
	}
}

int main(void) {
	Graph* graph;
	graph = createGraph(8);

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 3, 7);
	addEdge(graph, 4, 7);
	addEdge(graph, 2, 5);
	addEdge(graph, 2, 6);
	addEdge(graph, 6, 7);
	addEdge(graph, 5, 7);
	printGraph(graph);

	printf("\n BFS 방문정점 : ");
	BFS(graph, 0);   // 추가 
	return 0;
}