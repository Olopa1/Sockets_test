#define SERVER_IP "192.168.0.100"
#define WORKING_PORT 53000

struct message_t{
    char user_name[21];
    char message[1024];
};