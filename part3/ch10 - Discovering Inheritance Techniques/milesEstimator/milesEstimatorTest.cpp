#include <iostream>
// #include "milesEstimator.h"
#include "efficientCarMilesEstimator.h"
using namespace std;

int main()
{
    EfficientCarMilesEstimator myEstimator;
    myEstimator.setGallonsLeft(3);
    cout << myEstimator.getMilesLeft() << endl;
}