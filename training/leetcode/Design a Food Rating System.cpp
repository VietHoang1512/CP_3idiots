#include <bits/stdc++.h>
using namespace std;

int main()
{
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

bool cmp(string a, string b){
    if (a.compare(0, b.size(), b) == 0
        || b.compare(0, a.size(), a) == 0)
 
        return a.size() > b.size();

    else
        return a < b;
}
class FoodRatings
{
public:
    vector<string> foods;
    vector<string> cuisines;
    vector<int> rating;
    unordered_map<string, vector<int>> cuisines2foods;
    vector<string> lexical_order;
    unordered_map<int, int> food2order;
    unordered_map<string, int> food2id;
    FoodRatings(vector<string> &f, vector<string> &c, vector<int> &r)
    {
        foods = f;
        cuisines = c;
        rating = r;
        int total = f.size();
        for (int i = 0; i < total; i++)
        {
            lexical_order.push_back(f[i]);
            cuisines2foods[c[i]].push_back(i);

            food2id[f[i]] = i;
        }
        sort(lexical_order.begin(), lexical_order.end(), cmp);
        for (int i=0; i<total; i++){
            food2order[food2id[lexical_order[i]]] = i;
        }
    }

    void changeRating(string food, int newRating)
    {
        rating[food2id[food]] = newRating;
    }

    string highestRated(string cuisine)
    {
        int mx = -1;
        string res = "none";
        for (auto food : cuisines2foods[cuisine])
        {
            if (rating[food] > mx)
            {
                mx = rating[food];
                res = foods[food];
            }
            else if (rating[food] == mx)
            {

                if (food2order[food] < food2order[food2id[res]]){
                    res = foods[food];
                    mx = rating[food];
                }
            }
        }
        return res;
    }
};
