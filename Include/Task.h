#ifndef _TASK_H
#define _TASK_H

#include <string>

class Task
{
    friend class TaskManager;
public:


protected:
    Task(std::string taskName);
    ~Task();

private:
    virtual void _Run() = 0;

    std::string _taskName;

};

#endif