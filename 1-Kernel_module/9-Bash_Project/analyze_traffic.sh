#!/bin/bash

# Bash Script to Analyze Network Traffic

# Log file path
log_file="network_analysis.log"

# Input: Path to the Wireshark pcap file
read -p "Enter the path to the Wireshark pcap file: " pcap_file

# Redirect stdout and stderr to the log file for steps (but not analysis results)
exec > >(tee -a "$log_file") 2>&1

#logging & Debugging
# Function to log a message with the current timestamp
log_message() {
    echo "$(date '+%Y-%m-%d %H:%M:%S') - $1" >> "$log_file"
}
















# Function to check law pcap file mawgood

check_pcap_file() {
    log_message "Checking if the pcap file exists..."
    if [ ! -f "$pcap_file" ]; then
        log_message "Error: Pcap file not found!"
        exit 1
    fi
    log_message "Pcap file found: $pcap_file"
}











# wc -l: This counts the number of lines in the output, which corresponds to the total number of packets. 
# Each packet is displayed on a separate line by tshark.
# Function to extract the total number of packets
extract_total_packets() {
    log_message "Extracting total number of packets..."
    total_packets=$(tshark -r "$pcap_file" | wc -l)
    if [ $? -ne 0 ]; then
        log_message "Error: Failed to extract total packets"
        exit 1
    fi
    log_message "Total Packets: $total_packets"
}







# Function to extract HTTP packets
# -Y "tls": Filters the output to show only TLS (Transport Layer Security, often used in HTTPS) packets.

extract_http_packets() {
    log_message "Extracting HTTP packets..."
    http_packets=$(tshark -r "$pcap_file" -Y "http" | wc -l)
    if [ $? -ne 0 ]; then
        log_message "Error: Failed to extract HTTP packets"
        exit 1
    fi
    log_message "HTTP Packets: $http_packets"
}








# Function to extract HTTPS/TLS packets
extract_https_packets() {
    log_message "Extracting HTTPS/TLS packets..."
    https_packets=$(tshark -r "$pcap_file" -Y "tls" | wc -l)
    if [ $? -ne 0]; then
        log_message "Error: Failed to extract HTTPS/TLS packets"
        exit 1
    fi
    log_message "HTTPS/TLS Packets: $https_packets"
}








# Function to extract top 5 source IP addresses
# -T fields: Specifies that tshark should output specific fields instead of the full packet details.
# -e ip.src: Extracts the source IP address field (ip.src) from each packet.
# sort: Sorts the IP addresses.
# uniq -c: Counts the occurrences of each IP address, outputting the count and the IP.
# sort -nr: Sorts the counts in numerical order, with the highest counts first.
# head -5: Outputs the top 5 most frequent source IP addresses

extract_top_source_ips() {
    log_message "Extracting top 5 source IP addresses..."
    top_source_ips=$(tshark -r "$pcap_file" -T fields -e ip.src | sort | uniq -c | sort -nr | head -5)
    if [ $? -ne 0 ]; then
        log_message "Error: Failed to extract top source IP addresses"
        exit 1
    fi
    log_message "Top 5 Source IP Addresses extracted"
}












# Function to extract top 5 destination IP addresses
# -T fields: Outputs specific fields, similar to the previous command.
# -e ip.dst: Extracts the destination IP address field (ip.dst) from each packet.
# sort | uniq -c | sort -nr | head -5: This sequence of commands works the same as for source IPs but applies to destination IPs.


extract_top_dest_ips() {
    log_message "Extracting top 5 destination IP addresses..."
    top_dest_ips=$(tshark -r "$pcap_file" -T fields -e ip.dst | sort | uniq -c | sort -nr | head -5)
    if [ $? -ne 0 ]; then
        log_message "Error: Failed to extract top destination IP addresses"
        exit 1
    fi
    log_message "Top 5 Destination IP Addresses extracted"
}











# Function to display analysis summary
display_summary() {
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

# Main function to run all steps
analyze_traffic() {
    log_message "Starting network traffic analysis..."
    check_pcap_file
    extract_total_packets
    extract_http_packets
    extract_https_packets
    extract_top_source_ips
    extract_top_dest_ips
    display_summary
    log_message "Network traffic analysis completed."
}

# Run the main analysis function
analyze_traffic
