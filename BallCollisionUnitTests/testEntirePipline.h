#ifndef TEST_ENTIRE_PIPELINE_H
#define TEST_ENTIRE_PIPELINE_H

#include <QTest>

class TestEntirePipeline: public QObject{

    Q_OBJECT
public:

    explicit TestEntirePipeline(QObject *parent = 0): QObject(parent){
    };


private slots:
    void testEntirePipeline01();
    void testEntirePipeline02();
    void testEntirePipeline03();
};

#endif
