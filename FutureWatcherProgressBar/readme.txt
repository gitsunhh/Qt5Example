核心代码：
```
// 信号连接
connect(&this->FutureWatcher, SIGNAL(finished()), this, SLOT(slot_finished()));
// .......
// 进度条
this->progressBar->show();
// QtConcurrent并发线程
QFuture<void> future = QtConcurrent::run(&this->MyObject, &MyClass::LongFunction);
// FutureWatcher线程观察
this->FutureWatcher.setFuture(future);
```

后端算法运行耗时比较久的时候，通常需要显示进度条，同时由于无法跟踪运行进度，唯一知道的就是开始和结束。
在这种情况下，通常采用多线程方法。
使用QFutureWatcher和QtConcurrent::run()，可能是最容易的一种方法。
进度条设置循环移动（在属性中将最小值和最大值都设为0）

Qt Version: 5.14.2
[FutureWatcher QProgressBar Example](https://wiki.qt.io/Progress_Bar#QProgressDialog_Example)