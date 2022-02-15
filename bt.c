#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(){
    struct sockaddr_rc addr = { 0 };
    int s, status;
    char *dest =  "98:D3:31:F7:3B:D0"; //  HC05 = "98:D3:31:F7:3B:D0"

    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;
    str2ba( dest, &addr.rc_bdaddr );

    status = connect(s, (struct sockaddr *)&addr, sizeof(addr));
    if( status < 0 ) perror("uh oh");

    char motion[1];
    while(1){
        char buf[50];
        memset(buf, 0, 50);
        printf("\n\e[0;33myour command: \e[0;36m");
        scanf("%s\e[0;37m", motion);
        send(s, motion, 1, 0);
        sleep(1);
        int bytes_read = 0;
        while(buf[bytes_read-1] != ';'){
            bytes_read = recv(s, buf, sizeof(buf), 0);
            printf("\e[0;35m%s", buf);
        }
    }
    close(s);
    return 0;
}