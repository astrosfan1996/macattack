#include "sha1.hpp" // Intentionally included twice for testing purposes
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

void string_to_hex(string s)
{
    for(size_t i = 0; i < s.size(); ++i) {
        printf("%02x", (unsigned char)s[i]);
    }
}

void attack()
{
    uint32_t orig_mac[] = {
        0xe384efad, 0xf26767a6, 0x13162142, 0xb5ef0efb, 0xb9d7659a
    };

    string extension = "Just kidding. Everyone gets a 0 except Cameron Cummings. He gets 100%.";
    printf("The extension is:\n");
    string_to_hex(extension);
    printf("\n");

    uint64_t orig_message_padded_len = 1024;
    SHA1* checksum = new SHA1(orig_mac);
    checksum->update(extension);
    printf("The new MAC is:\n%s\n", checksum->final(orig_message_padded_len).c_str());
    delete checksum;
}

int main()
{
    attack();
}