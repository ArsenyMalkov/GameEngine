#include "pch.h"
#include "../GameEngine/Math.h"


namespace {

    const double abs_error = 0.0001;

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
        EXPECT_NEAR(vector.magnitude(), 52.8103, abs_error);

        vector = Vector3(2, 3, 4);
        EXPECT_NEAR(vector.magnitude(), 5.3851, abs_error);
    }

    TEST(MathTest, Normalize) {
        Vector3 vector = Vector3();
        Vector3 normalized = vector.normalize();
        EXPECT_EQ(normalized.x, 0);
        EXPECT_EQ(normalized.y, 0);
        EXPECT_EQ(normalized.z, 0);

        vector = Vector3(6, -4.2, 52.3);
        normalized = vector.normalize();
        EXPECT_NEAR(normalized.x, 0.1136, abs_error);
        EXPECT_NEAR(normalized.y, -0.0795, abs_error);
        EXPECT_NEAR(normalized.z, 0.9903, abs_error);

        vector = Vector3(2, 3, 4);
        normalized = vector.normalize();
        EXPECT_NEAR(normalized.x, 0.3714, abs_error);
        EXPECT_NEAR(normalized.y, 0.5570, abs_error);
        EXPECT_NEAR(normalized.z, 0.7428, abs_error);
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
        EXPECT_NEAR(result.x, 10, abs_error);
        EXPECT_NEAR(result.y, -5.7, abs_error);
        EXPECT_NEAR(result.z, 48.1, abs_error);

        vector = Vector3(2, -3, -4);
        result -= vector;
        EXPECT_NEAR(result.x, 8, 0.1);
        EXPECT_NEAR(result.y, -2.7, abs_error);
        EXPECT_NEAR(result.z, 52.1, abs_error);

        result = vector - 3;
        EXPECT_EQ(result.x, -1);
        EXPECT_EQ(result.y, -6);
        EXPECT_EQ(result.z, -7);

        result -= 0.1;
        EXPECT_EQ(result.x, -1.1);
        EXPECT_EQ(result.y, -6.1);
        EXPECT_EQ(result.z, -7.1);
    }

    TEST(MathTest, OperatorMultiply) {
        Vector3 vector = Vector3();
        Vector3 vector1 = Vector3();
        Vector3 result = vector * vector1;
        EXPECT_EQ(result.x, 0);
        EXPECT_EQ(result.y, 0);
        EXPECT_EQ(result.z, 0);

        result *= vector1;
        EXPECT_EQ(result.x, 0);
        EXPECT_EQ(result.y, 0);
        EXPECT_EQ(result.z, 0);

        vector = Vector3(6, -4.2, 13.32);
        result = vector * 2.2;
        EXPECT_NEAR(result.x, 13.2, abs_error);
        EXPECT_NEAR(result.y, -9.24, abs_error);
        EXPECT_NEAR(result.z, 29.304, abs_error);

        result *= -6.2;
        EXPECT_NEAR(result.x, -81.84, abs_error);
        EXPECT_NEAR(result.y, 57.288, abs_error);
        EXPECT_NEAR(result.z, -181.6848, abs_error);

        vector = Vector3(6, -4.2, 52.3);
        vector1 = Vector3(-4, 1.5, 4.2);
        result = vector * vector1;
        EXPECT_NEAR(result.x, -24, abs_error);
        EXPECT_NEAR(result.y, -6.3, abs_error);
        EXPECT_NEAR(result.z, 219.66, abs_error);

        vector = Vector3(2, -3, -4);
        result *= vector;
        EXPECT_NEAR(result.x, -48, abs_error);
        EXPECT_NEAR(result.y, 18.9, abs_error);
        EXPECT_NEAR(result.z, -878.64, abs_error);

        result = vector * 3.19;
        EXPECT_EQ(result.x, 6.38);
        EXPECT_EQ(result.y, -9.57);
        EXPECT_EQ(result.z, -12.76);

        result *= 1.1;
        EXPECT_NEAR(result.x, 7.018, abs_error);
        EXPECT_NEAR(result.y, -10.527, abs_error);
        EXPECT_NEAR(result.z, -14.036, abs_error);
    }

    TEST(MathTest, OperatorDivide) {
        Vector3 vector = Vector3();
        Vector3 vector1 = Vector3(0.1, 0.5, 5.5);
        Vector3 result = vector / vector1;
        EXPECT_EQ(result.x, 0);
        EXPECT_EQ(result.y, 0);
        EXPECT_EQ(result.z, 0);

        result /= vector1;
        EXPECT_EQ(result.x, 0);
        EXPECT_EQ(result.y, 0);
        EXPECT_EQ(result.z, 0);

        vector = Vector3(6, -4.2, 13.32);
        result = vector / 2.2;
        EXPECT_NEAR(result.x, 2.7272, abs_error);
        EXPECT_NEAR(result.y, -1.9090, abs_error);
        EXPECT_NEAR(result.z, 6.0545, abs_error);

        result /= -6.2;
        EXPECT_NEAR(result.x, -0.4398, abs_error);
        EXPECT_NEAR(result.y, 0.3079, abs_error);
        EXPECT_NEAR(result.z, -0.9765, abs_error);

        vector = Vector3(6, -4.2, 52.3);
        vector1 = Vector3(-4, 1.5, 4.2);
        result = vector / vector1;
        EXPECT_NEAR(result.x, -1.5, abs_error);
        EXPECT_NEAR(result.y, -2.8, abs_error);
        EXPECT_NEAR(result.z, 12.4524, abs_error);

        vector = Vector3(2, -3, -4);
        result /= vector;
        EXPECT_NEAR(result.x, -0.75, abs_error);
        EXPECT_NEAR(result.y, 0.9333, abs_error);
        EXPECT_NEAR(result.z, -3.1131, abs_error);

        result = vector / 3.19;
        EXPECT_NEAR(result.x, 0.6269, abs_error);
        EXPECT_NEAR(result.y, -0.9404, abs_error);
        EXPECT_NEAR(result.z, -1.2539, abs_error);

        result /= 1.1;
        EXPECT_NEAR(result.x, 0.5699, abs_error);
        EXPECT_NEAR(result.y, -0.8549, abs_error);
        EXPECT_NEAR(result.z, -1.1399, abs_error);
    }
}