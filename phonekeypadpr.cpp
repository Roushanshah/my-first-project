// phone keypad problem
// letter combinations of a phone number
//given a string containing digits from 2-9 inclusive,return all possible letter combinations that the number
//could represent. Return the answer in any order.
#include<iostream>
#include<vector>
using namespace std;
class solution{
    private:
    void solve(string digit,string output,vector<string>& ans,int index,string mapping[]){
        if (index>=digit.length())
        {
            ans.push_back(output);
            return;
        }

       
        int number=digit[index]-'0';
        string value=mapping[number];
        for (int i = 0; i < value.length(); i++)
        {
          output.push_back(value[i]);
          solve(digit,output,ans,index+1,mapping);
          output.pop_back();
        }
        
    }
    public:
    vector<string> letterCombinations(string digit){
          vector<string> ans;
          if (digit.length()==0)
          {
            return ans;
          }
          
          string output;
          int index=0;
          string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
          solve(digit,output,ans,index,mapping);
          return ans;
    }
};
int main(){
  solution phone;
  string str="23";
  phone.letterCombinations(str);
  return 0;
}