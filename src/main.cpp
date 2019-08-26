#include <iostream>
#include <boost/program_options.hpp>
#include "crc32.h"

using namespace boost::program_options;
int main(int argc, char const *argv[]) {

    //std::string payload = "ENTER DFU BOOTLOADER MODE24937079";

    // Variables that will store parsed values.
    std::string payload, crc32hex;
    try
    {
        // Setup options.
        options_description desc("Options");
        desc.add_options()
        ("help,h", "Submit options")
        ("payload", value<std::string>(&payload))
        ;
        // Parse mocked up input.
        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);

		if (vm.count("help")) {
			std::cout << desc << std::endl;
			return 0;
		}

        std::cout<<"Checked: " << payload << std::endl;

        bool status = CRC32Helper::checksum(payload, crc32hex);
        if (status) std::cout<<"Checked: " << payload <<"\t" << crc32hex << std::endl;
    }
    catch (const error &ex){
        std::cerr << ex.what() << '\n';
    }
    return 0;
}
// ./crc32exe --payload "ENTER DFU BOOTLOADER MODE24937079"
