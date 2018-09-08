
#include "processor/node.h"

#include "processor/cpu.cpp"
#include "processor/control.cpp"


#define threads 4

using namespace std;

int counter = 0;
//Struct que pasa como parametro a cada uno de los threads con informacion compartida para todos
struct description{
    pthread_mutex_t lock;
    pthread_mutex_t controlLock;
    mainMemory mem;
    controlBus control = controlBus(&controlLock);
    bus ics = bus(&mem,&control,&controlLock);

};


//metodo paralelizado el cual se encarga de generar cada uno de los nodos que corren de manera paralela
void *init(void* args){
   description *des = (description *) args;
   node pc = node(&des->ics,&des->control,counter,&des->lock,&des->controlLock);
   pc.start();
}

/*
 * Main del Sistema genera los threads y las variables que se van a utilizar
 */
int main()
{
    //--CPU THREAD---------------------------------------
   int ret;
   int *stat;
   pthread_t tid[4];
   description des;
    /*
     * Generado de lock para bus principal
     * */
   if (pthread_mutex_init(&des.lock, NULL) != 0)
   {
      printf("\n mutex init failed\n");
      return 1;
   }
    /*
      * Generador de lock para bus de control
      * */
    if (pthread_mutex_init(&des.controlLock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }
    /*
     * Creacion de la cantidad de threads seleccionada
     * */
   for (int i = 0; i <threads ; ++i) {
      counter++;
      if ((ret = pthread_create(&tid[i], NULL, init,&des) ) != 0) {
         cout << "Error creating thread: " << strerror(ret) << endl;
         exit(1);
      }

      std::this_thread::sleep_for (std::chrono::seconds(1));
   }
   /*
    * EL sistema espera a que todos los threads terminen para terminar sus procesos
    * */
   for (int j = 0; j < threads ; ++j) {
      pthread_join(tid[j],NULL);
   }

    return 0;
}