
#include "processor/node.h"

#include "processor/cpu.cpp"
#include "processor/control.cpp"


#define threads 2

using namespace std;

int counter = 0;

struct description{
    int _id = 0;
};

void *init(void* args){
   bus *ics = (bus *) args;
   node pc = node(ics,counter);
   pc.start();
}

int main()
{
    //--CPU THREAD---------------------------------------
   int ret;
   int *stat;
   pthread_t tid[4];
   bus ics;
   for (int i = 0; i <threads ; ++i) {
      counter++;
      if ((ret = pthread_create(&tid[i], NULL, init,&ics) ) != 0) {
         cout << "Error creating thread: " << strerror(ret) << endl;
         exit(1);
      }

      std::this_thread::sleep_for (std::chrono::seconds(1));
   }
   for (int j = 0; j < threads ; ++j) {
      pthread_join(tid[j],NULL);
   }
   //----------------------------------------------------



   //--random generator----------------------------------
   /*
   randomGenerator ran = randomGenerator();
    for (int i = 0; i <10 ; ++i) {
        cout<<ran.getTask()<<endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
   for (int i = 0; i <10 ; ++i) {
      cout<<ran.getTask()<<endl;
      //std::this_thread::sleep_for (std::chrono::seconds(1));
   }
   */
    //---------------------------------------------------


    return 0;
}