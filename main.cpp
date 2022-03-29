#include <iostream>
#include <vector>
#include<map>
#include<algorithm>


class Post {
    int no_likes;
    int no_comments;
    std::vector<std::string> hashtags;
    std::string theme;
public:
    // Constructor de Initiere
    Post(int noLikes, int noComments, const std::vector<std::string> &hashtags, const std::string &theme) : no_likes(
            noLikes), no_comments(noComments), hashtags(hashtags), theme(theme) {}

    // Operator ==(de egalitate)
    bool operator==(const Post &postare) const {
        return (no_likes == postare.no_likes) &&
               (no_comments == postare.no_comments) &&
               (hashtags == postare.hashtags) &&
               (theme == postare.theme);
    }

    bool operator<(const Post &other) const {
        if (no_likes == other.no_likes) {
            return no_comments < other.no_comments;
        } else {
            return no_likes < other.no_likes;
        }
    }

    // Operator =
    Post &operator=(const Post &other) {
        no_likes = other.no_likes;
        no_comments = other.no_comments;
        theme = other.theme;
        std::copy(other.hashtags.begin(), other.hashtags.end(), hashtags.begin());
//        hashtags.clear();
//        for (std::string hashtag : other.hashtags) {
//            hashtags.push_back(hashtag);
//        }
        return *this;
    }

    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Post &post) {
        os << "no_likes: " << post.no_likes << ", no_comments: " << post.no_comments
           << ", theme: " << post.theme;
        os << "\n hashtags: ";
        for (std::string hashtag : post.hashtags) {
            os << hashtag << " ";
        }
        return os;
    }

    // Constructor Copiere
    Post(const Post &other) : no_likes{other.no_likes}, no_comments{other.no_comments}, hashtags{other.hashtags},
                              theme{other.theme} {}

    // Destructor
    ~Post() {}

    //setter
    void increment_no_likes() {
        ++this->no_likes;
    }

//
    void decrement_no_likes() {
        --this->no_likes;
    }

    void add_hashtag(std::string hashtag) {
        this->hashtags.push_back(hashtag);
    }

    void change_theme(std::string const &new_theme) {
        this->theme = new_theme;
    }

    //getter
    int get_likes() {
        return this->no_likes;
    }

    std::vector<std::string> get_hashtags() {
        return this->hashtags;
    }

    std::string get_theme() {
        return this->theme;
    }

};

class Account {
    std::string username;
    int followers;
    int following;
    std::string target_audience;
    std::vector<Post> posts;
    std::map<Post *, bool> likes;

public:
    // Constructor de Initiere
    Account(const std::string &username, int followers, int following, const std::string &targetAudience,
            std::vector<Post> &posts) : username(username), followers(followers), following(following),
                                        target_audience(targetAudience), posts(posts) {}

//    // Operator =
//    Account &operator=(const Account &other) {
//        username = other.username;
//        followers = other.followers;
//        following = other.following;
//        target_audience = other.target_audience;
//
//        std::copy(other.posts.begin(), other.posts.end(), posts.begin());
//        return *this;
//    }

    // Operator == (de egalitate)
    bool operator==(const Account &cont) const {
        return username == cont.username &&
               followers == cont.followers &&
               following == cont.following &&
               target_audience == cont.target_audience &&
               posts == cont.posts;
    }

    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Account &account) {
        os << "username: " << account.username << ", followers: " << account.followers << ", following: "
           << account.following << ", no_posts: " << account.posts.size() << ", target_audience: "
           << account.target_audience
           << "\n posts:\n " ;
        int i = 1;
        for(const auto& postare: account.posts) {

            std::cout << "postare " << i << " : " << postare << '\n';
            i++;
        }
        return os;
    }

    // Destructor
    ~Account() {}

    //setters
    void do_like(Post *post_u) {
        if (likes.count(post_u)) {
            return;
        }
        this->likes.insert(std::pair<Post *, bool>(post_u, true));
        post_u->increment_no_likes();
    }

    void do_unlike(Post *post_u) {
        if (!likes.count(post_u)) {
            return;
        }
        auto it = likes.find(post_u);
        likes.erase(it);
        post_u->decrement_no_likes();
    }

    void parcurgere_likes() {
        std::map<Post *, bool>::iterator it = likes.begin();
        for (; it != likes.end(); it++) {
            std::cout << *it->first << " :: " << it->second << std::endl;
        }
    }

    void new_follower() {
        ++this->followers;
    }

    void new_following() {
        ++this->following;
    }

    void add_post(Post postare) {
        this->posts.push_back(postare);
    }

    void change_audience(std::string const &new_target) {
        this->target_audience = new_target;
    }

    //getters
    std::string get_username() {
        return this->username;
    }

    int get_followers() {
        return this->followers;
    }

    int get_following() {
        return this->following;
    }

    void get_posts() {
        for (Post post : this->posts) {
            std::cout << post << " ";
        }
    }

    Post get_top_post() {
        std::vector<Post> copy_posts;
        copy_posts = this->posts;

        sort(copy_posts.begin(), copy_posts.end(), [](Post lhs, Post rhs) {
            return lhs.get_likes() > rhs.get_likes();
        });
        return copy_posts[0];
    }

    std::string get_audience() {
        return this->target_audience;
    }

    // find

    Post find_post_by_theme(const std::string &searched_theme) {
        auto it = std::find_if(this->posts.begin(), this->posts.end(), [searched_theme](Post post) {
            return post.get_theme() == searched_theme;
        });
        return *it;
    }

};

class Manager {
    std::string name;
    std::vector<Account> accounts;
public:
    //Constructor de Initiere
    Manager(const std::string &name, const std::vector<Account> &accounts) : name(name), accounts(accounts) {}

    //Operator == (de egalitate)
    bool operator==(const Manager &mg) const {
        return name == mg.name &&
               accounts == mg.accounts;
    }

    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Manager &manager) {
        os << "name: " << manager.name << "\naccounts: \n";
        int i = 1;
        for (const auto &conturi: manager.accounts) {
            std::cout << "contul " << i << " : " << conturi << '\n';
            i++;
        }
        return os;
    }
    // Destructor
    ~Manager() {}

    //setters
    void change_name(std::string const& new_name){
        this->name = new_name;
    }

    void add_account(Account new_account) {
        this->accounts.push_back(new_account);
    }

    //getters
    std::string get_name() {
        return this->name;
    }

    Account get_top_account() {
        std::vector<Account> copy_accounts;
        copy_accounts = this->accounts;

        sort(copy_accounts.begin(), copy_accounts.end(), [](Account lhs, Account rhs) {
            return lhs.get_followers() > rhs.get_followers();
        });
        return copy_accounts[0];
    }

    // find account by username
    Account find_account_by_username(const std::string &searched_username) {
        auto it = std::find_if(this->accounts.begin(), this->accounts.end(), [searched_username](Account account) {
            return account.get_username() == searched_username;
        });
        return *it;
    }

};
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
    cont1.parcurgere_likes();
    std::cout << postari[0];

//    std::cout << cont1.get_top_post() << "\n";
//    std::cout << man.get_top_account() << "\n";
//    std::cout << cont1.find_post_by_theme("crypto");
//    std::cout << man.find_account_by_username("jack_sparrow");
//    Post post2{150, 345, {"crypto", "btc", "eth"}, "crypto"};
//
//    post2 = postari[1];
//    std::cout << post2;
//    // Functionalitati postare
////    postari[0].do_like();
//    std::cout << postari[0].get_likes() << std::endl;
////    postari[0].do_unlike();
//    std::cout << postari[0].get_likes() << std::endl;
//
//    for (std::string hashtag : postari[0].get_hashtags()) {
//        std::cout << hashtag << " ";
//    }
//    std::cout << cont1;
//    std::cout << '\n';
//    postari[0].add_hashtag("newww");
//    postari[0].get_hashtags();
//    std::cout << '\n';
//
//    std::cout << postari[1].get_theme() << std::endl;
//    postari[1].change_theme("hollywood");
//    std::cout << postari[1].get_theme() << std::endl;
////
////
////    // Functionalitati cont
//    std::cout << cont1;
//    cont1.add_post(Post{150, 345, {"food", "kitchen", "healthy"}, "cooking"});
//    cont1.get_posts();
////
//    std::cout << cont1.get_followers() << std::endl;
//    std::cout << cont1.get_following() << std::endl;
//    cont1.new_follower();
//    cont1.new_following();
//    std::cout << cont1.get_followers() << std::endl;
//    std::cout << cont1.get_following() << std::endl;
////
//    std::cout << cont1.get_audience() << std::endl;
//    cont1.change_audience("girls");
//    std::cout << cont1.get_audience() << std::endl;
////
////    // Functionalitati manager
//    std::cout << man.get_name();
//    man.change_name("Jane Smith");
//    man.add_account(Account{"john.not", 100, 1000, "teenagers", postari});
//    std::cout << man;

}