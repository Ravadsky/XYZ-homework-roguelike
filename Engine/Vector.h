#pragma once

	template<typename T>
	class Vector2D
	{
	public:
		T x;
		T y;
	public:
		Vector2D()
		{
			x = (T)0;
			y = (T)0;
		}
		Vector2D(T newX, T newY)
		{
			x = newX;
			y = newY;
		}
		Vector2D<T> operator+(const Vector2D<T>& rhs)
		{
			return { x + rhs.x, y + rhs.y };
		}

		Vector2D<T> operator-(const Vector2D<T>& rhs)
		{
			return { x - rhs.x, y - rhs.y };
		}

		Vector2D<T> operator*(const Vector2D<T>& rhs)
		{
			return { x * rhs.x, y * rhs.y };
		}

		Vector2D<T> operator*(const T& scalar)
		{
			return { x * scalar, y * scalar };
		}

		bool operator==(const Vector2D<T>& rhs)
		{
			return x == rhs.x && y == rhs.y;
		}

		inline float GetVectorLength()
		{
			return sqrtf(x * x + y * y);
		}
		inline float DotProduct(const Vector2D<T>& vector)
		{
			return { x * vector.x + y * vector.y };
		}
		inline Vector2D<T> Normalize()
		{
			float length = sqrt(x * x + y * y);

			if (length != 0.0f)
				return Vector2D<T>(x / length, y / length);
			else
				return Vector2D<T>(0.0f, 0.0f);
		}

	};

	template<typename U, typename V>
	U Convert(const V& v)
	{
		return { static_cast<decltype(U::x)>(v.x), static_cast<decltype(U::y)>(v.y) };
	}

	using Vector2Df = Vector2D<float>;
	using Vector2Di = Vector2D<int>;
	using Position = Vector2Df;
