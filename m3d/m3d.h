#ifndef M3D_H
#define M3D_H

/** ------------- typedef based controls
    sets how the library works, what types of floating points to use etc */

#ifdef M3D_DOUBLE
typedef double M3dValue;
#else
typedef float M3dValue;
#endif // M3D_DOUBLE

/** ---------------- structs */

/** a two component vector */
typedef struct{
    M3dValue x;
    M3dValue y;
}Vec2;

/** a three component vector */
typedef struct{
    M3dValue x;
    M3dValue y;
    M3dValue z;
}Vec3;

/** a four component vector */
typedef struct{
    M3dValue x;
    M3dValue y;
    M3dValue z;
    M3dValue w;
}Vec4;

/** a quaternion */
typedef struct{
    M3dValue i;
    M3dValue j;
    M3dValue k;
    M3dValue w;
}Quat;

/** a matrix with width 3 and height 3
    00  01  02
    10  11  12
    20  21  22
*/
typedef struct{
    M3dValue m[3][3];
}Mat3x3;

/** a matrix with width 4 and height 4
    00  01  02  03
    10  11  12  13
    20  21  22  23
    30  31  32  33

*/
typedef struct{
    M3dValue m[4][4];
}Mat4x4;

/** ---------------- 1 dimensional maths*/

#define PI 3.1415926535897
#define TO_RADS PI / 180.0
#define TO_DEGS 180.0 / PI

/** returns value v clamped between low and high*/
M3dValue m3d1DClamp(M3dValue v, M3dValue low, M3dValue high);
/** linear interpolation between a and b based on t*/
M3dValue m3d1DLerp(M3dValue a, M3dValue b, M3dValue t);

/** ---------------- Vec2 related functions */

/** returns the angle in radians between vectors a and b */
M3dValue m3dVec2Angle(Vec2 a, Vec2 b);
 /** returns the distance between vectors a and b */
M3dValue m3dVec2Distance(Vec2 a, Vec2 b);
/** returns the dot product multiplication of vectors a and b */
M3dValue m3dVec2Dot(Vec2 a, Vec2 b);
/** returns the unsigned length of vector v */
M3dValue m3dVec2Length(Vec2 v);
/** returns the square length of vector v */
M3dValue m3dVec2LengthSqr(Vec2 v);
/** returns the linear interpolation between vectors a and b at value t */
Vec2 m3dVec2Lerp(Vec2 a, Vec2 b, M3dValue t);
/** returns a vector made of the largest components between vectors a and b */
Vec2 m3dVec2Max(Vec2 a, Vec2 b);
/** returns a vector made of the smallest components between vectors a and b */
Vec2 m3dVec2Min(Vec2 a, Vec2 b);
/** returns a normalized copy of the vector passed in */
Vec2 m3dVec2Normalized(Vec2 v);
/** returns the reflection of vector v over the normal vector n */
Vec2 m3dVec2Reflect(Vec2 v, Vec2 n);
/** returns the spherical linear interpolation between vectors a and b */
Vec2 m3dVec2Slerp(Vec2 a, Vec2 b, M3dValue t);

/** returns vector of a and b added by component */
Vec2 m3dVec2AddVec2(Vec2 a, Vec2 b);
/** returns vector of b added to each component of a */
Vec2 m3dVec2AddValue(Vec2 a, M3dValue b);
/** returns vector of a and b subtracted by component */
Vec2 m3dVec2SubVec2(Vec2 a, Vec2 b);
/** returns vector of b subtracted from each component of a */
Vec2 m3dVec2SubValue(Vec2 a, M3dValue b);
/** returns vector of a and b multiplied by component */
Vec2 m3dVec2MulVec2(Vec2 a, Vec2 b);
/** returns vector of b multiplied with each component of a */
Vec2 m3dVec2MulValue(Vec2 a, M3dValue b);
/** returns vector of a and b divided by component */
Vec2 m3dVec2DivVec2(Vec2 a, Vec2 b);
/** returns vector of b divided from each component of a */
Vec2 m3dVec2DivValue(Vec2 a, M3dValue b);

char m3dVec2Equal(Vec2 a, Vec2 b);

/** ---------------- Vec3 related functions*/

/** returns the angle in radians between vectors a and b */
M3dValue m3dVec3Angle(Vec3 a, Vec3 b);
/** returns the cross product multiplication of vectors a and b */
Vec3 m3dVec3Cross(Vec3 a, Vec3 b);
 /** returns the distance between vectors a and b */
M3dValue m3dVec3Distance(Vec3 a, Vec3 b);
/** returns the dot product multiplication of vectors a and b */
M3dValue m3dVec3Dot(Vec3 a, Vec3 b);
/** returns the unsigned length of vector v */
M3dValue m3dVec3Length(Vec3 v);
/** returns the sqr length of vector v */
M3dValue m3dVec3LengthSqr(Vec3 v);
/** returns the linear interpolation between vectors a and b at value t */
Vec3 m3dVec3Lerp(Vec3 a, Vec3 b, M3dValue t);
/** returns a vector made of the largest components between vectors a and b */
Vec3 m3dVec3Max(Vec3 a, Vec3 b);
/** returns a vector made of the smallest components between vectors a and b */
Vec3 m3dVec3Min(Vec3 a, Vec3 b);
/** returns a normalized copy of the vector passed in */
Vec3 m3dVec3Normalized(Vec3 v);
/** returns the reflection of vector v over the normal vector n */
Vec3 m3dVec3Reflect(Vec3 v, Vec3 n);
/** returns the spherical linear interpolation between vectors a and b */
Vec3 m3dVec3Slerp(Vec3 a, Vec3 b, M3dValue t);

/** returns vector of a and b added by component */
Vec3 m3dVec3AddVec3(Vec3 a, Vec3 b);
/** returns vector of b added to each component of a */
Vec3 m3dVec3AddValue(Vec3 a, M3dValue b);
/** returns vector of a and b subtracted by component */
Vec3 m3dVec3SubVec3(Vec3 a, Vec3 b);
/** returns vector of b subtracted from each component of a */
Vec3 m3dVec3SubValue(Vec3 a, M3dValue b);
/** returns vector of a and b multiplied by component */
Vec3 m3dVec3MulVec3(Vec3 a, Vec3 b);
/** returns vector of b multiplied with each component of a */
Vec3 m3dVec3MulValue(Vec3 a, M3dValue b);
/** returns vector of a and b divided by component */
Vec3 m3dVec3DivVec3(Vec3 a, Vec3 b);
/** returns vector of b divided from each component of a */
Vec3 m3dVec3DivValue(Vec3 a, M3dValue b);

char m3dVec3Equal(Vec3 a, Vec3 b);

/** ---------------- Vec4 related functions*/

/** returns vector of a and b added by component */
Vec4 m3dVec4AddVec4(Vec4 a, Vec4 b);
/** returns vector of b added to each component of a */
Vec4 m3dVec4AddValue(Vec4 a, M3dValue b);
/** returns vector of a and b subtracted by component */
Vec4 m3dVec4SubVec4(Vec4 a, Vec4 b);
/** returns vector of b subtracted from each component of a */
Vec4 m3dVec4SubValue(Vec4 a, M3dValue b);
/** returns vector of a and b multiplied by component */
Vec4 m3dVec4MulVec4(Vec4 a, Vec4 b);
/** returns vector of b multiplied with each component of a */
Vec4 m3dVec4MulValue(Vec4 a, M3dValue b);
/** returns vector of a and b divided by component */
Vec4 m3dVec4DivVec4(Vec4 a, Vec4 b);
/** returns vector of b divided from each component of a */
Vec4 m3dVec4DivValue(Vec4 a, M3dValue b);

char m3dVec4Equal(Vec4 a, Vec4 b);

/** ---------------- Quaternion related functions*/

/** Many of these functions require the quaternion to be normalized
    before being passed into the function*/

/** returns the angle in radians between quaternion a and b */
M3dValue m3dQuatAngle(Quat a, Quat b);
Quat m3dQuatAngleVec3(Vec3 a, Vec3 b, Vec3 up);
/** returns a Quaternion rotated r radians around axis a*/
Quat m3dQuatAngleAxis(M3dValue r, Vec3 a);
/** returns the conjugate of quaternion v */
Quat m3dQuatConjugate(Quat v);
/** returns the Euler angles of quaternion v */
Vec3 m3dQuatEuler(Quat v);
Quat m3dQuatFace(Vec3 dir, Vec3 up);
/** returns the unsigned length of quaternion v */
M3dValue m3dQuatLength(Quat v);
/** returns a quaternion that is a linear interpolation from quaternion a to b at value t */
Quat m3dQuatLerp(Quat a, Quat b, M3dValue t);
/** returns a normalized copy of quaternion v */
Quat m3dQuatNormalized(Quat v);
/** returns vector b rotated by quaternion a */
Vec3 m3dQuatRotateVec3(Quat a, Vec3 b);
/** returns a quaternion that is a spherical linear interpolation from quaternion a to b at value t */
Quat m3dQuatSlerp(Quat a, Quat b, M3dValue t);

/** returns quaternion a added to quaternion b*/
Quat m3dQuatAddQuat(Quat a, Quat b);
/** returns quaternion b subtracted from quaternion a*/
Quat m3dQuatSubQuat(Quat a, Quat b);
/** returns quaternion a multiplied by quaternion b*/
Quat m3dQuatMulQuat(Quat a, Quat b);

/** returns quaternion a multiplied component wise by b*/
Quat m3dQuatMulValue(Quat a, M3dValue b);
/** returns quaternion a divided component wise by b*/
Quat m3dQuatDivValue(Quat a, M3dValue b);

char m3dQuatEqual(Quat a, Quat b);

/** ---------------- Mat3x3 related functions*/

/** returns the identity matrix */
Mat3x3 m3dMat3x3InitIdentity();
/** returns an 2d orthographic matrix */
Mat3x3 m3dMat3x3InitOrtho(M3dValue r, M3dValue l, M3dValue t, M3dValue b);
/** returns an 2d orthographic matrix centered at the middle of w and h*/
Mat3x3 m3dMat3x3InitOrthoCentered(M3dValue w, M3dValue h);
/** returns a 3d rotation matrix confined in a 3x3 matrix */
Mat3x3 m3dMat3x3InitRotationFromQuat(Quat quat);
/** sets the matrix m rotated around z by r, returns copy of m after rotation */
Mat3x3 m3dMat3x3Rotate(Mat3x3 *m, M3dValue r);
/** sets the matrix m scaled by s, returns copy of m after scaling */
Mat3x3 m3dMat3x3Scale(Mat3x3 *m, Vec2 s);
/** sets the matrix m translated by t, returns copy of m after translation */
Mat3x3 m3dMat3x3Translate(Mat3x3 *m, Vec2 t);

Mat3x3 m3dMat3x3FromMat4x4(Mat4x4 m);

/** returns the matrix multiplication of a and b*/
Mat3x3 m3dMat3x3MulMat3x3(Mat3x3 a, Mat3x3 b);
Vec3 m3dMat3x3MulVec3(Mat3x3 a, Vec3 b);

/** ---------------- Mat4x4 related functions*/

/** returns the identity matrix */
Mat4x4 m3dMat4x4InitIdentity();
/** returns a 3d orthographic matrix */
Mat4x4 m3dMat4x4InitOrtho(M3dValue r, M3dValue l, M3dValue t, M3dValue b, M3dValue n, M3dValue f);
/** returns a 3d orthographic matrix centered at the middle of the w and h */
Mat4x4 m3dMat4x4InitOrthoCentered(M3dValue w, M3dValue h, M3dValue n, M3dValue f);
/** returns a perspective projection matrix*/
Mat4x4 m3dMat4x4InitPerspective(M3dValue w, M3dValue h, M3dValue fov, M3dValue n, M3dValue f);
/** returns the inverse of a homogeneous matrix, ie: rotation and position ONLY */
// TODO implement this
Mat4x4 m3dMat4x4InverseHomogeneous(Mat4x4 mat);
/** sets the matrix m rotated by r, returns copy of m after rotation */
Mat4x4 m3dMat4x4Rotate(Mat4x4 *m, Quat r);
Mat4x4 m3dMat4x4RotateY(Mat4x4 *m, M3dValue r);
/** sets the matrix m scaled by s, returns copy of m after scaling */
Mat4x4 m3dMat4x4Scale(Mat4x4 *m, Vec3 s);
/** sets the matrix m translated by t, returns copy of m after translation */
Mat4x4 m3dMat4x4Translate(Mat4x4 *m, Vec3 t);

Mat4x4 m3dMat4x4FromMat3x3(Mat3x3 m);

/** returns the matrix multiplication of a and b*/
Mat4x4 m3dMat4x4MulMat4x4(Mat4x4 a, Mat4x4 b);
Vec4 m3dMat4x4MulVec4(Mat4x4 a, Vec4 b);

#endif // M3D_H
