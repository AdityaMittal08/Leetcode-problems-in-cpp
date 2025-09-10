#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {

        unordered_set <int> teach;
        for(auto&friendship : friendships){
            int user1 = friendship[0] - 1;
            int user2 = friendship[1] - 1;
            bool canCommunicate = false;

            for(int lang1 : languages[user1]){
                for(int lang2 : languages[user2]){
                    if(lang1 == lang2){
                        canCommunicate = true;
                        break;
                    }
                }
                if(canCommunicate) break;
            }
            if(!canCommunicate){
                teach.insert(user1);
                teach.insert(user2);
            }
            
        }

        int minUsersToTeach = languages.size() + 1;

        for(int language = 1; language <= n; language++){
            int count = 0;

            for(int user : teach){
                bool knowsLanguage = false;
                for(int lang: languages[user]){
                    if(lang == language){
                        knowsLanguage = true;
                        break;
                    }
                }
                if(!knowsLanguage) count ++;
            }

            minUsersToTeach = min(minUsersToTeach, count);
        }
        return minUsersToTeach;
    }
};