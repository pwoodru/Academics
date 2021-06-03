// Server side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT	 3600 
#define MAXLINE 1024 


int main() { 
	int sockfd; 
	char buffer[MAXLINE]; 
	char hello[100] = "Hello from server"; 
	struct sockaddr_in servaddr, cliaddr; 
	char    from_ip[1024] = "";
	// Creating socket file descriptor 
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	
	// Filling server information 
	servaddr.sin_family = AF_INET; // IPv4 
	servaddr.sin_addr.s_addr =  INADDR_ANY; //inet_addr("127.0.0.1");
 	servaddr.sin_port = htons(PORT); 
	
	// Bind the socket with the server address 
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, 
			sizeof(servaddr)) < 0 ) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	int addrlen= sizeof(struct sockaddr);
	int n=0; 
	n = recvfrom(sockfd, (char *)buffer, MAXLINE, 0, ( struct sockaddr *) &cliaddr, &addrlen); 
	buffer[n] = '\0'; 
	printf("Received from client: %s, n:%d, addrlen:%d\n", buffer, n, addrlen);
	
	//inet_ntop(AF_INET, &cliaddr.sin_addr, from_ip, sizeof(from_ip));
	//printf("Received %d bytes from %s@%d : %s\n", n, from_ip, ntohs(cliaddr.sin_port), buffer);

	struct sockaddr_in *addr_in = (struct sockaddr_in *)&cliaddr;
	char *cliip = inet_ntoa(addr_in->sin_addr);
	int cliport = ntohs(addr_in->sin_port);
	printf("IP address: %s, port: %d\n", cliip, cliport);
 
	sendto(sockfd, (const char *)hello, strlen(hello), 
		MSG_CONFIRM, (const struct sockaddr *) &cliaddr, 
			addrlen); 
	printf("Hello message sent to client.\n"); 
	
	return 0; 
} 


