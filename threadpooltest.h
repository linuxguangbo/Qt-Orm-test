#ifndef THREADPOOLTEST_H
#define THREADPOOLTEST_H

#include <QObject>
#include <QRunnable>
class threadPoolTest : public QRunnable
{
	//Q_OBJECT

public:
	int id;
	threadPoolTest(int id);
	~threadPoolTest();
	void run();

private:
	
};

#endif // THREADPOOLTEST_H
