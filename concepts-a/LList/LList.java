package LList;

import java.util.Scanner;
/**
 *
 * @author carsongedeus
 */
class Node {
    
    int data;
    Node next;
    
    Node(int data) {
        this.data = data;
    }
}

public class LList {
    
    Node head;
    
    public Node insertnode(int data) {
        
        Node temp;
        
        if(head == null) {
            head = new Node(data);
        } else {
            temp = new Node(data);
            temp.next = head;
            head = temp;
        }
        return head;
    }
    
    public void deletenode(int data) {

        Node prev = null;

        for (Node trace = head; trace != null; trace = trace.next) {

            if (trace.data == data) {
                if (prev == null) {
                    head = trace.next;
                } else {
                    prev.next = trace.next;
                }
            } else {
                prev = trace;
            }
        }
    }
    
    public void printer() {
        System.out.println(head.data);
    }
    
    public static void main(String[] args) {
        
        LList linkedlist = new LList();
        Scanner scan = new Scanner(System.in);
        int n;
        
        for(int i = 0; i < (n = 10); i++) {
            linkedlist.insertnode((int)(Math.random()*100+1));
            linkedlist.printer();
        }
        
        System.out.println("Delete something: ");
        int input = scan.nextInt();
        linkedlist.deletenode(input);
        
        System.out.println(input + " deleted.");
    }
}