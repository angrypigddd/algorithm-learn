class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        //构造辅助数组
        vector<vector<int>> vv;
        for(int i = 0; i < matrix.size(); i++){
            vector<int> tmp;
            for(int j = 0; j < matrix[0].size(); j++){
                if(j == 0){
                    if(matrix[i][j] == '0'){
                        tmp.push_back(0);
                    }else{
                        tmp.push_back(1);
                    }
                    cout << tmp[0] << " ";
                    continue;
                }
                if(matrix[i][j] == '0'){
                    tmp.push_back(0);
                }else{
                    tmp.push_back(tmp[j-1] + 1);
                }
                cout << tmp[j] << " ";
            }
            cout << endl;
            vv.push_back(tmp);
        }
        //按列进行计算
        int ans = 0;
        if(matrix.size() == 0)
            return ans;
        for(int i = 0; i < matrix[0].size(); i++){  //计算每一列
            vector<int> v;
            for(int j = 0; j < matrix.size(); j++){
                v.push_back(vv[j][i]);
            }
            int max_ans = getMaxAanglePerColumn(v);
            ans = ans < max_ans ? max_ans : ans;
        }
        return ans;
    }
private:
    typedef struct Rec{
        Rec(int height_, int width_)
            : height(height_), width(width_){}
        int height;
        int width;
    }Rec;
    int getMaxAanglePerColumn(vector<int>& heights){
        int ans = 0;
        stack<Rec> s;
        for(auto height : heights){
            int acu = 0;
            while(!s.empty() && s.top().height > height){
                int area = (s.top().width + acu) * s.top().height;
                ans = ans > area ? ans : area;
                acu += s.top().width;
                s.pop();
            }
            
            s.push(Rec(height, 1 + acu));
        }
        int acu = 0;
        while(!s.empty()){
            int area = (s.top().width + acu) * s.top().height;
            ans = ans > area ? ans : area;
            acu += s.top().width;
            s.pop();
        }
        return ans;

    }

};
