#include "hiker.h"
#include <stdio.h>

// The learner put a print inside a loop to see what was happening, and it
// prints far more than the 50K the runner keeps.
int answer()
{
    int total = 0;
    for (int i = 0; i != 5000; i++)
    {
        printf("debug: i is %d, total is %d\n", i, total);
        total += 6;
    }
    return 6 * 7;
}
