class CustomStack {
public:
    vector<int> stack;
    int top;
    int maxSize;  // Keeping track of the maximum size

    CustomStack(int maxSize) {
        stack.resize(maxSize); // Initialize the vector with maxSize capacity
        this->maxSize = maxSize;
        top = -1;             // Initialize top to -1 indicating an empty stack
    }

    void push(int x) {
        if (top + 1 < maxSize) { // Check if there's room to push
            top++;
            stack[top] = x;
        }
    }

    int pop() {
        if (top != -1) {
            return stack[top--];
        }
        return -1; // Return -1 if stack is empty
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, top + 1); i++) {
            stack[i] += val;
        }
    }
};