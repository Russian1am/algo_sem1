#include "functions.hpp"
#include <cstdio>
#include <cstring>

char* json_to_ptrChar(const json& json_object) {
    const char* source = json_object.get_ref<const json::string_t&>().c_str();
    size_t local_length = strlen(source) + 1;
    char* name = new char[local_length];
    strcpy(name, source);
    return name;
}

char* raw_to_ptrChar(const char* input) {
    char* output = new char[std::strlen(input)+1];
    std::strcpy(output, input);
    return output;
}

char* int_to_ptrChar(const int number, size_t& object_size) {
    int length = snprintf(nullptr, 0, "%d", number);

    object_size = static_cast<size_t>(length) + 1;

    char* result = new char[object_size];

    snprintf(result, object_size, "%d", number);

    return result;
}

char* readLine(size_t& size) {
    size_t capacity = 16;
    size_t length = 0;
    char* buffer = new char[capacity];
    int ch;

    while ((ch = fgetc(stdin)) != '\n' && ch != EOF) {
        if (length + 1 >= capacity) {
            capacity *= 2;
            char* newBuffer = new char[capacity];

            for (size_t i = 0; i < length; i++) {
                newBuffer[i] = buffer[i];
            }

            delete[] buffer;
            buffer = newBuffer;
        }

        buffer[length] = static_cast<char>(ch);
        length++;
    }

    if (ch == EOF && length == 0) {
        delete[] buffer;
        size = 0;
        return nullptr;
    }

    buffer[length] = '\0';
    size = length;
    return buffer;
}

char* readLine() {
    size_t size;
    return readLine(size);
}

int mod(int x) {
    return (x < 0) ? -x : x;
}

int readInt(const int lim1, const int lim2) {
    int year;

    while (true) {

        int result = scanf("%d", &year);

        if (result == EOF) {
            return 1;
        }

        bool valid = (result == 1);
        int ch;

        while ((ch = getchar()) != '\n' && ch != EOF) {
            if (ch != ' ' && ch != '\t') {
                valid = false;
            }
        }

        if (valid && year >= lim1 && year <= lim2) {
            break;
        }

        printf("Invalid input!\n");

        if (ch == EOF) {
            return 1;
        }
    }

    return year;
}

bool GetDataFromFile(char*& data, const char* file_location) {
    FILE *f = fopen(file_location, "rb");
    if (f == NULL){
        printf("No such file or direction!\n");
        return false;
    }

    long long file_size;
    fseek(f, 0, SEEK_END);
    file_size = ftell(f);
    rewind(f);
    data = new char[file_size+1];

    size_t counter = 0;
    char elem;
    while (fscanf(f, "%c", &elem) == 1){
        data[counter] = elem;
        counter++;
    }
    data[counter] = '\0';

    int close_result = fclose(f);
    if (close_result != 0){
        printf("Close error!\n");
        return false;
    }
    return true;
}

bool WriteDataInFile(const char* data, const char* file_location) {
    FILE *f = fopen(file_location, "a");
    int close_result;
    if (f == NULL){
        printf("No cuch file or direction!\n");
        return false;
    }
    if (data == nullptr){
        printf("No data given to input!\n");
        close_result = fclose(f);
        if (close_result != 0){
            printf("Close error!\n");
            return false;
        }
        return false;
    }

    fprintf(f, "%s", data);
    close_result = fclose(f);
    if (close_result != 0){
        printf("Close error!\n");
        return false;
    }
    return true;
}

bool ReWriteDataInFile(const char* data, const char* file_location) {
    FILE *f = fopen(file_location, "w");
    int close_result;
    if (f == NULL){
        printf("No cuch file or direction!\n");
        return false;
    }
    if (data == nullptr){
        printf("No data given to input!\n");
        close_result = fclose(f);
        if (close_result != 0){
            printf("Close error!\n");
            return false;
        }
        return false;
    }

    fprintf(f, "%s", data);
    close_result = fclose(f);
    if (close_result != 0){
        printf("Close error!\n");
        return false;
    }
    return true;
}

size_t json_to_sizet(const json& object) {
    return static_cast<size_t>(object.get<int>());
}

size_t get_book_amount(const char* loc_location) {
    char* data = nullptr;
    bool result = GetDataFromFile(data, loc_location);
    if (!result){
        printf("Error occured while reading data!");
        return false;
    }

    json object = json::parse(data)["Books"]["Book-Amount"];
    return json_to_sizet(object);
}

int compare(const char* a, const char* b) {
    if (a == nullptr && b == nullptr)
        return 0;

    if (a == nullptr)
        return -1;

    if (b == nullptr)
        return 1;

    return strcmp(a, b);
}

int findIdentity(const char* line1, const char* line2) {
    if (line1 == nullptr || line2 == nullptr) {
        return -1;
    }

    size_t length1 = strlen(line1);
    size_t length2 = strlen(line2);

    size_t maxLength = (length1 > length2) ? length1 : length2;
    size_t minLength = (length1 < length2) ? length1 : length2;

    if (maxLength == 0) {
        return 100;
    }

    size_t matches = 0;

    for (size_t k = 0; k < minLength; k++) {
        if (line1[k] == line2[k]) {
            matches++;
        }
    }

    return static_cast<int>((matches * 100) / maxLength);
}
