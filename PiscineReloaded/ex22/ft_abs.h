#define ABS(val) (abs(val))

int abs(int value)
{
    if(value < 0)
        return -value;
    else
        return value;
}

#define test "hello"