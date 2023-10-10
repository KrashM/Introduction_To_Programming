#include <iostream>

int main ()
{
    int declaredButNotInitializedVariable;
    int declared_but_not_initialized_variable;
    //int declared-but-not-initialized-variable;

    int declaredAndInitializedVariable = 10;

    int dummyVariable; // declared variable
    dummyVariable = 20; // assigning a value

    dummyVariable = 200;
    dummyVariable = declaredAndInitializedVariable;
    declaredAndInitializedVariable = dummyVariable;

    return 0;
}