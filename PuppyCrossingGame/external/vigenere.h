#pragma once
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int index(char c);
std::string extend_key(std::string& msg, std::string& key);
std::string encrypt_vigenere(std::string& msg, std::string& key);
std::string decrypt_vigenere(std::string& encryptedMsg, std::string& newKey);
