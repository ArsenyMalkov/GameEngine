#include "pch.h"
#include "../GameEngine/Math.h"


namespace {
	TEST(MathTest, CreateVector) {
		// EXPECT_EQ(1, 1);
		// EXPECT_TRUE(true);
		Vector3 vector = Vector3();
		EXPECT_EQ(vector.x, 0);
		EXPECT_EQ(vector.y, 0);
		EXPECT_EQ(vector.z, 0);

		vector = Vector3(6, -4.2, 52.3);
		EXPECT_EQ(vector.x, 6);
		EXPECT_EQ(vector.y, -4.2);
		EXPECT_EQ(vector.z, 52.3);
	}

	TEST(MathTest, Magnitude) {
		Vector3 vector = Vector3();
		EXPECT_EQ(vector.magnitude(), 0);

		vector = Vector3(6, -4.2, 52.3);
		EXPECT_NEAR(vector.magnitude(), 52.8103, 0.1);

		vector = Vector3(2, 3, 4);
		EXPECT_NEAR(vector.magnitude(), 5.3851, 0.1);
	}

	TEST(MathTest, Normalize) {
		Vector3 vector = Vector3();
		Vector3 normalized = vector.normalize();
		EXPECT_EQ(normalized.x, 0);
		EXPECT_EQ(normalized.y, 0);
		EXPECT_EQ(normalized.z, 0);

		vector = Vector3(6, -4.2, 52.3);
		normalized = vector.normalize();
		EXPECT_NEAR(normalized.x, 0.1136, 0.1);
		EXPECT_NEAR(normalized.y, -0.0795, 0.1);
		EXPECT_NEAR(normalized.z, 0.9903, 0.1);

		vector = Vector3(2, 3, 4);
		normalized = vector.normalize();
		EXPECT_NEAR(normalized.x, 0.3714, 0.1);
		EXPECT_NEAR(normalized.y, 0.5570, 0.1);
		EXPECT_NEAR(normalized.z, 0.7428, 0.1);
	}

	TEST(MathTest, OperatorPlus) {
		Vector3 vector = Vector3();
		Vector3 vector1 = Vector3();
		Vector3 result = vector + vector1;
		EXPECT_EQ(result.x, 0);
		EXPECT_EQ(result.y, 0);
		EXPECT_EQ(result.z, 0);

		result += vector1;
		EXPECT_EQ(result.x, 0);
		EXPECT_EQ(result.y, 0);
		EXPECT_EQ(result.z, 0);

		result = vector + 2;
		EXPECT_EQ(result.x, 2);
		EXPECT_EQ(result.y, 2);
		EXPECT_EQ(result.z, 2);

		result += -6.2;
		EXPECT_EQ(result.x, -4.2);
		EXPECT_EQ(result.y, -4.2);
		EXPECT_EQ(result.z, -4.2);

		vector = Vector3(6, -4.2, 52.3);
		vector1 = Vector3(-4, 1.5, 4.2);
		result = vector + vector1;
		EXPECT_EQ(result.x, 2);
		EXPECT_EQ(result.y, -2.7);
		EXPECT_EQ(result.z, 56.5);

		vector = Vector3(2, -3, -4);
		result += vector;
		EXPECT_EQ(result.x, 4);
		EXPECT_EQ(result.y, -5.7);
		EXPECT_EQ(result.z, 52.5);

		result = vector + 3;
		EXPECT_EQ(result.x, 5);
		EXPECT_EQ(result.y, 0);
		EXPECT_EQ(result.z, -1);

		result += 0.1;
		EXPECT_EQ(result.x, 5.1);
		EXPECT_EQ(result.y, 0.1);
		EXPECT_EQ(result.z, -0.9);
	}

	TEST(MathTest, OperatorMinus) {
		Vector3 vector = Vector3();
		Vector3 vector1 = Vector3();
		Vector3 result = vector - vector1;
		EXPECT_EQ(result.x, 0);
		EXPECT_EQ(result.y, 0);
		EXPECT_EQ(result.z, 0);

		result -= vector1;
		EXPECT_EQ(result.x, 0);
		EXPECT_EQ(result.y, 0);
		EXPECT_EQ(result.z, 0);

		result = vector - 2;
		EXPECT_EQ(result.x, -2);
		EXPECT_EQ(result.y, -2);
		EXPECT_EQ(result.z, -2);

		result -= -6.2;
		EXPECT_EQ(result.x, 4.2);
		EXPECT_EQ(result.y, 4.2);
		EXPECT_EQ(result.z, 4.2);

		vector = Vector3(6, -4.2, 52.3);
		vector1 = Vector3(-4, 1.5, 4.2);
		result = vector - vector1;
		EXPECT_NEAR(result.x, 10, 0.1);
		EXPECT_NEAR(result.y, -5.7, 0.1);
		EXPECT_NEAR(result.z, 48.1, 0.1);

		vector = Vector3(2, -3, -4);
		result -= vector;
		EXPECT_NEAR(result.x, 8, 0.1);
		EXPECT_NEAR(result.y, -2.7, 0.1);
		EXPECT_NEAR(result.z, 52.1, 0.1);

		result = vector - 3;
		EXPECT_EQ(result.x, -1);
		EXPECT_EQ(result.y, -6);
		EXPECT_EQ(result.z, -7);

		result -= 0.1;
		EXPECT_EQ(result.x, -1.1);
		EXPECT_EQ(result.y, -6.1);
		EXPECT_EQ(result.z, -7.1);
	}
}