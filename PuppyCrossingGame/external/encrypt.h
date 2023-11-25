#pragma once
#include "Base64.h"
#include "vigenere.h"
#include <iostream>
#include <string>

std::string encrypt(std::string& msg, std::string& key);
// https://stackoverflow.com/questions/17316506/strip-invalid-utf8-from-string-in-c-c
std::string sanitize_utf8(std::string& str);
std::string decrypt(std::string& encrypted_msg, std::string& key);
