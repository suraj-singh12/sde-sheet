import java.util.* ;
import java.io.*; 
/****************************************************************

    Following is the class structure of the Node class:

    class LinkedListNode {
        int data;
        LinkedListNode next;
        
        public LinkedListNode(int data) {
            this.data = data;
        }
    }

*****************************************************************/


public class Solution {
    static LinkedListNode addTwoNumbers(LinkedListNode head1, LinkedListNode head2) {
        if(head1 == null) return head2;
        if(head2 == null) return head1;
        // use basic maths: sum, digit, carry
        LinkedListNode ansList = new LinkedListNode(0);
        LinkedListNode newHead = ansList;
        
        int sum = 0, carry = 0, digit = 0;
        
        while(head1 !=  null && head2 != null) {
            sum = head1.data + head2.data + carry;
            digit = sum % 10;            // take the digit
            
            // create data node
            LinkedListNode ansNode = new LinkedListNode(digit);
            // add to the ans list
            ansList.next = ansNode;
            ansList = ansList.next;
            
            carry = sum / 10;        // carry it forward
            head1 = head1.next;
            head2 = head2.next;
        }
        while(head1 != null) {
            sum = head1.data + carry;
            digit = sum % 10;
            
             // create data node
            LinkedListNode ansNode = new LinkedListNode(digit);
            // add to the ans list
            ansList.next = ansNode;
            ansList = ansList.next;
            
            carry = sum / 10;
            head1 = head1.next;
        } 
        while(head2 != null) {
            sum = head2.data + carry;
            digit = sum % 10;
            
             // create data node
            LinkedListNode ansNode = new LinkedListNode(digit);
            // add to the ans list
            ansList.next = ansNode;
            ansList = ansList.next;
            
            carry = sum / 10;
            head2 = head2.next;
        }
        if(carry != 0) {
             // create data node
            LinkedListNode ansNode = new LinkedListNode(carry);
            // add to the ans list
            ansList.next = ansNode;
            ansList = ansList.next;
        }
        return newHead.next;
    }
}
