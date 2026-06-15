/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        ListNode temp = head;
        int n =0;
        while(temp!= null){
            n++;
            temp= temp.next;
        }
        temp = head;
        if (head == null || head.next == null) {
            return null;
        }
        int m = n/2;
        for(int i =0; i<m-1; i++){
            temp = temp.next;
        }
        temp.next= temp.next.next;
        return head;
    }
}