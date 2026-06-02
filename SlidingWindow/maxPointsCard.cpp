/* Maximum point you can obtain from cards
Given N cards arranged in a row, each card has an associated score denoted by the cardScore array. Choose exactly k cards. In each step, a card can be chosen either from the beginning or the end of the row. The score is the sum of the scores of the chosen cards.

Examples

Input :cardScore = [1, 2, 3, 4, 5, 6] , k = 3
Output : 15
Explanation :Choosing the rightmost cards will maximize your total score. 
So optimal cards chosen are the rightmost three cards 4 , 5 , 6.
Th score is 4 + 5 + 6 => 15.


Input :cardScore = [5, 4, 1, 8, 7, 1, 3] , k = 3
Output :12
Explanation : In first step we will choose card from beginning with score of 5.
In second step we will choose the card from beginning again with score of 4.
In third step we will choose the card from end with score of 3.
The total score is 5 + 4 + 3 => 12
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxPointsFromCard(vector<int> &cardScore, int k){
    int score = 0, n = cardScore.size();
    for(int i = 0; i <= k; i++){
      int tempScore = 0;
      for(int j = 0; j < i; j++){
        tempScore += cardScore[j];
      }
      for(int j = 0; j < k - i; j++){
        tempScore += cardScore[n - 1 - j];
      }
      score = max(score, tempScore);
    }
    return score;
  }
  
  int maxPointsFromCardSW(vector<int> &cardScore, int k){
    int score = 0, left = 0;
    int n = cardScore.size();
    for(int i = 0; i < k; i++) // add first k terms
      score += cardScore[i];
    int maxScore = score;
    for(int i = 0; i < k; i++){ // slide from the right to left and replace with last element
      score -= cardScore[k - 1 - i];
      score += cardScore[n - 1 - i];
      maxScore = max(maxScore, score);
    }
    return maxScore;
  }
};

int main() {
  vector<int> cardScore = {5, 4, 1, 8, 7, 1, 3}; // Output : 15
  int k = 3;  
  Solution sl;
  cout<<sl.maxPointsFromCard(cardScore, k)<<endl;
  cout<<sl.maxPointsFromCardSW(cardScore, k)<<endl;
  return 0;
}
