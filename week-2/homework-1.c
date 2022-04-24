class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        for(int i = 0; i < cpdomains.size(); i++){
            int level = getDomainLevel(cpdomains[i]);
            int num = getTimesFromString(cpdomains[i]);
            if(level == 3){
                std::string top_domain = getTopDomain(cpdomains[i]);
                if(m_map.find(top_domain) != m_map.end()){
                    m_map[top_domain] = m_map[top_domain] + num;
                }else{
                    m_map[top_domain] = num;
                }
                std::string second_domain = getSecondDomain(cpdomains[i]);
                if(m_map.find(second_domain) != m_map.end()){
                    m_map[second_domain] = m_map[second_domain] + num;
                }else{
                    m_map[second_domain] = num;
                }
                std::string third_domain = getThirdDomain(cpdomains[i]);
                if(m_map.find(third_domain) != m_map.end()){
                    m_map[third_domain] = m_map[third_domain] + num;
                }else{
                    m_map[third_domain] = num;
                }
            }else if(level == 2){
                std::string top_domain = getTopDomain(cpdomains[i]);
                if(m_map.find(top_domain) != m_map.end()){
                    m_map[top_domain] = m_map[top_domain] + num;
                }else{
                    m_map[top_domain] = num;
                }
                std::string third_domain = getThirdDomain(cpdomains[i]);
                if(m_map.find(third_domain) != m_map.end()){
                    m_map[third_domain] = m_map[third_domain] + num;
                }else{
                    m_map[third_domain] = num;
                }
            }else if(level ==1){
                if(m_map.find(cpdomains[i]) != m_map.end()){
                    m_map[cpdomains[i]] = m_map[cpdomains[i]] + num;
                }else{
                    m_map[cpdomains[i]] = num;
                }
            }
        }
        vector<std::string> ans;
        for(auto it = m_map.begin(); it != m_map.end(); it++){
            stringstream ss;
            ss.clear();
            ss << it->second;
            std::string tmp;
            ss >> tmp;
            tmp = tmp + " " + it->first;
            ans.push_back(tmp);
        } 
        return ans;
    }

private:
    int getTimesFromString(std::string str){
        auto it = str.find(' ');
        std::string number = str.substr(0, it);
        int num = atoi(number.c_str());
        return num;
    }
    std::string getTopDomain(std::string str){
        auto it = str.rfind('.');
        std::string top_domain = str.substr(it+1);
        return top_domain;
    }
    std::string getSecondDomain(std::string str){
        std::string third_domain = getThirdDomain(str);
        auto it = third_domain.find('.');
        std::string second_domain = third_domain.substr(it+1);
        return second_domain;
    }
    std::string getThirdDomain(std::string str){
        auto it = str.find(' ');
        std::string third_domain = str.substr(it+1);
        return third_domain;
    }
    int getDomainLevel(std::string str){
        auto it = str.find('.');
        if(it == std::string::npos){
            return 1;
        }
        auto it1 = str.rfind('.');
        if(it == it1){
            return 2;
        }else{
            return 3;
        }

    }
private:
    std::unordered_map<std::string, int> m_map;
};
