#pragma once
#include <cmath>
#include <iostream>

class Vector3D {
private:
    double x, y, z;
public:
    Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);
    Vector3D(const Vector3D& vec);

    Vector3D operator+(const Vector3D& vec) const;
    Vector3D operator-(const Vector3D& vec) const;
    Vector3D operator+() const;
    Vector3D operator-() const;

    double operator*(const Vector3D& vec) const;
    Vector3D operator^(const Vector3D& vec) const;

    Vector3D& operator+=(const Vector3D& vec);
    Vector3D& operator-=(const Vector3D& vec);
    Vector3D& operator^=(const Vector3D& vec);

    double length() const;
    void normalize();
    double distance(const Vector3D& vec) const;

    bool operator==(const Vector3D& vec) const;
    bool operator!=(const Vector3D& vec) const;

    friend std::ostream& operator<< (std::ostream &out, const Vector3D &point);
};
