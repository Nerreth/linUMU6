#include <assert.h>

float calc_resistance(int count, char conn, float* array);

int main(int argc, const char *argv[])
{
    float serialArray[] = {1.0f, 2.0f, 3.0f};

    float result = calc_resistance(3, 'S', serialArray);
    assert(result == 6.0f);

    float parallelArray[] = {1, 2, 4, 4};

    result = calc_resistance(4, 'P', parallelArray);
    assert(result == 0.5f);

    result = calc_resistance(-1, 'P', parallelArray);
    assert(result == -1.0f);

    result = calc_resistance(4, 'T', parallelArray);
    assert(result == -1.0f);

    result = calc_resistance(4, 'P', 0);

    assert(result == -1.0f);


    return 0;
}

