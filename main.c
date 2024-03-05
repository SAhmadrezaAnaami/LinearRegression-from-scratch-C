#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    /* linear Regression */
    // y= 2x + 1 
    float x[9] = {1,2,3,4 , 5, 6 ,7 , 8, 9};
    float y[9] = {3,5,7,9 , 11, 13 ,15 , 17, 19};

    // y = ax + y
    float a = 0;
    float b = 0;

    // fit 
    int iters = 500000;
    float learning_rate = 0.01;
    for (int i = 0; i < iters; i++)
    {
        float da = 0;
        float db = 0;
        float error = 0 ;
        for (int j = 0; j < 9; j++)
        {
            float y_pred = a * x[j] + b;
            error = y_pred - y[j];
            float sum = 1.0f/9.0f;
            // print sum
            
            da += sum * error * x[j];
            db += sum * error;

        }
        a -= learning_rate * da;
        b -= learning_rate * db;

        printf("iter = %d\n", i);
        printf("error = %f\n", error);
        printf("a = %f\n", a);
        printf("b = %f\n", b);
        
    }
    

}
