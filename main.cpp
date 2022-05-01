#include <iostream>
#include <vector>
#include<algorithm>
#include <cstring>
#include "Account.h"
#include "Manager.h"

int main() {

    std::vector<Account> accounts;
    std::vector<Manager> managers;
    // date de intrare
//    Account account = Account{"john_doe", 0, 0, "Crypto"};
//    accounts.push_back(account);
//    Account account2 = Account{"idk_username", 0, 0, "Teenagers"};
//    accounts.push_back(account2);
//
//    accounts[0].add_photo({"BTC", "ETH", "DEFI"}, "Crypto", 50,
//                          40, 38, "Sepia", "poza1.jpeg");
//    accounts[0].add_photo({"food", "lifestyle", "vegan"}, "food", 40,
//                          40, 30, "Sepia", "poza2.jpeg");
//    accounts[0].add_photo({"sport", "workout", "outfit"}, "workout", 0,
//                          0, 0, "Sepia", "poza3.jpeg");
//    accounts[0].add_photo({"strong", "gym", "tennis"}, "workout", 0,
//                          0, 0, "Sepia", "poza4.jpeg");
//    accounts[0].add_photo({"business", "money", "invest"}, "investing", 10,
//                          20, 20, "Sepia", "poza5.jpeg");
//    accounts[0].add_photo({"fashionable", "outfit", "pink"}, "fashion", 50,
//                          90, 87, "Sepia", "poza5.jpeg");
//    accounts[0].add_photo({"make-up", "colors", "lipstick"}, "make-up", 50,
//                          40, 38, "Sepia", "poza6.jpeg");
//
//    accounts[0].do_like(0);
//    accounts[0].do_like(1);
//    accounts[0].do_like(1);
//
//
//    Manager manager1 = Manager{"Dorian"};
//    Manager manager2 = Manager{"Simona"};
//    managers.push_back(manager1);
//    managers.push_back(manager2);
//    managers[0].add_account(accounts[0]);
//    managers[1].add_account(accounts[1]);
//    managers[0].swap_accounts(managers[1], 0, 0);


    std::cout << "APP STARTED:\n";

    char input[100];
    int input_index = 0;
    int input_index2 = 0;
    int account_selected = -1;
    int second_account = -1;
    int manager_selected = -1;
    int second_manager = -1;


    while (true) {
        std::cin.getline(input, 100);
        if (strcmp(input, "ADD_ACCOUNT") == 0) {
            // input
            std::string username, targetAudience;
            int following, followers;
            std::cout << "\nUsername: ";
            std::cin >> username;
            std::cout << "\nFollowers: ";
            std::cin >> followers;
            std::cout << "\nFollowing: ";
            std::cin >> following;
            std::cout << "\nTarget Audience: ";
            std::cin >> targetAudience;

            Account cont(username, followers, following, targetAudience);
            accounts.push_back(cont);
        }
        if (strcmp(input, "SHOW_ACCOUNTS") == 0) {
            int l_index = 0;
            for (auto &acc: accounts) {
                std::cout << "Cont ID: " << l_index << "\n\t" << acc << "\n";
                l_index++;
            }
        }
        if (strcmp(input, "SELECT_MY_ACCOUNT") == 0) {
            // input id
            std::cout << "\nID CONT: ";
            std::cin >> account_selected;
            std::cout << "\nCont selectat!\n";
        }
        if (strcmp(input, "ADD_FOLLOWER") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            accounts[account_selected].new_follower();

        }
        if (strcmp(input, "CHANGE_AUDIENCE") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::string new_audience;
            std::cout << "\nAudienta noua: ";
            std::cin >> new_audience;
            accounts[account_selected].change_audience(new_audience);
        }
        if (strcmp(input, "ADD_FOLLOWING") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            accounts[account_selected].new_following();
        }
        if (strcmp(input, "SHOW_MY_USERNAME") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::cout << accounts[account_selected].get_username();
        }
        if (strcmp(input, "SHOW_MY_FOLLOWERS") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::cout << accounts[account_selected].get_followers();
        }
        if (strcmp(input, "SHOW_MY_FOLLOWING") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::cout << accounts[account_selected].get_following();
        }
        if (strcmp(input, "SHOW_MY_AUDIENCE") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::cout << accounts[account_selected].get_audience();
        }

        // _------------___----__--__-___ POST ____---____--_-_-_-
        if (strcmp(input, "ADD_PHOTO") == 0) {
            std::vector<std::string> hashtags;
            std::string hashtag, theme, filter, file_path;
            int brightness, contrast, saturation;
            std::cout << "\nIntroduceti 3 hashtaguri.";
            for (int i = 1; i <= 3; i++) {
                std::cout << "\nHashtag " << i << ": ";
                std::cin >> hashtag;
                hashtags.push_back(hashtag);
            }
            std::cout << "\nTheme: ";
            std::cin >> theme;
            std::cout << "\nBrightness: ";
            std::cin >> brightness;
            std::cout << "\nContrast: ";
            std::cin >> contrast;
            std::cout << "\nSaturation: ";
            std::cin >> saturation;
            std::cout << "\nFilter: ";
            std::cin >> filter;
            std::cout << "\nFile name: ";
            std::cin >> file_path;
            accounts[account_selected].add_photo(hashtags, theme, brightness, contrast, saturation, filter, file_path);
        }
        if (strcmp(input, "ADD_CHECK_IN") == 0) {
            std::vector<std::string> hashtags;
            std::string hashtag, theme, adress, city, country;
            std::cout << "\nIntroduceti 3 hashtaguri.";
            for (int i = 1; i <= 3; i++) {
                std::cout << "\nHashtag " << i << ": ";
                std::cin >> hashtag;
                hashtags.push_back(hashtag);
            }
            std::cout << "\nTheme: ";
            std::cin >> theme;
            std::cout << "\nAdress: ";
            std::cin >> adress;
            std::cout << "\nCity: ";
            std::cin >> city;
            std::cout << "\nCountry: ";
            std::cin >> country;

            accounts[account_selected].add_check_in(hashtags, theme, adress, city, country);
        }
        if (strcmp(input, "ADD_LIVE") == 0) {
            std::vector<std::string> hashtags;
            std::string hashtag, theme;
            int starting_time, ending_time, people_watching;
            std::cout << "\nIntroduceti 3 hashtaguri.";
            for (int i = 1; i <= 3; i++) {
                std::cout << "\nHashtag " << i << ": ";
                std::cin >> hashtag;
                hashtags.push_back(hashtag);
            }
            std::cout << "\nTheme: ";
            std::cin >> theme;
            std::cout << "\nNumber of people watching: ";
            std::cin >> people_watching;
            std::cout << "\nStarting time: ";
            std::cin >> starting_time;
            std::cout << "\nEnding time: ";
            std::cin >> ending_time;

            accounts[account_selected].add_live(hashtags, theme, people_watching, starting_time, ending_time);
        }
        if (strcmp(input, "LIKE_MY_POST") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::cout << "\nPost ID: ";
            std::cin >> input_index;
            accounts[account_selected].do_like(input_index);
        }
        if (strcmp(input, "UNLIKE_MY_POST") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::cout << "\nPost ID: ";
            std::cin >> input_index;
            accounts[account_selected].do_unlike(input_index);
        }
        if (strcmp(input, "GET_MY_TOP_POST") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            accounts[account_selected].get_top_post();
        }
        if (strcmp(input, "FIND_POST_BY_THEME") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::string searched_theme;
            std::cout << "\nTema cautata: ";
            std::cin >> searched_theme;
            accounts[account_selected].find_post_by_theme(searched_theme);
        }
        if (strcmp(input, "GET_MY_POST") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::cout << "\nID Postare: ";
            std::cin >> input_index;
            accounts[account_selected].get_post(input_index);
        }
        if (strcmp(input, "GET_MY_POSTS") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            accounts[account_selected].get_posts();
        }
        if (strcmp(input, "SHOW_MY_LIKES") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            accounts[account_selected].show_my_likes();
        }

        if (strcmp(input, "SELECT_SECOND_ACCOUNT") == 0) {
            std::cout << "\nID CONT: ";
            std::cin >> second_account;
            std::cout << "\nAl doilea cont a fost selectat!\n";
        }
        if (strcmp(input, "GET_POST") == 0) {
            if (second_account == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::cout << "\nID Postare: ";
            std::cin >> input_index;
            accounts[second_account].get_post(input_index);
        }
        if (strcmp(input, "GET_POSTS") == 0) {
            if (second_account == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            accounts[second_account].get_posts();
        }

        if (strcmp(input, "SHARE_POST") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            if (second_account == -1) {
                std::cout << "\nNu ai selectat un al doilea cont.\n";
                continue;
            }
            std::cout << "\nID Postare: ";
            std::cin >> input_index;
            accounts[account_selected].share(input_index, &accounts[second_account]);
            std::cout << "Post shared!";
        }
        if (strcmp(input, "MY_SHARED_POSTS") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            accounts[account_selected].show_shared();
        }

        if (strcmp(input, "PIN_POST") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::cout << "\nID Postare: ";
            std::cin >> input_index;
            accounts[account_selected].pin_post(input_index);
            std::cout << "\nPost pinned!\n";
        }
        if (strcmp(input, "DELETE_PIN") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            accounts[account_selected].delete_pin();
            std::cout << "\nPin deleted.\n";
        }
        if (strcmp(input, "SHOW_PIN") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            accounts[account_selected].show_pin();
        }
//-------------------MANAGER-------------------------------------

        if (strcmp(input, "ADD_MANAGER") == 0) {
            // input
            std::string name;
            std::cout << "\nName: ";
            std::cin >> name;
            Manager manager(name);
            managers.push_back(manager);
            std::cout << "\nManager adaugat!\n";
        }
        if (strcmp(input, "SHOW_MANAGERS") == 0) {
            int l_index = 0;
            for (auto &man: managers) {
                std::cout << "Manager ID: " << l_index << "\n\t" << man << "\n";
                l_index++;
            }
        }
        if (strcmp(input, "SELECT_MANAGER") == 0) {
            std::cout << "\nID Manager: ";
            std::cin >> manager_selected;
            std::cout << "\nManager selectat!\n";
        }
        if (strcmp(input, "CHANGE_MANAGER_NAME") == 0) {
            if (manager_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::string new_name;
            std::cout << "\nNume nou: ";
            std::cin >> new_name;
            managers[manager_selected].change_name(new_name);
        }
        if (strcmp(input, "ADD_ACCOUNT_TO_MANAGER") == 0) {
            if (manager_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::cout << "\nID cont: ";
            std::cin >> input_index;
            managers[manager_selected].add_account(accounts[input_index]);
        }
        if (strcmp(input, "GET_MANAGER_NAME") == 0) {
            if (manager_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::cout << managers[manager_selected].get_name();
        }
        if (strcmp(input, "GET_TOP_ACCOUNT") == 0) {
            if (manager_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            managers[manager_selected].get_top_account();
        }
        if (strcmp(input, "FIND_ACCOUNT_BY_USERNAME") == 0) {
            if (manager_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::string username;
            std::cout << "\nUsername cont: ";
            std::cin >> username;
            managers[manager_selected].find_account_by_username(username);
        }
        if (strcmp(input, "SWAP_ACCOUNTS") == 0) {
            if (manager_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            std::cout << "Second manager ID:";
            std::cin >> second_manager;
            std::cout << "Account 1 ID:";
            std::cin >> input_index;
            std::cout << "Account 2 ID:";
            std::cin >> input_index2;
            managers[manager_selected].swap_accounts(managers[second_manager], input_index, input_index2);
            std::cout << "\nAccounts swapped!\n";

        }
        if (strcmp(input, "EXIT") == 0) {
            break;
        }

    }

    return 0;
}