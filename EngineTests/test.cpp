#include "pch.h"
#include "Vector.h"

TEST(VectorTests, ZeroVectorConstructor) {

	Vector2D<float> vector;
	EXPECT_EQ(vector.x, 0);
	EXPECT_EQ(vector.y, 0);
}

TEST(VectorTests, VectorConstructor) {

	Vector2D<float> vector(2.f, 5.f);
	EXPECT_EQ(vector.x, 2.f);
	EXPECT_EQ(vector.y, 5.f);
}