class BinaryIndexedTree {
public:
    int size;               // The size of the array
    vector<int> treeArray;  // The array that represents the tree

    // Constructor to initialize the tree with a given size.
    BinaryIndexedTree(int size)
        : size(size)
        , treeArray(size + 1, 0) {}  // Allocate space for 'size+1' because of 1-based indexing

    // Function to update the value at a specific index,
    // 'delta' represents the value to be added.
    void update(int index, int delta) {
        while (index <= size) {
            treeArray[index] += delta;  // Add 'delta' to current index
            index += lowbit(index);     // Move to the next index that needs to be updated
        }
    }

    // Function to return the prefix sum from the tree, up to a given index.
    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += treeArray[index]; // Add current value to the sum
            index -= lowbit(index);  // Move to the next component of the prefix sum
        }
        return sum;
    }

private:
    // Internal function to calculate the least significant bit that is set.
    int lowbit(int x) {
        return x & -x;
    }
};

// NumArray class to manage an array of numbers using a Binary Indexed Tree,
// enabling efficient updates and range sum queries.
class NumArray {
private:
    unique_ptr<BinaryIndexedTree> tree; // Pointer to the Fenwick Tree

public:
    // Constructor with a given vector of numbers, initializes the Binary Indexed Tree.
    NumArray(vector<int>& nums) {
        int n = nums.size();
        tree = make_unique<BinaryIndexedTree>(n);
        // Initialize the tree with the initial values of 'nums'
        for (int i = 0; i < n; ++i) tree->update(i + 1, nums[i]);
    }

    // Function to update an element of the array at a given 'index' with a new value 'val'.
    void update(int index, int val) {
        int current = sumRange(index, index);  // Get current value at the index
        tree->update(index + 1, val - current); // Update the tree with the difference
    }

    // Function to calculate the sum of the elements in the range [left, right].
    int sumRange(int left, int right) {
        // Use tree queries to find the sum from 0 to 'right' and subtract the sum from 0 to 'left-1'
        return tree->query(right + 1) - tree->query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index, val);
 * int param_2 = obj->sumRange(left, right);
 */
