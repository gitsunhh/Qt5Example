#include <QApplication>
#include <QDebug>

#include <QMutex>
#include <QMutexLocker>
#include <QFile>
#include <QTextStream>
 
//重定向qdebug输出到文件
void myMessageHandle(QtMsgType , const QMessageLogContext& , const QString& msg)
{
    static QMutex mut; //多线程打印时需要加锁
    QMutexLocker locker(&mut);
    QFile file("log.txt");
    if(file.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        QTextStream stream(&file);
        stream<<msg<<endl;
        file.close();
    }
}


#include "LogManager.h"
int main(int argc, char *argv[])
{
    //推荐方法：设置重定向的日志类
    LogManager::getInstance()->initManager();//初始化

    //方法2：设置重定向操作的函数
    //qInstallMessageHandler(myMessageHandle);

    //方法3：设置输出格式
    //qSetMessagePattern("%{time yyyy-MM-dd hh:mm:ss}--[%{type}]--%{function}:%{message}");

    QCoreApplication a(argc, argv);

    qDebug("This is a debug message");
    qInfo("This is a info message");
    qWarning("This is a warning message");
    qCritical("This is a critical message");   
    //qFatal("This is a fatal message");

    return a.exec();
}
