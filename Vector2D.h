#pragma once
#ifndef VECTOR2D_H
#define VECTOR2D_H

template<typename T>
class Vector2D
{

public:
	Vector2D();
	Vector2D(T newx,T newy) : x(newx),y(newy){}
	Vector2D(const Vector2D&);
	Vector2D& operator=(const Vector2D&);
	~Vector2D() = default;

private:
	T x, y;
};
 
template <typename T>
Vector2D<T>::Vector2D()
{
	this->x = 0;
	this->y = 0;
}

template <typename T>
Vector2D<T>::Vector2D(const Vector2D& s)
{
	this->x = s.x;
	this->y = s.y;
}

template <typename T>
Vector2D<T>& Vector2D<T>::operator=(const Vector2D<T>& s)
{
	this->x = s.x;
	this->y = s.y;
}

template <typename T>
T Vector2DDot(Vector2D<T>& A,Vector2D<T>& B)
{
	return A.x * B.x + A.y * B.y;
}

#endif