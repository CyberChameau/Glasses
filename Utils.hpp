#ifndef UTILS_H
#define UTILS_H

// k > 0 - left shift
// k < 0 - right shift
template <typename T>
T cycle_shift(T n, int8_t k) 
{
    if (k > 0)
        return n << k | n >> sizeof(n)*8 - k;
    else if (k < 0)
        return n >> -k | n << sizeof(n)*8 + k;
    
    return n;
}

#endif