#include "testBallUtils.h"
#include "BallCollision/BallUtils.h"
#include "BallCollision/VectorUtils.h"

using namespace BallUtils;

void TestBallUtils::testResolveCollision01()
{
    const sf::Vector2f pLhs{30.0f, 30.0f};
    const sf::Vector2f pRhs{30.0f, 32.0f};
    const float r{1.0f};
    const float speedX = 0.0f;
    const float speedY = 20.0f;

    Ball ballLhs{pLhs, r, speedX, speedY};
    Ball ballRhs{pRhs, r, speedX, (-1) * speedY};

    const sf::Vector2f velocityLhs = ballLhs.velocity();
    const sf::Vector2f velocityRhs = ballRhs.velocity();

    resolveCollision(ballLhs, ballRhs);

    const sf::Vector2f ansLhsVelocity{0.0f, -20.0f};
    const sf::Vector2f ansRhsVelocity{0.0f, 20.0f};

    QVERIFY(VectorUtils::isAlmostEqual(ballLhs.velocity(), ansLhsVelocity));
    QVERIFY(VectorUtils::isAlmostEqual(ballRhs.velocity(), ansRhsVelocity));

    // the momentum before and after the collision is equal
    QVERIFY(VectorUtils::isAlmostEqual(ballLhs.square() * ballLhs.velocity() + ballRhs.square() * ballRhs.velocity(),
            ballLhs.square() * velocityLhs + ballRhs.square() * velocityRhs));
}

void TestBallUtils::testResolveCollision02()
{
    const sf::Vector2f pLhs{30.0f, 30.0f};
    const sf::Vector2f pRhs{33.0f, 30.0f};
    const float rLhs{1.0f};
    const float rRhs{2.0f};
    const float speedX = 20.0f;
    const float speedY = 0.0f;

    Ball ballLhs{pLhs, rLhs, speedX, speedY};
    Ball ballRhs{pRhs, rRhs, (-1) * speedX, speedY};

    const sf::Vector2f velocityLhs = ballLhs.velocity();
    const sf::Vector2f velocityRhs = ballRhs.velocity();

    resolveCollision(ballLhs, ballRhs);

    const sf::Vector2f ansLhsVelocity{-44.0f, 0.0f};
    const sf::Vector2f ansRhsVelocity{-4.0f, 0.0f};

    QVERIFY(VectorUtils::isAlmostEqual(ballLhs.velocity(), ansLhsVelocity));
    QVERIFY(VectorUtils::isAlmostEqual(ballRhs.velocity(), ansRhsVelocity));
    QVERIFY(VectorUtils::isAlmostEqual(ballLhs.square() * ballLhs.velocity() + ballRhs.square() * ballRhs.velocity(),
            ballLhs.square() * velocityLhs + ballRhs.square() * velocityRhs));
  }

void TestBallUtils::testResolveCollision03()
{
    const sf::Vector2f pLhs{30.0f, 30.0f};
    const sf::Vector2f pRhs{53.0f, 50.0f};
    const float rLhs{1.0f};
    const float rRhs{2.0f};
    const float speedX = 20.0f;
    const float speedY = 0.0f;

    Ball ballLhs{pLhs, rLhs, speedX, speedY};
    Ball ballRhs{pRhs, rRhs, (-1) * speedX, speedY};

    resolveCollision(ballLhs, ballRhs);

    const sf::Vector2f ansLhsVelocity{speedX, speedY};
    const sf::Vector2f ansRhsVelocity{(-1) * speedX, speedY};

    QVERIFY(VectorUtils::isAlmostEqual(ballLhs.velocity(), ansLhsVelocity));
    QVERIFY(VectorUtils::isAlmostEqual(ballRhs.velocity(), ansRhsVelocity));

}

void TestBallUtils::testResolveCollision04()
{
    const sf::Vector2f pLhs{32.0f, 30.0f};
    const sf::Vector2f pRhs{30.0f, 30.0f};
    const float rLhs{1.0f};
    const float rRhs{2.0f};
    const float speedX = 20.0f;
    const float speedY = 20.0f;

    Ball ballLhs{pLhs, rLhs, speedX, speedY};
    Ball ballRhs{pRhs, rRhs, (-1) * speedX, (-1) * speedY};

    const sf::Vector2f velocityLhs = ballLhs.velocity();
    const sf::Vector2f velocityRhs = ballRhs.velocity();

    resolveCollision(ballLhs, ballRhs);

    const float ansSpeedXLhs = -44.0f;
    const float ansSpeedXRhs = -4.0f;

    Ball ansBallLhs{pLhs + sf::Vector2f(0.5f, 0.0f), rLhs, ansSpeedXLhs, speedY};
    Ball ansBallRhs{pRhs - sf::Vector2f(0.5f, 0.0f), rRhs, ansSpeedXRhs, (-1) * speedY};

    QVERIFY(ballLhs == ansBallLhs);
    QVERIFY(ballRhs == ansBallRhs);
    QVERIFY(VectorUtils::isAlmostEqual(ballLhs.square() * ballLhs.velocity() + ballRhs.square() * ballRhs.velocity(),
            ballLhs.square() * velocityLhs + ballRhs.square() * velocityRhs));

}

void TestBallUtils::testResolveCollisionForPatrition01()
{

}

void TestBallUtils::testResolveCollisionForPatrition02()
{

}

void TestBallUtils::testResolveCollisionForPatrition03()
{

}

void TestBallUtils::testResolveCollisionForPatrition04()
{

}
