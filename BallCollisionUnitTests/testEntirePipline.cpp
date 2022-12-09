#include "testEntirePipline.h"
#include "BallCollision/BallUtils.h"
#include "BallCollision/DrawingUtils.h"

void TestEntirePipeline::testEntirePipeline01()
{
    const std::vector<sf::Vector2f> partitioning{
        sf::Vector2f{1023, 383},
    };

    const float speedX = 0.0f;
    const float speedY = 20.0f;

    Ball ball0{sf::Vector2f{0.0f, 30.0f}, 5.0f, speedX, speedY};
    Ball ball1{sf::Vector2f{30.0f, 30.0f}, 1.0f, speedX, speedY};
    Ball ball2{sf::Vector2f{30.0f, 32.0f}, 1.0f, speedX, (-1) * speedY};
    Ball ball3{sf::Vector2f{60.0f, 60.0f}, 3.0f, speedX, speedY};
    Ball ball4{sf::Vector2f{60.0f, 62.0f}, 3.0f, speedX, (-1) * speedY};
    Ball ball5{sf::Vector2f{1020.0f, 60.0f}, 5.0f, speedX, speedY};

    std::vector<Ball> balls{ball0, ball2, ball4, ball3, ball1, ball5};

    auto sortByPosition = [](const Ball& lhsBall, const Ball& rhsBall){
        if (lhsBall.p.x == rhsBall.p.x )
            return lhsBall.p.y < rhsBall.p.y;
        return lhsBall.p.x < rhsBall.p.x;
    };

    std::sort(balls.begin(), balls.end(), sortByPosition);
    BallUtils::resolveCollisionForPatrition(partitioning, balls);

    const float deltaTime{20.0f};
    for (auto& ball : balls)
        DrawingUtils::move_ball(ball, deltaTime);

    const Ball ansBall0{sf::Vector2f{5.0f, speedY * deltaTime + 30.0f}, 5.0f, (-1) * speedX, speedY};
    const Ball ansBall1{sf::Vector2f{30.0f, 1.0f}, 1.0f, speedX, speedY};
    const Ball ansBall2{sf::Vector2f{30.0f, speedY * deltaTime + 32.0f}, 1.0f, speedX, speedY};
    const Ball ansBall3{sf::Vector2f{60.0f, 3.0f}, 3.0f, speedX, speedY};
    const Ball ansBall4{sf::Vector2f{60.0f, speedY * deltaTime + 64.0f}, 3.0f, speedX, speedY};
    const Ball ansBall5{sf::Vector2f{1018.0f, speedY * deltaTime + 60.0f}, 5.0f, (-1) * speedX, speedY};

    QVERIFY(balls[0] == ansBall0);
    QVERIFY(balls[1] == ansBall1);
    QVERIFY(balls[2] == ansBall2);
    QVERIFY(balls[3] == ansBall3);
    QVERIFY(balls[4] == ansBall4);
    QVERIFY(balls[5] == ansBall5);
}

void TestEntirePipeline::testEntirePipeline02()
{
    const std::vector<sf::Vector2f> partitioning{
        sf::Vector2f{1023, 383},
    };

    const float speedX = 0.0f;
    const float speedY = 20.0f;

    Ball ball0{sf::Vector2f{5.0f, 430.0f}, 5.0f, (-1) * speedX, speedY};
    Ball ball1{sf::Vector2f{30.0f, 1.0f}, 1.0f, speedX, speedY};
    Ball ball2{sf::Vector2f{30.0f, 432.0f}, 1.0f, speedX, speedY};
    Ball ball3{sf::Vector2f{60.0f, 3.0f}, 3.0f, speedX, speedY};
    Ball ball4{sf::Vector2f{60.0f, 464.0f}, 3.0f, speedX, speedY};
    Ball ball5{sf::Vector2f{1018.0f, 460.0f}, 5.0f, (-1) * speedX, speedY};

    std::vector<Ball> balls{ball0, ball2, ball4, ball3, ball1, ball5};

    auto sortByPosition = [](const Ball& lhsBall, const Ball& rhsBall){
        if (lhsBall.p.x == rhsBall.p.x )
            return lhsBall.p.y < rhsBall.p.y;
        return lhsBall.p.x < rhsBall.p.x;
    };

    std::sort(balls.begin(), balls.end(), sortByPosition);
    BallUtils::resolveCollisionForPatrition(partitioning, balls);

    const float deltaTime{1.0f};
    for (auto& ball : balls)
        DrawingUtils::move_ball(ball, deltaTime);

    const Ball ansBall0{sf::Vector2f{5.0f, speedY * deltaTime + 430.0f}, 5.0f, speedX, speedY};
    const Ball ansBall1{sf::Vector2f{30.0f, speedY * deltaTime + 1.0f}, 1.0f, speedX, speedY};
    const Ball ansBall2{sf::Vector2f{30.0f, speedY * deltaTime + 432.0f}, 1.0f, speedX, speedY};
    const Ball ansBall3{sf::Vector2f{60.0f, speedY * deltaTime + 3.0f}, 3.0f, speedX, speedY};
    const Ball ansBall4{sf::Vector2f{60.0f, speedY * deltaTime + 464.0f}, 3.0f, speedX, speedY};
    const Ball ansBall5{sf::Vector2f{1018.0f, speedY * deltaTime + 460.0f}, 5.0f, (-1) * speedX, speedY};

    QVERIFY(balls[0] == ansBall0);
    QVERIFY(balls[1] == ansBall1);
    QVERIFY(balls[2] == ansBall2);
    QVERIFY(balls[3] == ansBall3);
    QVERIFY(balls[4] == ansBall4);
    QVERIFY(balls[5] == ansBall5);
}

void TestEntirePipeline::testEntirePipeline03()
{
    const std::vector<sf::Vector2f> partitioning{
        sf::Vector2f{1023, 383},
    };

    const float speedX = 10.0f;
    const float speedY = 20.0f;

   Ball ball0{sf::Vector2f{5.0f, 460.0f}, 5.0f, (-1) * speedX, speedY};
   Ball ball1{sf::Vector2f{30.0f, 21.0f}, 1.0f, speedX, speedY};
   Ball ball2{sf::Vector2f{30.0f, 452.0f}, 1.0f, speedX, speedY};
   Ball ball3{sf::Vector2f{60.0f, 23.0f}, 3.0f, speedX, speedY};
   Ball ball4{sf::Vector2f{60.0f, 484.0f}, 3.0f, speedX, speedY};
   Ball ball5{sf::Vector2f{1018.0f, 80.0f}, 5.0f, speedX, speedY};

    std::vector<Ball> balls{ball0, ball2, ball4, ball3, ball1, ball5};

    auto sortByPosition = [](const Ball& lhsBall, const Ball& rhsBall){
        if (lhsBall.p.x == rhsBall.p.x )
            return lhsBall.p.y < rhsBall.p.y;
        return lhsBall.p.x < rhsBall.p.x;
    };

    std::sort(balls.begin(), balls.end(), sortByPosition);
    BallUtils::resolveCollisionForPatrition(partitioning, balls);

    const float deltaTime{1.0f};
    for (auto& ball : balls)
        DrawingUtils::move_ball(ball, deltaTime);

    const Ball ansBall0{sf::Vector2f{5.0f, speedY * deltaTime + 460.0f}, 5.0f, speedX, speedY};
    const Ball ansBall1{sf::Vector2f{speedX * deltaTime +30.0f, speedY * deltaTime + 21.0f}, 1.0f, speedX, speedY};
    const Ball ansBall2{sf::Vector2f{speedX * deltaTime + 30.0f, speedY * deltaTime + 452.0f}, 1.0f, speedX, speedY};
    const Ball ansBall3{sf::Vector2f{speedX * deltaTime + 60.0f, speedY * deltaTime + 23.0f}, 3.0f, speedX, speedY};
    const Ball ansBall4{sf::Vector2f{speedX * deltaTime + 60.0f, speedY * deltaTime + 484.0f}, 3.0f, speedX, speedY};
    const Ball ansBall5{sf::Vector2f{1018.0f, speedY * deltaTime + 80.0f}, 5.0f, (-1) * speedX, speedY};

    QVERIFY(balls[0] == ansBall0);
    QVERIFY(balls[1] == ansBall1);
    QVERIFY(balls[2] == ansBall2);
    QVERIFY(balls[3] == ansBall3);
    QVERIFY(balls[4] == ansBall4);
    QVERIFY(balls[5] == ansBall5);
}
