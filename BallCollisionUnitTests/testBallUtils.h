#ifndef BALL_UTILS_TEST_H
#define BALL_UTILS_TEST_H

#include <QTest>

class TestBallUtils: public QObject{

    Q_OBJECT
public:

    explicit TestBallUtils(QObject *parent = 0): QObject(parent){
    };


private slots:

    void testResolveCollision01();
    void testResolveCollision02();
    void testResolveCollision03();
    void testResolveCollision04();

    void testResolveCollisionForPatrition01();
    void testResolveCollisionForPatrition02();
    void testResolveCollisionForPatrition03();
    void testResolveCollisionForPatrition04();
};

#endif
