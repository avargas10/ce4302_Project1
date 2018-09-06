
#include "processor/node.h"

#include "processor/cpu.cpp"
#include "processor/control.cpp"


#define threads 2

using namespace std;

int counter = 0;

struct description{
    pthread_mutex_t lock;
    pthread_mutex_t controlLock;
    mainMemory mem;
    controlBus control = controlBus(&controlLock);
    bus ics = bus(&mem,&control,&controlLock);

};

void *init(void* args){
   description *des = (description *) args;
   node pc = node(&des->ics,&des->control,counter,&des->lock,&des->controlLock);
   pc.start();
}

int main()
{
    //--CPU THREAD---------------------------------------
   int ret;
   int *stat;
   pthread_t tid[4];
   description des;

   if (pthread_mutex_init(&des.lock, NULL) != 0)
   {
      printf("\n mutex init failed\n");
      return 1;
   }
    if (pthread_mutex_init(&des.controlLock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

   for (int i = 0; i <threads ; ++i) {
      counter++;
      if ((ret = pthread_create(&tid[i], NULL, init,&des) ) != 0) {
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