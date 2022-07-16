import java.util.* ;
import java.io.*; 
/*
	Following is the structure of the Singly Linked List.	
	class LinkedListNode<T> 
    {
    	T data;
    	LinkedListNode<T> next;
    	public LinkedListNode(T data) 
        {
        	this.data = data;
    	}
	}

*/
public class Solution 
{
    public static LinkedListNode<Integer> reverseLinkedList(LinkedListNode<Integer> head) 
    {
        // using 3 pointers (optimized) approach
        LinkedListNode<Integer> prev = null, current = head, next;
        
        while(current != null) {
            // save the next node in next
            next = current.next;
            // point current node's next pointer to previous (reversing)
            current.next = prev;
            // update previous & current
            prev = current;
            current = next;
        }
        
        // at last prev is at the last original node (i.e. first node of our reversed linked list)
        return prev;
    }
}
