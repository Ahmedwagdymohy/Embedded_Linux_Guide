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

#include <iostream>                                      /* input-output stream */
#include <string>                                        /* C-style string */
#include <sys/socket.h>                                  /* For Creating and managing sockets */
#include <netinet/in.h>                                  /* For ports and Ip Addresses */
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


















int server_fileD;                                       /* File descriptor for the server's socket.*/
int new_socket;                                         /* File descriptor for the client's connection after it is accepted */
struct sockaddr_in address;                             
int addrlen = sizeof(address);                          /* Stores the length of the address structure */
char buffer[1024] = {0};                                /*Buffer to store the comming messages */
const char* hello = "Hello from Server";                /*Message to be sent to the Client*/





/**
 * @brief socket(): This function creates an endpoint for communication. It takes three arguments:
*  -> AF_INET: Address family (IPv4).
*  -> SOCK_STREAM: Socket type (TCP for reliable communication).
*  -> 0: Default protocol (TCP in this case).
*  -> If the socket creation fails, it returns 0, and the program will output an error and exit
 * 
 */

if ((server_fileD = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    std::cerr << "Socket failed" << std::endl;
    exit(EXIT_FAILURE);
}



address.sin_family = AF_INET;
address.sin_addr. s_adde = INADDR_ANY;






