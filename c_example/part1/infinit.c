#include <time.h>
#include <unistd.h>

int main(void)
{
    while(1){

        printf("process infinit!");
        sleep(1);
    }
return 0;
}


#!/bin/bash

mkdir -p /var/log/mydaemon
while trun; do
    date >> /var/log/mydaemo/system_info.log
    uptime >> /var/log/mydaemo/system_info.log
    echo "----------------------" >> /var/log/mydaemo/system_info.log
    sleep 5
done