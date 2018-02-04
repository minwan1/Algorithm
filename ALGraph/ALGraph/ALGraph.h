//
//  ALGraph.h
//  ALGraph
//
//  Created by wan on 2018. 2. 4..
//  Copyright © 2018년 wan. All rights reserved.
//

#ifndef ALGraph_h
#define ALGraph_h

#include "DLinkedList.h"
#include <stdio.h>


enum {A, B, C, D, E, F, G, H, I, J}; // 정점의 이름을 상수화!

typedef struct _ual
{
    int numV; // 정점의 수
    int numE; // 간선의 수
    List * adjList; // 간선의 정보
} ALGraph;

//그래의 초기화
void GraphInit(ALGraph * pg, int nv);

//그래프의 리소스 해제
void GraphDestroy(ALGraph * pg);

//간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV);

//간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

#endif /* ALGraph_h */
