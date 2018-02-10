#ifndef TEST_QRMF_SOCKETADAPTER_H
#define TEST_QRMF_SOCKETADAPTER_H

#include <QtTest/QtTest>
namespace RemoteFile
{

class TestSocketAdapter : public QObject
{
   Q_OBJECT
private slots:
   void test_acknowledge();
   void test_onReadyRead();
   void test_onReadyRead_partial_short_msg();
   void test_onReadyRead_partial_long_msg();
};

}
#endif // TEST_QRMF_SOCKETADAPTER_H
