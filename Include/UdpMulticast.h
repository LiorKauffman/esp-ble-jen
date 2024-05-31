// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

// int main() {
//     int sock;
//     struct sockaddr_in sa;
//     struct ip_mreq mreq;
//     char *message, serverMessage[20];

//     // Create a UDP socket
//     if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
//         printf("Could not create socket");
//     }
//     printf("Socket created \n");

//     // Prepare the sockaddr_in structure
//     sa.sin_family = AF_INET;
//     sa.sin_port = htons(1234);
//     sa.sin_addr.s_addr = inet_addr("239.255.255.250");

//     // Join multicast group
//     mreq.imr_multiaddr.s_addr = inet_addr("239.255.255.250");
//     mreq.imr_interface.s_addr = htonl(INADDR_ANY);
//     if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&mreq, sizeof(mreq)) < 0) {
//         printf("Error joining multicast group");
//     }

//     // Send a message to the multicast group
//     message = "Hello, World!";
//     if (sendto(sock, message, strlen(message), 0, (struct sockaddr*)&sa, sizeof(sa)) < 0) {
//         printf("Send failed");
//     }

//     // Close the socket
//     close(sock);

//     return 0;
// }
