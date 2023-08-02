#include "utilities.hpp"

std::string read_shader(std::string filename) {
    std::ifstream ifs(filename.c_str());
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
    return content;
};


