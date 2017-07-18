#include<stdio.h>

/**
 * binary search, oriented the ordered and progressive increase sequence. we need three
 * pointers to record the position start and end of every trip(1.fall down 2.a visit),
 * and the middle between in the start and end pointer.
 * 1.Firstly, find the middle position number,case1: if the number greater then the target
 * number, the target number maybe existed in the left of the middle position,so set the
 * end pointer to middle pointer - 1 . case2 on the contrary, if the number of middle position
 * is less than the target number, so set the start pointer to middle pointer. the target
 * number may be existed in the right of the middle position , so set the start pointer
 * to middle pointer.of course the middle position.number equals to the target number,break
 * the search,and turn to "2.second". if the start pointer greater then end pointer, it demonstrates(suggests/shows/illustrates ) the fact
 * that we can't find the target number.Survive and thrive, failure is the indispensable
 * part of our daily life. Hence, wo choose to insert the target number into the sequence
 * in its suitable(appropriate) position to rationalize the sequence orderly.
 * 2.Secondly ,Prior to that, we find the target number's pointer we need to exchange this
 * number with the next number.However  the target number maybe is the last one,under the
 * circumstances, we don't need to exchange.
 */
void SearchExchangeInsert(int iSequence[], int iSeqLength, int iTargetNumber) {
    int iLowIndex = 0, iHighIndex = iSeqLength - 1, iMiddleIndex;
    //iStartIndex < iEndIndex break the while , the iStartIndex = iEndIndex = iMiddleIndex
    while (iLowIndex <= iHighIndex) {
        iMiddleIndex = (iLowIndex + iHighIndex) / 2;
        //we find the target number index is the middle pointer
        if (iSequence[iMiddleIndex] == iTargetNumber)
            break;
        //on the left of the middle pointer, set the end pointer to middle pointer - 1
        if (iSequence[iMiddleIndex] > iTargetNumber) {
            iHighIndex = iMiddleIndex - 1;
        } else
            iLowIndex = iMiddleIndex + 1;
    }

    if(iSequence[iMiddleIndex] == iTargetNumber && iMiddleIndex != iTargetNumber -1){
        int iTemple = iSequence[iMiddleIndex] ;
        iSequence[iMiddleIndex] = iSequence[iMiddleIndex + 1];
        iSequence[iMiddleIndex + 1] = iTemple;
    } else if(iHighIndex < iLowIndex ){
        //the target number must be on the left of the middle position
        for(int i = iHighIndex + 1 ; i < iSeqLength; i++  )
            iSequence[i + 1] = iSequence [i];
        iSequence[iHighIndex + 1] = iTargetNumber;
    }
}

int main() {
    int sequence[]= {1,2,3,4,5,7,8,9};
    SearchExchangeInsert(sequence,8,91);
}