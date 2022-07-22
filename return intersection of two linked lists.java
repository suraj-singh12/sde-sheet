import java.util.* ;
import java.io.*; 
/************************************
	 
	 //Following is the class structure of the LinkedListNode class:
	 
	  class LinkedListNode<T> {
		public T data;
		public LinkedListNode<T> next;
		
		public LinkedListNode(T data) {
			this.data = data;
			this.next = null;
		}
	}

*****************************************/
public class Solution {

	public static int findIntersection(LinkedListNode<Integer> firstHead, LinkedListNode<Integer> secondHead) {
        
        LinkedListNode<Integer> a = firstHead, b = secondHead;
        while(a != b) {
            a = (a == null) ? secondHead : a.next;
            b = (b == null) ? firstHead : b.next;
        }
        if(a != null) 
            return a.data;
        return -1;
	}
}
