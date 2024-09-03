#!/bin/bash

# Bash Script to Analyze Network Traffic

# Log file path
log_file="logs/network_analysis.log"

# Input: Path to the Wireshark pcap file
read -p "Enter the path to the Wireshark pcap file: " pcap_file

# Redirect stdout and stderr to the log file for steps (but not analysis results)
exec > >(tee -a "$log_file") 2>&1

# Function to log a message with the current timestamp
log_message() {
    echo "$(date '+%Y-%m-%d %H:%M:%S') - $1" >> "$log_file"
}

# Function to extract information from the pcap file
analyze_traffic() {
    log_message "Step 1: Checking if the pcap file exists..."
    
    # Check if the pcap file exists
    if [ ! -f "$pcap_file" ]; then
        log_message "Error: Pcap file not found!"
        exit 1
    fi
    log_message "Pcap file found: $pcap_file"

    log_message "Step 2: Extracting total number of packets..."
    
    # Extract total packets
    total_packets=$(tshark -r "$pcap_file" | wc -l)
    if [ $? -ne 0 ]; then
        log_message "Error: Failed to extract total packets"
        exit 1
    fi
    log_message "Total Packets: $total_packets"

    log_message "Step 3: Extracting HTTP packets..."
    
    # Extract HTTP packets
    http_packets=$(tshark -r "$pcap_file" -Y "http" | wc -l)
    if [ $? -ne 0 ]; then
        log_message "Error: Failed to extract HTTP packets"
        exit 1
    fi
    log_message "HTTP Packets: $http_packets"

    log_message "Step 4: Extracting HTTPS/TLS packets..."
    
    # Extract HTTPS/TLS packets
    https_packets=$(tshark -r "$pcap_file" -Y "tls" | wc -l)
    if [ $? -ne 0 ]; then
        log_message "Error: Failed to extract HTTPS/TLS packets"
        exit 1
    fi
    log_message "HTTPS/TLS Packets: $https_packets"

    log_message "Step 5: Extracting top 5 source IP addresses..."
    
    # Extract top 5 source IP addresses
    top_source_ips=$(tshark -r "$pcap_file" -T fields -e ip.src | sort | uniq -c | sort -nr | head -5)
    if [ $? -ne 0 ]; then
        log_message "Error: Failed to extract top source IP addresses"
        exit 1
    fi
    log_message "Top 5 Source IP Addresses extracted"

    log_message "Step 6: Extracting top 5 destination IP addresses..."
    
    # Extract top 5 destination IP addresses
    top_dest_ips=$(tshark -r "$pcap_file" -T fields -e ip.dst | sort | uniq -c | sort -nr | head -5)
    if [ $? -ne 0 ]; then
        log_message "Error: Failed to extract top destination IP addresses"
        exit 1
    fi
    log_message "Top 5 Destination IP Addresses extracted"

    # Print analysis summary to the screen
    echo "----- Network Traffic Analysis Report -----"
    echo "1. Total Packets: $total_packets"
    echo "2. Protocols:"
    echo "   - HTTP: $http_packets packets"
    echo "   - HTTPS/TLS: $https_packets packets"
    echo ""
    echo "3. Top 5 Source IP Addresses:"
    echo "$top_source_ips"
    echo ""
    echo "4. Top 5 Destination IP Addresses:"
    echo "$top_dest_ips"
    echo ""
    echo "----- End of Report -----"
    
    log_message "Analysis summary report generated and displayed."
}

# Run the analysis function
log_message "Starting network traffic analysis..."
analyze_traffic
log_message "Network traffic analysis completed."
