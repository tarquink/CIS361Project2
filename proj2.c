#include <stdlib.h>
#include <math.h>
#define AVG_SERVICE 2.0

void simulation (int numOfTellers);

Rand double expdist (double mean) {
double r = rand();
r /= RAND_MAX;
return -mean * log(r);
}

int main () {
double t;
                                                   
t = expdist (AVG_SERVICE);

}

