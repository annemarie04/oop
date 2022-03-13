#include <iostream>
#include <vector>


class Post {
    int no_likes;
    int no_comments;
    std::vector<std::string> hashtags;
    std::string theme;
public:
    // Constructor de Initiere
    Post(int noLikes, int noComments, const std::vector<std::string> &hashtags, const std::string &theme) : no_likes(
            noLikes), no_comments(noComments), hashtags(hashtags), theme(theme) {}

    // Operator =
    bool operator==(const Post &postare) const {
        return no_likes == postare.no_likes &&
               no_comments == postare.no_comments &&
               hashtags == postare.hashtags &&
               theme == postare.theme;
    }

    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Post& post) {
        os << "no_likes: " << post.no_likes << ", no_comments: " << post.no_comments
           << ", theme: " << post.theme;
        os << "\n hashtags: ";
        for (std::string hashtag : post.hashtags ){
            os << hashtag << " ";
        }
        return os;
    }
    // Constructor Copiere
    Post(const Post& other) : no_likes{other.no_likes}, no_comments{other.no_comments}, hashtags{other.hashtags}, theme{other.theme} {}

    // Destructor
    ~Post() {}

    //setter
    void do_like(){
        ++this->no_likes;
    }

    void do_unlike(){
        --this->no_likes;
    }

    void add_hashtag(std::string hashtag){
        this->hashtags.push_back(hashtag);
    }

    void change_theme(std::string const& new_theme){
        this->theme = new_theme;
    }

    //getter
    int get_likes(){
        return this->no_likes;
    }

    void get_hashtags(){
        for (std::string hashtag : this->hashtags){
            std::cout << hashtag << " ";
        }
    }

    std::string get_theme(){
        return this->theme;
    }

};

class Account {
    std::string username;
    int followers;
    int following;
    int no_posts;
    std::string target_audience;
    std::vector<Post> posts;

public:
    // Constructor de Initiere
    Account(const std::string &username, int followers, int following, int noPosts, const std::string &targetAudience,
             std::vector<Post> &posts) : username(username), followers(followers), following(following),
                                              no_posts(noPosts), target_audience(targetAudience), posts(posts) {}

    // Operator =
    bool operator==(const Account &cont) const {
        return username == cont.username &&
               followers == cont.followers &&
               following == cont.following &&
               no_posts == cont.no_posts &&
               target_audience == cont.target_audience &&
               posts == cont.posts;
    }
    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Account& account) {
        os << "username: " << account.username << ", followers: " << account.followers << ", following: "
           << account.following << ", no_posts: " << account.no_posts << ", target_audience: " << account.target_audience
           << "\n posts:\n " ;
        int i = 1;
        for(const auto& postare: account.posts) {

            std::cout << "postare " << i <<" : "<< postare << '\n';
            i++;
        }
        return os;
    }
    // Destructor
    ~Account() {}

    //setters
    void new_follower() {
        ++this->followers;
    }

    void new_following() {
        ++this->following;
    }

    void add_post(Post postare) {
        this->posts.push_back(postare);
        ++this->no_posts;
    }

    void change_audience(std::string const& new_target) {
        this->target_audience = new_target;
    }

    //getters
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

    std::string get_audience(){
        return this->target_audience;
    }
};

class Manager {
    std::string name;
    std::vector<Account> accounts;
public:
    //Constructor de Initiere
    Manager(const std::string &name, const std::vector<Account>& accounts) : name(name), accounts(accounts) {}
//    explicit Manager(const std::string &nume) : name(nume) {}
    //Operator =
    bool operator==(const Manager &mg) const {
        return name == mg.name &&
               accounts == mg.accounts;
    }
    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Manager &manager) {
        os << "name: " << manager.name << "\naccounts: \n";
        int i = 1;
        for(const auto& conturi: manager.accounts) {
            std::cout << "contul " << i <<" : "<< conturi << '\n';
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

    void add_account(Account new_account){
        this->accounts.push_back(new_account);
    }

    //getters
    std::string get_name(){
        return this->name;
    }

};
int main() {
    std::vector<Post> postari{Post{150, 345, {"crypto", "btc", "eth"}, "crypto"},
                              Post{151, 345, {"sport", "food", "travel"}, "lifestyle"},
                              Post{123, 444, {"ceva", "ceva", "ceva"}, "ceva"}};
    Account cont1{"jane.doe12", 345, 789, 6, "children", postari};
    Manager man{"John Smith", {cont1}};

    // Functionalitati postare
    postari[0].do_like();
    std::cout << postari[0].get_likes() << std::endl;
//    Post postare2 = postari[0];
//    std::cout << postare2;
    postari[0].do_unlike();
    std::cout<<postari[0].get_likes() << std::endl;

    postari[0].get_hashtags();
    std::cout<<'\n';
    postari[0].add_hashtag("newww");
    postari[0].get_hashtags();
    std::cout<<'\n';

    std::cout << postari[1].get_theme() << std::endl;
    postari[1].change_theme("hollywood");
    std::cout << postari[1].get_theme() << std::endl;


    // Functionalitati cont
    std::cout <<cont1;
    cont1.add_post(Post{150, 345, {"food", "kitchen", "healthy"}, "cooking"});
    cont1.get_posts();

    std::cout << cont1.get_followers() << std::endl;
    std::cout << cont1.get_following() << std::endl;
    cont1.new_follower();
    cont1.new_following();
    std::cout << cont1.get_followers() << std::endl;
    std::cout << cont1.get_following() << std::endl;

    std::cout << cont1.get_audience() << std::endl;
    cont1.change_audience("girls");
    std::cout << cont1.get_audience() << std::endl;

    // Functionalitati manager
    std::cout << man.get_name();
    man.change_name("Jane Smith");
    man.add_account(Account{"john.not", 100, 1000, 3, "teenagers", postari});
    std::cout <<man;
}