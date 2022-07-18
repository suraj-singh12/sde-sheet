import java.util.* ;
import java.io.*; 
/************************************************************

    Following is the linked list node structure:
    
    class LinkedListNode<T> {
        T data;
        LinkedListNode<T> next;

        public LinkedListNode(T data) {
            this.data = data;
        }
    }

************************************************************/

public class Solution {
	public static LinkedListNode<Integer> sortTwoLists(LinkedListNode<Integer> first, LinkedListNode<Integer> second) {
        /*
        Approach1: make a new linked list having all the nodes in it in ascending order
        Approach2: do in place next pointer modification in the lists to make them one sorted list (better/optimal): TC: O(M + N), SC: O(1)
        */
        
        //boundary cases
        if(first == null && second == null) {
            return null;
        } else if(first == null) {
            return second;
        } else if(second == null) {
            return first;
        }
        LinkedListNode<Integer> list = null;
        if(first.data > second.data) {
            LinkedListNode temp = first;
            first =  second;
            second = temp;
        }
        list = first;
        while(first != null && second != null) {
            LinkedListNode prev = null;
            while(first!=null &&  first.data <= second.data) {
                prev = first;
                first = first.next;
            }
            prev.next = second;
            LinkedListNode temp = first;
            first = second;
            second = temp;
        }
        return list;
	}
}
