核心代码：
```
// signal and slot
connect(&this->FutureWatcher, SIGNAL(finished()), this, SLOT(slot_finished()));
connect(&this->FutureWatcher, SIGNAL(finished()), this->ProgressDialog, SLOT(cancel()));
// QFutureWatcher and QtConcurrent::run()
QFuture<void> future = QtConcurrent::run(&this->MyObject, &MyClass::LongFunction);
this->FutureWatcher.setFuture(future);
// ProgressDialog
this->ProgressDialog->setMinimum(0);
this->ProgressDialog->setMaximum(0);
this->ProgressDialog->setWindowModality(Qt::WindowModal);
this->ProgressDialog->exec();
```

将progressBar更换为ProgressDialog
bug: ProgressDialog取消事件没有定义信号，导致即使窗口取消线程也不会中断。
Qt Version: 5.14.2
[FutureWatcher QProgressDialog Example(https://wiki.qt.io/Progress_Bar#QProgressDialog_Example)