
int _invalid_arguments(int count, char conn, float* array)
{
    int result = 0;
    if (count < 0)
    {
        result = 1;
    }

    if (conn != 'S' && conn != 'P')
    {
        result = 1;
    }

    if (array == 0)
    {
        result = 1;
    }

    return result;
}

float _parallel(int count, float* array)
{
    float intermediateResult = 0.0f;

    int i;
    for (i = 0; i < count; i++)
    {
        intermediateResult += 1.0f / array[i];
    }

    float result = 1.0f / intermediateResult;

    return result; 
}

float _serial(int count, float* array)
{
    float result = 0.0f;

    int i;
    for (i = 0; i < count; i++)
    {
        result += array[i];
    }

    return result; 
}


float calc_resistance(int count, char conn, float* array)
{
    if (_invalid_arguments(count, conn, array))
    {
        return -1.0f;
    }

    float result = 0.0f;

    if (conn == 'P')
    {
        result = _parallel(count, array);
    }
    else
    {
        result = _serial(count, array);
    }

    return result;
}
