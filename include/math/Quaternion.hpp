#pragma once
#include <stdexcept>
#include "string"

class Quaternion
{

private:
    /// data

    // w, xi, yj, zk
    double _data[4];

public:
    // Constructors

    Quaternion(double w, double xi, double  yj, double zk);

    Quaternion();
    ~Quaternion();

    /// Quaternion operators

    double operator[](const uint &i) const;
    Quaternion& operator=(const Quaternion& otherQuaternion);
    Quaternion operator*(const Quaternion& otherQuaternion) const;
    Quaternion& operator*=(const Quaternion& otherQuaternion);

    Quaternion conjugate() const;

    static Quaternion IDENTITY();
};


/*
def quaternion_mult(q,r):
    return [r[0]*q[0]-r[1]*q[1]-r[2]*q[2]-r[3]*q[3],
            r[0]*q[1]+r[1]*q[0]-r[2]*q[3]+r[3]*q[2],
            r[0]*q[2]+r[1]*q[3]+r[2]*q[0]-r[3]*q[1],
            r[0]*q[3]-r[1]*q[2]+r[2]*q[1]+r[3]*q[0]]

def point_rotation_by_quaternion(point,q):
    r = [0]+point
    q_conj = [q[0],-1*q[1],-1*q[2],-1*q[3]]
    return quaternion_mult(quaternion_mult(q,r),q_conj)[1:]
*/