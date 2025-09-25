#include <iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

#include "ClientAgent.h"

#define USB_DEVICE "/dev/ttyUSB0"

int main()
{
    int fd = open(USB_DEVICE, O_RDONLY);
    ClientAgent cliAgent = ClientAgent();
    if (fd < 0)
    {
        perror("open USB device");
        return 1;
    }

    std::cout << "RTOSense started, reading from " << USB_DEVICE << std::endl;
    std::cout.flush();

    std::string line;
    char c;

    while (true)
    {
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(fd, &readfds);

        int ret = select(fd + 1, &readfds, nullptr, nullptr, nullptr);
        if (ret > 0 && FD_ISSET(fd, &readfds))
        {
            ssize_t n = read(fd, &c, 1);
            if (n > 0)
            {
                if (c == '\n')
                {
                    std::cout << "Daemon sent: " << line << std::endl;
                    std::cout.flush();
                    
                    if (cliAgent.sendToClient(line.c_str()))
                    {
                        std::cerr << "Failed to send to client";
                    }

                    line.clear();
                }
                else
                {
                    line += c;
                }
            }
        }
        else if (ret < 0)
        {
            perror("select");
            break;
        }
    }
    close(fd);
    return 0;
}