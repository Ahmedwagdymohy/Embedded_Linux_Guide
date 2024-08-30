# Project Description:


## Overview
This project is designed to demonstrate basic networking concepts in C++. It includes both a server and a client, each with specific functionalities and requirements. The project emphasizes the initialization, connection handling, and state management of both the server and client components.

## Server Requirements

### 1. Server Initialization
- **Description**: The server must initialize and start listening on a specified port.
- **Functionality**: Once started, the server should be able to accept incoming connections.

### 2. Port Configuration
- **Description**: The server should allow configuration of the port number on which it listens.
- **Functionality**: The port number should be configurable before the server starts listening.

### 3. Connection Handling
- **Description**: The server should be ready to accept client connections as soon as it starts listening.
- **Functionality**: The server must maintain a listening state until it is explicitly stopped or encounters an error.

## Client Requirements

### 1. Client Initialization
- **Description**: The client must start and initiate a connection request to a server.
- **Functionality**: The client should be able to connect to a server identified by a specific IP address and port number.

### 2. Connection Request
- **Description**: The client should establish a connection with the server if the server is available.
- **Functionality**: The client must maintain the connection as long as the server is active and handle disconnections gracefully.

## Test Cases

### Server Test Cases

#### 1. Server Initialization Test
- **Objective**: Verify that the server starts and listens on the specified port.
- **Steps**:
  1. Configure the server with a specific port.
  2. Start the server.
  3. Verify the server is listening on the specified port using tools like `netstat` or `ss`.
- **Expected Result**: The server should be listed as listening on the configured port.

#### 2. Port Configuration Test
- **Objective**: Ensure the server listens on different specified ports.
- **Steps**:
  1. Start the server with port A.
  2. Verify the server is listening on port A.
  3. Stop the server and restart it with port B.
  4. Verify the server is listening on port B.
- **Expected Result**: The server should successfully listen on both port A and port B as specified.

#### 3. Connection Acceptance Test
- **Objective**: Confirm that the server accepts incoming connections.
- **Steps**:
  1. Start the server.
  2. Use a client to attempt a connection to the server.
  3. Check server logs or use a monitoring tool to verify the connection was accepted.
- **Expected Result**: The server should accept the incoming connection from the client.

### Client Test Cases

#### 1. Client Initialization Test
- **Objective**: Ensure the client starts correctly and attempts to connect to the server.
- **Steps**:
  1. Start the client with a valid server IP and port number.
  2. Verify that the client sends a connection request to the server.
- **Expected Result**: The client should successfully initiate a connection request to the server.

#### 2. Server Identification Test
- **Objective**: Verify that the client can connect to different servers based on IP and port.
- **Steps**:
  1. Start the client with server A's IP and port number.
  2. Verify connection to server A.
  3. Reconfigure the client to connect to server B with a different IP and port.
  4. Verify connection to server B.
- **Expected Result**: The client should successfully connect to both servers as configured.

#### 3. Connection Failure Handling Test
- **Objective**: Ensure the client handles cases where the server is unavailable or refuses the connection.
- **Steps**:
  1. Start the client with a server IP and port where no server is running.
  2. Observe the client's reaction to the failed connection attempt.
- **Expected Result**: The client should gracefully handle the failed connection attempt, possibly by retrying or showing an error message.
