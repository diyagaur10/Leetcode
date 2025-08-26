class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_dia = 0;
        int max_area = 0;
        
        for(int i =0; i<dimensions.size(); i++){
            int h = dimensions[i][0];
            int b = dimensions[i][1];
            int curr_dia = h*h + b*b;
            if(curr_dia > max_dia || (curr_dia == max_dia && h*b > max_area)){
                max_dia= curr_dia;
                max_area = h * b;
            }
        }
        return max_area;
    }
};