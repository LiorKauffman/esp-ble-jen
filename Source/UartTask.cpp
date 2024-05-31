#include "../Include/UartTask.h"
#include <fcntl.h>
#include <termios.h>
#include <cstring>
#include <poll.h>
#include <unistd.h>

UartTask::UartTask(WifiTask& wifiTask) :
    Task(_TASK_NAME),
    _wifiTask(wifiTask)
{
}

void UartTask::_Run()
{
    auto isFirstTime = true;

        
    int fd = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY);

    struct termios tio;
    memset(&tio, 0, sizeof(tio));
    tio.c_iflag = 0;
    tio.c_oflag = 0;
    tio.c_cflag = CS8 | CREAD | CLOCAL;
    tio.c_cc[VMIN] = 1;
    tio.c_cc[VTIME] = 0;

    printf("Hey\n");

    cfsetospeed(&tio, B115200);
    cfsetispeed(&tio, B115200);

    tcsetattr(fd, TCSANOW, &tio);

    // Send data
    const char* msg = "Hello, World!\n";
    write(fd, msg, strlen(msg));

    struct pollfd fds;
    fds.fd = fd;
    fds.events = POLLIN;

    // Receive data
    char buf[256];

    while (true)
    {
        /* code */    
        poll(&fds, 1, -1);

        ssize_t numRead = read(fd, buf, sizeof(buf) - 1);

        if (numRead >= 0)
         {
            buf[numRead] = '\0';
            printf("Received: %s\n", buf);

            if (_IsBarkerFound(buf))
            {
                printf("Barker Found!\n");

                write(fd, &buf[strlen(_BARKER)], strlen(&buf[strlen(_BARKER)]));
                _wifiTask.SendPacket(buf);

            }
        }

        else
        {
            break;
        }
    }

    close(fd);
}

bool UartTask::_IsBarkerFound(const char* buffer)
{
    return strncmp(buffer, _BARKER, strlen(_BARKER)) == 0;
}