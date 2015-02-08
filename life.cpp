#include "life.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//RULES
/*
1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by overcrowding.
4. Any dead cell with exactly three neighbors becomes a live cell, as if by reproduction.
*/

using namespace std;

void World::populate(){
  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
    world[i][j] = rand() % 2;
    ghost_world[i][j] = 0;
    }
   
  }
/**
//////////////Select Initial Live Cells/////////////////////////
world[10][8] = 1;
world[10][9] = 1;
world[10][10] = 1;
world[10][11] = 1;
world[11][8] = 1;
world[11][9] = 1;
world[11][10] = 1;
world[12][8] = 1;
world[12][9] = 1;
world[12][10] = 1;
world[12][11] = 1;

////////////////////////////////////////////////////////////////
**/
};

void World::print(){
  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
    string cell;
    if (world[i][j] == 0){cell = " ";}
    else if (world[i][j] == 1){cell = "O";}
    else {cell = "X  ";} 
    if (j == width-1){
    cout<<cell<<endl;
    }
    else {
    cout<<cell;
    }
    }
  } 
};

int World::find_neighbor(int i,int j){
   int neb;
   if (i==0) {
     if (j==0){
     neb = world[i][j+1] + world[i+1][j] + world[i+1][j+1] + world[height-1][j] + world[height-1][j+1] + world[height-1][width-1] + world[i][width-1] + world[i+2][width-1];
     }
     else if(j==width-1) {
     neb = world[i][width-2] + world[i+1][width-1] + world[i+1][width-2] + world[i][0] + world[i+1][0] + world[height-1][0] + world[height-1][width-1] + world[height-1][width-2]; 
     }
     else {
     neb = world[i][j-1] + world[i+1][j-1] + world[i+1][j] + world[i+1][j+1] + world[i][j+1] + world[height-1][j-1] + world[height-1][j] + world[height-1][j+1];
     }
   }
   else if (i==height-1){
     if(j==0){
     neb = world[height-2][j] + world[height-2][j+1] + world[height-1][j+1] + world[height-2][width-1] + world[height-1][width-1] + world[0][j] + world[0][j+1] + world[0][width-1]; 
     }
     else if(j==width-1){
     neb = world[height-2][width-1] + world[height-2][width-2] + world[height-1][width-2] + world[height-2][0] + world[height-1][0] + world[0][0] + world[0][width-2] + world[0][width-1];
     }
     else {
     neb = world[i][j-1] + world[i-1][j-1] + world[i-1][j] + world[i-1][j+1] + world[i][j+1] + world[0][j-1] + world[0][j] + world[0][j+1];
     }
   }
   else if(j==0){
   neb = world[i-1][j] + world[i-1][j+1] + world[i][j+1] + world[i+1][j+1] + world[i+1][j] + world[i-1][width-1] + world[i][width-1] + world[i+1][width-1];
   }
   else if(j==width-1){
   neb = world[i-1][j] + world[i-1][j-1] + world[i][j-1] + world[i+1][j-1] + world[i+1][j] + world[i-1][0] + world[i][0] + world[i+1][0];
   }
   else {
   neb = world[i-1][j-1] + world[i-1][j] + world[i-1][j+1] + world[i][j+1] + world[i][j-1] + world[i+1][j-1] + world[i+1][j] + world[i+1][j+1]; 
   }
   return neb;
}

void World::update(){
  
  for(int i=0;i<height;i++){
  for(int j=0;j<width;j++){
    int neb = find_neighbor(i,j);
    bool live = (world[i][j]==1);
    if ( neb<2 &&  live) {
    ghost_world[i][j] = 0;
    }
    else if (1<neb && neb<4 && live){
   ghost_world[i][j] = 1; 
  } else if ((neb>3) && live){
   ghost_world[i][j] = 0;
  }
    else if (neb==3 && !live){
    ghost_world[i][j] = 1;
  }
    else {
    ghost_world[i][j] = world[i][j];
  }
  }
  }
  for(int i=0;i<height;i++){
  for(int j=0;j<width;j++){
  world[i][j] = ghost_world[i][j];
  }
  } 
 }

