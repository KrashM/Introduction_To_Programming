#include <iostream>
#include <cstring>

unsigned const NUMBER_OF_BITS_IN_BYTE = 8;

void FreeMemory(bool const * const * const hotel, size_t const floors){

    for(size_t i = 0; i < floors; ++i) delete[] hotel[i];
    delete[] hotel;

}

bool **AllocateMatrix(size_t const floors, size_t const numberOfRoomsPerFloor){

    bool **hotel = new(std::nothrow) bool *[floors];

    if(!hotel) return nullptr;

    for(size_t i = 0; i < floors; ++i){

        hotel[i] = new(std::nothrow) bool[numberOfRoomsPerFloor];

        if(!hotel[i]){

            FreeMemory(hotel, i);
            return nullptr;

        }

    }

    return hotel;

}

void InputMatrix(bool * const * const hotel, size_t const floors, size_t const numberOfRoomsPerFloor){

    for(size_t i = 0; i < floors; ++i)
        for(size_t j = 0; j < numberOfRoomsPerFloor; ++j)
            std::cin >> hotel[i][j];

}

size_t FindHacker(bool const * const * const hotel, size_t const floors, size_t const numberOfRoomsPerFloor){

    size_t result = 0;

    for(size_t i = 0; i < floors; ++i)
        for(size_t j = 0; j < numberOfRoomsPerFloor; ++j)
            if(hotel[i][j])
                result ^= i * numberOfRoomsPerFloor + j;

    return result;

}

char *DecriptMessage(bool const * const * const hotel, size_t const floors, size_t const numberOfRoomsPerFloor){

    size_t const messageLength = floors * numberOfRoomsPerFloor / NUMBER_OF_BITS_IN_BYTE;
    char *message = new(std::nothrow) char[messageLength + 1];

    if(!message) return nullptr;

    memset(message, 0, messageLength + 1);

    for(size_t i = 0; i < floors; ++i)
        for(size_t j = 0; j < numberOfRoomsPerFloor; ++j)
            message[2 * i + j / NUMBER_OF_BITS_IN_BYTE] |= hotel[i][j] << (j % NUMBER_OF_BITS_IN_BYTE);

    return message;

}

bool IsPowerOfTwo(size_t const n){
    return n && !(n & (n - 1));
}

int main(){

    size_t const NUMBER_OF_ROOMS_PER_FLOOR = 16;
    size_t n;

    std::cin >> n;

    if(!IsPowerOfTwo(n) || n < NUMBER_OF_ROOMS_PER_FLOOR){

        std::cout << "Invalid input for n\n";
        return -1;

    }

    size_t const FLOORS = n / NUMBER_OF_ROOMS_PER_FLOOR;

    bool **hotel = AllocateMatrix(FLOORS, NUMBER_OF_ROOMS_PER_FLOOR);

    if(!hotel){

        std::cout << "Memory error\n";
        return -1;

    }

    InputMatrix(hotel, FLOORS, NUMBER_OF_ROOMS_PER_FLOOR);

    std::cout << "Hacker resides in room: " << FindHacker(hotel, FLOORS, NUMBER_OF_ROOMS_PER_FLOOR) << '\n';

    char *message = DecriptMessage(hotel, FLOORS, NUMBER_OF_ROOMS_PER_FLOOR);

    if(!message){

        std::cout << "Memory error\n";
        FreeMemory(hotel, FLOORS);
        return -1;

    }

    std::cout << message << '\n';

    FreeMemory(hotel, FLOORS);
    delete[] message;

    return 0;

}