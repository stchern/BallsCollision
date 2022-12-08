#include "DrawingUtils.h"
#include <QDebug>

void DrawingUtils::draw_ball(sf::RenderWindow& window, const Ball& ball)
{
    sf::CircleShape gball;
    gball.setRadius(ball.r);
    gball.setPosition(ball.p.x, ball.p.y);
    window.draw(gball);
}

void DrawingUtils::move_ball(Ball& ball, float deltaTime)
{
//    qDebug()<< deltaTime;
    const float epsilon = 1e-10;
    float dx = ball.velocity().x * deltaTime;
    float dy = ball.velocity().y * deltaTime;

    // умножение и деление добавлено для визуально правильной отрисовки

//    if ( ball.p.x + 2.0f *  ball.r + dx  >= WINDOW_X ) {
//        ball.speedX = -ball.speedX;
//        dx = -ball.p.x + WINDOW_X - 2.0f * ball.r - 1;
//    }

//    if ( ball.p.y + 2.0f * ball.r + dy >= WINDOW_Y ) {
//        ball.speedY = -ball.speedY;
//        dy = -ball.p.y + WINDOW_Y - 2.0f * ball.r - 1;
//    }

//    if ( ball.p.x - ball.r / 4.0f + dx < 0 ) {
//        ball.speedX = -ball.speedX;
//        dx = -(ball.p.x - ball.r / 4.0f);
//    }

//    if ( ball.p.y - ball.r / 4.0f + dy < 0 ) {
//        ball.speedY = -ball.speedY;
//        dy = -(ball.p.y - ball.r / 4.0f );
//    }


    if ( (ball.p.x + ball.r + dx + 1.0f - WINDOW_X) > epsilon ) {
        ball.speedX *= -1.0f;
        dx = -ball.p.x + WINDOW_X - ball.r - 1;
    }

    if ( (ball.p.y + ball.r + dy + 1.0f - WINDOW_Y) > epsilon) {
        ball.speedY *= -1.0f;
        dy = -ball.p.y + WINDOW_Y - ball.r - 1;
    }

    if ( ball.p.x - ball.r + dx < epsilon ) {
        ball.speedX *= -1.0f;
        dx = -(ball.p.x - ball.r);
    }

    if ( ball.p.y - ball.r + dy < epsilon ) {
        ball.speedY *= -1.0f;
        dy = -(ball.p.y - ball.r);
    }

    ball.p.x += dx;
    ball.p.y += dy;

}

void DrawingUtils::draw_fps(sf::RenderWindow& window, float fps)
{
    char c[32];
    snprintf(c, 32, "FPS: %f", fps);
    std::string string(c);
    sf::String str(c);
    window.setTitle(str);
}

std::vector<sf::Vector2f> DrawingUtils::partitioning(size_t splitFrequency, size_t offset)
{
    Q_ASSERT(splitFrequency > 0 && offset >= 0 && offset < qMin(WINDOW_X, WINDOW_Y));
    std::vector<sf::Vector2f> endPositions;
    // создание разбиения окна, в зависимости от частоты разбиения (splitFrequency)
    // при заданной splitFrequency окно разбивается на splitFrequency*splitFrequency областей
    // каждая область задается только нижней границей, т.к шары отсортированы слева направо и сверху вниз, и необходимость в верхней границе отпадает
    for (size_t y_part = 0; y_part < splitFrequency; ++y_part)
        for (size_t x_part = 0; x_part < splitFrequency; ++x_part) {
            sf::Vector2f firstSectionEnd(WINDOW_X * (x_part + 1) / splitFrequency - 1 - offset, WINDOW_Y * (y_part + 1) / splitFrequency - 1 - offset);
            endPositions.push_back(firstSectionEnd);
        }

    return endPositions;
}

