#include "crc32.h"
#include <iostream>
#include <sstream>

std::string
CRC32Helper::crc32hex(const std::string& my_string) {
    std::stringstream stream;
    stream << std::hex << CRC32Helper::calculate(my_string);
    return stream.str();
}

bool
CRC32Helper::checksum(std::string& payload, std::string& calculated_crc32_chex){
    std::string received_crc32_chex = payload.substr (payload.size()-8, 8);
    payload = payload.substr(0, payload.size()-8);

    calculated_crc32_chex = CRC32Helper::crc32hex(payload);
    //std::cout << payload <<"\tReceived: "<<received_crc32_chex<<"\tCalculed: "<<calculated_crc32_chex<<std::endl;
    return (received_crc32_chex.compare(calculated_crc32_chex) == 0);
}


int
CRC32Helper::calculate(const std::string& my_string) {
    boost::crc_32_type result;
    result.process_bytes(my_string.data(), my_string.length());
    return result.checksum();
}

