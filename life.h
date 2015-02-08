//Created by Nathaniel Taylor 5/27/13
#ifndef _WORLD_H_
#define _WORLD_H_

using namespace std;

//World class

class World {

  public:
  int height;
  int width;
  World(int x, int y){
  height = x;
  width = y;
  }
  void populate();
  void update();
  void print();
  private:
  int world[200][200];
  int ghost_world[200][200];
  int find_neighbor(int i,int j);


};

#endif
