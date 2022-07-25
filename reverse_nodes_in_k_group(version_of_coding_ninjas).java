import java.util.* ;
import java.io.*; 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

public class Solution {
    public static Node getListAfterReverseOperation(Node head, int n, int b[]) {
        
        // make a dummy node
        // use 3 pointers to reverse the list as per B[]
        
        Node dummy = new Node(0);
        dummy.next = head;
        Node pre = dummy, cur = dummy, nex = dummy;
        
        // get the count of the number of nodes in Linked list
        Node tmp = head;
        int cnt = 0;
        while(tmp != null) {
            cnt++;
            tmp = tmp.next;
        }
        int origCnt = cnt;
        
        int i = 0;
        while(i < n) {
            while(i < n && b[i] == 0) 
                i++;
            if(i == n) break;
            if(cnt == 0) break;
            if(!(cnt >= b[i])) 
                b[i] = cnt;
            
            cur = pre.next;
            nex = cur.next;
            
            for(int c = 1; c < b[i];++c) {
                cur.next = nex.next;
                nex.next = pre.next;
                pre.next = nex;
                nex = cur.next;
            }
            pre = cur;
            cnt -= b[i];
            i++;
        }
        return dummy.next;
    }
}
