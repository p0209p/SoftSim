#ifndef POINT3_HPP 
#define POINT3_HPP

#include <ostream>
#include <math.h>

class Point3 {
    public:
        float x;
        float y;
        float z;
        Point3(float xc,float yc,float zc) {x = xc; y=yc; z=zc;}
        Point3(float p[3]) {x = p[0]; y=p[1]; z=p[2];}
        Point3(const float *p) {x = p[0]; y=p[1]; z=p[2];}
    
        Point3 operator +(Point3 a) {Point3 c(a.x+x,a.y+y,a.z+z); return c;}
        Point3 operator -(Point3 a) {Point3 c(a.x-x,a.y-y,a.z-z); return c;}
        Point3 operator *(Point3 a) {Point3 c(a.x*x,a.y*y,a.z*z); return c;}
        Point3 operator /(Point3 a) {Point3 c(x/a.x,y/a.y,z/a.z); return c;}
        
        void normalize() {float mag = magnitude(); x /= mag; y /= mag; z /= mag;};
        inline float magnitude() {return pow(x*x + y*y + z*z, 0.5);}
        inline float sqmagnitude() {return x*x + y*y + z*z;}

        Point3  operator *=(float s) {x*=s; y*=s; z*=s; return *this;}
        Point3  operator +=(float s) {x+= s; y+=s; z+=s; return *this;}
        Point3  operator -=(float s) {x-=s; y-=s; z-=s; return *this;}
        Point3  operator /=(float s) {x/=s; y/=s; z/=s; return *this;}
};

typedef Point3 Vector3;

float dot(Point3 a, Point3 b);
Point3 cross(Point3 a, Point3 b);

#endif
