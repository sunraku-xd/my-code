#include <stdio.h>
int main() {
    int population = 80000;

    int men = population * 52 / 100;
    int women = population - men;

    int total_literate = population * 48 / 100;
    int literate_men = population * 35 / 100;
    int literate_women = total_literate - literate_men;

    int illiterate_men = men - literate_men;
    int illiterate_women = women - literate_women;

    printf("Illiterate men = %d\n", illiterate_men);
    printf("Illiterate women = %d\n", illiterate_women);

    return 0;
}
