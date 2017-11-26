//
//  SimpleHeap.c
//  SimpleHeap
//
//  Created by wan on 2017. 11. 26..
//  Copyright © 2017년 wan. All rights reserved.
//

#include "SimpleHeap.h"


void HeapInit(Heap * ph){ // heap 의 초기화
    ph->numOfData = 0;
}

int HIsEmpty(Heap * ph){  // 힙이 비어있는지 확인
    if(ph->numOfData == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

int GetParentIDX(int idx){ // 부모 노드의 인덱스 값 반환
    return idx/2;
}

int GetLChildIDX(int idx){ // 왼쪽 자식 노드의 인덱스 값 반환
    return idx*2;
}

int GetRChildIDX(int idx){ // 오른쪽 자식 노드의 인덱스 값 반환
    return GetLChildIDX(idx)+1;
}

// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 변환
int GetHiPriChildIDX(Heap * ph, int idx){
    
    //자식 노드가 존재 한다면 numOfData 값이 리턴되는것보다 클것이고 아니면 numOfData 가 작을것이다.
    if(GetLChildIDX(idx) > ph->numOfData)
        return 0;
    // 자식 노드가 왼쪽 자식노드 한만 존재한다면
    else if(GetLChildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
    else {
        //오른쪽 자식 노드의 우선순위가 높다면
        if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
            return GetRChildIDX(idx); // 오른쪽 자식 노드의 인덱스 값 변환
        else
            return GetLChildIDX(idx); // 왼쪽 자식 노드의 인덱스 값 변환
    }
}

//힙에 데이터 저장
void HInsert(Heap * ph, HData data, Priority pr){
    int idx = ph->numOfData+1; // 새노드가 저장딜 인덱스 값을 idx에 저장
    HeapElem nelem =  {pr,data}; // 새 노드의 생성 및 초기화
    
    // 새노드가 저장될 위치가 루트 노드의 위치가 아니라면 while문 반복
    while(idx != 1){
        
        // 새노드와 부모 노드의 우선순위 비교
        if(pr < (ph->heapArr[GetParentIDX(idx)].pr)){ // 새노드의 우선순위가 높다면
            // 부모노드를 한 레벨 내림, 실제로 내림
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            // 새 노드를 한 레벨 올림, 실제로 올리지는 않고 인덱스 값만 갱신
            idx = GetParentIDX(idx);
        }else{
            break; // 새 노드의 우선순위가 높지 않다면
        }
    }
    
    ph->heapArr[idx] = nelem; // 새 노드를 배열에 저장
    ph->numOfData += 1;
}


//힙에서 데이터 삭제
HData HDelete(Heap * ph){
    HData retData = (ph->heapArr[1]).data; // 반환을 위해서 삭제할 데이터 저장
    HeapElem lastElem = ph->heapArr[ph->numOfData]; // 힙의 마지막 노드 저장
    
    // 아래의 변수 parentIdx에는 마지막 노드가 저장될 위치 정보가 담긴다.
    int parentIdx = 1; // 루트 노드가 위치해야 할 인덱 값 저장
    int childIdx;
    
    
    // 루트 노드의 우선순위가 높은 자식 노드를 시작으로 반복문 시작
    while(childIdx = GetHiPriChildIDX(ph, parentIdx)){
        
        //마지막 노드와 우선순위 비교
        // pr가 낮을수록 우선순위가 높은것
        if(lastElem.pr <= ph->heapArr[childIdx].pr){
            // 마지막 노드의 우선순위가 높으면 반복문 탈출
            break;
        }
        // 마지막 노드보다 우선순위 높으니, 비교대상 노드의 위치를 한 레벨 올림
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        // 마지막 노드가 저장될 위치정보를 한 레벨 내림
        parentIdx = childIdx;
    } // 반복문 탈출하면 parentIdx에는 마지막 노드의 위치정보가 시작됨
    
    
    // 마지막 노드 최종 저장
    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
    
}




