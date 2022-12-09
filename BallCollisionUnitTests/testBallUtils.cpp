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
    const std::vector<sf::Vector2f> partitioning{
        sf::Vector2f{501, 373},
        sf::Vector2f{1013, 373},
        sf::Vector2f{501, 757},
        sf::Vector2f{1013, 757}
    };

    const float speedX = 0.0f;
    const float speedY = 20.0f;
    Ball ballF{sf::Vector2f{30.0f, 30.0f}, 1.0f, speedX, speedY};
    Ball ballS{sf::Vector2f{30.0f, 32.0f}, 1.0f, speedX, (-1) * speedY};
    Ball ballT{sf::Vector2f{50.0f, 50.0f}, 3.0f, speedX, speedY};

    std::vector<Ball> balls{ballF, ballS, ballT};
    resolveCollisionForPatrition(partitioning, balls);

    const Ball ansBallF{sf::Vector2f{30.0f, 30.0f}, 1.0f, speedX, (-1) * speedY};
    const Ball ansBallS{sf::Vector2f{30.0f, 32.0f}, 1.0f,  speedX, speedY};
    const Ball ansBallT{sf::Vector2f{50.0f, 50.0f}, 3.0f, speedX, speedY};

    QVERIFY(balls[0] == ansBallF);
    QVERIFY(balls[1] == ansBallS);
    QVERIFY(balls[2] == ansBallT);
}

void TestBallUtils::testResolveCollisionForPatrition02()
{
    //partitioning includes only small part of the window; balls should not change after resolving Collision ForePart
    const std::vector<sf::Vector2f> partitioning{
        sf::Vector2f{10, 10}
    };

    const float speedX = 0.0f;
    const float speedY = 20.0f;
    Ball ballF{sf::Vector2f{30.0f, 30.0f}, 1.0f, speedX, speedY};
    Ball ballS{sf::Vector2f{30.0f, 32.0f}, 1.0f, speedX, (-1) * speedY};
    Ball ballT{sf::Vector2f{50.0f, 50.0f}, 3.0f, speedX, speedY};

    std::vector<Ball> balls{ballF, ballS, ballT};
    resolveCollisionForPatrition(partitioning, balls);

    QVERIFY(balls[0] == ballF);
    QVERIFY(balls[1] == ballS);
    QVERIFY(balls[2] == ballT);
}

void TestBallUtils::testResolveCollisionForPatrition03()
{
    //partitioning includes only small part of the window;
    // but balls are in this part
    const std::vector<sf::Vector2f> partitioning{
        sf::Vector2f{60, 60}
    };

    const float speedX = 0.0f;
    const float speedY = 20.0f;
    Ball ballF{sf::Vector2f{30.0f, 30.0f}, 1.0f, speedX, speedY};
    Ball ballS{sf::Vector2f{30.0f, 32.0f}, 1.0f, speedX, (-1) * speedY};
    Ball ballT{sf::Vector2f{50.0f, 50.0f}, 3.0f, speedX, speedY};

    std::vector<Ball> balls{ballF, ballS, ballT};
    resolveCollisionForPatrition(partitioning, balls);
    const Ball ansBallF{sf::Vector2f{30.0f, 30.0f}, 1.0f, speedX, (-1) * speedY};
    const Ball ansBallS{sf::Vector2f{30.0f, 32.0f}, 1.0f,  speedX, speedY};
    const Ball ansBallT{sf::Vector2f{50.0f, 50.0f}, 3.0f, speedX, speedY};

    QVERIFY(balls[0] == ansBallF);
    QVERIFY(balls[1] == ansBallS);
    QVERIFY(balls[2] == ansBallT);
}

void TestBallUtils::testResolveCollisionForPatrition04()
{
    //partitioning includes only small part of the window;
    // some balls are in this part, some balls are not
    const std::vector<sf::Vector2f> partitioning{
        sf::Vector2f{50, 50}
    };

    const float speedX = 0.0f;
    const float speedY = 20.0f;
    Ball ball1{sf::Vector2f{30.0f, 30.0f}, 1.0f, speedX, speedY};
    Ball ball2{sf::Vector2f{30.0f, 32.0f}, 1.0f, speedX, (-1) * speedY};
    Ball ball3{sf::Vector2f{60.0f, 60.0f}, 3.0f, speedX, speedY};
    Ball ball4{sf::Vector2f{60.0f, 62.0f}, 3.0f, speedX, (-1) * speedY};

    std::vector<Ball> balls{ball1, ball2, ball3, ball4};
    resolveCollisionForPatrition(partitioning, balls);
    const Ball ansBall1{sf::Vector2f{30.0f, 30.0f}, 1.0f, speedX, (-1) * speedY};
    const Ball ansBall2{sf::Vector2f{30.0f, 32.0f}, 1.0f,  speedX, speedY};

    QVERIFY(balls[0] == ansBall1);
    QVERIFY(balls[1] == ansBall2);
    QVERIFY(balls[2] == ball3);
    QVERIFY(balls[3] == ball4);
}
