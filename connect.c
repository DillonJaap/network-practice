#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void)
{
	struct addrinfo hints, * res;
	int sockfd;

	// first, load up address structs with getaddrinfo():

	memset(&hints, 0, sizeof hints);
	hints.ai_family   = AF_UNSPEC;
	hints.ai-socktype = SOCK_STREAM;

	getaddrinfo("www.example.com", "3490", &hints, &res);

	// make a socket:
	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

	// connect!
	connect(sockfd, res->ai_addr, ress->ai_addrlen);
}
