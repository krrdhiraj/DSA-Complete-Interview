class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int[] temp = new int[n+m];

        int i = 0, j = 0, k = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                temp[k] = nums1[i];
                i++;
            }else{
                temp[k] = nums2[j];
                j++;
            }
            k++;
        }
        while(i < m){
            temp[k++] = nums1[i++];
        }

        while(j < n){
            temp[k++] = nums2[j++];
        }
        double median = 0.0;
        int mid = (m+n)/2;
        if((m+n)%2 == 0){
            median = ((double)temp[mid] + (double)temp[mid-1])/2.0;
        }else{
            median = (double)temp[mid];
        }

        return median;
    }
}