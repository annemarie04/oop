#include <iostream>
#include <vector>
#include<algorithm>
#include <cstring>
#include "Account.h"
#include "Manager.h"
#include "my_exceptie.h"

void create_feed(std::shared_ptr<Account> a, int b, int c, int s) {
    for (auto post : a->getPosts()) {
        if (dynamic_cast<Photo *>(post.get())) {
            Photo *p = dynamic_cast<Photo *>(post.get());
            p->edit_photo(b, c, s);
        }
    }
}


int main() {

    std::cout << "APP STARTED:\n";

    Photo p1(0, 0, {"food", "organic", "vegan"}, "healthy food", 20, 10, 38, "Sienna", "pic1.jpg");
    Photo p2(0, 0, {"toy", "wood", "fun"}, "old_school toys", 50, 60, 18, "clarendon", "pic2.jpg");
    Live l1(0, 0, {"gaming", "player"}, "gaming", 45, 17, 18);
    Live l2(0, 0, {"make-up", "lip stick"}, "make-up tutorial", 10, 12, 15);
    Check_in c1(0, 0, {"latte", "cappuccino"}, "coffee shops", "Forma Cafe", "Bucharest", "Romania");
    Check_in c2(0, 0, {"burger", "lunch"}, "fast food", "Burger King", "Bucharest", "Romania");
    std::shared_ptr<Account> acc1 = std::make_shared<Account>(Account("jane.doe", 0, 0, "children"));
    acc1->add_photo(p1);
    acc1->add_check_in(c1);
    acc1->add_live(l1);
    std::shared_ptr<Account> acc2 = std::make_shared<Account>(Account("jim.carry", 0, 0, "teenagers"));
    std::shared_ptr<Account> acc3 = std::make_shared<Account>(Account("jon_snow", 0, 0, "teenagers"));
//    acc2->add_photo(p2);
    acc2->add_check_in(c2);
    acc2->add_live(l2);

    std::shared_ptr<Manager> m1 = std::make_shared<Manager>(Manager("Ioana"));
    std::shared_ptr<Manager> m2 = std::make_shared<Manager>(Manager("Dorel"));
    try {
        acc1->do_like(2);
        acc1->do_unlike(1);
        acc1->new_following();
        acc1->new_follower();
        acc2->change_audience("mothers");
        std::cout << acc2->get_following();
        acc2->show_post(1);
        std::cout << acc2->get_audience();
        acc2->show_my_likes();
        acc2->show_posts();
        acc2->sort_posts_by_likes();
        std::cout << acc2->find_post_by_theme("old_school toys");
        acc1->share(1, acc2);
        acc1->show_shared();
        acc1->pin_post(1);
        acc1->delete_pin();
    } catch (my_exceptie &err) {
        std::cout << err.what();
    }

    m1->add_account(acc1);
    m1->add_account(acc2);
    m2->add_account(acc3);
    m1->change_name("george");
    std::cout << m1->get_name();
    std::cout << *m1->get_top_account();
    std::cout << *m1->find_account_by_username("jane.doe");
    m1->swap_accounts(m2, 0, 0);

    std::cout << p1.scor_relevanta();
    p1.setNoComments(4);
//    acc1->get_posts();
//
//    create_feed(acc1, 10, 20, 30);
//    acc1->get_posts();

//    std::cout << a3;
//    std::cout << "-------------------------------------------/n";
//    Account a1("a1",0, 0, "ceva"), a2("a2",0, 0, "altceva");
//    a1.add_photo(p1);
//    a2.add_photo(p2);
//    Account a3{a2};
//    Account a3 = a1;
//
//    std::cout << a3;
//    std::cout << a1 << a2; // post 1 post 2
//    a1 = a2;
//    std::cout << a1 << a2; // post 2 post 2
//    a2.get_post(2).update("Post 2");
//    std::cout << a1 << a2; // Post 2 Post 2
/*
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

            Photo photo(0, 0, hashtags, theme, brightness, contrast, saturation, filter, file_path);
            accounts[account_selected].add_photo(photo);
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

            Check_in check_in(0, 0, hashtags, theme, adress, city, country);
            accounts[account_selected].add_check_in(check_in);
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

            Live live(0, 0, hashtags, theme, people_watching, starting_time, ending_time);
            accounts[account_selected].add_live(live);
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
        if (strcmp(input, "SORT_POSTS_BY_LIKES") == 0) {
            if (account_selected == -1) {
                std::cout << "\nNu ai selectat niciun cont.\n";
                continue;
            }
            accounts[account_selected].sort_posts_by_likes();
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
    */
}