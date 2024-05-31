
#ifndef _TASK_MANAGER_H
#define _TASK_MANAGER_H

#include <thread>

#include "Task.h"

class TaskManager
{
public:
    TaskManager() = delete;
    TaskManager(TaskManager& other) = delete;
    TaskManager(TaskManager&& other) = delete;

    TaskManager& operator=(TaskManager& other) = delete;
    TaskManager& operator=(TaskManager&& other) = delete;

    static inline void Run(Task& task) { std::thread t( _RunTask, std::ref(task)); t.detach(); }

private:
    static inline void _RunTask(Task& task) { task._Run(); }
};

#endif