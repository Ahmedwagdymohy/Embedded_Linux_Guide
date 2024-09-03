/**
 * @file server.cpp
 * @author Wagdy (ahmedwagdymohy@gmail.com)
 * @brief  Server side code for the project
 * @version 0.1
 * @date 2024-08-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */


















/************************************************************************************************************************************************/
/********************************************************** INCLUDES ****************************************************************************/
/************************************************************************************************************************************************/

#include <iostream>                                      /* input-output stream                  */
#include <string.h>                                        /* C-style string                       */
#include <sys/socket.h>                                  /* For Creating and managing sockets    */
#include <netinet/in.h>                                  /* For ports and Ip Addresses           */
#include <unistd.h>                                      /* For using the function read()        */
using namespace std;

/************************************************************************************************************************************************/
/********************************************************** END OF INCLUDES ****************************************************************************/
/************************************************************************************************************************************************/








/************************************************************************************************************************************************/
/********************************************************** DEFINES ****************************************************************************/
/************************************************************************************************************************************************/

#define PORT        8080                                /* Port number the server will listen to */

/************************************************************************************************************************************************/
/********************************************************** END of DEFINES ****************************************************************************/
/************************************************************************************************************************************************/

int main(void)
{

    int server_fileD;                        /* File descriptor for the server's socket.*/
    int new_socket;                          /* File descriptor for the client's connection after it is accepted */
    struct sockaddr_in address;
    int addrlen = sizeof(address);           /* Stores the length of the address structure */
    char buffer[1024] = {0};                 /*Buffer to store the comming messages */
    const char *hello = "Hello from Server"; /*Message to be sent to the Client*/









    /**
     * @brief socket(): This function creates an endpoint for communication. It takes three arguments:
     *  -> AF_INET: Address family (IPv4).
     *  -> SOCK_STREAM: Socket type (TCP for reliable communication).
     *  -> 0: Default protocol (TCP in this case).
     *  -> If the socket creation fails, it returns 0, and the program will output an error and exit
     *
     */








    if ((server_fileD = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        std::cerr << "Socket failed" << std::endl;
        exit(EXIT_FAILURE);
    }

    /**
     * @brief
     *  -> sin_family: Specifies the address family (IPv4 in this case).
     *  -> sin_addr.s_addr: This specifies the IP address. INADDR_ANY binds the socket to all available
     *  -> interfaces (i.e., allows the server to accept connections on any of the server's IP addresses).
     *  -> sin_port: Converts the port number to network byte order using htons().
     *
     *
     *
     */
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);










    /**
     * @brief
     * bind(): This function assigns the specified IP address and port to the socket. If it fails, the program
     * outputs an error message and exits
     *
     */
    if (bind(server_fileD, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        std::cerr << "Bind failed" << std::endl;
        exit(EXIT_FAILURE);
    }












    /**
     * @brief listen(): It tells the operating system that your server is ready to accept connections.
     *   The second parameter (3) specifies the maximum number of pending
     *   connections that can be queued.
     *
     */

    if (listen(server_fileD, 3) < 0)
    {
        std::cerr << "Listen Error" << std::endl;
        exit(EXIT_FAILURE);
    }

    cout << "Server is waiting for connections...\n";












    /**
     * @brief
     * Purpose: accept() takes the first connection from the queue (created by listen()), creates a new socket for that connection, and returns a file descriptor for the newly connected socket. This new socket is what you use to communicate with the client.
     *  -> How It Works:    When accept(server_fd, ...) is called, it blocks (waits) until a client connects. Once a client connects, accept() returns a new socket file descriptor (new_socket), which is used for that specific client.
     *  -> Why Not in a Loop:   accept() is typically called once for each client connection. Since your code is designed to handle only one connection at a time, it makes sense to place accept() outside the loop. After accepting a connection, the server enters a communication loop to interact with that specific client.
     *
     *
     */
    if ((new_socket = accept(server_fileD, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        std::cerr << "Accept failed" << std::endl;
        exit(EXIT_FAILURE);
    }









    /** The Code Won't continue if the function accept didn't pass , It's blocking function */
    std::cout << "Client connected!\n";













    while (1)
    {
        /* Clearing all the buffer content and setting it with 0  */
        memset(buffer, 0, sizeof(buffer));

        /* Reading from descriptor */
        int valread = read(new_socket, buffer, 1024);

        std::cout << "Client: " << buffer << std::endl;



        /* Checking if the client types exit ,it will exit the program */
        if (strcmp(buffer, "exit") == 0)
        {
            std::cout << "Client disconnected." << std::endl;
            break;
        }



        /* Preparing the text which will be sent to the client  */
        string reply;
        cout<<"server: " ;
        getline(cin,reply );

        /**Sending the reply text to the Client using send */
        send(new_socket, reply.c_str(), reply.length(), 0);


    }

    close(new_socket);
    close(server_fileD);

  return 0;
}