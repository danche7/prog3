#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> rez;
        int m = nums1.size(), n = nums2.size();
        
        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> max1 = najgolema(nums1, i);
            vector<int> max2 = najgolema(nums2, k - i);
            vector<int> mozda = merge(max1, max2);
            rez = max(rez, mozda);
        }
        
        return rez;
    }

    
    vector<int> najgolema(vector<int>& vi, int k) {
        vector<int> v;
        int ne = vi.size()-k;

        for(int num:vi)
        {
            while(!v.empty() and v.back()<num and ne>0)
            {
                v.pop_back();
                ne--;
            }
            v.push_back(num);
        }

        v.resize(k);
        return v;
    }
    
    
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> spojse;
        auto i = nums1.begin(), j = nums2.begin();
        while (i != nums1.end() || j != nums2.end()) 
        {
            //sakam od najgolemata niza da staam broj 
            if (lexicographical_compare(i, nums1.end(), j, nums2.end())) 
            {
                spojse.push_back(*j);
                j++;
            
            }
            else 
            {
                spojse.push_back(*i);
                i++;
            }
        }
        return spojse;
    }
};
