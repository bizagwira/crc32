#ifndef CRC32HELPER_H
#define CRC32HELPER_H

#include <string>
#include <boost/crc.hpp>


class CRC32Helper{
    public:
        static bool checksum(std::string& framestr, std::string& crchex);
        static int calculate(const std::string& my_string);
        static std::string crc32hex(const std::string &my_string);
    private:
        CRC32Helper(){}
};

#endif //CRC32HELPER_H
