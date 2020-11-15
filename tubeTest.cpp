#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <cstring>
#include "tube.h"

#define TEST_TUBE_SIZE 4
#define TEST_TUBE_AMOUNT 3

int main() {

   int const testTubeSize = TEST_TUBE_SIZE;
   int const testTubeAmount = TEST_TUBE_AMOUNT;
   int const balls [4] = { RED, BLUE, WHITE, YELLOW };
   int const balls_poped [4] = { YELLOW, WHITE, BLUE, RED }; 
   
   bool isEmpty = false;
   bool isResolved = false;
   bool isSet = false;
   bool isFull = false;
   int popedBall = EMPTY;
   int tubeColor = EMPTY;
   
   Tube* tubeArray = new Tube [testTubeAmount];
   tubeArray[0].init(testTubeSize);
   tubeArray[1].init(testTubeSize);
   
   printf("===Tube should be empty at begining=== \n");
   isEmpty = tubeArray[0].isTubeEmpty();
   assert(isEmpty);
   
   printf("===Empty Tube shouldn't pop any ball when it hasn't any balls=== \n");  
   popedBall = tubeArray[0].popTube();
   assert(EMPTY == popedBall);

   printf("===Tube colour is the colour on the top === \n");
   tubeColor = tubeArray[0].getTubeColor();
   assert(EMPTY == tubeColor);
   
   printf("===Empty Tube can perform push %d times=== \n", TEST_TUBE_SIZE);
   for(int times = 0; times < TEST_TUBE_SIZE; times++){
	  isSet = tubeArray[0].pushTube(balls[times]);
	  assert(isSet);
	  
	  //printf("===Tube shouldn't be empty when it has any balls=== \n");
	  isEmpty = tubeArray[0].isTubeEmpty();
      assert(!isEmpty);
      //printf("===Tube colour is the colour on the top === \n");
      tubeColor = tubeArray[0].getTubeColor();
      assert(balls[times] == tubeColor);
   }
   
   printf("===Tube should be full at this moment=== \n");
   isFull = tubeArray[0].isTubeFull();
   assert(isFull);
   
   printf("===Tube shouldn't allow a push when is full=== \n");
   isSet = tubeArray[0].pushTube(ORANGE);
   assert(!isSet);
   
   printf("===Full Tube can perform pop %d times=== \n", TEST_TUBE_SIZE);
   for(int times = 0; times < TEST_TUBE_SIZE; times++){ 
	  //printf("===Tube colour is the colour on the top === \n");
      tubeColor = tubeArray[0].getTubeColor();
      assert(balls_poped[times] == tubeColor);
      
	  popedBall = tubeArray[0].popTube();
	  //also the balls must be in inverse order.
	  assert(balls_poped[times] == popedBall);
	  
	  isFull = tubeArray[0].isTubeFull();
      assert(!isFull);
   }
   
   printf("===Tube should be empty at begining=== \n");
   isEmpty = tubeArray[0].isTubeEmpty();
   assert(isEmpty);
   
   printf("===Empty Tube shouldn't pop any ball when it hasn't any balls=== \n");  
   popedBall = tubeArray[0].popTube();
   assert(EMPTY == popedBall);

   printf("===Tube colour is the colour on the top === \n");
   tubeColor = tubeArray[0].getTubeColor();
   assert(EMPTY == tubeColor);
   
   
   //////////////////
   printf("===Empty Tube should be marked as resolved === \n");
   isResolved = tubeArray[1].isTubeResolved();
   assert(isResolved);
   
   printf("===Empty Tube can perform validPushTube %d times=== \n", TEST_TUBE_SIZE);
   for(int times = 0; times < TEST_TUBE_SIZE; times++){
	  isSet = tubeArray[1].validPushTube(RED);
	  assert(isSet);
	  
	  isSet = tubeArray[1].validPushTube(BLUE);
	  assert(!isSet);
	  if( times == 0 || times == 1 ) {
		  isResolved = tubeArray[1].isTubeResolved();
          assert(!isResolved);
	  }
	  
   }
   
   printf("===Full Tube with the same color should be marked as resolved === \n");
   isResolved = tubeArray[1].isTubeResolved();
   assert(isResolved);
   
   delete [] tubeArray; //invoke the destructor !!
   return 0; 
}
