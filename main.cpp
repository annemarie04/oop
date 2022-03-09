#include <iostream>
#include <vector>


class Post {
    int no_likes;
    int no_comments;
//    std::vector<std::string> hashtags;
    std::string theme;
public:

    // Constructor de Initiere
//    Post(int noLikes, int noComments, const std::vector<std::string> &hashtags, const std::string &theme) : no_likes(
//            noLikes), no_comments(noComments), hashtags(hashtags), theme(theme) {}
    Post(int noLikes, int noComments, const std::string &theme) : no_likes(
            noLikes), no_comments(noComments), theme(theme) {}
    // Operator =
    bool operator==(const Post &postare) const {
        return no_likes == postare.no_likes &&
               no_comments == postare.no_comments &&
//               hashtags == postare.hashtags &&
               theme == postare.theme;
    }
    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Post &post) {
        os << "no_likes: " << post.no_likes << " no_comments: " << post.no_comments
           << " theme: " << post.theme;
        return os;
    }
    // Destructor
    ~Post() {}

};

class Account {
    std::string username;
    int followers;
    int following;
    int no_posts;
    std::string target_audience;
//    std::vector<Post> posts;
public:
    // Constructor de Initiere
//    Account(const std::string &username, int followers, int following, int noPosts, const std::string &targetAudience,
//            const std::vector<Post> &posts) : username(username), followers(followers), following(following),
//                                              no_posts(noPosts), target_audience(targetAudience), posts(posts) {}
    Account(const std::string &username, int followers, int following, int noPosts, const std::string &targetAudience) : username(username), followers(followers), following(following),
                                              no_posts(noPosts), target_audience(targetAudience) {}
    // Operator =
    bool operator==(const Account &cont) const {
        return username == cont.username &&
               followers == cont.followers &&
               following == cont.following &&
               no_posts == cont.no_posts &&
               target_audience == cont.target_audience;
//               posts == cont.posts;
    }
    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Account &account) {
        os << "username: " << account.username << " followers: " << account.followers << " following: "
           << account.following << " no_posts: " << account.no_posts << " target_audience: " << account.target_audience;
//           << " posts: " << account.posts;
        return os;
    }
    // Destructor
    ~Account() {}
};

class Manager {
    std::string name;
//    std::vector<Account> accounts;
public:
    //Constructor de Initiere
//    Manager(const std::string &name, const std::vector<Account> &accounts) : name(name), accounts(accounts) {}
    Manager(const std::string &name) : name(name) {}
    //Operator =
    bool operator==(const Manager &mg) const {
        return name == mg.name;
//               accounts == mg.accounts;
    }
    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Manager &manager) {
        os << "name: " << manager.name;
        return os;
    }
    // Destructor
    ~Manager() {}
};
int main(){
    Post postare1 = {151, 345, "lifestyle"};
    Account cont1 = {"jane.doe12", 345, 789, 6, "children"};
    Manager manager = {"John Smith"};

}
