#include "tube.h"
#include <stdio.h>
#include <assert.h>
#include <cstring>
Tube::Tube(){}

/***
 * TESTED PASS
 * */
void Tube::init(int testTubeSize){
  if(testTubeSize < 1) {
      //printf("=========testTubeSize must be >= 1============ \n");
      assert(testTubeSize < 1);
   } 
   this->testTubeSize = testTubeSize;
   contain = new int[testTubeSize];
   std::memset(contain, EMPTY, sizeof(int) * testTubeSize); 
   return;
}

/***
 * TESTED PASS
 * */
Tube::~Tube(){
   printf("=========~Neuron============ \n");
   if (testTubeSize >= 1) {
	   delete []contain;
   }
}

/***
 * TESTED PASS
 * */
bool Tube::isTubeEmpty() {
   //programming errors cases
   assert(testTubeSize >= 1);
   return EMPTY == contain[FIRST_OBJECT_INDEX];
 }
 
 /***
 * TESTED PASS
 * */
 bool Tube::isTubeFull() {
   //programming errors cases
   assert(testTubeSize >= 1);

   return EMPTY != contain[(testTubeSize-1)];
 }

/***
 * TESTED PASS
 * */
int Tube::getTubeColor() {
   //programming errors cases
   assert(testTubeSize >= 1);

   int ballAtTheTop = EMPTY;
   //All elements in the tube are colors
   for( int objectIndex = (testTubeSize-1); objectIndex >= FIRST_OBJECT_INDEX; objectIndex--) {
      ballAtTheTop = contain[objectIndex];
      if(EMPTY != ballAtTheTop) {
         break;
      }
   }
   return ballAtTheTop;
 }

/***
 * TESTED PASS
 * */
int Tube::popTube() {
   //programming errors cases
   assert(testTubeSize >= 1);

   int ballAtTheTop = EMPTY;
   //All elements in the tube are colors
   for( int objectIndex = (testTubeSize-1); objectIndex >= FIRST_OBJECT_INDEX; objectIndex--) {
      if(EMPTY != contain[objectIndex]) {
         ballAtTheTop = contain[objectIndex];
         contain[objectIndex] = EMPTY;
         break;
      }
   }
   return ballAtTheTop;
 }

/**
 * Return if isSet the newBall into the tube. 
 * */
 /***
 * TESTED PASS
 * */
bool Tube::pushTube(int newBall) {
   //programming errors cases
   assert(testTubeSize >= 1);

   //All elements in the tube are colors
   for( int objectIndex = FIRST_OBJECT_INDEX; objectIndex < testTubeSize;objectIndex++) {
      //if it is the first empty space
      if(EMPTY == contain[objectIndex]){
         contain[objectIndex] = newBall;
         return true;
      }
   }
   return false;
 }
 
bool Tube::isTubeResolved() {
   //programming errors cases
   assert(testTubeSize >= 1);

   bool isResolved = true;
   int const tubeColor = contain[FIRST_OBJECT_INDEX];
   
   //All elements in the tube are colors
   for( int objectIndex = FIRST_OBJECT_INDEX; objectIndex < testTubeSize;objectIndex++) {
      if(tubeColor != contain[objectIndex]){
         isResolved = false;
         break;
      }
   }
   return isResolved;
 }

/**
 * Return if isSet the newBall into the tube. 
 * */
 /***
 * TESTED PASS
 * */
bool Tube::validPushTube(int newBall) {
   //programming errors cases
   assert(testTubeSize >= 1);
   int currentTubeColor = EMPTY;
   //All elements in the tube are colors
   for( int objectIndex = FIRST_OBJECT_INDEX; objectIndex < testTubeSize;objectIndex++) {
      //if it is the first empty space
      if(EMPTY == contain[objectIndex]){
         if( currentTubeColor == newBall){
			 contain[objectIndex] = newBall;
             return true;
		}
         if( currentTubeColor == EMPTY){
			 contain[objectIndex] = newBall;
             return true;
		}
		return false;
      }
      currentTubeColor = contain[objectIndex];
   }
   return false;
 }

void Tube::fillCollorArray(int* colorArray, int length) {
	//programming errors cases
    assert(testTubeSize >= 1);
    
	for( int objectIndex = FIRST_OBJECT_INDEX; objectIndex < testTubeSize;objectIndex++) {
		if(EMPTY == contain[objectIndex]){
			break;
		}
		int colorIndex = contain[objectIndex];
		assert(length > colorIndex );
		colorArray[colorIndex]++;
	}
	
	return;
}
