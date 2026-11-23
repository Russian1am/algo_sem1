#include "class.hpp"
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <stdexcept>

Book::Book(BookData InputData) {
    local_name = InputData.Name;
    local_name_length = local_name ? std::strlen(local_name) : 0;
    local_author = InputData.Author;
    local_author_length = local_author ? std::strlen(local_author) : 0;
    local_creation_year = InputData.Year;
    local_genre = InputData.Genre;
    local_genre_length = local_genre ? std::strlen(local_genre) : 0;
    local_description = InputData.Description;
    local_description_length = local_description ? std::strlen(local_description) : 0;
}

Book::Book(const Book& object) {
    local_name = object.get_name();
    local_name_length = object.get_name_length();

    local_author = object.get_author();
    local_author_length = object.get_author_length();

    local_creation_year = object.get_creation_year();

    local_genre = object.get_genre();
    local_genre_length = object.get_genre_length();

    local_description = object.get_description();
    local_description_length = object.get_description_length();
}

Book::~Book() {
    delete[] local_name;
    delete[] local_author;
    delete[] local_genre;
    delete[] local_description;
}

void Book::edit_all() {

    delete[] local_name;
    local_name = nullptr;
    delete[] local_author;
    local_author = nullptr;
    delete[] local_genre;
    local_genre = nullptr;
    delete[] local_description;
    local_description = nullptr;

    printf("Enter new book name: ");
    local_name = readLine(local_name_length);

    printf("Enter new book author: ");
    local_author = readLine(local_author_length);

    printf("Enter new book creation year: ");
    local_creation_year = readInt();

    printf("Enter new book genre: ");
    local_genre = readLine(local_genre_length);

    printf("Enter new book description: ");
    local_description = readLine(local_description_length);
}

char* Book::get_name() const {
    if (local_name == nullptr) {
        return nullptr;
    }

    char* buffer = new char[local_name_length + 1];

    for (size_t i = 0; i < local_name_length; i++) {
        buffer[i] = local_name[i];
    }

    buffer[local_name_length] = '\0';
    return buffer;
}

char* Book::get_author() const {
    if (local_author == nullptr) {
        return nullptr;
    }

    char* buffer = new char[local_author_length + 1];

    for (size_t i = 0; i < local_author_length; i++) {
        buffer[i] = local_author[i];
    }

    buffer[local_author_length] = '\0';
    return buffer;
}

char* Book::get_genre() const {
    if (local_genre == nullptr) {
        return nullptr;
    }

    char* buffer = new char[local_genre_length + 1];

    for (size_t i = 0; i < local_genre_length; i++) {
        buffer[i] = local_genre[i];
    }

    buffer[local_genre_length] = '\0';
    return buffer;
}

char* Book::get_description() const {
    if (local_description == nullptr) {
        return nullptr;
    }

    char* buffer = new char[local_description_length + 1];

    for (size_t i = 0; i < local_description_length; i++) {
        buffer[i] = local_description[i];
    }

    buffer[local_description_length] = '\0';
    return buffer;
}

int Book::get_creation_year() const {
    return local_creation_year;
}

size_t Book::get_name_length() const {
    return local_name_length;
}

size_t Book::get_author_length() const {
    return local_author_length;
}

size_t Book::get_genre_length() const {
    return local_genre_length;
}

size_t Book::get_description_length() const {
    return local_description_length;
}

bool Book::edit_name() {
    size_t new_length = 0;

    printf("Enter new name: ");
    char* new_name = readLine(new_length);

    if (new_name == nullptr) {
        return false;
    }

    delete[] local_name;

    local_name = new_name;
    local_name_length = new_length;

    return true;
}

bool Book::edit_author() {
    size_t new_length = 0;

    printf("Enter new author: ");
    char* new_author = readLine(new_length);

    if (new_author == nullptr) {
        return false;
    }

    delete[] local_author;

    local_author = new_author;
    local_author_length = new_length;

    return true;
}

bool Book::edit_genre() {
    size_t new_length = 0;

    printf("Enter new genre: ");
    char* new_genre = readLine(new_length);

    if (new_genre == nullptr) {
        return false;
    }

    delete[] local_genre;

    local_genre = new_genre;
    local_genre_length = new_length;

    return true;
}

bool Book::edit_description() {
    size_t new_length = 0;

    printf("Enter new description: ");
    char* new_description = readLine(new_length);

    if (new_description == nullptr) {
        return false;
    }

    delete[] local_description;

    local_description = new_description;
    local_description_length = new_length;

    return true;
}

bool Book::edit_creation_year() {
    printf("Enter new creation year: ");
    unsigned short new_year = readInt();

    if (new_year > 0 && new_year <= 2026) {
        local_creation_year = new_year;
        return true;
    }
    else {
        printf("Invalid year! Enter digit from 0 to 2026.\n");
        return false;
    }
}

Book& Book::operator=(const Book& other) {
    if (this == &other){
        return *this;
    }
    Book copy(other);
    char* name = local_name;
    local_name = copy.local_name;
    copy.local_name = name;
    size_t name_length = local_name_length;
    local_name_length = copy.local_name_length;
    copy.local_name_length = name_length;
    char* author = local_author;
    local_author = copy.local_author;
    copy.local_author = author;
    size_t author_length = local_author_length;
    local_author_length = copy.local_author_length;
    copy.local_author_length = author_length;
    int year = local_creation_year;
    local_creation_year = copy.local_creation_year;
    copy.local_creation_year = year;
    char* genre = local_genre;
    local_genre = copy.local_genre;
    copy.local_genre = genre;
    size_t genre_length = local_genre_length;
    local_genre_length = copy.local_genre_length;
    copy.local_genre_length = genre_length;
    char* description = local_description;
    local_description = copy.local_description;
    copy.local_description = description;
    size_t description_length = local_description_length;
    local_description_length = copy.local_description_length;
    copy.local_description_length = description_length;
    return *this;
}

BookStruct::BookStruct() {
    data = new Book[size];
}

BookStruct::~BookStruct() {
    delete[] data;
}

void BookStruct::add(Book new_book) {
    if (amount == size){

        size *= 2;
        Book* buffer = new Book[size];

        for (size_t i = 0 ; i < amount; i++){
            buffer[i] = data[i];
        }

        delete[] data;
        data = buffer;
        data[amount] = new_book;

        amount++;
        return;
    }
    else{
        data[amount] = new_book;
        amount++;

        return;
    }
}

bool BookStruct::delete_by_index(const size_t index) {
    if (index >= amount){
        throw std::out_of_range("No data by index");
        return false;
    }

    Book* buffer = new Book[size];
    size_t ptr = 0;
    for (size_t i = 0 ; i < amount; i++){
        if (i != index){
            buffer[ptr] = data[i];
            ptr++;
        }
    }

    delete[] data;
    data = buffer;
    amount = ptr;

    return true;
}

void BookStruct::clear() {
    size = 1;
    amount = 0;
    delete[] data;
    data = new Book[size];
}

size_t BookStruct::get_amount() const {
    return amount;
}

size_t BookStruct::get_size() const {
    return size;
}

Book& BookStruct::get_by_index(const size_t index) {
    if (index >= amount){
        throw std::out_of_range("No data by index!");
    }
    else{
        return data[index];
    }
}

bool BookStruct::swap(const size_t index1, const size_t index2) {
    if (index1 == index2){
        return false;
    }

    Book* buffer = new Book[size];
    for (size_t i = 0 ; i < amount; i++){
        if (i == index1){
            buffer[i] = data[index2];
        }
        else if (i == index2){
            buffer[i] = data[index1];
        }
        else{
            buffer[i] = data[i];
        }
    }

    delete[] data;
    data = buffer;

    return true;
}

Book& BookStruct::operator[](const size_t index) {
    if (index >= amount){
        throw std::out_of_range("No data by index!");
    }
    else{
        return data[index];
    }
}

bool readBooks(BookStruct& D, const char* file_location) {
    if (!file_location) return false;
    FILE* file = fopen(file_location, "r");
    if (!file) return false;

    try {
        const json document = json::parse(file);
        const bool read_ok = ferror(file) == 0;
        const bool closed = fclose(file) == 0;
        file = nullptr;
        if (!read_ok || !closed) return false;

        const json& books = document.at("Books");
        if (!books.is_object()) return false;

        for (size_t i = 0; i < books.size(); ++i) {
            char key[sizeof(size_t) * CHAR_BIT + 1];
            size_t start = sizeof(key) - 1;
            key[start] = '\0';
            size_t number = i + 1;
            do {
                key[--start] = static_cast<char>('0' + number % 10);
                number /= 10;
            } while (number != 0);

            const json& entry = books.at(key + start);

            BookData obj;
            obj.Year = std::atoi(entry.at("Year").get_ref<const json::string_t&>().c_str());
            try {
                obj.Name = json_to_ptrChar(entry.at("Name"));
                obj.Author = json_to_ptrChar(entry.at("Author"));
                obj.Genre = json_to_ptrChar(entry.at("Genre"));
                obj.Description = json_to_ptrChar(entry.at("Description"));
            }
            catch (...) {
                delete[] obj.Name;
                delete[] obj.Author;
                delete[] obj.Genre;
                delete[] obj.Description;
                throw;
            }

            Book buffer(obj);
            D.add(buffer);
        }

        return true;
    }
    catch (...) {
        if (file) fclose(file);
        return false;
    }
}

bool readConfig(BookStruct& S, const char* loc_location, PREF& settings) {
    char* data = nullptr;
    bool result = GetDataFromFile(data, loc_location);
    if (!result){
        printf("Error occured while reading data!");
        return false;
    }

    json obj_sorting_type = json::parse(data)["Settings"]["SortingType"];
    json obj_sorting_direction = json::parse(data)["Settings"]["Direction"];

    char* ch_sorting_type = json_to_ptrChar(obj_sorting_type);
    char* ch_sorting_direction = json_to_ptrChar(obj_sorting_direction);


    // Type
    if (strcmp(ch_sorting_type, "ByName") == 0){
        settings.SortType = ST::ByName;
    }
    else if (strcmp(ch_sorting_type, "ByAuthor") == 0){
        settings.SortType = ST::ByAuthor;
    }
    else if (strcmp(ch_sorting_type, "ByGenre") == 0){
        settings.SortType = ST::ByGenre;
    }
    else if (strcmp(ch_sorting_type, "ByYear") == 0){
        settings.SortType = ST::ByYear;
    }
    else{
        settings.SortType = ST::None;
    }


     // Direction
    if (strcmp(ch_sorting_direction, "Up") == 0){
        settings.SortDirection = SD::Up;
    }
    else if (strcmp(ch_sorting_direction, "Down") == 0){
        settings.SortDirection = SD::Down;
    }
    else{
        settings.SortDirection = SD::None;
    }

    int amount = 0;
    size_t buffer = 0;

    while (true){
        if (json::parse(data)["Books"]["Data"].contains(int_to_ptrChar(amount+1, buffer))){
            amount++;
        }
        else{
            break;
        }
    }

    for (int k = 0; k < amount; k++){
        BookData obj;

        char* key = int_to_ptrChar(k + 1, buffer);
        json entry = json::parse(data).at("Books").at("Data").at(key);
        delete[] key;

        obj.Name = json_to_ptrChar(entry.at("Name"));
        obj.Author = json_to_ptrChar(entry.at("Author"));
        obj.Genre = json_to_ptrChar(entry.at("Genre"));
        obj.Description = json_to_ptrChar(entry.at("Description"));

        char* year = json_to_ptrChar(entry.at("Year"));
        obj.Year = std::atoi(year);
        delete[] year;

        Book new_book(obj);
        S.add(new_book);
    }

    return true;
}

bool writeConfig(BookStruct& books, const char* location, const PREF& settings) {
    const char* sort_type = "None";
    if (settings.SortType == ST::ByName) {
        sort_type = "ByName";
    } else if (settings.SortType == ST::ByAuthor) {
        sort_type = "ByAuthor";
    } else if (settings.SortType == ST::ByGenre) {
        sort_type = "ByGenre";
    } else if (settings.SortType == ST::ByYear) {
        sort_type = "ByYear";
    }

    const char* direction = "None";
    if (settings.SortDirection == SD::Up) {
        direction = "Up";
    } else if (settings.SortDirection == SD::Down) {
        direction = "Down";
    }

    json config;
    config["Settings"]["SortingType"] = sort_type;
    config["Settings"]["Direction"] = direction;

    auto& entries = config["Books"]["Data"];
    entries = json::object();

    for (size_t i = 0; i < books.get_amount(); ++i) {
        const Book& book = books.get_by_index(i);

        char key[32];
        char year[32];
        std::snprintf(key, sizeof(key), "%zu", i + 1);
        std::snprintf(year, sizeof(year), "%d", book.get_creation_year());

        auto& entry = entries[key];

        auto write_text = [&entry](const char* field, char* value) {
            try {
                entry[field] = value ? value : "";
            } catch (...) {
                delete[] value;
                throw;
            }
            delete[] value;
        };

        write_text("Name", book.get_name());
        write_text("Author", book.get_author());
        write_text("Genre", book.get_genre());
        write_text("Description", book.get_description());
        entry["Year"] = year;
    }

    const auto text = config.dump(4);

    FILE* file = std::fopen(location, "w");
    if (file == nullptr) {
        return false;
    }

    const bool written = std::fprintf(file, "%s\n", text.c_str()) >= 0;
    const bool closed = std::fclose(file) == 0;
    return written && closed;
}

Manager::Manager() {
    //settings
    PREF sets;
    readConfig(D, global_config_location, sets);
    GlobalSortDirection = sets.SortDirection;
    GlobalSortType = sets.SortType;
}

Manager::~Manager() {
    PREF settings;
    settings.SortType = GlobalSortType;
    settings.SortDirection = GlobalSortDirection;
    writeConfig(D, global_config_location, settings);
}

void Manager::debugInfo() {
    printf("==== Data ==============\n");

    printf("Sort direction => ");
    switch (GlobalSortDirection){
        case SD::Down:
            printf("Down\n"); break;
        case SD::Up:
            printf("Up\n"); break;
        default:
            printf("None\n"); break;
    }
    printf("Sort Type => ");
    switch (GlobalSortType){
        case ST::ByName:
            printf("By Name\n"); break;
        case ST::ByAuthor:
            printf("By Author\n"); break;
        case ST::ByGenre:
            printf("By Genre\n"); break;
        default:
            printf("None\n"); break;
    }

    size_t loc_amount = D.get_amount();
    printf("Amount of books = %lu\n", loc_amount);
    printf("Array size => %lu\n", D.get_size());

    printf("====== Books ============\n");
    for (size_t k = 0; k < loc_amount; k++){
        printf("%lu | %s\t| %s\t| %i\t| %s\n\n", k+1, D[k].get_name(), D[k].get_author(), D[k].get_creation_year(), D[k].get_genre());
    }
}

void Manager::sortByName(SD Direction) {
    bool flag = true;
    if (Direction == SD::None || Direction == SD::Up){
        // small -> big
        while (flag){
            flag = false;
            for (size_t k = 0; k < D.get_amount()-1; k++){
                int result = compare(D[k].get_name(), D[k+1].get_name());
                if (result > 0){
                    D.swap(k, k+1);
                    flag = true;
                }
            }
        }
    }
    else{
        // big -> small
        while (flag){
            flag = false;
            for (size_t k = 0; k < D.get_amount()-1; k++){
                int result = compare(D[k].get_name(), D[k+1].get_name());
                if (result < 0){
                    D.swap(k, k+1);
                    flag = true;
                }
            }
        }
    }
    GlobalSortDirection = Direction;
    GlobalSortType = ST::ByName;
}

void Manager::sortByAuthor(SD Direction) {
    bool flag = true;
    if (Direction == SD::None || Direction == SD::Up){
        // small -> big
        while (flag){
            flag = false;
            for (size_t k = 0; k < D.get_amount()-1; k++){
                int result = compare(D[k].get_author(), D[k+1].get_author());
                if (result > 0){
                    D.swap(k, k+1);
                    flag = true;
                }
            }
        }
    }
    else{
        // big -> small
        while (flag){
            flag = false;
            for (size_t k = 0; k < D.get_amount()-1; k++){
                int result = compare(D[k].get_author(), D[k+1].get_author());
                if (result < 0){
                    D.swap(k, k+1);
                    flag = true;
                }
            }
        }
    }
    GlobalSortDirection = Direction;
    GlobalSortType = ST::ByAuthor;
}

void Manager::sortByGenre(SD Direction) {
    bool flag = true;
    if (Direction == SD::None || Direction == SD::Up){
        // small -> big
        while (flag){
            flag = false;
            for (size_t k = 0; k < D.get_amount()-1; k++){
                int result = compare(D[k].get_genre(), D[k+1].get_genre());
                if (result > 0){
                    D.swap(k, k+1);
                    flag = true;
                }
            }
        }
    }
    else{
        // big -> small
        while (flag){
            flag = false;
            for (size_t k = 0; k < D.get_amount()-1; k++){
                int result = compare(D[k].get_genre(), D[k+1].get_genre());
                if (result < 0){
                    D.swap(k, k+1);
                    flag = true;
                }
            }
        }
    }
    GlobalSortDirection = Direction;
    GlobalSortType = ST::ByGenre;
}

void Manager::sortByYear(SD Direction) {
    bool flag = true;
    if (Direction == SD::None || Direction == SD::Up){
        // small -> big
        while (flag){
            flag = false;
            for (size_t k = 0; k < D.get_amount()-1; k++){
                bool result = D[k].get_creation_year() > D[k+1].get_creation_year();
                if (result){
                    D.swap(k, k+1);
                    flag = true;
                }
            }
        }
    }
    else{
        // big -> small
        while (flag){
            flag = false;
            for (size_t k = 0; k < D.get_amount()-1; k++){
                bool result = D[k].get_creation_year() < D[k+1].get_creation_year();
                if (result){
                    D.swap(k, k+1);
                    flag = true;
                }
            }
        }
    }
    GlobalSortDirection = Direction;
    GlobalSortType = ST::ByYear;
}

Book& Manager::pop(const size_t index) {
    if (index >= D.get_amount()){
        throw std::out_of_range("No data by index!");
    }
    else{
        return D[index];
    }
}

BookStruct& Manager::getStructRef() {
    return D;
}

SD Manager::get_sort_direction() const {
    return GlobalSortDirection;
}

ST Manager::get_sort_type() const {
    return GlobalSortType;
}

size_t Manager::searchByName(const char* input) {
    int top_result, buffer;
    size_t ret_index = 0;
    for (size_t k = 0; k < D.get_amount(); k++){
        buffer = mod(findIdentity(input, D[k].get_name()));
        if (buffer > top_result){
            top_result = buffer;
            ret_index = k;
        }
    }
    return ret_index;
}

size_t Manager::searchByAuthor(const char* input) {
    int top_result, buffer;
    size_t ret_index = 0;
    for (size_t k = 0; k < D.get_amount(); k++){
        buffer = mod(findIdentity(input, D[k].get_author()));
        if (buffer > top_result){
            top_result = buffer;
            ret_index = k;
        }
    }
    return ret_index;
}

size_t Manager::searchByGenre(const char* input) {
    int top_result, buffer;
    size_t ret_index = 0;
    for (size_t k = 0; k < D.get_amount(); k++){
        buffer = mod(findIdentity(input, D[k].get_genre()));
        if (buffer > top_result){
            top_result = buffer;
            ret_index = k;
        }
    }
    return ret_index;
}

void Manager::showBookInfo(const size_t index) {
    if (index >= D.get_amount()){
        throw std::out_of_range("No data by index!");
        return;
    }

    Book object = D[index];
    printf("Name - %s\nAuthor - %s\nCreation year - %i\nGenre - %s\nDescription - %s\n", object.get_name(), object.get_author(), object.get_creation_year(), object.get_genre(), object.get_description());

}

bool Manager::addFromFile(const char* file_location) {
    char* data = nullptr;
    bool result = GetDataFromFile(data, file_location);
    if (!result){
        printf("Error occured while reading data!");
        return false;
    }

    int amount = 0;
    size_t buffer = 0;

    while (true){
        if (json::parse(data)["Books"].contains(int_to_ptrChar(amount+1, buffer))){
            amount++;
        }
        else{
            break;
        }
    }

    for (int k = 0; k < amount; k++){
        BookData obj;

        char* key = int_to_ptrChar(k + 1, buffer);
        json entry = json::parse(data).at("Books").at(key);
        delete[] key;

        obj.Name = json_to_ptrChar(entry.at("Name"));
        obj.Author = json_to_ptrChar(entry.at("Author"));
        obj.Genre = json_to_ptrChar(entry.at("Genre"));
        obj.Description = json_to_ptrChar(entry.at("Description"));

        char* year = json_to_ptrChar(entry.at("Year"));
        obj.Year = std::atoi(year);
        delete[] year;

        Book new_book(obj);
        D.add(new_book);
    }

    return true;
}

Book& Manager::operator[](const size_t index) {
    if (index >= D.get_amount()){
        throw std::out_of_range("No data by index!");
    }
    else{
        return D[index];
    }
}


