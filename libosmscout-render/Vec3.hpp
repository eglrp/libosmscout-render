/*
    libosmscout-render

    Copyright (C) 2012, Preet Desai

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef OSMSCOUTRENDER_VEC3_HPP
#define OSMSCOUTRENDER_VEC3_HPP

#include <math.h>

namespace osmscout
{
    // cartesian coordinate system 3d vector class
    
    class Vec3
    {
    public:
        Vec3() :
            x(0),y(0),z(0) {}

        Vec3(double myX, double myY, double myZ) :
            x(myX),y(myY),z(myZ) {}

        inline double Dot(Vec3 const & otherVec) const
        {
            return (x*otherVec.x)+
                   (y*otherVec.y)+
                   (z*otherVec.z);
        }

        inline Vec3 Cross(Vec3 const & otherVec) const
        {
            return Vec3((y*otherVec.z - z*otherVec.y),
                        (z*otherVec.x - x*otherVec.z),
                        (x*otherVec.y - y*otherVec.x));
        }

        inline double Magnitude() const
        {
            return sqrt(x*x + y*y + z*z);
        }

        inline double DistanceTo(Vec3 const &otherVec) const
        {
            return sqrt((x-otherVec.x)*(x-otherVec.x) +
                        (y-otherVec.y)*(y-otherVec.y) +
                        (z-otherVec.z)*(z-otherVec.z));
        }

        inline double Distance2To(Vec3 const &otherVec) const
        {
            return ((x-otherVec.x)*(x-otherVec.x) +
                    (y-otherVec.y)*(y-otherVec.y) +
                    (z-otherVec.z)*(z-otherVec.z));
        }

        inline Vec3 Normalized() const
        {      
            double vecMagnitude = sqrt(x*x + y*y + z*z);

            return Vec3(x/vecMagnitude,
                        y/vecMagnitude,
                        z/vecMagnitude);
        }

        inline Vec3 ScaledBy(double scaleFactor) const
        {
            return Vec3(x*scaleFactor,
                        y*scaleFactor,
                        z*scaleFactor);
        }

        inline Vec3 RotatedBy(Vec3 const &axisVec, double angleDegCCW)
        {
            if(!angleDegCCW)
            {   return Vec3(this->x,this->y,this->z);   }

            Vec3 rotatedVec;
            double angleRad = angleDegCCW*3.141592653589/180.0;
            rotatedVec = this->ScaledBy(cos(angleRad)) +
                         (axisVec.Cross(*this)).ScaledBy(sin(angleRad)) +
                         axisVec.ScaledBy(axisVec.Dot(*this)).ScaledBy(1-cos(angleRad));

            return rotatedVec;
        }

        inline Vec3 operator+ (const Vec3 &otherVec) const
        {
            return Vec3(x+otherVec.x,
                        y+otherVec.y,
                        z+otherVec.z);
        }

        inline Vec3 operator- (const Vec3 &otherVec) const
        {
            return Vec3(x-otherVec.x,
                        y-otherVec.y,
                        z-otherVec.z);
        }

        double x;
        double y;
        double z;
    };
}

#endif
