#ifndef TEST_VECTOR_UTILS_H
#define TEST_VECTOR_UTILS_H

#include <QTest>

class TestVectorUtils: public QObject
{
    Q_OBJECT

public:
    explicit TestVectorUtils(QObject *parent = 0): QObject(parent){
    };

private slots:
    void testLengthVector201();
    void testLengthVector202();
    void testLengthVector203();

    void testDot01();
    void testDot02();
    void testDot03();

    void testIsAlmostEqual01();
    void testIsAlmostEqual02();
    void testIsAlmostEqual03();
};

#endif // TEST_VECTOR_UTILS_H

