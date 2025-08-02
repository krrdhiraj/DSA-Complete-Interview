class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(auto i : nums1){
            nums2.push_back(i);
        }
        double med = 0.0;
        sort(nums2.begin(), nums2.end());
        int size = nums2.size();
        int mid = size/2;
        if(size % 2 == 0){
            
            med = double(nums2[mid-1] + nums2[mid])/2.0;
        }else{
            med = double(nums2[mid]);
        }
        return med;
    }
};