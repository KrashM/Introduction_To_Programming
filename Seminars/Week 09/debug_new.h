// You add this to your code with:
// #include "debug_new.h"
// Afterwards you can continue using operators new and delete as normal.
// To check if you have cleaned your memory,
// you just use the function checkMemoryLeaks() at the end of your program.
// If there is a memory leak it will alert you exactly where it happened
// !!!Important note!!! This code runs in c++ standart >= 11.

#ifndef DEBUG_NEW
#define DEBUG_NEW

#include <cstddef>
#include <cstdio>
#include <string>
#include <vector>

struct ptr_info{

    char const *file, *function;
    void *ptr = nullptr;
    size_t size;
    int line;

    ptr_info(){}
    ptr_info(void * const ptr, size_t const size, char const *file, char const *function, int const line): ptr(ptr), size(size), file(file), function(function), line(line){}

};

std::vector<ptr_info> info_list;
typedef std::vector<ptr_info>::iterator v_iter;

void *allocateMemory(size_t const size, char const *file, char const *function, int const line){

    void *ptr = malloc(size);

    info_list.emplace_back(ptr, size, file, function, line);

    return ptr;

}

void freeMemory(void *ptr){

    if(ptr == nullptr) return;

    for(v_iter i = info_list.begin(); i != info_list.end(); ++i)
        if(i -> ptr == ptr){

            free(i -> ptr);
            info_list.erase(i);
            return;

        }

}

void *operator new(size_t const size, char const *file, char const *function, int const line){ return allocateMemory(size, file, function, line); }
void *operator new[](size_t const size, char const *file, char const *function, int const line){ return allocateMemory(size, file, function, line); }

void operator delete(void *pointer) noexcept{ freeMemory(pointer); }
void operator delete[](void *pointer) noexcept{ freeMemory(pointer); }

void operator delete(void *pointer, size_t const size) noexcept{ freeMemory(pointer); }
void operator delete[](void *pointer, size_t const size) noexcept{ freeMemory(pointer); }

void printList(){

    for(size_t i = 0; i < info_list.size(); ++i)
        printf("%zu. Found leaked object at %#x (size %zu[bytes]) allocated in: %s: %s(): %d\n", 
            i + 1, info_list[i].ptr, info_list[i].size, info_list[i].file, info_list[i].function, info_list[i].line);

}

void checkMemoryLeaks(){

    if(info_list.empty()){

        printf("Memory is clean\n");
        return;

    }

    for(size_t i = 0; i < info_list.size(); ++i){

        printf("%zu. Found leaked object at %#x (size %zu[bytes]) allocated in: %s: %s(): %d\n", 
            i + 1, info_list[i].ptr, info_list[i].size, info_list[i].file, info_list[i].function, info_list[i].line);
        free(info_list[i].ptr);

    }

    info_list.clear();

}

#define new(NOTHROW) new(__FILE__, __FUNCTION__, __LINE__)

#endif