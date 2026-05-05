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
    public ListNode rotateRight(ListNode head, int k) {
        //base case
        if(head == null || head.next == null){
            return head;
        }
        ListNode temp = head;
        int count = 1;
        while(temp.next != null){
            temp = temp.next;
            count++;
        }
        k %= count;
        ListNode current = head;
        for(int i = 1; i < count - k; i++){
            current = current.next;
        } 
        temp.next = head;
        head = current.next;
        current.next = null;
        return head;

        
    }
}