#pragma once

#include <cstddef>
#include "json.hpp"
using json = nlohmann::json;

// Sort Direction
enum class SD{
    None, // 1
    Up, // 2
    Down // 3
};

// Sort Type
enum class ST{
    None, // 1
    ByName, // 2
    ByAuthor, // 3
    ByGenre, // 4
    ByYear // 5
};

struct PREF{
    SD SortDirection;
    ST SortType;
};

struct BookData{
    char* Name = nullptr;
    char* Author = nullptr;
    int Year = -1;
    char* Genre = nullptr;
    char* Description = nullptr;
};

char* json_to_ptrChar(const json& json_object);

char* raw_to_ptrChar(const char* input);


char* int_to_ptrChar(const int number, size_t& object_size);

char* readLine(size_t& size);

char* readLine();

int mod(int x);

int readInt(const int lim1 = -1, const int lim2 = 2026);

bool GetDataFromFile(char*& data, const char* file_location);

bool WriteDataInFile(const char* data, const char* file_location);

bool ReWriteDataInFile(const char* data, const char* file_location);

size_t json_to_sizet(const json& object);

size_t get_book_amount(const char* loc_location);

int compare(const char* a, const char* b);

int findIdentity(const char* line1, const char* line2);
