class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum =0;
        int n= columnTitle.length();
        for(int i =0; i<n; i++){
            int ch = columnTitle[i] - 'A' + 1;
            cout<<ch<<endl;
            sum += pow(26,n-i-1) * ch;
            cout<<sum<<endl;
        }
        return sum;
    }
};