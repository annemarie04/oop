#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
#include "Post.h"
#include "Account.h"
#include "Manager.h"

int main() {
    std::vector<Post> postari{Post{170, 345, {"crypto", "btc", "eth"}, "crypto"},
                              Post{151, 345, {"sport", "food", "travel"}, "lifestyle"},
                              Post{181, 345, {"sport", "food", "travel"}, "lifestyle"},
                              Post{251, 345, {"sport", "food", "travel"}, "lifestyle"},
                              Post{351, 345, {"sport", "food", "travel"}, "lifestyle"},
                              Post{551, 345, {"sport", "food", "travel"}, "lifestyle"},
                              Post{123, 444, {"ceva", "ceva", "ceva"}, "ceva"}};
    Account cont1{"jane.doe12", 125, 789, "children", postari};
    Account cont2{"harry.potter", 2235, 789, "children", postari};
    Account cont3{"batman", 345, 789, "children", postari};
    Account cont4{"dune34", 85, 789, "children", postari};
    Account cont5{"jack_sparrow", 1345, 789, "children", postari};
    Manager man{"John Smith", {cont1, cont2, cont3, cont4, cont5}};

    cont1.do_like(&postari[0]);
    cont1.do_like(&postari[1]);
    cont1.do_like(&postari[1]);
    cont1.do_like(&postari[4]);
    cont1.do_like(&postari[0]);
    cont2.do_like(&postari[0]);
    cont1.do_unlike(&postari[0]);
//    cont1.parcurgere_likes();
    std::cout << postari[0];

    std::cout << cont1.get_top_post() << "\n";
    std::cout << man.get_top_account() << "\n";
    std::cout << cont1.find_post_by_theme("crypto");
    std::cout << man.Manager::find_account_by_username("jack_sparrow");
    Post post2{150, 345, {"crypto", "btc", "eth"}, "crypto"};

    post2 = postari[1];
    std::cout << post2;
    // Functionalitati postare
//    postari[0].do_like();
    std::cout << postari[0].get_likes() << std::endl;
//    postari[0].do_unlike();
    std::cout << postari[0].get_likes() << std::endl;

    for (std::string hashtag : postari[0].get_hashtags()) {
        std::cout << hashtag << " ";
    }

    std::cout << cont1;
    std::cout << '\n';
    postari[0].add_hashtag("newww");
    postari[0].Post::get_hashtags();
    std::cout << '\n';

    std::cout << postari[1].get_theme() << std::endl;
    postari[1].change_theme("hollywood");
    std::cout << postari[1].get_theme() << std::endl;
//
//
//    // Functionalitati cont
    std::cout << cont1;
    cont1.add_post(Post{150, 345, {"food", "kitchen", "healthy"}, "cooking"});
    cont1.get_posts();
//
    std::cout << cont1.Account::get_followers() << std::endl;
    std::cout << cont1.Account::get_following() << std::endl;
    cont1.new_follower();
    cont1.new_following();
    std::cout << cont1.get_followers() << std::endl;
    std::cout << cont1.get_following() << std::endl;
//
    std::cout << cont1.Account::get_audience() << std::endl;
    cont1.Account::change_audience("girls");
    std::cout << cont1.Account::get_audience() << std::endl;
//
//    // Functionalitati manager
    std::cout << man.Manager::get_name();
    man.Manager::change_name("Jane Smith");
    man.Manager::add_account(Account{"john.not", 100, 1000, "teenagers", postari});
    std::cout << man;

}