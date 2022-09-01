# 基于qDebug的调试log（日志记录）
## 输出
.log文件输出+控制台输出  
## 类型
- qDebug()	调试消息
- qInfo()	信息消息
- qWarning()	警告消息和可恢复的错误
- qCritical()	关键错误和系统错误
- qFatal()	致命错误
## test result
![console](test-result/qDebug_console.png)

![logtext](test-result/qDebug_log.png)
## Reference
[Qt documentation - QDebug Class](https://doc.qt.io/qt-6/qdebug.html)

[QtMessageHandler](https://doc.qt.io/qt-5/qtglobal.html#qInstallMessageHandler)

[QT重定向QDEBUG，自定义一个简易的日志管理类](https://www.freesion.com/article/49341199626/)

[Qt - 消息重定向(输出日志)](https://blog.csdn.net/qq_39453936/article/details/120675366)
