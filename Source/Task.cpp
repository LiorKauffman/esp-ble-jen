#include "../Include/Task.h"

#include <iostream>
#include <thread>

Task::Task(std::string taskName) :
    _taskName(taskName)
{
    std::cout << "Hello from "<< _taskName << std::endl;
}

Task::~Task()
{
    std::cout << _taskName << " Terminate!" << std::endl;
}
