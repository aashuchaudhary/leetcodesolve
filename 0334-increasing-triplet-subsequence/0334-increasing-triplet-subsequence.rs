impl Solution {
    pub fn increasing_triplet(nums: Vec<i32>) -> bool {
        if nums.len() < 3 {
            return false;
        }

        let mut left = i32::MAX;
        let mut mid = i32::MAX;

        for &num in &nums {
            if num > mid {
                return true;
            } else if num < left {
                left = num;
            } else if num > left && num < mid {
                mid = num;
            }
        }

        false
    }
}
