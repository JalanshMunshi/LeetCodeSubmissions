class Solution {
public:
    int maxArea(int h, int w, vector<int>& hori, vector<int>& verti) {
        
        hori.push_back(0);
        hori.push_back(h);
        verti.push_back(0);
        verti.push_back(w);
        sort(hori.begin(), hori.end());
        sort(verti.begin(), verti.end());
        
        long height = 1, width = 1, htemp, wtemp;
        
        for(int i=1; i<hori.size(); i++)
        {
            htemp = hori[i] - hori[i-1];
            if(htemp > height)
                height = htemp;
        }
        for(int i=1; i<verti.size(); i++)
        {
            wtemp = verti[i] - verti[i-1];
            if(wtemp > width)
                width = wtemp;
        }
        return ((height%1000000007)*(width%1000000007))%1000000007;
    }
};