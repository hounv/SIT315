#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <pthread.h>

#define NUM_THREADS 100

using namespace std::chrono;
using namespace std;

struct RandomTask{
    int *v;
    int start;
    int end;
}

void* randomVector(void* arg)
{
    RandomTask *task = ((struct RandomTask *)args);

    for (int i = task->start; i < task->end; i++)
    {
        task->v[i] = rand() % 100;//...vector[i] = rand() % 100;
    }
}


int main(){

    unsigned long size = 100000000; //vector size 100 million index

    srand(time(0));

    int *v1, *v2, *v3; //3 pointers

    pthread_t randomThread[NUM_THREADS];
    pthread_t addThread[NUM_THREADS];

    //the clock of start and end time of 
    auto start = high_resolution_clock::now(); 

    // memory been allocated to vector .... for the entire size of the integer
    v1 = (int *) malloc(size * sizeof(int *));
    v2 = (int *) malloc(size * sizeof(int *));
    v3 = (int *) malloc(size * sizeof(int *));

    int partition_size = size/(NUM_THREADS/2);

    for[size_t i = 0; i<NUM_THREADS/2; i++]{
        struct RandomTask *randomTask = (struct RandomTask *)malloc(sizeof(struct RandomTask))
        randomTask->v =v1;
        randomTask->start = i * partition_size;
        randomTask->end = randomTask->start + partition_size - 1;

        pthread_create(&randomThread[i], NULL, randomVector, (void *)randomTask):
    }
    for[size_t i = NUM_THREADS/2; i<NUM_THREADS; i++]{
        struct RandomTask *randomTask = (struct RandomTask *)malloc(sizeof(struct RandomTask))
        randomTask->v =v2;
        randomTask->start = i * partition_size;
        randomTask->end = randomTask->start + partition_size - 1;

        pthread_create(&randomThread[i], NULL, randomVector, (void *)randomTask):
    }


    for(size_t i = 0; i < NUM_THREADS; i++){
        pthread_join(randomThread[i], NULL);
    }
    //add up the rest of it 
    for (int i = 0; i < size; i++)
    {
        v3[i] = v1[i] + v2[i];
    }

    auto stop = high_resolution_clock::now();

    //Calculate the duration
    auto duration = duration_cast<microseconds>(stop - start);


    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}