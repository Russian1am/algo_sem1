#pragma once

#include "functions.hpp"

class Book {
    private:
        char* local_name = nullptr;
        size_t local_name_length = 0;

        char* local_author = nullptr;
        size_t local_author_length = 0;

        int local_creation_year = 0;

        char* local_genre = nullptr;
        size_t local_genre_length = 0;

        char* local_description = nullptr;
        size_t local_description_length = 0;

    public:

        // Constructors
        Book() = default;

        Book(BookData InputData);

        Book(const Book& object);


        // Destructor
        ~Book();

        // special methods
        void edit_all();

        // Getters
        char* get_name() const;

        char* get_author() const;

        char* get_genre() const;

        char* get_description() const;

        int get_creation_year() const;

        // lengths getters
        size_t get_name_length () const;

        size_t get_author_length () const;

        size_t get_genre_length () const;

        size_t get_description_length () const;

        // Edit methods
        bool edit_name();

        bool edit_author();

        bool edit_genre();

        bool edit_description();

        bool edit_creation_year();

        // operator
        Book& operator= (const Book& other);
};

class BookStruct{
    private:
        Book* data = nullptr;
        size_t size = 1;
        size_t amount = 0;
    public:
        BookStruct();

        BookStruct(const BookStruct&) = delete;
        BookStruct& operator=(const BookStruct&) = delete;

        ~BookStruct();

        void add(Book new_book);

        bool delete_by_index(const size_t index);

        void clear();

        size_t get_amount() const;

        size_t get_size() const;

        Book& get_by_index(const size_t index);

        bool swap(const size_t index1, const size_t index2);

        Book& operator[] (const size_t index);

};

bool readBooks(BookStruct& D, const char* file_location);

bool readConfig(BookStruct& S, const char* loc_location, PREF& settings);

bool writeConfig(BookStruct& books, const char* location, const PREF& settings);

// TODO: добить чтение/сохранение из файла
// TODO: поиск постоянно выдает одну и ту же книгу


class Manager{
    private:
        BookStruct D;
        SD GlobalSortDirection = SD::None;
        ST GlobalSortType = ST::None;
        const char* global_config_location = "./app/data/config.json";
    public:
        Manager();
        ~Manager();

        void debugInfo();


        // sort methods
        void sortByName (SD Direction);

        void sortByAuthor(SD Direction);

        void sortByGenre(SD Direction);

        void sortByYear(SD Direction);

        // getters

        Book& pop(const size_t index);
        BookStruct& getStructRef();

        SD get_sort_direction () const;

        ST get_sort_type () const;

        // search methods

        size_t searchByName (const char* input);

        size_t searchByAuthor (const char* input);

        size_t searchByGenre (const char* input);

        void showBookInfo (const size_t index);

        bool addFromFile(const char* file_location);

        Book& operator[] (const size_t index);
};


