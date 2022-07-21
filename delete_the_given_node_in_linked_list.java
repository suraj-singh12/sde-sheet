import java.util.* ;
import java.io.*; 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    class LinkedListNode<T> {
        T data;
        LinkedListNode<T> next;
        LinkedListNode(T data)
        {
            this.data = data;
            this.next = null;
        }
    }

*****************************************************************/

public class Solution {
	public static void deleteNode(LinkedListNode<Integer> node) {
        // indirectly deleting the node
        
        if(node == null) return;
        
        if(node.next == null) 
            node.data = -1;    // deleted
        
        node.data = node.next.data;
        node.next = node.next.next;
        // the node in between is dropped, & it's data is in current node
        // and current node's data is lost
        // so indirectly current node is deleted
	}
}
