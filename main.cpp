#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <cstring>
#include "UartTask.h"
#include "TaskManager.h"
#include "WifiTask.h"

int main() 
{
    WifiTask wifiTask;

    UartTask uartTask(wifiTask);
    TaskManager::Run(uartTask);
    
    TaskManager::Run(wifiTask);

    printf("main\n");

    while(true);

    return 0;
}
