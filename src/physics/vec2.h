template <typename T>
class vec2 {
public:
    T x, y, n;

    vec2(T x = 0, T y = 0);

    vec2 operator+(vec2 v2);
    vec2 operator-(vec2 v2);
    vec2 operator*(T n);
    T operator*(vec2 v2);
};

template <typename T>
vec2<T>::vec2(T x, T y) {
    this->x = x;
    this->y = y;
}

template <typename T>
vec2<T> vec2<T>::operator+(vec2 v2) {
    x = x + v2.x;
    y = y + v2.y;
    return vec2(x, y);
}

template <typename T>
vec2<T> vec2<T>::operator-(vec2 v2) {
    x = x - v2.x;
    y = y - v2.y;
    return vec2(x, y);
}

template <typename T>
T vec2<T>::operator*(vec2 v2) {
    x = x * v2.x;
    y = y * v2.y;
    return x + y;
}

template <typename T>
vec2<T> vec2<T>::operator*(T n) {
    x = x * n;
    y = y * n;
    return vec2(x, y);
}