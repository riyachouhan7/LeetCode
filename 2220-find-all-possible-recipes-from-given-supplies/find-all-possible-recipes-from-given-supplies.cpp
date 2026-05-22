class Solution {
public:
    vector<string> findAllRecipes(
            vector<string>& recipes,
            vector<vector<string>>& ingredients,
            vector<string>& supplies) {

        unordered_set<string> available(
                supplies.begin(),
                supplies.end());

        vector<string> ans;

        bool changed=true;

        while(changed){

            changed=false;

            for(int i=0;i<recipes.size();i++){

                if(available.count(recipes[i]))
                    continue;

                bool canMake=true;

                for(string ing:ingredients[i]){

                    if(!available.count(ing)){
                        canMake=false;
                        break;
                    }
                }

                if(canMake){

                    available.insert(recipes[i]);

                    ans.push_back(recipes[i]);

                    changed=true;
                }
            }
        }

        return ans;
    }
};