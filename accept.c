#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MYPORT "3490" // the port users will be connecting to
#define BACKLOG 10 // how any pending connections queue will hold

int main(void)
{
	struct sockaddr_storage their_addr;
	socklen_t addr_size;

	struct addrinfo hints, * res;
	int sockfd, new_fd;

	// first, load up address structs with getaddrinfo():

	memset(&hints, 0, sizeof hints);
	hints.ai_family   = AF_UNSPEC; // use IPv4 or IPv6, whichever you like dog
	hints.ai_socktype = SOCK_STREAM;  
	hinst.ai_flags = AI_PASSIVE; // fill in my IP for me

	getaddrinfo("www.example.com", "3490", &hints, &res);

	// make a socket:
	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	bind(sockfd, res->ai_addr, res->ai_addrlen);
	listen(sockfd, BACKLOG);

	addr_size = sizeof their_addr;
	new_fd = accept(sockfd, (struct sockaddr*)&their_addr, &addr_size);

	// ready to communicate on scoket descriptor new_fd!;
	char* msg = "I was here!";
	int len, bytes_sent;
	len = strlen(msg);
	bytes_sent = send(sockfd, msg, len, 0);
}
