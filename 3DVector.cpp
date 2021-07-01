#include "3DVector.h"

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {
}

Vector3D Vector3D::operator+(const Vector3D& vec) const {
    return Vector3D(x + vec.x, y + vec.y, z + vec.z);
}

Vector3D Vector3D::operator-(const Vector3D& vec) const {
    return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

Vector3D Vector3D::operator+() const {
    return Vector3D(*this);
}

Vector3D Vector3D::operator-() const {
    return Vector3D(-x, -y, -z);
}

double Vector3D::operator*(const Vector3D &vec) const {
    return x * vec.x + y * vec.y + z * vec.z;
}

Vector3D Vector3D::operator^(const Vector3D &vec) const {
    return Vector3D(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
}

Vector3D& Vector3D::operator+=(const Vector3D &vec) {
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}

Vector3D &Vector3D::operator^=(const Vector3D &vec) {
    x = y * vec.z - z * vec.y;
    y = z * vec.x - x * vec.z;
    z = x * vec.y - y * vec.x;
    return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &vec) {
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}

double Vector3D::length() const {
    return sqrt(x * x + y * y + z * z);
}

void Vector3D::normalize() {
    double eps = 1e-6;
    if (length() < eps) {
        return;
    }
    auto len = length();
    x /= len;
    y /= len;
    z /= len;
}

double Vector3D::distance(const Vector3D &vec) const {
    return Vector3D(vec - *this).length();
}

bool Vector3D::operator==(const Vector3D &vec) const {
    double eps = 1e-6;
    return Vector3D(vec - *this).length() < eps;
}

std::ostream &operator<<(std::ostream &out, const Vector3D &vec) {
    return out << '{' << vec.x << ',' << vec.y << ',' << vec.z << '}';
}

bool Vector3D::operator!=(const Vector3D &vec) const {
    return !(*this == vec);
}

Vector3D::Vector3D(const Vector3D &vec) = default;

