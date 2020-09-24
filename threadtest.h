#ifndef THREADTEST_H
#define THREADTEST_H

#include <QObject>
#include <QThread>
class ThreadTest : public QThread
{
	//Q_OBJECT
	
public:
	int id;
	ThreadTest(QObject *parent);
	~ThreadTest();
	void run();
private:
	
};

#endif // THREADTEST_H
