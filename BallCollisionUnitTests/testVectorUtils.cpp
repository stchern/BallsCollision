#include "testVectorUtils.h"
#include "BallCollision/VectorUtils.h"

using namespace VectorUtils;
const float epsilon = 1e-10;

void TestVectorUtils::testLengthVector201()
{
    const sf::Vector2<float> vec{0.0f, 0.0f};
    const float length = lengthVector2(vec);
    const float ansLength = 0.0f;
    QVERIFY(length - ansLength < epsilon);
}

void TestVectorUtils::testLengthVector202()
{
    const sf::Vector2<float> vec{2.0f, 3.0f};
    const float length = lengthVector2(vec);
    const float ansLength = 5.0f;
    QVERIFY(length - ansLength < epsilon);
}

void TestVectorUtils::testLengthVector203()
{
    const sf::Vector2<float> vec{-20.0f, -30.0f};
    const float length = lengthVector2(vec);
    const float ansLength = 50.0f;
    QVERIFY(length - ansLength < epsilon);
}

void TestVectorUtils::testDot01()
{
    const sf::Vector2<float> vecLhs{0.0f, 0.0f};
    const sf::Vector2<float> vecRhs{5.0f, 5.0f};
    const float scalar = dot(vecLhs, vecRhs);
    const float ansScalar = 0.0f;
    QVERIFY(scalar - ansScalar < epsilon);
}

void TestVectorUtils::testDot02()
{
    const sf::Vector2<float> vecLhs{1.0f, 0.0f};
    const sf::Vector2<float> vecRhs{5.0f, 5.0f};
    const float scalar = dot(vecLhs, vecRhs);
    const float ansScalar = 5.0f;
    QVERIFY(scalar - ansScalar < epsilon);
}

void TestVectorUtils::testDot03()
{
    const sf::Vector2<float> vecLhs{1.0f, 1.0f};
    const sf::Vector2<float> vecRhs{-5.0f, 5.0f};
    const float scalar = dot(vecLhs, vecRhs);
    const float ansScalar = 0.0f;
    QVERIFY(scalar - ansScalar < epsilon);
}


void TestVectorUtils::testIsAlmostEqual01()
{
    const sf::Vector2<float> vecLhs{1.0f, 1.0f};
    const sf::Vector2<float> vecRhs{-5.0f, 5.0f};

    QVERIFY(!isAlmostEqual(vecLhs, vecRhs));
}

void TestVectorUtils::testIsAlmostEqual02()
{
    const sf::Vector2<float> vecLhs{1.0f, 1.0f};
    const sf::Vector2<float> vecRhs{1.0f, 1.0f};

    QVERIFY(isAlmostEqual(vecLhs, vecRhs));
}

void TestVectorUtils::testIsAlmostEqual03()
{
    const sf::Vector2<float> vecLhs{1.0f, 1.0f};
    const sf::Vector2<float> vecRhs{1.0f, 1.0f - 1e-10};

    QVERIFY(isAlmostEqual(vecLhs, vecRhs));
}
