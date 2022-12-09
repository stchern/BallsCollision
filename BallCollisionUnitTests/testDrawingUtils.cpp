#include "testDrawingUtils.h"
#include "BallCollision/DrawingUtils.h"


using namespace DrawingUtils;

void TestDrawingUtils::testMoveBall01()
{
    const sf::Vector2f p{30.0f, 30.0f};
    const float r{10.0f};
    const float speedX = 20.0f;
    const float speedY = 20.0f;

    Ball ball{p, r, speedX, speedY};
    const float deltaTime{15e-5};

    move_ball(ball, deltaTime);

    const float dx = ball.velocity().x * deltaTime;
    const float dy = ball.velocity().y * deltaTime;

    const sf::Vector2f newP{p.x + dx, p.y + dy};
    const Ball ansBall{newP, r, speedX, speedY};
    QVERIFY(ball == ansBall);
}

void TestDrawingUtils::testMoveBall02()
{
    const sf::Vector2f p{10.0f, 10.0f};
    const float r{10.0f};
    const float speedX = 20.0f;
    const float speedY = 20.0f;

    Ball ball{p, r, speedX, speedY};
    const float deltaTime{15e-5};

    move_ball(ball, deltaTime);

    const float dx = ball.velocity().x * deltaTime;
    const float dy = ball.velocity().y * deltaTime;

    const sf::Vector2f newP{p.x + dx, p.y + dy};
    const Ball ansBall{newP, r, speedX, speedY};
    QVERIFY(ball == ansBall);
}

void TestDrawingUtils::testMoveBall03()
{
    const sf::Vector2f p{10.0f, 10.0f};
    const float r{10.0f};
    const float speedX = -20.0f;
    const float speedY = -20.0f;

    Ball ball{p, r, speedX, speedY};
    const float deltaTime{15e-5};

    move_ball(ball, deltaTime);

    const sf::Vector2f newP{p.x, p.y};
    const Ball ansBall{p, r, speedX * -1, speedY * -1};
    QVERIFY(ball == ansBall);
}

void TestDrawingUtils::testMoveBall04()
{
    const float r{10.0f};
    const sf::Vector2f p{WINDOW_X - r - 1.0f, WINDOW_Y - r - 1.0f};
    const float speedX = 20.0f;
    const float speedY = 20.0f;

    Ball ball{p, r, speedX, speedY};
    const float deltaTime{15e-5};

    move_ball(ball, deltaTime);
    const Ball ansBall{p, r, speedX * -1, speedY * -1};
    QVERIFY(ball == ansBall);
}

void TestDrawingUtils::testPartitioning01()
{
    const size_t splitFrequency = 2;
    const std::vector<sf::Vector2f> resultPartitioning = partitioning(splitFrequency);
    const std::vector<sf::Vector2f> ansPartitioning{
        sf::Vector2f{511, 383},
        sf::Vector2f{1023, 383},
        sf::Vector2f{511, 767},
        sf::Vector2f{1023, 767}
    };

    QVERIFY(resultPartitioning == ansPartitioning);
}

void TestDrawingUtils::testPartitioning02()
{
    const size_t splitFrequency = 2;
    const int offset = 10;
    const std::vector<sf::Vector2f> resultPartitioning = partitioning(splitFrequency, offset);
    const std::vector<sf::Vector2f> ansPartitioning{
        sf::Vector2f{501, 373},
        sf::Vector2f{1013, 373},
        sf::Vector2f{501, 757},
        sf::Vector2f{1013, 757}
    };

    QVERIFY(resultPartitioning == ansPartitioning);
}

void TestDrawingUtils::testPartitioning03()
{
    const size_t splitFrequency = 3;
    const std::vector<sf::Vector2f> resultPartitioning = partitioning(splitFrequency);
    const std::vector<sf::Vector2f> ansPartitioning{
        sf::Vector2f{340, 255},
        sf::Vector2f{681, 255},
        sf::Vector2f{1023, 255},
        sf::Vector2f{340, 511},
        sf::Vector2f{681, 511},
        sf::Vector2f{1023, 511},
        sf::Vector2f{340, 767},
        sf::Vector2f{681, 767},
        sf::Vector2f{1023, 767}
    };

    QVERIFY(resultPartitioning == ansPartitioning);
}

