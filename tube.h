/*
@Author: Francisco Adrian Llaryora 

The Tube class represents a tube of glass with the balls inside or empty.
*/

#ifndef _TUBE_H_
#define _TUBE_H_

#define EMPTY 0
#define YELLOW 1
#define PINK 2
#define ORANGE 3
#define RED 4
#define GREEN 5
#define WHITE_BLUE 6
#define LIGHT_BLUE 7
#define BLUE 8
#define PURPLE 9
#define WHITE 10

#define COLOURS_LENGTH 11

#define FIRST_OBJECT_INDEX 0
/**
 * Positions in the array
 * \   /
 * | 2 |
 * | 1 |
 * | 0 |
 * \___/
 *       */
 
class Tube{
public:
   Tube(); //It doesn't anything
   ~Tube();
   void init(int testTubeSize);
   
   bool isTubeEmpty();
   bool isTubeFull();
   
   int getTubeColor();
   
   int popTube();
   bool pushTube(int newBall);
   bool validPushTube(int newBall);
   
   bool isTubeResolved();
   
   void fillCollorArray(int* colorArray, int length);
   
private:
   int testTubeSize;
   int * contain;

};
#endif //_TUBE_H_

