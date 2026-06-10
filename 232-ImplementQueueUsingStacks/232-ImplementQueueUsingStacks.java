// Last updated: 6/10/2026, 7:25:34 PM
/*
 * @lc app=leetcode id=232 lang=java
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
import java.util.*;
class MyQueue {
    Deque<Integer> stackIn , stackOut;

    public MyQueue() {
        stackOut = new ArrayDeque<>();
        stackIn = new ArrayDeque<>();    
    }
    
    public void push(int x) {
        stackIn.addLast(x);
    }
    
    public int pop() {
        if (stackOut.isEmpty()) {
            while (!stackIn.isEmpty()) stackOut.addLast(stackIn.removeLast());
        } 
        return stackOut.removeLast();
    }
    
    public int peek() {
        if (stackOut.isEmpty()) {
            while (!stackIn.isEmpty()) stackOut.addLast(stackIn.removeLast());
        } 
        return stackOut.peekLast();
    }
    
    public boolean empty() {
        return stackIn.isEmpty() && stackOut.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
// @lc code=end

