// Example program
#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;
int main()
{
    
  string strData = "(12{2356(782[efsdvdfbdf]vfsbfbf)vsbfbfbd}vfsbd)";
  stack<char> currentBrackets;
  map<char,char> bracketTypes;
  
  bracketTypes['{'] = '}';
  bracketTypes['('] = ')';
  bracketTypes['['] = ']';
  
  int nLength =  strData.length();
  for(int i=0;i<nLength;i++){
      if(bracketTypes.find(strData.at(i))!=bracketTypes.end()){ 
            currentBrackets.push(bracketTypes[strData.at(i)]);
      }else if(strData.at(i)==')' || strData.at(i)=='}' || strData.at(i)==']'){
            if(currentBrackets.empty() || strData.at(i) != currentBrackets.top()){
                //return false;
                cout << "False" << endl;
            }else {
                currentBrackets.pop();
            }
      }
  }
  
  cout << "True" << endl;
  
}
