#ifndef _UART_TASK_H
#define _UART_TASK_H

#include "Task.h"
#include "WifiTask.h"

class UartTask : public Task
{
public:
    UartTask(WifiTask& wifiTask);

private:
    static constexpr auto _TASK_NAME = "Uart Task";
    static constexpr auto _BARKER    = "Lior: ";

    void _Run() override;

    bool _IsBarkerFound(const char* buffer);

    WifiTask& _wifiTask;
};

#endif // _UART_TASK_H