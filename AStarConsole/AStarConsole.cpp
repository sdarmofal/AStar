// AStarConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"

const int x = 20, y = 20;
int map[x][y];
int closedNodes[x][y];
int openNodes[x][y];
int heurestic[x][y];
int endpointX = 5, endpointY = 13;

void setEndpoint();
void calculateHeurestic();
void printMap(int(*)[x]);

int main()
{
	setEndpoint();
	calculateHeurestic();

	printf("****** CURRENT MAP ******\n");
	printMap(map);
	printf("****** CURRENT HEURESTIC ******\n");
	printMap(heurestic);


	return 0;
}

void setEndpoint() {
	map[endpointX][endpointY] = 9;
}

void calculateHeurestic() {
	int distanceToEndpointX;
	int distanceToEndpointY;

	printf("****** CALCULATING HEURESTIC ******");

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			distanceToEndpointX = endpointX - j;
			distanceToEndpointY = endpointY - i;
			heurestic[i][j] = abs(distanceToEndpointX) + abs(distanceToEndpointY);
			printf("%d    ", heurestic[i][j]);
		}
		printf("\n");
	}
}

void printMap(int(*map)[x]) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}