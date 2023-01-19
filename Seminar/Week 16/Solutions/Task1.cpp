#include <iostream>

using std::cin;
using std::cout;
using std::swap;
using std::nothrow;

struct Seminar{
    unsigned start, duration, end;
};

struct Available_Seminars{

    size_t n;
    Seminar *seminars;

};

Available_Seminars *initialize(const unsigned * const &start_time, const unsigned * const &duration, const size_t &n){

    Available_Seminars *temp = new Available_Seminars;

    temp -> n = n;

    temp -> seminars = new(nothrow) Seminar[n];

    if(!temp -> seminars) return nullptr;

    for(size_t i = 0; i < n; ++i){

        temp -> seminars[i].start = start_time[i];
        temp -> seminars[i].duration = duration[i];
        temp -> seminars[i].end = start_time[i] + duration[i];

    }

    return temp;

}

void sort(Available_Seminars * const &ptr){

    for(size_t i = 0; i < ptr -> n; ++i)
        for(size_t j = 0; j < ptr -> n; ++j)
            if(ptr -> seminars[i].end < ptr -> seminars[j].end)
                swap(ptr -> seminars[i], ptr -> seminars[j]);

}

size_t CalculateMaxSeminars(Available_Seminars * const &ptr){

    size_t count = 1, last_attended;

    sort(ptr);

    last_attended = ptr -> seminars[0].end;

    for(size_t i = 1; i < ptr -> n; ++i)
        if(last_attended <= ptr -> seminars[i].start){

            count++;
            last_attended = ptr -> seminars[i].end;

        }

    return count;

}

int main(){

    size_t n;
    cin >> n;

    unsigned *start_time, *duration;

    start_time = new(nothrow) unsigned[n];
    if(!start_time) return 1;

    duration = new(nothrow) unsigned[n];
    if(!duration){

        delete[] start_time;
        return 1;

    }

    for(size_t i = 0; i < n; ++i)
        cin >> start_time[i];

    for(size_t i = 0; i < n; ++i)
        cin >> duration[i];

    Available_Seminars *ptr = initialize(start_time, duration, n);

    if(!ptr){

        delete[] start_time;
        delete[] duration;
        return 1;

    }

    cout << CalculateMaxSeminars(ptr) << '\n';

    delete[] start_time;
    delete[] duration;
    delete ptr;

}