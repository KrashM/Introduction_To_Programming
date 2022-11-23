// You add this to your code with:
// #include "debug_new.h"
// Afterwards you use it in the following manner:
// int *ptr = new(1) int;
// Where 1 can be virually anything you want
// To check if you have cleaned your memory
// You just use the function checkMemoryLeaks();
// If there is a memory leak it will alert you exactly where it happened

#pragma once

#include <cstring>
#include <stdlib.h>
#include <iostream>

using std::cout;

#define DEFAULT_FILE_NAME_SIZE 1024
#define DEFAULT_LIST_SIZE 1024
typedef unsigned long long int size_t;

struct ptr_info_list{

    void *ptr;
    char fileName[DEFAULT_FILE_NAME_SIZE];
    char function[DEFAULT_FILE_NAME_SIZE];
    size_t line, size;

};

static ptr_info_list info_list[DEFAULT_LIST_SIZE];
static size_t ind = 0;

inline void *allocateMemory(const size_t size, const char *fileName, const char *function, const size_t line){

    ptr_info_list newNode;
    strncpy(newNode.fileName, fileName, DEFAULT_FILE_NAME_SIZE);
    strncpy(newNode.function, function, DEFAULT_FILE_NAME_SIZE);
    newNode.ptr = malloc(size);
    newNode.line = line;
    newNode.size = size;

    info_list[ind++] = newNode;

    return newNode.ptr;
    
}

inline void freeMemory(void *ptr){

    if(ptr == nullptr) return;
    ptr_info_list toRemoveNode;
    for(size_t i = 0; i < ind; i++)
        if(info_list[i].ptr == ptr){

            free(info_list[i].ptr);
            for(size_t j = i; j < ind - 1; j++) info_list[j] = info_list[j + 1];
            ind--;
            return;

        }

}

inline void *operator new(size_t size, const bool, const char *fileName = __builtin_FILE(), const char *function = __builtin_FUNCTION(), const size_t line = __builtin_LINE()){ return allocateMemory(size, fileName, function, line); }
inline void *operator new[](size_t size, const bool, const char *fileName = __builtin_FILE(), const char *function = __builtin_FUNCTION(), const size_t line = __builtin_LINE()){ return allocateMemory(size, fileName, function, line); }

inline void operator delete(void* pointer){ freeMemory(pointer); }
inline void operator delete[](void* pointer){ freeMemory(pointer); }

inline void operator delete(void* pointer, size_t size){ freeMemory(pointer); }
inline void operator delete[](void* pointer, size_t size){ freeMemory(pointer); }

inline void checkMemoryLeaks(){

    if(ind == 0){

        cout << "Memory is clean\n";
        return;

    }

    for(size_t i = 0; i < ind; i++)
        cout << i + 1 << ". Found leaked object at " << info_list[i].ptr << " (size " << info_list[i].size << "[bytes]) allocated in: " << info_list[i].fileName << ":" << info_list[i].function << ":" << info_list[i].line << '\n';

}