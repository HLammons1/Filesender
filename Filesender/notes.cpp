/*
need these two for socket programming:
#include <winsock2.h>
#include <ws2tcpip.h>

#include <winsock2.h>

https://beej.us/guide/bgnet/html/split/intro.html#intro

{
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "WSAStartup failed.\n");
        exit(1);
    }

    if (LOBYTE(wsaData.wVersion) != 2 ||
        HIBYTE(wsaData.wVersion) != 2)
    {
        fprintf(stderr,"Versiion 2.2 of Winsock is not available.\n");
        WSACleanup();
        exit(2);
    }

}

next steps are to find a way to send the key and the iv, then have the server
have aes as well and use it to decode on the server.

after that maybe use libssh2 key exchange method


*/