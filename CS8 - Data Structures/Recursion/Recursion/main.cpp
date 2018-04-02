#include <cassert>    // Provides assert
#include <cstdlib>    // Provides EXIT_SUCCESS
#include "useful.h"   // From Appendix H. Provides random_real, display

// PROTOTYPE for the function used in this demonstration program.
void random_fractal
(double left_height, double right_height, double width, double epsilon);

int main()
{
    cout << "Turn your head sideways to see a nice landscape:" << endl;
    random_fractal(0, 0, 16, 1);
    return EXIT_SUCCESS;
}

void random_fractal
(double left_height, double right_height, double width, double epsilon)
{
    double mid_height;   // Height of the midpoint of the line segment

    assert(width > 0);
    assert(epsilon > 0);
    if (width <= epsilon){
cout << "this checks if width is small enough to kick itself out of the recursion" << endl;
            display(right_height);
            cout << "IM FREE FROM THE RECURSIVE HELL!" << endl;

    }
    else
    {
        cout << "mid height will decrease by each recursion" << endl;
        mid_height = (left_height + right_height) / 2;
            mid_height += random_real(-width, width);
            cout << "recursion takes place here, where the width will be be then decreased" << endl;
            random_fractal(left_height, mid_height,   width/2, epsilon);
            cout << "this moves the mid to left" << endl;
            random_fractal(mid_height,  right_height, width/2, epsilon);
            cout << "this moves the mid to right" << endl;
    }
}
