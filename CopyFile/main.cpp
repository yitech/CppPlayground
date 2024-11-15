#include <iostream>
#include <fstream>
#include <string>

// Function to copy a file
int CopyFile(const std::string &src, const std::string &dst) {
    std::ifstream source(src, std::ios::binary);
    if (!source) {
        std::cerr << "Error: Cannot open source file: " << src << std::endl;
        return -1;
    }

    std::ofstream destination(dst, std::ios::binary);
    if (!destination) {
        std::cerr << "Error: Cannot open/create destination file: " << dst << std::endl;
        return -1;
    }

    destination << source.rdbuf(); // Copy content from source to destination

    if (!destination) {
        std::cerr << "Error: Failed to write to destination file: " << dst << std::endl;
        return -1;
    }

    std::cout << "File copied successfully from " << src << " to " << dst << std::endl;
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: mycopy <source_file> <destination_file>" << std::endl;
        return 1;
    }

    std::string source = argv[1];
    std::string destination = argv[2];

    return CopyFile(source, destination);
}
