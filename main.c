#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 1000

struct scan_args {
    char *ip;
    int port;
};

void* scan_port(void *arguments) {
    struct scan_args *args = arguments;
    int sockfd;
    struct sockaddr_in target;

    printf("Scanning port %d...\n", args->port); // Added to show progress

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) pthread_exit(NULL);

    target.sin_family = AF_INET;
    target.sin_port = htons(args->port);
    target.sin_addr.s_addr = inet_addr(args->ip);

    if (connect(sockfd, (struct sockaddr*)&target, sizeof(target)) == 0) {
        printf("Port %d is open\n", args->port);
    }

    close(sockfd);
    free(args);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <IP> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start = atoi(argv[2]);
    int end = atoi(argv[3]);

    pthread_t threads[MAX_THREADS];

    for (int port = start; port <= end; port++) {
        struct scan_args *args = malloc(sizeof(struct scan_args));
        args->ip = ip;
        args->port = port;

        pthread_create(&threads[port - start], NULL, scan_port, args);
    }

    for (int i = 0; i <= end - start; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
