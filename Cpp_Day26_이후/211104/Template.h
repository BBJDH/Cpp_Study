#pragma once

template<typename T>
T add(T const x, T const y);

template<typename T,typename U=float>
class Pair
{
public:
	Pair<T, U> operator+(Pair const& pair)const;
public:

		T upper;
		U lower;
};


