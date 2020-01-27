#pragma once
#include <cmath>

template <typename T>
class vec2 {
public:
    T x, y;

    vec2(T x = 0, T y = 0);

    vec2 operator+(vec2 v2);
    vec2 operator-(vec2 v2);
    vec2 operator*(T n);
    vec2 normalization();
    T operator*(vec2 v2);
    T vectorLength();
};

template <typename T>
vec2<T>::vec2(T x, T y) {
    this->x = x;
    this->y = y;
}

// Сумма векторов
template <typename T>
vec2<T> vec2<T>::operator+(vec2 v2) {
    x = x + v2.x;
    y = y + v2.y;
    return vec2(x, y);
}

// Разность векторов
template <typename T>
vec2<T> vec2<T>::operator-(vec2 v2) {
    x = x - v2.x;
    y = y - v2.y;
    return vec2(x, y);
}

// Произведение векторов
template <typename T>
T vec2<T>::operator*(vec2 v2) {
    x = x * v2.x;
    y = y * v2.y;
    return x + y;
}

// Произведение вектора на скаляр
template <typename T>
vec2<T> vec2<T>::operator*(T n) {
    x = x * n;
    y = y * n;
    return vec2(x, y);
}

// Длина вектора
template <typename T>
T vec2<T>::vectorLength() {
    x *= x;
    y *= y;
    return sqrt(x + y);
}

// Нормализация вектора
template <typename T>
vec2<T> vec2<T>::normalization() {
    T length = vectorLength();
    x = sqrt(x) / length;
    y = sqrt(y) / length;
    return vec2(x, y);
}

typedef vec2<int> vec2i;
typedef vec2<long> vec2l;
typedef vec2<float> vec2f;
typedef vec2<double> vec2d;
typedef vec2<long double> vec2ld;