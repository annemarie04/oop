#include <iostream>
#include "Account.h"
#include "Manager.h"
#include "my_exceptie.h"
#include "Photo_builder.h"
#include "Live_builder.h"
#include "Checkin_builder.h"

void edit_feed(const std::shared_ptr<Account> &a, int b, const int c, const int s) {
    for (const auto &post: a->getPosts()) {
        if (dynamic_cast<Photo *>(post.get())) {
            auto *p = dynamic_cast<Photo *>(post.get());
            p->edit_photo(b, c, s);
        }
    }
}


int main() {
    try {

        Photo_builder photo_builder;
        Live_builder live_builder;
        Checkin_builder checkin_builder;
        Photo p1 = photo_builder
                .likes(0)
                .comments(0)
                .hashtags({"food", "organic", "vegan"})
                .theme("healthy food")
                .contrast(20)
                .saturation(10)
                .brightness(38)
                .filter("Sienna")
                .file_path("img1.jpg")
                .build();
        Photo p2 = photo_builder
                .likes(12)
                .comments(10)
                .hashtags({"toy", "wood", "fun"})
                .theme("old_school toys")
                .saturation(50)
                .contrast(50)
                .brightness(18)
                .filter("clarendon")
                .file_path("pic2.jpg")
                .build();
        Live l1 = live_builder
                .hashtags({"gaming", "player"})
                .theme("gaming")
                .people_watching(45)
                .starting_time(17)
                .ending_time(18)
                .build();
        Live l2 = live_builder
                .likes(100)
                .comments(52)
                .hashtags({"make-up", "lip stick"})
                .theme("make-up tutorial")
                .people_watching(10)
                .starting_time(12)
                .ending_time(15)
                .build();
        Check_in c1 = checkin_builder
                .likes(30)
                .comments(12)
                .hashtags({"burger", "lunch"})
                .theme("fast food")
                .adress("Burger King")
                .city("Bucharest")
                .country("Romania")
                .build();
        Check_in c2 = checkin_builder
                .likes(19)
                .comments(32)
                .hashtags({"latte", "cappuccino"})
                .theme("coffee shops")
                .adress("Forma Cafe")
                .city("Bucharest")
                .country("Romania")
                .build();


        std::shared_ptr<Account> acc1 = std::make_shared<Account>(Account("jane.doe", 1, 1, "none"));
        std::shared_ptr<Account> acc2 = std::make_shared<Account>(Account("kim_joe", 100, 100, "children"));
        std::shared_ptr<Account> acc3 = std::make_shared<Account>(Account("bella_", 250000, 12, "fashion"));
        std::shared_ptr<Account> acc4 = std::make_shared<Account>(Account("travel_", 213214, 2134, "travel"));


        std::shared_ptr<Manager<int>> m1 = std::make_shared<Manager<int>>(Manager<int>("Ioana", 771018));
        std::shared_ptr<Manager<std::string>> m2 = std::make_shared<Manager<std::string>>(
                Manager<std::string>("Richard", "Richard@invmarketing.com"));
        std::shared_ptr<Manager<std::string>> m3 = std::make_shared<Manager<std::string>>(
                Manager<std::string>("Cosmin", "Cosmin@gmail.com"));


        m1->add_account(acc1);
        m1->add_account(acc4);
        m2->add_account(acc2);
        m3->add_account(acc3);
        acc1->add_photo(p1);
        acc1->add_check_in(c1);
        acc1->add_live(l1);

        acc2->add_check_in(c2);
        acc2->add_live(l2);

        m1->change_name("george");
        acc1->do_like(1);
        acc1->do_unlike(1);
        acc1->new_following();
        acc1->new_follower();
        acc2->change_audience("mothers");
//        std::cout << acc2->get_following() << "\n";
        acc2->show_post(1);
        std::cout << acc2->get_audience() << "\n";
        acc2->show_my_likes();
        acc2->show_posts();
        acc2->sort_posts_by_likes();
        std::cout << *acc2->find_post_by_theme("coffee shops") << "\n";
        acc1->share(1, acc2);
        acc1->show_shared();
        acc1->pin_post(1);
        acc1->delete_pin();
        std::cout << acc1->get_following() << "\n";
        std::cout << acc1->get_followers() << "\n";
        std::cout << acc1->get_audience() << "\n";

        edit_feed(acc1, 10, 20, 30);

        std::cout << m1->get_name() << "\n";
        std::cout << *m1->get_top_account() << "\n";
        std::cout << *m1->find_account_by_username("jane.doe") << "\n";
        m2->swap_accounts(m3, 0, 0);

        std::cout << p1.scor_relevanta() << "\n";
        p1.setNoComments(4);
        std::cout << p1.getBrightness() << "\n";
        std::cout << p1.getContrast() << "\n";
        std::cout << p1.getSaturation() << "\n";
        p1.setFilePath("this_pic.idk");
        p1.setFilter("clarendon");
        std::cout << p1.getFilePath() << "\n";
        std::cout << p1.getFilter() << "\n";
        m2->changeContact("Richard_Morison");
        std::cout << m2->getContact() << "\n";
    } catch (my_exceptie &err) {
        std::cout << err.what();
    }

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