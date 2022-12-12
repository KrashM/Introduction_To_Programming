#include<iostream>
#include<stdio.h>

const double g = 9.8;

struct Body
{
    int x, y;
    double mass, speed;
    char description[20];
};

void defineBodies(Body *bodies, unsigned n);
void printBodies(Body bodies[], unsigned n);
void printBody(Body body);
Body findBody(Body bodies[], unsigned n, char type);

int main(){

    const unsigned n = 5;
    Body bodies[n];

    defineBodies(bodies, n);
    printBodies(bodies, n);

    // char type;

    // std :: cout << "What type do you want to search for?\n:";
    // std :: cin >> type;

    // printBody(findBody(bodies, n, type));

    printBody(findBody(bodies, n, 'p'));
    printBody(findBody(bodies, n, 'k'));
    printBody(findBody(bodies, n, 's'));

    return 0;

}

void defineBodies(Body *bodies, unsigned n){

    for (int i = 0; i < n; i++){
        std :: cout << "Insert coordinates x and y -> int int\n:";
        std :: cin >> bodies[i].x >> bodies[i].y;

        std :: cout << "Insert mass -> double\n:";
        std :: cin >> bodies[i].mass;

        std :: cout << "Insert speed -> double\n:";
        std :: cin >> bodies[i].speed;

        std :: cout << "Insert description -> char[20]\n:";
        std :: cin.get();
        std :: cin.getline(bodies[i].description, sizeof(bodies[i].description));
        
    }

    std :: cout << '\n';

}

void printBody(Body body){
    printf("Body coordinates -> (%i,%i)\nBody mass -> %.2fkg\nBody speed -> %.2fkm/h\nDescription -> %s\n\n", body.x, body.y, body.mass, body.speed, body.description);
}

void printBodies(Body *bodies, unsigned n){

    for (int i = 0; i < n; i++) printBody(bodies[i]);

}

Body findMaxPotentialEnergy(Body bodies[], unsigned n);
Body findMaxKineticEnergy(Body bodies[], unsigned n);
Body findClosestFullEnergyToTheAverageOfAllFullEnergies(Body bodies[], unsigned n);

enum Type{

    MAX_POTENTIAL_ENERGY = 'p',
    MAX_KINETIC_ENERGY = 'k'

};

Body findBody(Body bodies[], unsigned n, char type){

    switch (type){

        case Type::MAX_POTENTIAL_ENERGY:
            return findMaxPotentialEnergy(bodies, n);

        case Type::MAX_KINETIC_ENERGY:
            return findMaxKineticEnergy(bodies, n);
        
        default:
            return findClosestFullEnergyToTheAverageOfAllFullEnergies(bodies, n);
        
    }

}

Body findMaxPotentialEnergy(Body bodies[], unsigned n){

    double maxEnergy = 0;
    int indexOfBody = 0;

    for (int i = 0; i < n; i++){

        double potentialEnergy = bodies[i].mass * bodies[i].y * g;
        if(potentialEnergy > maxEnergy){
            
            indexOfBody = i;
            maxEnergy = potentialEnergy;

        }

    }

    return bodies[indexOfBody];

}

Body findMaxKineticEnergy(Body bodies[], unsigned n){

    double maxEnergy = 0;
    int indexOfBody = 0;

    for (int i = 0; i < n; i++){

        double kineticEnergy = bodies[i].speed * bodies[i].speed * bodies[i].mass / 2;
        if(kineticEnergy > maxEnergy){

            indexOfBody = i;
            maxEnergy = kineticEnergy;

        }

    }

    return bodies[indexOfBody];    

}

double abs(double value){ return (value < 0) ? value * -1 : value; }

Body findClosestFullEnergyToTheAverageOfAllFullEnergies(Body bodies[], unsigned n){

    double fullEnergies[n], average = 0;

    for (int i = 0; i < n; i++){

        double potentialEnergy, kineticEnergy;

        potentialEnergy = bodies[i].mass * bodies[i].y * g;
        kineticEnergy = bodies[i].speed * bodies[i].speed * bodies[i].mass / 2;

        fullEnergies[i] = potentialEnergy + kineticEnergy;
        average += fullEnergies[i];

    }

    average /= n;

    double smallestDifference = abs(fullEnergies[0] - average);
    int indexOfBody = 0;

    for (int i = 1; i < n; i++){

        double curDifference = abs(fullEnergies[i] - average);

        if(curDifference < smallestDifference){

            smallestDifference = curDifference;
            indexOfBody = i;

        }
        
    }
    
    return bodies[indexOfBody];

}

/*
0 0
15
15
Hello world
15 10
12.45
183.45
Pass this string
46 12
1
156
This is intresting
78 64
85
12
I'm fat
45 64
15
35
Who are you?
*/