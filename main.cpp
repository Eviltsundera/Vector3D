#include <iostream>
#include "3DVector.h"

template <typename T>
void ASSERT_EQUAL(const T& lhs, const T& rhs) {
    if (lhs != rhs) {
        throw -1;
    }
}

int main() {
    Vector3D a(1, 2, 3);
    Vector3D b(4, 5, 6);

    ASSERT_EQUAL(a + b, Vector3D(5, 7, 9));
    ASSERT_EQUAL(a - b, Vector3D(-3, -3, -3));
    ASSERT_EQUAL(-a, Vector3D(-1, -2, -3));
    ASSERT_EQUAL(a * b, 32.0);
    ASSERT_EQUAL(a ^ b, Vector3D(-3, 6, -3));
    ASSERT_EQUAL(a.length(), sqrt(14));
    ASSERT_EQUAL(a.distance(b), sqrt(27));
    a.normalize();
    ASSERT_EQUAL(a, Vector3D(1 / sqrt(14), 2 / sqrt(14), 3 / sqrt(14)));
    return 0;
}
