#include<iostream>

struct node{

    int data;
    node *link;

};

struct q1{

    node *front;
    node *rear;
    node *link;

};

struct queue{

    q1 q;
    node *t;

    public:
        void initialize() {

            q.front = NULL;
            q.rear = NULL;

        }

        int front(){
            return q.front -> data;
        }

        void enqueue(int data){

            t = new(node);

            t -> data = data;
            t -> link = NULL;

            if((q.rear) == NULL) q.front = t;
            else q.rear -> link = t;

            q.rear = t;

        }
        void dequeue(){
            
            if(q.front == NULL) return;

            t = q.front;
            q.front = q.front -> link;

            if(q.front == NULL) q.rear = NULL;

            delete(t);

        }
        bool isEmpty(){
            
            if(q.front == NULL) return true;
            return false;

        }

};

void sort(int *array, int size);

int main(){

    int array[] = {3, 45, 1535, 7, 67, 4, 1};
    
    for(unsigned i = 0; i < sizeof(array) / 4; i++) std :: cout << array[i] << ' ';
    std :: cout << '\n';

    sort(array, sizeof(array) / 4);

    for(unsigned i = 0; i < sizeof(array) / 4; i++) std :: cout << array[i] << ' ';
    std :: cout << '\n';

    return 0;

}

void sort(int *array, int size){

    const unsigned countOfAllDigits = 10;
    queue numbers[countOfAllDigits];
    for (unsigned i = 0; i < countOfAllDigits; i++) numbers[i].initialize();
    unsigned maxPowOfTen = 1, currPowOfTen = 1;

    for (unsigned i = 0; i < size; i++)
        while(array[i] / maxPowOfTen != 0) maxPowOfTen *= 10;

    while(currPowOfTen != maxPowOfTen){

        for(unsigned i = 0; i < size; i++) numbers[array[i] / currPowOfTen % 10].enqueue(array[i]);

        int index = 0;
        
        for (unsigned i = 0; i < countOfAllDigits; i++){

            while(!numbers[i].isEmpty()){

                array[index] = numbers[i].front();
                numbers[i].dequeue();
                index++;

            }
            
        }

        currPowOfTen *= 10;
        
    }
    

}