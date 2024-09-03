/**
 * @file client.cpp
 * @author Wagdy (ahmedwagdymohy@gmail.com)
 * @brief  Client side code for the project
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
#include <string.h>                                      /* C-style string manipulation          */
#include <sys/socket.h>                                  /* For creating and managing sockets    */
#include <arpa/inet.h>                                   /* For sockaddr_in and inet_addr        */
#include <unistd.h>                                      /* For read(), write(), and close()     */

using namespace std;

/************************************************************************************************************************************************/
/********************************************************** END OF INCLUDES ****************************************************************************/
/************************************************************************************************************************************************/














/************************************************************************************************************************************************/
/********************************************************** DEFINES ****************************************************************************/
/************************************************************************************************************************************************/

#define PORT        8080                                /* Port number the client will connect to */

/************************************************************************************************************************************************/
/********************************************************** END of DEFINES ****************************************************************************/
/************************************************************************************************************************************************/

int main(void)
{
    int client_fileD;                        /* File descriptor for the client's socket */
    struct sockaddr_in serv_addr;            /* Structure to hold server address information */
    char buffer[1024] = {0};                 /* Buffer to store incoming messages */
    string message;                          /* Message to be sent to the server */











    /**
     * @brief socket(): This function creates an endpoint for communication. It takes three arguments:
     *  -> AF_INET: Address family (IPv4).
     *  -> SOCK_STREAM: Socket type (TCP for reliable communication).
     *  -> 0: Default protocol (TCP in this case).
     *  -> If the socket creation fails, it returns -1, and the program will output an error and exit.
     *
     */
    if ((client_fileD = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }









    /**
     * @brief
     *  -> memset(): Clears the serv_addr structure by setting all bytes to 0.
     *  -> sin_family: Specifies the address family (IPv4 in this case).
     *  -> sin_port: Converts the port number to network byte order using htons().
     *  -> inet_pton(): Converts the IP address from text to binary form.
     *      - AF_INET: Address family (IPv4).
     *      - "127.0.0.1": Loopback IP address (localhost).
     *      - &serv_addr.sin_addr: Pointer to the server address structure's sin_addr field.
     *  -> If inet_pton fails, it returns -1, and the program will output an error and exit.
     *
     */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) 
    {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return -1;
    }











    /**
     * @brief connect(): This function attempts to establish a connection to the server specified by serv_addr.
     *  -> client_fileD: The socket file descriptor.
     *  -> (struct sockaddr *)&serv_addr: Pointer to the server address structure.
     *  -> sizeof(serv_addr): Size of the server address structure.
     *  -> If the connection fails, it returns -1, and the program will output an error and exit.
     *
     */
    if (connect(client_fileD, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        std::cerr << "Connection Failed" << std::endl;
        return -1;
    }

    std::cout << "Connected to the server successfully!\n";









    /**
     * @brief
     * The client enters a loop where it can send messages to the server and receive responses.
     *  -> The loop continues until the client types "exit".
     *  -> Each iteration:
     *      - Prompts the user to enter a message.
     *      - Sends the message to the server.
     *      - Waits for and reads the server's response.
     *      - Displays the server's response.
     *      - If either the client or server sends "exit", the loop breaks and the connection closes.
     *
     */
    while (1)
    {
        /* Clearing the buffer content and setting it with 0 */
        memset(buffer, 0, sizeof(buffer));

        /* Prompting user for input */
        std::cout << "Client: ";
        getline(cin, message);

        /* Sending the message to the server */
        send(client_fileD, message.c_str(), message.length(), 0);

        /* Checking if the client wants to exit */
        if (message == "exit")
        {
            std::cout << "Disconnected from server." << std::endl;
            break;
        }

        /* Reading the server's response */
        int valread = read(client_fileD, buffer, 1024);

        /* Checking if the server has closed the connection */
        if (valread == 0)
        {
            std::cout << "Server disconnected." << std::endl;
            break;
        }

        std::cout << "Server: " << buffer << std::endl;

        /* Checking if the server wants to exit */
        if (strcmp(buffer, "exit") == 0)
        {
            std::cout << "Server has terminated the connection." << std::endl;
            break;
        }
    }









    /**
     * @brief
     * Closing the socket after communication is done.
     */
    close(client_fileD);

    return 0;
}
