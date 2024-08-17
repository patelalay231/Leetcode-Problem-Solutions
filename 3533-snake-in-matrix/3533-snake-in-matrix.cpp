class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0;
        int j = 0;
        for(auto command : commands){
            if(command == "RIGHT"){
                j++;
            }
            else if(command == "LEFT"){
                j--;
            }
            else if(command == "DOWN"){
                i++;
            }
            else{
                i--;
            }
        }
        return (i*n)+j;
    }
};