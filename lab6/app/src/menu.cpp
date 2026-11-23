#include "menu.hpp"
#include "class.hpp"
#include <cstdio>
#include <iostream>

bool ManipulateByIndex(Book& object) {
    while(true){
        printf("\n======== Edit ========\n");
        printf("| 1. Edit Name       |\n");
        printf("| 2. Edit Author     |\n");
        printf("| 3. Edit Genre      |\n");
        printf("| 4. Edit Year       |\n");
        printf("| 5. Edit Description|\n");
        printf("| 6. Edit everything |\n");
        printf("| 7. Back            |\n");
        printf("======================\n");

        printf("Option: ");
        int user_input = readInt(1,7);

        if (user_input == 1){
            object.edit_name();
        }
        else if (user_input == 2){
            object.edit_author();
        }
        else if (user_input == 3){
            object.edit_genre();
        }
        else if (user_input == 4){
            object.edit_creation_year();
        }
        else if (user_input == 5){
            object.edit_description();
        }
        else if (user_input == 6){
            object.edit_all();
        }
        else{
            break;
        }

    }
    return true;
}

bool main_scenario() {
    Manager A;
    SD Direction = A.get_sort_direction();
    switch (A.get_sort_type()){
        case ST::ByName: A.sortByName(Direction); break;
        case ST::ByAuthor: A.sortByAuthor(Direction); break;
        case ST::ByGenre: A.sortByGenre(Direction); break;
        case ST::ByYear: A.sortByYear(Direction); break;
    }

    int user_input = 0;
    size_t index;
    while (true){
        printf("\n====== MENU =======\n");
        printf("1. Search books\n");
        printf("2. Show books\n");
        printf("3. Add books\n");
        printf("4. Delete\n");
        printf("5. Exit\n");

        printf("\n===================\n");
        printf("Option: ");
        user_input = readInt(1,5);

        if (user_input == 1){
            while (true){
                printf("\n===== Method ======\n");
                printf("1. Search by author\n");
                printf("2. Search by genre\n");
                printf("3. Search by name\n");
                printf("4. Back\n");

                printf("\n===================\n");
                printf("Option: ");
                user_input = readInt(1,5);

                size_t (Manager::*searchfoo)(const char*) = nullptr;
                if (user_input == 1){
                    searchfoo = &Manager::searchByAuthor;
                }
                else if (user_input == 2){
                    searchfoo = &Manager::searchByGenre;
                }
                else if (user_input == 3){
                    searchfoo = &Manager::searchByName;
                }
                else{
                    break;
                }
                printf("\nEnter search request: ");
                index = (A.*searchfoo)(readLine());
                printf("Nearest variant: %s", A.pop(index).get_name());

                printf("Want to edit this book? (y - 1 / n - 0): ");
                user_input = readInt(0,1);
                if (user_input == 1){
                    ManipulateByIndex(A.pop(index));
                }
            }
        }
        else if (user_input == 2){
            while (true){
                printf("\n===== Method ======\n");
                printf("1. Show by index\n");
                printf("2. Show all\n");
                printf("3. Sort\n");
                printf("4. Back\n");

                printf("\n===================\n");
                printf("Option: ");
                user_input = readInt(1,4);

                if (user_input == 1){
                    printf("\n===================\n");
                    printf("There are %lu books:", A.getStructRef().get_amount());
                    for (size_t k = 0; k < A.getStructRef().get_amount(); k++){
                        printf("\n%lu. %s", k+1, A.pop(k).get_name());
                    }

                    printf("\n\n===================");
                    printf("\nEnter book number: ");
                    index = readInt(1, A.getStructRef().get_amount());

                    printf("\n===== INFO ========\n");
                    A.showBookInfo(index-1);
                    printf("===================\n");

                    printf("Want to edit this book? (y - 1 / n - 0): ");
                    user_input = readInt(0,1);
                    if (user_input == 1){
                        ManipulateByIndex(A.pop(index-1));
                    }
                }
                else if (user_input == 2){
                    if (A.getStructRef().get_amount() == 0){
                        printf("\n===== BOOKS =======\n");
                        printf("|There`re no books|\n");
                        printf("===================\n");
                    }
                    else{
                        while(true){
                            printf("\n===== BOOKS =======\n");
                            for (size_t k = 0; k < A.getStructRef().get_amount(); k++){
                                A.showBookInfo(k);
                                printf("-------------------\n");
                            }
                            printf("Want to edit any book? (y - 1 / n - 0): ");
                            user_input = readInt(0,1);
                            if (user_input == 1){
                                printf("\nEnter book number: ");
                                index = readInt(1, A.getStructRef().get_amount());
                                ManipulateByIndex(A.pop(index-1));
                            }
                            break;
                        }
                    }
                }
                else if (user_input == 3){
                    while (true){
                        printf("\n====== SORT =======\n");
                        printf("1. Sort by Name\n");
                        printf("2. Sort by Year\n");
                        printf("3. Sort by Author\n");
                        printf("4. Sort by Genre\n");
                        printf("5. Back\n");
                        printf("===================\n");

                        printf("Option: ");
                        user_input = readInt(1,5);

                        SD loc_direction = SD::None;
                        if (user_input != 5){
                            printf("\nChoose direction (Up - 1 / Down - 0): ");
                            int int_dir = readInt(0,1);

                            if (int_dir == 1){
                                loc_direction = SD::Up;
                            }
                            else{
                                loc_direction = SD::Down;
                            }
                        }

                        if (user_input == 1){
                            A.sortByName(loc_direction);
                        }
                        else if (user_input == 2){
                            A.sortByYear(loc_direction);
                        }
                        else if (user_input == 3){
                            A.sortByAuthor(loc_direction);
                        }
                        else if (user_input == 4){
                            A.sortByGenre(loc_direction);
                        }
                        else{
                            break;
                        }
                    }
                }
                else{
                    break;
                }
            }
        }
        else if (user_input == 3){
            while (true){
                printf("\n===== Method ======\n");
                printf("1. From file\n");
                printf("2. Manully\n");
                printf("3. Back");

                printf("\n===================\n");
                printf("Option: ");
                user_input = readInt(1,3);

                if (user_input == 1){
                    printf("\n==== New Book =====\n");
                    printf("Enter file name: ");
                    const char* buffer_location = readLine();
                    bool adding_res = readBooks(A.getStructRef(), buffer_location);
                    if (!adding_res){
                        printf("\nAn error occured, while adding. Check file or try another location\n");
                    }

                }
                else if (user_input == 2){
                    Book object;
                    printf("\n==== New Book =====\n");
                    object.edit_all();
                    while (true){
                        printf("\n1. Save\n2. Refill\n3. Cancel\n");
                        printf("Option: ");
                        user_input = readInt(1,3);
                        if (user_input == 1){
                            A.getStructRef().add(object);
                            break;
                        }
                        else if (user_input == 2){
                            object.edit_all();
                        }
                        else{
                            break;
                        }
                    }

                }
                else{
                    break;
                }
            }
        }
        else if (user_input == 4) {
            while (true){
                printf("\n===== Delete ======\n");
                printf("1. Delete by index\n");
                printf("2. Delete all\n");
                printf("3. Back\n");

                printf("\n===================\n");
                printf("Option: ");
                user_input = readInt(1,3);

                if (user_input == 1){
                    printf("\n===================\n");
                    printf("There are %lu books:", A.getStructRef().get_amount());
                    for (size_t k = 0; k < A.getStructRef().get_amount(); k++){
                        printf("\n%lu. %s", k+1, A.pop(k).get_name());
                    }
                    printf("\n===================\n");
                    printf("\nEnter book index: ");
                    index = readInt(0, A.getStructRef().get_amount());

                    printf("Are you sure you want to delete book №%lu ?\n", index);
                    printf("Answer (y - 1 / n - 0): ");
                    user_input = readInt(0,1);
                    if (user_input == 1){
                        A.getStructRef().delete_by_index(index-1);
                    }
                    printf("\nBook №%lu deleted succeffully\n", index);


                }
                else if (user_input == 2){
                    printf("\nAre you sure? (y - 1 / n - 0): ");
                    user_input = readInt(0,1);

                    if (user_input == 1){
                        printf("\nTo delete all books, enter \"I want to delete all books\"\nAnswer: ");
                        char* answer = readLine();
                        if (compare(answer, "I want to delete all books") == 0){
                            A.getStructRef().clear();
                            if (A.getStructRef().get_amount() == 0){
                                printf("All books deleted succsfully!\n");
                            }
                        }
                        else{
                            printf("\nIncorect answer. Books wont be deleted!\n");
                        }
                    }
                }
                else{
                    break;
                }
            }
        }
        else{
            break;
        }
    }
    return true;
}
