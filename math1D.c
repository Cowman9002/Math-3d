#include "m3d/m3d.h"
#include <math.h>

M3dValue m3d1DClamp(M3dValue v, M3dValue low, M3dValue high)
{
    return fmin(fmax(low, v), high);
}

M3dValue m3d1DLerp(M3dValue a, M3dValue b, M3dValue t)
{
    return (1.0 - t) * a + b * t;
}
