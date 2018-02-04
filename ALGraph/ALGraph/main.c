//
//  main.c
//  ALGraph
//
//  Created by wan on 2018. 2. 4..
//  Copyright © 2018년 wan. All rights reserved.
//

#include <stdio.h>
#include "ALGraph.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    ALGraph graph;
    GraphInit(&graph, 5);
    
    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, C, D);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, A);
    
    ShowGraphEdgeInfo(&graph);
    
    GraphDestroy(&graph);
    return 0;
    
    
    return 0;
}
