#include "m3d/m3d.h"

int main(int argc, char **argv)
{
    Quat base = m3dQuatAngleAxis(180.0f * TO_RADS, (Vec3){0.0f, 1.0f, 0.0f});
    Quat rot  = m3dQuatAngleAxis(90.0f * TO_RADS, (Vec3){0.0f, 1.0f, 0.0f});

    Quat rotated = m3dQuatRotateQuat(base, rot);
    Vec3 r = m3dQuatEuler(rotated);

    printf("%f, %f, %f\n", r.x * TO_DEGS, r.y * TO_DEGS, r.z * TO_DEGS);

    return 0;
}
