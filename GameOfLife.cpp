#include "life.cpp"
#include <unistd.h>
#include <stdlib.h>
// Adam was here. 
int main(){
srand(time(NULL));
World *nt = new World(50,205);
nt->populate();
while(true){
system("clear");
nt->print();
nt->update();
usleep(100000);
}

return 0;
}
